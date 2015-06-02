/* 
 * File:   devicePlot.cpp
 * Author: 
 * 
 * Created on 2 Июнь 2015 г., 23:56
 */

#include "devicePlot.h"
void devicePlot::fill(int x1,int x2, int y1,int y2, char znak)

{
	
	int i,j;
	for ( i=x1;i<=x2;i++)
	
	{
		for (j=y1;j<=y2;j++)
		{
			if (array[i][j]==' ') continue;
			else //nasli znak
			
			{     j++;   //propuskaem
			  while (array[i][j]==' ')
			
			  {
		     	    array[i][j]=znak;j++;
			  }
		    }
			
		}
		
	}
	
}
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
