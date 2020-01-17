#include <stdio.h>
#include <string.h>
#include <iostream>

#include "XMLBase.h"

using namespace std;

XMLBase::XMLBase()
    :XMLRoot()
{
    //ctor
}

XMLBase::~XMLBase()
{
    //dtor
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
    while(text != '\n')                                 //on passe un linge
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

    while(fread(&text,1,1,load_xml) ==1)                //lecture fichier + mapage xml
    {
        cout<<text;
        //condition
        if((text == '<') && (!balise))
        {
            balise = true;
            nom_balise = true;
            if(racine)
            {
                racine = false;
                position->set_parent(NULL);
            }
            else
            {
                XMLRoot * tmpxml = new XMLRoot();
                position->add_root(*tmpxml);
                (position->get_root(position->length_root()-1))->set_parent(position);
                position = tmpxml;
            }
        }
        else
        {
            if(text == 0x47)
            {
                slash = true;
            }
            if(balise)
            {
                if(text!=' ' && text != '>')
                {
                    if(nom_balise)
                    {
                        position->set_element((position->get_element())+text);
                    }
                    if(atribue_balise)
                    {
                        position->set_attribut(position->get_attribut(position->length_attribut()-1)+text,position->length_attribut());
                    }
                    if(value_balise)
                    {
                        position->set_value(position->get_value(position->length_value()-1)+text,position->length_value());
                    }
                }
                if(text == ' ' && text != '>')
                {
                    if(nom_balise)
                    {
                        nom_balise = false;
                        atribue_balise = true;
                        position->add_attribut("");
                    }
                    if(atribue_balise)
                    {
                        atribue_balise = false;
                        value_balise = true;
                        position->add_value("");
                    }
                    if(value_balise)
                    {
                        value_balise = false;
                        atribue_balise = true;
                        position->add_attribut("");
                    }
                }
                if(text == '>')
                {
                    balise = false;
                    if(slash)
                    {
                        position = position->get_parent();
                    }
                }
            }
            else
            {
                if((text != 0x09)&&(text != '\n')&&(text != '\r'))
                {
                    position->set_text(position->get_text()+text);
                }
            }
        }
    }
    fclose(load_xml);





}
void XMLBase::save_xml_file(string file)
{

}