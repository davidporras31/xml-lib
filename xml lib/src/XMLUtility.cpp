
#include "XMLUtility.h"

int Search_by_atribut(XMLRoot * search_XML,string keyword)
{
    for(int i = 1; i <= search_XML->length_attribut(); i++)
    {
        if(search_XML->get_attribut(i-1) == keyword)
        {
            return i;
        }
    }
    return 0;
}
int Search_by_value(XMLRoot * search_XML,string keyword)
{
    for(int i = 1; i <= search_XML->length_root(); i++)
    {
        if(search_XML->get_value(i-1) == keyword)
        {
            return i;
        }
    }
    return 0;
}
bool Search_by_element(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword)
{
    bool return_value = false;
    for(int i = 1; i <= search_XML->length_root(); i++)
    {
        if(search_XML->get_root(i-1)->get_element() == keyword)
        {
            return_XML.push_back(search_XML->get_root(i-1));
            return_value = true;
        }
    }
    return return_value;
}
