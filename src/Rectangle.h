/* 
 * File:   Rectangle.h
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:53
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include "Line.h"
#include<cmath>

/*========================class Rectangle==============================================
 Trida reprezentuje obdelnik, ktery je zadany dvojici protilehlych rohu
*/
class Rectangle: public Line{
	
	protected:
		Line b,c,d;
	public:
	Rectangle(int x1,int y1,int x2,int y2) {
	setCoordinates(x1,y1,x2,y1);	// tim sestrojime primku 'a'
	b.setCoordinates(x2,y1,x2,y2);
	c.setCoordinates(x2,y2,x1,y2);
	d.setCoordinates(x1,y2,x1,y1);
   }
   
        
   void show (devicePlot *hdc ){
   	 Line::show(hdc);
   	 b.show(hdc);
   	 c.show(hdc);
   	 d.show(hdc);
   }     
        
   void show (devicePlot hdc ){
   	 Line::show(hdc);
   	 b.show(hdc);
   	 c.show(hdc);
   	 d.show(hdc);
   }
   
   void fill(int x1,int y1,int x2,int y2,devicePlot* hdc)
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
   
   
   
};

#endif	/* RECTANGLE_H */

