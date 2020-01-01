#ifndef XMLBASE_H
#define XMLBASE_H

#include <XMLRoot.h>


class XMLBase : public XMLRoot
{
    public:
        XMLBase();
        ~XMLBase();
        void load_xml_file(string file);
        void save_xml_file(string file);

    protected:

    private:

};

#endif // XMLBASE_H
