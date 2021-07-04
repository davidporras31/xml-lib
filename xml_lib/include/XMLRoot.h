//********************************************************
// author David PORRAS
// date : 31/11/2019
// file: XMLRoot.h
// base class for modify and construct XML file
//********************************************************
#ifndef XMLROOT_H
#define XMLROOT_H

#include <string>
#include <vector>
#include <functional>

using namespace std;

class XMLRoot
{
    public:
        XMLRoot();
        ~XMLRoot();
        /** \brief This is a function for modify tag name
		 *
		 * \param	el, the new tag name
		 *
		 * This is a function for modify tag name
		*/
        void set_tag_name(string el);
        /** \brief This is a function for geting tag name
		 *
		 * \return	the tag name
		 *
		 * This is a function for geting tag name
		*/
        string get_tag_name();

        /** \brief This is a function for modify text in balise
		 *
		 * \param	tx, the new text
		 *
		 * This is a function for modify text in balise
		*/
        void set_text(string tx);
        /** \brief This is a function for geting text in balise
		 *
		 * \return	the text
		 *
		 * This is a function for geting text in balise
		*/
        string get_text();
        /** \brief This is a function for geting length of text in balise
		 *
		 * \return	the length of text
		 *
		 * This is a function for geting text length of in balise
		*/
        size_t length_text();
        /** \brief This is a function for geting length of text in balise without wihtespace
		 *
		 * \return	the length of text without wihtespace
		 *
		 * This is a function for geting text length of in balise without wihtespace
		*/
        size_t length_text_without_wihtespace();


        /** \brief This is a function for add attribut name in balise
		 *
		 * \param	att, the new attribut name
		 *
		 * This is a function for add attribut name in balise at last
		*/
        void add_attribut(string att);
        /** \brief This is a function for modify attribut name in balise
		 *
		 * \param	att, the new attribut name
		 * \param	id, the place of attribut
		 *
		 * This is a function for modify attribut name in balise
		*/
        void set_attribut(string att,size_t id);
        /** \brief This is a function for geting attribut name in balise
		 *
		 * \param	id, the place of attribut
		 *
		 * \return	the attribut name
		 *
		 * This is a function for geting attribut name in balise
		*/
        string get_attribut(size_t id);
        /** \brief This is a function for geting length of attribut name in balise
		 *
		 * \return	the length of attribut name
		 *
		 * This is a function for geting attribut name length of in balise
		*/
        size_t length_attribut();

        /** \brief This is a function for add attribut value in balise
		 *
		 * \param	att, the new attribut value
		 *
		 * This is a function for add attribut value in balise at last
		*/
        void add_value(string val);
        /** \brief This is a function for modify attribut value in balise
		 *
		 * \param	val, the new attribut value
		 * \param	id, the place of attribut
		 *
		 * This is a function for modify attribut value in balise
		*/
        void set_value(string val,size_t id);
        /** \brief This is a function for geting attribut value in balise
		 *
		 * \param	id, the place of attribut
		 *
		 * \return	the attribut value
		 *
		 * This is a function for geting attribut value in balise
		*/
        string get_value(size_t id);
        /** \brief This is a function for geting length of attribut value in balise
		 *
		 * \return	the length of attribut value
		 *
		 * This is a function for geting attribut value length of in balise
		*/
        size_t length_value();

        /** \brief This is a function for geting parent balise
		 *
		 * \return	the parent balise pointer
		 *
		 * This is a function for geting parent balise
		*/
        XMLRoot * get_parent();
        /** \brief This is a function for modify parent balise
		 *
		 * \param	new_parent, the new parent pointer
		 *
		 * This is a function for modify parent balise
		*/
        void set_parent(XMLRoot * new_parent);

        /** \brief This is a function for add child
		 *
		 * \param	new_child, the new child
		 *
		 * This is a function for add child at last
		*/
        void add_child(XMLRoot new_child);
        /** \brief This is a function for replace child
		 *
		 * \param	new_child, the new child
		 * \param	id, the place of child
		 *
		 * This is a function for replace child
		*/
        void set_child(XMLRoot new_child,size_t id);
        /** \brief This is a function for geting child
		 *
		 * \param	id, the place of child
		 *
		 * \return	the child pointer
		 *
		 * This is a function for geting child
		*/
        XMLRoot * get_child(size_t id);
        /** \brief This is a function for geting last child
		 *
		 * \return	the child pointer
		 *
		 * This is a function for geting last child
		*/
        XMLRoot * get_child();
        /** \brief This is a function for geting number of child
		 *
		 * \return	the number of child
		 *
		 * This is a function for geting number of child
		*/
        size_t length_child();
        void for_each(function<void(XMLRoot *,void *)> prefunc, void * args = NULL);
        void for_each(function<void(XMLRoot *,void *)> prefunc, function<void(XMLRoot *,void *)> postfunc, void * args = NULL);
    protected:

    private:
        vector<XMLRoot> child;
        XMLRoot * parent;
        string tag_name;
        string text;
        vector<string> attribut;
        vector<string> value;
};

#endif // XMLROOT_H
