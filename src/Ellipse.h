/* 
 * File:   Ellipse.h
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:54
 */

#ifndef ELLIPSE_H
#define	ELLIPSE_H

#include <cmath>
#include "plotPoint.h"

//double M_PI=3.1415926;

class Ellipse : public plotPoint {
protected:
     int x1,y1,x2,y2;  
     double a,b,e,p;
     int STEP;
public:
    Ellipse(int x1,int y1, int x2,int y2 ):plotPoint((x2-x1)/2,(y2-y1)/2),x1(x1),y1(y1),x2(x2),y2(y2),STEP(200) {
       a= (x2-x1)/2;
       b= (y2-y1)/2;
       double c = sqrt( a*a -b*b );
       e =  c / a;
       p=a-c*e;
    }
    
    
    void show (devicePlot hdc ){
     double step=(2*M_PI)/STEP;
	  
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
	    double dx = r*cos( angle);
	    double dy = r*sin( angle);
	    
	    hdc.putPixel( int( X+dx+0.45), int(Y+dy+0.45) );
	    
	  }
       
    } 
      
};


#endif	/* ELLIPSE_H */

