/* 
 * File:   Ellipse.cpp
 * Author: 
 * 
 * Created on 3 Июнь 2015 г., 0:54
 */

#include "Ellipse.h"
Ellipse::Ellipse(int x1,int y1, int x2,int y2 ):plotPoint((x2+x1)/2,(y2+y1)/2),x1(x1),y1(y1),x2(x2),y2(y2),STEP(200) {
       a= (x2-x1)/2; //malenkaja poluos
       b= (y2-y1)/2;//bolsaja poluos
        
       /*a= (y2-y1)/2;
       b= (x2-x1)/2;*/
       c = sqrt(fabs( a*a -b*b) );//fokalnoje rasstojanije
       e =  c / a;//эксцентриситет
       p=a-c*e;//фокальный параметр
    }

 void Ellipse::show (devicePlot hdc ){
     double step=(2*M_PI)/STEP;
	  
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
	    double dx = r*cos( angle);
	    double dy= r*sin( angle);
	    //cout<<"r= "<<r<<" dx= "<<dx<<" dy="<<dy<<" X="<<X+c+dx+0.45<<" Y="<<Y-dy+0.45<<endl;
	    hdc.putPixel( int( (X-c)+dx+0.5), int(Y+dy+0.5) );
	    
	  }
       
    } 
      
void Ellipse::show (devicePlot *hdc ){
     double step=(2*M_PI)/STEP;
	  
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
	    double dx = r*cos( angle);
	    double dy= r*sin( angle);
	    //cout<<"r= "<<r<<" dx= "<<dx<<" dy="<<dy<<" X="<<X+c+dx+0.45<<" Y="<<Y-dy+0.45<<endl;
	    hdc->putPixel( int( (X-c)+dx+0.5), int(Y+dy+0.5) );
	    
	  }
       
    } 
      