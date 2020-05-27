#ifndef XMLUTILITY_H_INCLUDED
#define XMLUTILITY_H_INCLUDED

#include <vector>
#include <string>

#include "XMLBase.h"
#include "XMLRoot.h"

using namespace std;

int Search_by_atribut(XMLRoot * search_XML,string keyword);
int Search_by_value(XMLRoot * search_XML,string keyword);
bool Search_by_element(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword);

#endif // XMLUTILITY_H_INCLUDED
