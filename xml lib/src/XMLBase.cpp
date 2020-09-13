#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "XMLBase.h"

#ifdef DEBUG
    #define print(text) cout << text ;
#else
    #define print(text) //
#endif // DEBUG

using namespace std;

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
    int n = file.length();                      //convert string to char
    char char_array[n + 1];
    strcpy(char_array, file.c_str());

    FILE* load_xml = NULL;                      //ouverture fichier
    load_xml = fopen(char_array,"r");
    rewind(load_xml);

    char text;
    while(text != '\n')                                 //on passe une linge
    {
        fread(&text,1,1,load_xml);
    }

    //var de lecture
    XMLRoot * position = this;

    bool balise = false;
    bool nom_balise = false;
    bool atribue_balise = false;
    bool value_balise = false;
    bool racine = true;
    bool slash = false;
    bool chevron_open = false;

    while(fread(&text,1,1,load_xml) ==1)                //lecture fichier + mapage xml
    {
        returnRuntime:
        if(position==0x0)
        {
            break;
        }
        print(text)
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
                    fread(&text,1,1,load_xml);
                    print(text)
                }
                fread(&text,1,1,load_xml);
                goto returnRuntime;
            }
            else
            {
                if(racine)
                {
                    racine = false;
                    position->set_parent(NULL);
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
            if (slash)
            {
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
                position->set_text(position->get_text()+text);  //a ajouté gestion tab avec nb_space_for_tab
            }
        }
    }
    fclose(load_xml);
}
void XMLBase::save_xml_file(string file) //work in progress
{
    int n = file.length();                      //convert string to char
    char char_array[n + 1];
    strcpy(char_array, file.c_str());

    FILE* save_xml = NULL;                      //ouverture fichier
    save_xml = fopen(char_array,"w");
    rewind(save_xml);

    //création d'un fichier

    XMLRoot * position = this;
    string tmp;


    //char text;
    char debut[22] = "<?xml version=\"1.0\"?>";
    fwrite(debut , sizeof(char), sizeof(debut)-1, save_xml);
    char buffer = '\n';
    fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);

    while(position != NULL)
    {
        buffer = '<';
        fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);

        tmp = position->get_tag_name();
        for(unsigned int i = 0 ; i < tmp.length(); i++)
        {
            fwrite(&tmp.at(i) , sizeof(char), sizeof(char), save_xml);
        }

        for(int i=0 ; i<position->length_attribut() ; i++)
        {
            buffer = ' ';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
            tmp = position->get_attribut(i);
            for(unsigned int t = 0 ; t < tmp.length(); t++)
            {
                fwrite(&tmp.at(t) , sizeof(char), sizeof(char), save_xml);
            }
            buffer = '=';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
            buffer = '\"';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
            tmp = position->get_value(i);
            for(unsigned int t = 0 ; t < tmp.length(); t++)
            {
                fwrite(&tmp.at(t) , sizeof(char), sizeof(char), save_xml);
            }
            buffer = '\"';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
        }

        if(position->length_child() == 0 && position->length_text_without_wihtespace() == 0)
        {
            buffer = '/';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
            buffer = '>';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
            buffer = '\n';
            fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
        }
        else
        {
            if(position->length_child()!=0)
            {
                position = position->get_child(this->save_helper(position->get_parent(),position)+1);
            }
            else
            {
                XMLRoot * tmp_root = NULL;
                int back_test = 0;
                while(position != tmp_root)
                {
                    back_test = back_test+1;
                    tmp_root = position->get_parent()->get_child(back_test);
                }
                position = position->get_parent()->get_child(back_test+1);
            }
        }

        buffer = '>';
        fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
        buffer = '\n';
        fwrite(&buffer , sizeof(char), sizeof(buffer), save_xml);
    }

    fclose(save_xml);
}



int XMLBase::save_helper(XMLRoot * the_parent , XMLRoot * child)
{
    int i = 1;
    print(i)
    while(the_parent->get_child(i) != child)
    {
        i = i+1;
        print(i)
    }
    print(i)
    return i;
}
