/**
 * @file   Line.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    Line.h for declaration.
 */

#include "Line.h"
#include "plotObjects.h"
void Line::show(devicePlot *hdc )
 {   
    bool steep =abs(y - Y) > abs(x - X); 
    if (steep)
    {   
        swap(X, Y); 
        swap(x, y);
    }
    if (X > x)
    {
        swap(X, x);
        swap(Y, y);
    }
    int dx = x - X;
    int dy = abs(y - Y);
    int error = dx / 2; 
    int ystep = (Y < y) ? 1 : -1; 
    int yy = Y;
    for (int xx = X; xx <= x; xx++)
    {
        hdc->putPixel(steep ? yy : xx, steep ? xx : yy); 
        error -= dy;
        if (error < 0)
        {
            yy += ystep;
            error += dx;
        }
    }
 }





   void Line::setCoordinates (int x1,int y1, int x2,int y2 ) {
    	X=x1;
    	Y=y1;
    	
    	x=x2;
	y=y2;
    }
   
   
   
    Line::Line(int x1,int y1, int x2,int y2 ):plotPoint(x1,y1){
       x=x2;
       y=y2;
  
    }

    
    
