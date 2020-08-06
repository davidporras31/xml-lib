#include "XMLRoot.h"

XMLRoot::XMLRoot()
{
    //ctor
}

XMLRoot::~XMLRoot()
{
    //dtor
}
void XMLRoot::set_tag_name(string el)
{
    this->tag_name = el;
}
string XMLRoot::get_tag_name()
{
    return this->tag_name;
}

void XMLRoot::set_text(string tx)
{
    this->text = tx;
}
string XMLRoot::get_text()
{
    return this->text;
}
int XMLRoot::length_text()
{
    return this->text.length();
}
int XMLRoot::length_text_without_wihtespace()
{
    int nb = 0;
    for(unsigned int i=0;i<=this->text.length();i++)
    {
        if(this->text[i]!= '\t' && this->text[i]!= '\n' && this->text[i]!= '\r' && this->text[i]!= '\a' && this->text[i]!= '\b' && this->text[i]!= '\f' && this->text[i]!= '\v' && this->text[i]!= '\0'&& this->text[i]!= '\e')
        {
            nb = nb + 1;
        }
    }
    return nb;
}

void XMLRoot::add_attribut(string att)
{
    this->attribut.push_back(att);
}
void XMLRoot::set_attribut(string att,int id)
{
    this->attribut.at(id) = att;
}
string XMLRoot::get_attribut(int id)
{
    return this->attribut.at(id);
}
int XMLRoot::length_attribut()
{
    return this->attribut.size();
}

void XMLRoot::add_value(string val)
{
    this->value.push_back(val);
}
void XMLRoot::set_value(string val,int id)
{
    this->value.at(id) = val;
}
string XMLRoot::get_value(int id)
{
    return this->value.at(id);
}
int XMLRoot::length_value()
{
    return this->value.size();
}

XMLRoot * XMLRoot::get_parent()
{
    return this->parent;
}

void XMLRoot::set_parent(XMLRoot * new_parent)
{
    this->parent = new_parent;
}
void XMLRoot::add_child(XMLRoot new_child)
{
    this->child.push_back(new_child);
}
void XMLRoot::set_child(XMLRoot new_child,int id)
{
    this->child.at(id) = new_child;
}
XMLRoot * XMLRoot::get_child(int id)
{
    return &(this->child.at(id));
}
XMLRoot * XMLRoot::get_child()
{
    return &(this->child.back());
}
int XMLRoot::length_child()
{
    return this->child.size();
}
