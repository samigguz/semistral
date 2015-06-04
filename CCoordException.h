#ifndef CCOORDEXCEPTION_H
#define	CCOORDEXCEPTION_H

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class CCoordException
{
	public:
	    CCoordException (const string & a );
            friend ostream & operator << ( ostream &os, const CCoordException &exp )
            {
                os << "Coordinates entered incorrectly in object " << exp . Object<<'.'<< endl;
                return ( os );
            }
        private:
            string Object;
};

#endif	/* CCOORDEXCEPTION_H */
