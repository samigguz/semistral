/**
 * @file   Rectangle.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    Rectangle.h for declaration.
 */

#include "Rectangle.h"


Rectangle::Rectangle(int x1,int y1,int x2,int y2) {
	setCoordinates(x1,y1,x2,y1);
	b.setCoordinates(x2,y1,x2,y2);
	c.setCoordinates(x2,y2,x1,y2);
	d.setCoordinates(x1,y2,x1,y1);
   }
void Rectangle::fill(int x1,int y1,int x2,int y2,devicePlot* hdc)
   {
       int start=y1<y2?y1:y2;
       int end=y1<y2?y2:y1;
       Line l;
       int i;char ptr=hdc->Pen;
       
       hdc->Pen=hdc->Brush;
	for ( i=start;i<=end;i++)
	 {
            l.setCoordinates(x1,i,x2,i);
            l.show(hdc);	
	 }
       hdc->Pen=ptr;
   }
        
   void Rectangle::show (devicePlot *hdc ){
   	 Line::show(hdc);
   	 b.show(hdc);
   	 c.show(hdc);
   	 d.show(hdc);
   }     
      