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
	for(int i=0;i<M;i++)
	  {
	  for (int j=0;j<N;j++)
	  {
	  	cout<<array[i][j]<<" ";
	  }
	  cout<<endl;
	 }
     	
	
}

void devicePlot::printInfo()
{
  cout << "info " << M << "  " << N << endl;	
     	
	
}

devicePlot::devicePlot(int n,int m):M(m),N(n),Brush(' '),Pen('*')
		{
			array=new char *[n];

	           for (int i = 0; i < n; i++)
                    array[i] = new char [m];
                    for(int i=0;i<n;i++)
	              for (int j=0;j<m;j++)
	                {
	                  array[i][j]=' ';
	                }
			
		}

  void devicePlot::putPixel(int X, int Y, char znak) {
                    cout << "b" << endl;
		  if (  X >=0 && X < N && Y>=0 && Y<M )
		  { 
		    array[Y][X]=znak;
		  }  
		  
		}
  
