/* 
 * File:   Rectangle.h
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:53
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include "Line.h"

/*========================class Rectangle==============================================
 Trida reprezentuje obdelnik, ktery je zadany dvojici protilehlych rohu
*/
class Rectangle: public Line{
	
	protected:
		Line b,c,d;
	public:
	Rectangle(int x1,int y1,int x2,int y2) {
		
/*      y1    y2
		   a
  x1	 ----
	  d �    � b
  x2	 ----
		  c          */
		 
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
   
   
};

#endif	/* RECTANGLE_H */

