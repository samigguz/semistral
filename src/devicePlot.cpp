/**
 * @file   devicePlot.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    devicePlot.h for declaration.
 */
#include <iostream>
#include "devicePlot.h"
#include <map>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
devicePlot::devicePlot():Brush(' '),Pen('*')
{
     maxX=maxY=0;
}

void devicePlot::setColor(string &a)
{           
    if (map_colors.find(a)!=map_colors.end()) Color=map_colors[a];
    else Color=atoi(a.c_str());
}
        
void devicePlot::print(ofstream & fout)
{
	for(int i=0;i<maxY;i++)
	  {
	  for (int j=0;j<maxX;j++)
	  {
	  	fout<<array[i][j]<<"";
	  }
	  fout<<endl;
	 }
    	
}



devicePlot::devicePlot(int X,int Y):maxX(X),maxY(Y),Brush(' '),Pen('*')
		{
		   array=new char *[maxY];

	           for (int i = 0; i < maxY; i++)
                    array[i] = new char [maxX];
                    
                   for(int i=0;i<maxY;i++)
	              for (int j=0;j< maxX;j++)
	                {
	                  array[i][j]=' ';
	                }
			
     map_colors["Black"]=0;
     map_colors["Green"]=1;
     map_colors["Brown"]=2;
     map_colors["Blue"]=3;
     map_colors["Magenta"]=4;
     map_colors["Cyan"]=5;
     map_colors["Lightgray"]=6;
		}

  void devicePlot::putPixel(int X, int Y, char znak) {
                    //cout << "b" << endl;
		  if (  X >=0 && X < maxX && Y>=0 && Y<maxY )
		  { 
		    array[Y][X]=znak;
		  }  
		  
		}
  

  
  devicePlot::~devicePlot()
  {
      
      for (int i=0;i<maxY;i++)
      {
          delete [] array[i];
      }
      
      delete [] array;
      
      
  }

  
