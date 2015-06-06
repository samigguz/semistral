#include "CCoordException.h"

CCoordException::CCoordException (const string & a,int number ):Object(a){
//cout << "Coordinates entered incorrectly in object " << Object<<" in line "<<number<<'.'<<endl;

cout << "Error in line "<<number<<" \""<<Object<<'\"' <<'.'<<endl;

}

