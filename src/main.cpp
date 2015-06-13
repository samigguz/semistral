/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:11
 */

#include <cstdlib>
#include <iostream>
#include "interpretator.h"
#include "CCoordException.h"
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
    
    try
    {
    string fileIn,fileOut;
    if (argc<2) throw CCoordException("Missing the input file.");
    
    if (strcmp(argv[1],"--help")==0 || strcmp(argv[1],"help")==0)
    {
       
       cout<<"Usage: ./samigguz input_file"<<endl;
       cout<<"       ./samigguz input_file [output_file]"<<endl;
       return 0;
    }
    
    fileIn=argv[1];

    if (argc==3) 
    {
      fileOut=argv[2];
    }
    else 
    {
    fileOut+=fileIn;
    fileOut+=".out";
    }
   //cout<<fileIn<<" "<<fileOut<<endl;
    /*cout<<"Please enter the input filename."<<endl;
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
    }*/
    
    
    interpretator mainInterpretator(fileIn,fileOut);
    mainInterpretator.doIt();
    } catch  (CCoordException &error)
    {return 1;}

	return 0;
}


