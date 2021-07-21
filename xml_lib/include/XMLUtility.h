//********************************************************
// author David PORRAS
// date : 31/11/2019
// file: XMLUtility.h
// all utility function
//********************************************************
#ifndef XMLUTILITY_H_INCLUDED
#define XMLUTILITY_H_INCLUDED

#include <vector>
#include <string>

#include "XMLRoot.h"

using namespace std;
/** \brief This is a function for search atribut name position.
 *
 * \param	search_XML one XMLRoot.
 * \param	keyword the searched name of atribut.
 *
 * \return  the atribut position. -1 if keyword don't existe.
 *
 * This is a function search the same atribut name of keyword and return place of atribut in search_XML.
*/
size_t Search_by_atribut(XMLRoot * search_XML,string keyword);
/** \brief This is a function search tag by name
 *
 * \param	search_XML one XMLRoot
 * \param	return_XML result of query
 * \param	keyword the searched name of markup
 *
 * \return  false if don't find keyword
 *
 * This is a function search the same tag name of keyword and return all XMLRoot finded in return_XML
*/
bool Search_by_element(XMLRoot * search_XML,vector<XMLRoot *> &return_XML,string keyword);

#endif // XMLUTILITY_H_INCLUDED
