#include "../include/XMLBase.h"



XMLBase::XMLBase()
    :XMLRoot()
{
    //ctor

}

XMLBase::XMLBase(std::string file)
    :XMLRoot()
{
    //ctor
    this->load_xml_file(file);
}

XMLBase::~XMLBase()
{
    //dtor
}

void XMLBase::load_xml_file(std::string file)
{
#ifdef Use_Watchdogs
    unsigned int sleeping_time = this->timeout /8;
    this->curent_timeout = 0;
    std::thread load_thread(&XMLBase::Watchdogs_load_xml_file, this, file);
    this->job_finich = false;
    while(!this->job_finich)
    {
        if(this->curent_timeout > this->timeout)
        {
            throw XMLBase_load_Exception();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeping_time));
        this->curent_timeout += sleeping_time;
    }
    load_thread.join();
}
void XMLBase::Watchdogs_load_xml_file(std::string file)
{
#endif

    std::ifstream xml_file(file);
    char text = ' ';
    char last_text = ' ';

    while(text != '\n')                                 //add get encoding
    {
        xml_file.get(text);
    }

    //var use for reading
    XMLRoot * position = this;

    bool balise = false;
    bool nom_balise = false;
    bool atribue_balise = false;
    bool value_balise = false;
    bool racine = true;
    bool slash = false;
    bool chevron_open = false;

    while(xml_file.get(text))                //reading file + mapping xml
    {
        returnRuntime:

#ifdef Use_Watchdogs
            this->curent_timeout = 0;
#endif // Use_Watchdogs
        if(position==NULL)
        {
            break;
        }

        //condition
        if (chevron_open)
        {
            chevron_open = false;
            nom_balise = true;
            atribue_balise = false;
            value_balise = false;
            balise = true;
            if (text=='/')
            {
                position = position->get_parent();
                balise = false;
                while(text!='>')
                {
                    xml_file.get(text);
                }
                xml_file.get(text);
                last_text = text;
                goto returnRuntime;
            }
            else
            {
                if(racine)
                {
                    racine = false;
                    position->set_parent(nullptr);
                }
                else
                {
                    XMLRoot * tmpxml = new XMLRoot();
                    position->add_child(*tmpxml);
                    (position->get_child())->set_parent(position);
                    position = position->get_child();
                }
            }
        }
        if (text=='<')
        {
            chevron_open = true;
            slash = false;
        }
        if (text=='/')
        {
            slash = true;
        }
        if (text=='>')
        {
            balise = false;
            if (slash)                      //if is a orphan tag
            {
                std::string error = position->get_value(position->length_value()-1);
                error.erase(error.end()-1);
                position->set_value(error,position->length_value()-1);
                position = position->get_parent();
            }
        }
        if (balise)
        {
            if(text!=' ' && text != '\"' && text !='=')
            {
                if(nom_balise && text!='/')
                {
                    position->set_tag_name((position->get_tag_name())+text);
                }
                if(atribue_balise)
                {
                    position->set_attribut(position->get_attribut(position->length_attribut()-1)+text,position->length_attribut()-1);
                }
                if(value_balise)
                {
                    position->set_value(position->get_value(position->length_value()-1)+text,position->length_value()-1);
                }
            }
            if(text == ' ')
            {
                if(nom_balise)
                {
                    nom_balise = false;
                    atribue_balise = true;
                    position->add_attribut("");
                }
                if(value_balise && last_text == '\"')
                {
                    value_balise = false;
                    atribue_balise = true;
                    position->add_attribut("");
                }else if(value_balise && last_text != '\"')
                {
                    position->set_value(position->get_value(position->length_value()-1)+text,position->length_value()-1);
                }
            }
            else
            {
                if(text == '=' && atribue_balise)
                {
                    atribue_balise = false;
                    value_balise = true;
                    position->add_value("");
                }
            }
        }
        else
        {
            if(text!='<'&&text!='>')
            {
                position->set_text(position->get_text()+text);  //a ajout� gestion tab avec nb_space_for_tab
            }
        }
        last_text = text;
    }
    xml_file.close();
    this->for_each(this->precleanup,(void *)this);
#ifdef Use_Watchdogs
        this->job_finich = true;
#endif // Use_Watchdogs
}

void XMLBase::save_xml_file(std::string file) //work in progress
{
    #ifdef Use_Watchdogs
    unsigned int sleeping_time = this->timeout /8;
    this->curent_timeout = 0;
    this->job_finich = false;
    std::thread load_thread(&XMLBase::Watchdogs_save_xml_file, this, file);
    while(!this->job_finich)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeping_time));
        this->curent_timeout += sleeping_time;
        if(this->curent_timeout > this->timeout)
        {
            throw XMLBase_save_Exception();
        }
    }
    load_thread.join();
}
void XMLBase::Watchdogs_save_xml_file(std::string file)
{
    #endif
    //write
    output_file.open(file,std::ios::trunc);                       //open file
    output_file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;

    this->for_each(this->presave, this->postsave, this);

    output_file.close();

    #ifdef Use_Watchdogs
        this->job_finich = true;
    #endif // Use_Watchdogs
}
#ifdef Use_Watchdogs
void XMLBase::set_timeout(unsigned int timeout)
{
    this->timeout = timeout;
}
#endif // Use_Watchdogs

void XMLBase::presave(XMLRoot* root,void * args)
{
    #ifdef Use_Watchdogs
        ((XMLBase*)args)->curent_timeout = 0;
    #endif // Use_Watchdogs
    ((XMLBase*)args)->output_file << '<' << root->get_tag_name();
    if(root->length_attribut() != 0)
    {
        for(size_t i=0 ; i<root->length_attribut() && i<root->length_value() ; i++)
        {
            ((XMLBase*)args)->output_file << ' ' << root->get_attribut(i) << '=' << '\"' << root->get_value(i) << '\"';
        }
    }
    if(root->length_child() == 0 && root->length_text_without_wihtespace() == 0)
    {
        ((XMLBase*)args)->output_file << "/>" << std::endl;
    }
    else
    {
        ((XMLBase*)args)->output_file << '>'<< std::endl;
        if(root->length_text_without_wihtespace() != 0)
        {
            ((XMLBase*)args)->output_file << root->get_text() << std::endl;
        }
    }

}
void XMLBase::postsave(XMLRoot* root,void * args)
{
    #ifdef Use_Watchdogs
        ((XMLBase*)args)->curent_timeout = 0;
    #endif // Use_Watchdogs
    if(root->length_child() == 0 && root->length_text_without_wihtespace() == 0)
    {

    }
    else
    {
        ((XMLBase*)args)->output_file << "</" << root->get_tag_name() << ">" << std::endl;
    }
}

void XMLBase::precleanup(XMLRoot* root,void * args)
{
    #ifdef Use_Watchdogs
        ((XMLBase*)args)->curent_timeout = 0;
    #endif // Use_Watchdogs
    if(root->length_text() != 0)
    {
        std::string clean_text = root->get_text();
        //cleaning text
        size_t i = 0;
        if(clean_text.size() != 0)
        {
            while(is_wihtespace(clean_text[i]))
            {
                if(clean_text.size() <= i)
                    break;
                i++;
            }
            clean_text.erase(clean_text.begin(),clean_text.begin()+i);
        }
        i = clean_text.size();
        if(clean_text.size() != 0)
        {
            while(is_wihtespace(clean_text[i]))
            {
                if(0 > i)
                    break;
                i--;
            }
            clean_text.erase(clean_text.begin()+i+1,clean_text.end());
        }
        root->set_text(clean_text);
    }
    else
    {
        root->set_text("");
    }
}
