#include "XMLRoot.h"

XMLRoot::XMLRoot()
{
    //ctor
}

XMLRoot::~XMLRoot()
{
    //dtor
}
void XMLRoot::set_element(string el)
{
    this->element = el;
}
string XMLRoot::get_element()
{
    return this->element;
}

void XMLRoot::set_text(string tx)
{
    this->text = tx;
}
string XMLRoot::get_text()
{
    return this->text;
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
