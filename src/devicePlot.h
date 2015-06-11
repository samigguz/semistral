/**
 * @file   devicePlot.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    devicePlot.cpp for implementation.
 */



#ifndef DEVICEPLOT_H
#define	DEVICEPLOT_H
#include <iostream>
using namespace std;



class devicePlot {
public:
    devicePlot(){maxX=maxY=0;};
    
    devicePlot(int X,int Y);
		
        virtual void putPixel(int X, int Y) { this->putPixel(X,Y,Pen); }
	virtual void putPixel(int X, int Y, char znak);
	virtual	void print(void);
        virtual void setColor(int a){Color=a;}
        
        void printInfo();
            
             char **array;
             char Brush;
             char Pen;
	protected:
		int maxX;
		int maxY;
                int Color;
		
	 	

};

#endif	/* DEVICEPLOT_H */

