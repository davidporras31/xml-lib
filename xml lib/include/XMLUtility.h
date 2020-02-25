#ifndef XMLUTILITY_H_INCLUDED
#define XMLUTILITY_H_INCLUDED

#include <vector>

#include "XMLBase.h"
#include "XMLRoot.h"

using namespace std;

void Search_by_atribut(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword);
void Search_by_value(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword);
void Search_by_element(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword);

#endif // XMLUTILITY_H_INCLUDED
