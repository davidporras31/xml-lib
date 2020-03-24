#include <iostream>
#include <stdio.h>
#include <string>

#include "XMLBase.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    XMLBase worldmap;
    string chemain = "teste.xml";
    worldmap.load_xml_file(chemain);
    cout << worldmap.get_root(0)->length_text_without_wihtespace() << endl << "text :";
    cout << worldmap.get_text();
    cout <<endl<< worldmap.length_text_without_wihtespace();
    worldmap.save_xml_file("save.xml");
    return 0;
}
