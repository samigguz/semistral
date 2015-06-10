/* 
 * File:   devicePlot.cpp
 * Author: 
 * 
 * Created on 2 Июнь 2015 г., 23:56
 */
#include <iostream>
#include "devicePlot.h"

using namespace std;
void devicePlot::print(void)
{
	for(int i=0;i<maxY;i++)
	  {
	  for (int j=0;j<maxX;j++)
	  {
	  	cout<<array[i][j]<<" ";
	  }
	  cout<<endl;
	 }
     	
	
}

void devicePlot::printInfo()
{
  cout << "info " << maxX << "  " << maxY << endl;	
     	
	
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
			
		}

  void devicePlot::putPixel(int X, int Y, char znak) {
                    cout << "b" << endl;
		  if (  X >=0 && X < maxX && Y>=0 && Y<maxY )
		  { 
		    array[Y][X]=znak;
		  }  
		  
		}
  
