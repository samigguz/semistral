/* 
 * File:   CCoordException.h
 * Author: Гузель
 *
 * Created on 4 июня 2015 г., 20:47
 */

#ifndef CCOORDEXCEPTION_H
#define	CCOORDEXCEPTION_H

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class CCoordException
{
	public:
	    CCoordException (const string & a,int );
            friend ostream & operator << ( ostream &os, const CCoordException &exp )
            {
                os << "Coordinates entered incorrectly in object " << exp . Object<<'.'<< endl;
                return ( os );
            }
        private:
            string Object;
};


#endif	/* CCOORDEXCEPTION_H */

