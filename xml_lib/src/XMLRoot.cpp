#include "../include/XMLRoot.h"

XMLRoot::XMLRoot()
{
    //ctor
    this->parent = nullptr;
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
size_t XMLRoot::length_text()
{
    return this->text.length();
}
size_t XMLRoot::length_text_without_wihtespace()
{
    size_t nb = 0;
    for(size_t i=0;i<=this->text.length();i++)
    {
        if(this->text[i]!= '\t' && this->text[i]!= '\n' && this->text[i]!= '\r' && this->text[i]!= '\a'
           && this->text[i]!= '\b' && this->text[i]!= '\f' && this->text[i]!= '\v' && this->text[i]!= '\0'
           && this->text[i]!= '\e' && this->text[i]!= ' ')
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
void XMLRoot::set_attribut(string att,size_t id)
{
    this->attribut.at(id) = att;
}
string XMLRoot::get_attribut(size_t id)
{
    return this->attribut.at(id);
}
size_t XMLRoot::length_attribut()
{
    return this->attribut.size();
}

void XMLRoot::add_value(string val)
{
    this->value.push_back(val);
}
void XMLRoot::set_value(string val,size_t id)
{
    this->value.at(id) = val;
}
string XMLRoot::get_value(size_t id)
{
    return this->value.at(id);
}
size_t XMLRoot::length_value()
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
void XMLRoot::set_child(XMLRoot new_child,size_t id)
{
    this->child.at(id) = new_child;
}
XMLRoot * XMLRoot::get_child(size_t id)
{
    return &(this->child.at(id));
}
XMLRoot * XMLRoot::get_child()
{
    return &(this->child.back());
}
size_t XMLRoot::length_child()
{
    return this->child.size();
}
void XMLRoot::for_each(function<void(XMLRoot *,void *)> prefunc, void * args)
{
    prefunc(this, args);
    for(size_t i=0; i<this->length_child(); i++)
    {
        this->get_child(i)->for_each(prefunc, args);
    }
}
void XMLRoot::for_each(function<void(XMLRoot *,void *)> prefunc, function<void(XMLRoot *,void *)> postfunc, void * args)
{
    prefunc(this, args);
    for(size_t i=0; i<this->length_child(); i++)
    {
        this->get_child(i)->for_each(prefunc, postfunc, args);
    }
    postfunc(this, args);
}
