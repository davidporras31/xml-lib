//********************************************************
// author David PORRAS
// date : 31/11/2019
// file: XMLBase.h
// base class for save and load XML file
//********************************************************
#ifndef XMLBASE_H
#define XMLBASE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>

#ifdef Use_Watchdogs
	#include <thread>
  #include <chrono>
  #include <exception>
#endif

#include "XMLRoot.h"

class XMLBase : public XMLRoot
{
    public:
        XMLBase();
        XMLBase(std::string file);
        ~XMLBase();
        /** \brief This is a method for load XML file from path.
         *
         * \param	file The path of the file to load.
         *
         * This is a method for load XML file from a path specify in the file parameter.
        */
        void load_xml_file(std::string file);
        /** \brief This is a method for save XML file from path.
         *
         * \param	file The path of the return file.
         *
         * This is a method for save XML file in a path specify in the file parameter.
        */
        void save_xml_file(std::string file);

		#ifdef Use_Watchdogs
            /** \brief Change the timeout on load and save watchdogs.
             *
             * \param	timeout The the value in millisecond.
             *
             * This is a method for change the timeout on load and save watchdogs.
            */
			void set_timeout(unsigned int timeout);
		#endif

    protected:

    private:
        static void presave(XMLRoot* root,void * args);
        static void postsave(XMLRoot* root,void * args);
        static void precleanup(XMLRoot* root,void * args);
        std::ofstream output_file;
		#ifdef Use_Watchdogs
            bool job_finich;
			unsigned int timeout;
			unsigned int curent_timeout;
			void Watchdogs_load_xml_file(std::string file);
			void Watchdogs_save_xml_file(std::string file);
		#endif
};
#ifdef Use_Watchdogs
class XMLBase_load_Exception: public std::exception
{
    virtual const char* what() const throw()
  {
    return "timeout on parsing XML file";
  }
};
class XMLBase_save_Exception: public std::exception
{
    virtual const char* what() const throw()
  {
    return "timeout on writing XML file";
  }
};
#endif // Use_Watchdogs

#endif // XMLBASE_H
