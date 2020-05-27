#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "XMLBase.h"
#include "XMLUtility.h"

using namespace std;

int main()
{
    cout << "start" << endl;


    XMLBase worldmap;
    string chemain = "teste.xml";
    cout << "ouverture teste.xml" << endl;
    worldmap.load_xml_file(chemain);


    cout << endl << "Length text without wihtespace : " << worldmap.get_root(0)->length_text_without_wihtespace() << endl;
    cout << "text :" << endl << worldmap.get_text() << endl;


    cout << endl << "Length text without wihtespace : " << worldmap.length_text_without_wihtespace() << endl;


    cout << "query : test\tplace : " << Search_by_atribut(worldmap.get_root(0),"test") << endl;
    vector<XMLRoot *> return_query;
    if(Search_by_element(&worldmap,return_query,"cube"))
    {
        cout << "query : " <<return_query.at(1)->get_element()<< "\t" << "nb return : " << return_query.size() << endl;
    }


    worldmap.save_xml_file("save.xml");


    return 0;
}
