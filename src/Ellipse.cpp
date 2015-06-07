/* 
 * File:   Ellipse.cpp
 * Author: 
 * 
 * Created on 3 Июнь 2015 г., 0:54
 */

#include "Ellipse.h"
Ellipse::Ellipse(int x1,int y1, int x2,int y2 ):plotPoint((x2+x1)/2,(y2+y1)/2),x1(x1),y1(y1),x2(x2),y2(y2),STEP(200) {
       a= (x2-x1)/2; //mala poloosa
       b= (y2-y1)/2;//velka poloosa
     
       c = sqrt(fabs( a*a -b*b) );//Ohniskova vzdalenost, vyjadruje vzdalenost ohniska od stredu elipsy
       /*
        *  Ciselna excentricita e vyjadruje miru zplosteni elipsy,
        *  miru odlisnosti od kruznice. Ma smysl ji porovnavat i pro 
        *  ruzne velke elipsy
        */
       e =  c / a;
       /*
        *Vrcholová rovnice elipsy ma tvar y^2 = 2px - (p/a)x^2,
        *kde p = (b^2)/a je tzv. parametr elipsy.Tato rovnice 
        *vyjadruje elipsu, jejiz hlavni vrchol lezi v pocatku 
        *souradne soustavy a hlavni osa je rovnobezna s osou x.
        */
       
       p=a-c*e;//parametr elipsy
    }

 void Ellipse::show (devicePlot hdc ){
     double step=(2*M_PI/4)/STEP;
	  
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
            /*
             * Elipsu lze vyjadrit parametrickymi rovnicemi
             * x = r*cos(t)
             * y = r*sin(t)
             * kde t je tzv. excentricka anomalie.
            */
	    double dx = r*cos( angle);
	    double dy= r*sin( angle);
	    //cout<<"r= "<<r<<" dx= "<<dx<<" dy="<<dy<<" X="<<X+c+dx+0.45<<" Y="<<Y-dy+0.45<<endl;
	    hdc.putPixel( int( (X-c)+dx+0.5), int(Y+dy+0.5) );
            hdc.putPixel( int( (X+c)-dx+0.5), int(Y+dy+0.5) );
            hdc.putPixel( int( (X+c)-dx+0.5), int(Y-dy+0.5) );
            hdc.putPixel( int( (X-c)+dx+0.5), int(Y-dy+0.5) );
	    
	  }
       
    } 
      
void Ellipse::show (devicePlot *hdc ){
        cout<<endl<<"*******************************************"<<endl;

     double step=(2*M_PI/4)/STEP;
	  
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
	    double dx = r*cos( angle);
	    double dy= r*sin( angle);
	    //cout<<"r= "<<r<<" dx= "<<dx<<" dy="<<dy<<" X="<<X+c+dx+0.45<<" Y="<<Y-dy+0.45<<endl;
	    hdc->putPixel( int( (X-c)+dx+0.5), int(Y+dy+0.5) );
            hdc->putPixel( int( (X+c)-dx+0.5), int(Y+dy+0.5) );
            hdc->putPixel( int( (X+c)-dx+0.5), int(Y-dy+0.5) );
            hdc->putPixel( int( (X-c)+dx+0.5), int(Y-dy+0.5) );
	    
	  }
       
    } 
      