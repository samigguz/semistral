#include "CCoordException.h"

CCoordException::CCoordException (const string & a,int number ){

    string tmp;
    for (unsigned i=0;i<a.size();i++)
        if (a[i]==' ') continue;
        else tmp+=a[i];
    
 Line=tmp;
cout << "Error in line "<<number<<" \""<<Line<<'\"' <<'.'<<endl;

}

