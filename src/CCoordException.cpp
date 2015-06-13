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
CCoordException::CCoordException (const string & a)
{
    cout<<a<<endl;
}
CCoordException::CCoordException (const string & a,int number ){

    string tmp="";
    for (unsigned i=0;i<a.size()-1;i++)
        if (a[i]==' ' || a[i]=='\n') continue;
        else tmp+=a[i];
    
 Line=tmp;
 cout << "Line:"<<number<<": error : bad syntax in \"" <<Line<<"\"."<<endl;

}

CCoordException::CCoordException (const string & a,int number, const string & b ){

    string tmp;
    for (unsigned i=0;i<a.size()-1;i++)
        if (a[i]==' ') continue;
        else tmp+=a[i];
    
 Line=tmp;
 cout << "Line:"<<number<<": error : "<<b<<" in \"" <<Line<<"\"."<<endl;

}


