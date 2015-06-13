/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:11
 */

#include <cstdlib>
#include <iostream>

//#include "devicePlot.h"
//#include "plotPoint.h"
//#include "Line.h"
//#include "painter.h"
#include "interpretator.h"
#include "CCoordException.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //ut<<argv[1]<<endl;
    string fileIn,fileOut;
    cout<<"Please enter the input filename."<<endl;
    while (getline(cin,fileIn))
    {
        if (fileIn=="") cout<<"Please enter the input filename."<<endl;
        else break;
    }
    cout<<"Please enter the output filename."<<endl;
    while (getline(cin,fileOut))
    {
        if (fileOut=="") cout<<"Please enter the output filename."<<endl;
        else break;
    }
    
    try
    {
    interpretator mainInterpretator(fileIn,fileOut);
    mainInterpretator.doIt();
    } catch  (CCoordException &error)
    {return 1;}

	return 0;
}


