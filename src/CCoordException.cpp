/**
 * @file   CCoordException.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    CCoordException.h for declaration.
 */
#include "CCoordException.h"

#include <iostream>
#include <string>
using namespace std;
CCoordException::CCoordException (const string & a,int number ){

    string tmp;
    for (unsigned i=0;i<a.size();i++)
        if (a[i]==' ') continue;
        else tmp+=a[i];
    
 Line=tmp;
cout << "Error in line "<<number<<" \""<<Line<<'\"' <<'.'<<endl;

}
/*ostream & operator << ( ostream &os, const CCoordException &exp )
{
    
    os << "Error in line "<<" \""<<exp.Line<<'\"' <<'.'<<endl;
    return os;
}*/

