/**
 * @file   deviceColorPlot.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    deviceColorPlot.h for declaration.
 */

#include "deviceColorPlot.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

deviceColorPlot::deviceColorPlot():devicePlot() {
     this->default_console = "\033[0m";
     Color=0;
     
}

deviceColorPlot::deviceColorPlot(int X,int Y):devicePlot(X,Y){
    this->default_console = "\033[0m";
    colors = new int[maxX * maxY];
    for (int i=0; i< maxX * maxY; i++)
    colors[i]=0;  
    Color=0;
}

void deviceColorPlot::print(ofstream & fout)
{
    
    stringstream ss;
    string col[8];
    for (int i=0;i<8;i++) {
        ss.clear();
        ss <<"\33[0;" <<30 + i << "m";
        col[i]=ss.str();
    }
    
    
	for(int i=0;i<maxY;i++)
	  {
	  for (int j=0;j<maxX;j++)
	  {
                int c = colors[i * maxX+j];
                if ( c >=0 && c < 8)  cout<< col[c];
	  	cout<<array[i][j];
	  }
	  cout<<endl;
	 }
     	
   fout << this->default_console << endl;
   cout << this->default_console << endl;	
}

void deviceColorPlot::putPixel(int X, int Y, char znak) {
       		  if (  X >=0 && X < maxX && Y>=0 && Y<maxY )
		  { 
		    array[Y][X]=znak;
                    colors[Y * maxX + X] = Color;
		  }  
    }

 void deviceColorPlot::putPixel(int X, int Y) { this->putPixel(X,Y,Pen); }

 
 int  deviceColorPlot::getColor(int X, int Y) { return colors[Y * maxX + X]; }
 
deviceColorPlot::~deviceColorPlot()
{
    delete [] colors ;
}