#include "CCoordException.h"

CCoordException::CCoordException (const string & a ):Object(a){
cout << "Coordinates entered incorrectly in object " << Object<<'.'<< endl;
}

