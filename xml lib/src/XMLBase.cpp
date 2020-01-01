#include <stdio.h>
#include <string.h>

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
    bool balise = false;
    bool nom_balise = false;
    bool atribue_balise = false;
    bool value_balise = false;

    while(fread(&text,1,1,load_xml) ==1)                //lecture map
    {
        //condition
        if((text == '<') && (!balise))
        {
            balise = true;
            nom_balise = true;
        }
        else
        {
            if(balise)
            {
                if(text!=' ')
                {
                    if(nom_balise)
                    {
                        this->set_element((this->get_element())+text);
                    }
                    if(atribue_balise)
                    {
                        this->set_attribut(this->get_attribut(this->length_attribut())+text,this->length_attribut());
                    }
                    if(value_balise)
                    {
                        this->set_value(this->get_value(this->length_value())+text,this->length_value());
                    }
                }
                if(text == ' ' && text != '>')
                {
                    if(nom_balise)
                    {
                        nom_balise = false;
                        atribue_balise = true;
                        this->add_attribut("");
                    }
                    if(atribue_balise)
                    {
                        atribue_balise = false;
                        value_balise = true;
                        this->add_value("");
                    }
                    if(value_balise)
                    {
                        value_balise = false;
                        atribue_balise = true;
                        this->add_attribut("");
                    }
                }
                if(text == '>')
                {

                }
            }
        }
    }
    fclose(load_xml);





}
void XMLBase::save_xml_file(string file)
{

}
