#include "../include/XMLBase.h"



XMLBase::XMLBase()
    :XMLRoot()
{
    //ctor

}

XMLBase::XMLBase(string file)
    :XMLRoot()
{
    //ctor
    this->load_xml_file(file);
}

XMLBase::~XMLBase()
{
    //dtor
}

XMLBase XMLBase::operator=(XMLRoot t)
{
    this->set_parent(t.get_parent());
    this->set_tag_name(t.get_tag_name());
    this->set_text(t.get_text());

    for(int i = 0; i<=t.length_attribut()-1 ;i++)
    {
        this->add_attribut(t.get_attribut(i));
    }
    for(int i = 0; i<=t.length_value()-1 ;i++)
    {
        this->add_value(t.get_value(i));
    }

    for(int i = 0; i<=t.length_child()-1 ;i++)
    {
        this->add_child(* t.get_child(i));
    }
    return *this;
}

void XMLBase::load_xml_file(string file)
{

	ifstream xml_file(file);

    char text = ' ';
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
        if(position==0x0)
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
                    XMLRoot * tmpxml;
                    tmpxml = new XMLRoot();
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
                string error = position->get_value(position->length_value()-1);
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
                if(value_balise)
                {
                    value_balise = false;
                    atribue_balise = true;
                    position->add_attribut("");
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
    }
    xml_file.close();
}

void XMLBase::save_xml_file(string file) //work in progress
{
    //write
    ofstream result_file;                       //open file
    result_file.open(file,ios::trunc);
    result_file << "<?xml version=\"1.0\"?>" << endl;

    XMLRoot * position = this;
    XMLRoot * last = nullptr;

    do{
        if(last!=nullptr)
        {
            if(last->length_child() != 0 || last->length_text_without_wihtespace() != 0)
            {
                result_file << "</" << last->get_tag_name() << '>' << endl;
            }
        }
        result_file << '<' << position->get_tag_name();

        for(int i=0 ; i<position->length_attribut() ; i++)
        {
            result_file << ' ' << position->get_attribut(i) << '=' << '\"' << position->get_value(i) << '\"';
        }

        if(position->length_child() == 0 && position->length_text_without_wihtespace() == 0)
        {
            result_file << "/>" << endl;
        }
        else
        {
            result_file << '>'<< endl;
        }
        if(position->length_text_without_wihtespace() != 0)
        {
            result_file << position->get_text();
        }
        if(position->length_child() != 0)
        {
            position = position->get_child(0);
        }
        else
        {
            bool loop = false;
            do{
                last = position;
                position = position->get_parent();
                if(position != nullptr)
                {
                    int i = 0;
                    while(position->get_child(i) != last)
                    {
                        i=i+1;
                    }
                    if(position->length_child()-1 != i)
                    {
                        position = position->get_child(i+1);
                    }
                    else
                    {
                        if(position->get_parent()!=nullptr)
                        {
                            loop = true;
                        }
                    }
                }
            }while(loop);
        }
    }while(position->get_parent() != nullptr);
    result_file << "</" << this->get_tag_name() << ">";
    result_file.close();
    return;
}
