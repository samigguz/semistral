/**
 * @file   CCoordException.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    CCoordException.cpp for implementation.
 */


#ifndef CCOORDEXCEPTION_H
#define	CCOORDEXCEPTION_H
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
/**
*   @brief Exception class.
*
*   It is thrown when in the input file was used the wrong data format.
*   It has only one private attribute CCoordException#Line.
*/

class CCoordException
{
	public:
            
	    CCoordException (const string & a,int number );
            /*
                string tmp;
    for (unsigned i=0;i<a.size();i++)
        if (a[i]==' ') continue;
        else tmp+=a[i];
    
 Line=tmp;
  cout << "Error in line "<<number<<" \""<<Line<<'\"' <<'.'<<endl;
            }*/
/**
*   @brief Friend function that clarifies use with ostream.
*   @return modified ostream
*/
           // friend ostream & operator << ( ostream &os, const CCoordException &exp );
            
        private:
            string Line;/**< Line with the wrong data format. */
};


#endif	/* CCOORDEXCEPTION_H */

