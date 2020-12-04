#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "XMLBase.h"
#include "XMLRoot.h"
#include "XMLUtility.h"

using namespace std;

int main()
{
    cout << "start" << endl;


    XMLBase worldmap;
    string chemain = "teste.xml";
    cout << "ouverture de "<< chemain << endl;
    worldmap.load_xml_file(chemain);

    /*
    cout << endl << "Length text without wihtespace : " << worldmap.get_child(0)->length_text_without_wihtespace() << endl;
    cout << "text :" << endl << worldmap.get_text() << endl;


    cout << endl << "Length text without wihtespace : " << worldmap.length_text_without_wihtespace() << endl;
    */

    //cout << "query : test\tplace : " << Search_by_atribut(worldmap.get_root(0),"test") << endl;
    vector<XMLRoot *> return_query;
    if(Search_by_element(&worldmap,return_query,"cube"))
    {
        cout << endl << "query : " <<return_query.at(1)->get_tag_name()<< "\t" << "nb return : " << return_query.size() << endl;
    }
    cout << "convert XMLRoot in XMLBase" << endl;
    XMLRoot parent;		//make parent
	parent.set_tag_name("parent");	//give it the name "parent"

	XMLRoot * tmp_root = new XMLRoot; //create tmp_root for contain pointer on new root and create new root
	tmp_root->set_tag_name("cube");	//change the name of root
	tmp_root->add_attribut("color");	//add a new attribut name "color"
	tmp_root->add_value("red");	//add a new attribut value "red"

	parent.add_child(*tmp_root);

    XMLBase new_file;

    new_file = parent;
    cout << "data access test :" << new_file.get_child()->get_tag_name() << endl;


    worldmap.save_xml_file("save.xml");


    return 0;
}
