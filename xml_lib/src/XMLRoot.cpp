#include "../include/XMLRoot.h"

XMLRoot::XMLRoot()
{
    //ctor
    this->set_parent(NULL);
}

XMLRoot::XMLRoot(XMLRoot* t)
{
    this->set_tag_name( t->get_tag_name() );
    this->set_text( t->get_text() );
    this->set_parent(NULL);

    for(size_t y=0; y < t->length_attribut(); y++)
    {
        this->add_attribut(t->get_attribut(y));
    }
    for(size_t y=0; y < t->length_value(); y++)
    {
        this->add_value(t->get_value(y));
    }
    this->for_each(this->precopy,(void*)t);
}

XMLRoot::~XMLRoot()
{
    //dtor
}
void XMLRoot::set_tag_name(std::string el)
{
    this->tag_name = el;
}
std::string XMLRoot::get_tag_name()
{
    return this->tag_name;
}

void XMLRoot::set_text(std::string tx)
{
    this->text = tx;
}
std::string XMLRoot::get_text()
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
        if(!XMLRoot::is_wihtespace(this->text[i]))
        {
            nb = nb + 1;
        }
    }
    return nb;
}

void XMLRoot::add_attribut(std::string att)
{
    this->attribut.push_back(att);
}
void XMLRoot::set_attribut(std::string att,size_t id)
{
    this->attribut.at(id) = att;
}
std::string XMLRoot::get_attribut(size_t id)
{
    return this->attribut.at(id);
}
size_t XMLRoot::length_attribut()
{
    return this->attribut.size();
}

void XMLRoot::add_value(std::string val)
{
    this->value.push_back(val);
}
void XMLRoot::set_value(std::string val,size_t id)
{
    this->value.at(id) = val;
}
std::string XMLRoot::get_value(size_t id)
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
void XMLRoot::for_each(std::function<void(XMLRoot *,void *)> prefunc, void * args)
{
    prefunc(this, args);
    for(size_t i=0; i<this->length_child(); i++)
    {
        this->get_child(i)->for_each(prefunc, args);
    }
}
void XMLRoot::for_each(std::function<void(XMLRoot *,void *)> prefunc, std::function<void(XMLRoot *,void *)> postfunc, void * args)
{
    prefunc(this, args);
    for(size_t i=0; i<this->length_child(); i++)
    {
        this->get_child(i)->for_each(prefunc, postfunc, args);
    }
    postfunc(this, args);
}

bool XMLRoot::is_wihtespace(char text)
{
    #ifndef _MSC_BUILD
    bool test = text== '\a' || text== '\b' || text== '\t' || text== '\n'
			|| text== '\v' || text== '\f' || text== '\r' || text== '\0'
			|| text== '\e' || text== ' ';
    #else
    bool test = text== '\a' || text== '\b' || text== '\t' || text== '\n'
			|| text== '\v' || text== '\f' || text== '\r' || text== '\0'
			|| text== ' ';
    #endif
    return test;
}

void XMLRoot::precopy(XMLRoot* root,void * args)
{
    XMLRoot * to_get = (XMLRoot*)args;
    for(size_t i=0; i < to_get->length_child(); i++)
    {
        XMLRoot tmp;
        tmp.set_tag_name( to_get->get_child(i)->get_tag_name() );
        tmp.set_text( to_get->get_child(i)->get_text() );
        tmp.set_parent(root);

        for(size_t y=0; y < to_get->get_child(i)->length_attribut(); y++)
        {
            tmp.add_attribut(to_get->get_child(i)->get_attribut(y));
        }
        for(size_t y=0; y < to_get->get_child(i)->length_value(); y++)
        {
            tmp.add_value(to_get->get_child(i)->get_value(y));
        }

        root->add_child(tmp);
    }
}
