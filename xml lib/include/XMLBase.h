//********************************************************
// author D PORRAS
// date : 31/11/2019
// file: XMLBase.h
// base class for modify XML file
//********************************************************
#ifndef XMLBASE_H
#define XMLBASE_H

#include <XMLRoot.h>


class XMLBase : public XMLRoot
{
    public:
        XMLBase();
        XMLBase(string file);
        XMLBase(string file , int nb);
        ~XMLBase();
        /** \brief This is a method for load XML file from path.
         *
         * \param	file The path of the file to load.
         *
         * This is a method for load XML file from a path specify in the file parameter.
        */
        void load_xml_file(string file);
        void save_xml_file(string file);
        void set_space_number(int nb);
        int get_space_number();
    protected:

    private:
        int nb_space_for_tab;
};

#endif // XMLBASE_H
