/* 
 * File:   devicePlot.h
 * Author: 
 *
 * Created on 2 Июнь 2015 г., 23:56
 */



#ifndef DEVICEPLOT_H
#define	DEVICEPLOT_H

#include <iostream>
using namespace std;


class devicePlot {
public:
    devicePlot(){M=N=0;};
    
		devicePlot(int n,int m):M(m),N(n),Brush(' '),Pen('*')
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
		
		virtual void putPixel(int X, int Y) { this->putPixel(X,Y,Pen); }
		
		virtual void putPixel(int X, int Y, char znak) {
                    cout << "b" << endl;
		  if (  X >=0 && X < N && Y>=0 && Y<M )
		  { 
		    array[Y][X]=znak;
		  }  
		  
		}
	virtual	void print(void);
        virtual	void fill(int,int,int,int, char);

        virtual void setColor(int a){Color=a;}
        
        void printInfo();
            
             char **array;
             char Brush;
             char Pen;
	protected:
		int M;
		int N;
                int Color;
		
	 	

};

#endif	/* DEVICEPLOT_H */

