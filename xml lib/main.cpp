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
    return 0;
}
