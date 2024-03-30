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

class XMLRoot
{
    public:
        XMLRoot();
        XMLRoot(XMLRoot* t);
        ~XMLRoot();
        /** \brief This is a function for modify tag name
		 *
		 * \param	el, the new tag name
		 *
		 * This is a function for modify tag name
		*/
        void set_tag_name(std::string el);
        /** \brief This is a function for geting tag name
		 *
		 * \return	the tag name
		 *
		 * This is a function for geting tag name
		*/
        std::string get_tag_name();

        /** \brief This is a function for modify text in balise
		 *
		 * \param	tx, the new text
		 *
		 * This is a function for modify text in balise
		*/
        void set_text(std::string tx);
        /** \brief This is a function for geting text in balise
		 *
		 * \return	the text
		 *
		 * This is a function for geting text in balise
		*/
        std::string get_text();
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
        void add_attribut(std::string att);
        /** \brief This is a function for modify attribut name in balise
		 *
		 * \param	att, the new attribut name
		 * \param	id, the place of attribut
		 *
		 * This is a function for modify attribut name in balise
		*/
        void set_attribut(std::string att,size_t id);
        /** \brief This is a function for geting attribut name in balise
		 *
		 * \param	id, the place of attribut
		 *
		 * \return	the attribut name
		 *
		 * This is a function for geting attribut name in balise
		*/
        std::string get_attribut(size_t id);
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
        void add_value(std::string val);
        /** \brief This is a function for modify attribut value in balise
		 *
		 * \param	val, the new attribut value
		 * \param	id, the place of attribut
		 *
		 * This is a function for modify attribut value in balise
		*/
        void set_value(std::string val,size_t id);
        /** \brief This is a function for geting attribut value in balise
		 *
		 * \param	id, the place of attribut
		 *
		 * \return	the attribut value
		 *
		 * This is a function for geting attribut value in balise
		*/
        std::string get_value(size_t id);
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
        /** \brief This is a function for invoke function on all child of the current instance and on the current instance
		 *
		 * \param	prefunc, the function to invoke, the first parameter is the current instance executed, the final parameter is the data of args parameter
		 * \param	args, one common parameter to use on the loop
		 *
		 * This is a function for invoke function on all child of the current instance and on the current instance
		*/
        void for_each(std::function<void(XMLRoot *,void *)> prefunc, void * args = NULL);
        /** \brief This is a function for invoke function on all child of the current instance and on the current instance
		 *
		 * \param	prefunc, the function to invoke, the first parameter is the current instance executed, the final parameter is the data of args parameter
		 * \param	postfunc, the function to invoke after invoke all child, the first parameter is the current instance executed, the final parameter is the data of args parameter
		 * \param	args, one common parameter to use on the loop
		 *
		 * This is a function for invoke function on all child of the current instance and on the current instance
		*/
        void for_each(std::function<void(XMLRoot *,void *)> prefunc, std::function<void(XMLRoot *,void *)> postfunc, void * args = NULL);
        /** \brief This is a function for finding if the char is wihtespace
		 *
		 * \param	text, the char
		 *
		 * \return	true if text is wihtespace
		 *
		 * This is a function for finding if the char is wihtespace
		*/
        static bool is_wihtespace(char text);
    protected:

    private:
        static void precopy(XMLRoot* root,void * args);

        std::vector<XMLRoot> child;
        XMLRoot * parent;
        std::string tag_name;
        std::string text;
        std::vector<std::string> attribut;
        std::vector<std::string> value;

};

#endif // XMLROOT_H
