
#include "../include/XMLUtility.h"

size_t Search_by_atribut(XMLRoot * search_XML,string keyword)
{
    for(size_t i = 0; i < search_XML->length_attribut(); i++)
    {
        if(search_XML->get_attribut(i) == keyword)
        {
            return i;
        }
    }
    return -1;
}
bool Search_by_element(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword)
{
    bool return_value = false;
    for(size_t i = 0; i < search_XML->length_child(); i++)
    {
        if(search_XML->get_child(i)->get_tag_name() == keyword)
        {
            return_XML.push_back(search_XML->get_child(i));
            return_value = true;
        }
    }
    return return_value;
}
