/**
 * @file   Ellipse.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    Ellipse.h for declaration.
 */

#include "Ellipse.h"


/**
 * The eccentricity of an ellipse is the ratio of the distance between
 * the two foci, to the length of the major axis or e =\f$\frac{2f}{2a} = \frac{f}{a}\f$.
 * 
 */ 

/**
 *  The distance to the focal point from the center of the ellipse
 * is sometimes called the linear eccentricity, f, of the ellipse.
 * 
 * Due to the Pythagorean theorem:
 * \f$f^2 = \sqrt{(a)^2+(b)^2}\f$.
 */  

Ellipse::Ellipse(int x1,int y1, int x2,int y2 ):plotPoint((x2+x1)/2,(y2+y1)/2),x1(x1),y1(y1),x2(x2),y2(y2),STEP(200) {
       a= (x2-x1)/2; ///<  major axis
       b= (y2-y1)/2;///<  minor axis
     
       f = sqrt(fabs( a*a -b*b) );///< foci, linear eccentricity
       e =  f / a;
       p=a-f*e;///<parametr of the ellipse
    }

 /**
 * @brief The equation of an ellipse whose major and minor axes coincide with 
 * the Cartesian axes is \f$\(frac{x}{a})^2 + (\frac{y}{b})^2} = 1\f$. 
 * This can be explained as follows:
 * 
 * \f${x} = {a}\cos\theta\f$. 
 * \f${y} = {b}\sin\theta\f$.
 * Then plotting x and y values for all angles of θ between 0 and 2π results in an ellipse.
 */  
      
void Ellipse::show (devicePlot *hdc ){
     double step=(2*M_PI/4)/STEP;
	  
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
	    double dx = r*cos( angle);
	    double dy= r*sin( angle);
	    hdc->putPixel( int( (X-f)+dx+0.5), int(Y+dy+0.5) );
            hdc->putPixel( int( (X+f)-dx+0.5), int(Y+dy+0.5) );
            hdc->putPixel( int( (X+f)-dx+0.5), int(Y-dy+0.5) );
            hdc->putPixel( int( (X-f)+dx+0.5), int(Y-dy+0.5) );
	    
	  }
       
    } 
      

void Ellipse::fill(devicePlot* hdc, char brush)
{
    double step=(2*M_PI/4)/STEP;
    Line l,k;char ptr=hdc->Pen;  
    
	 for (int i=0; i < STEP; i++ ) {
	    double angle=step*i;
	    double r = p / (1 -e* cos(angle));
	    double dx = r*cos( angle);
	    double dy= r*sin( angle);
	    
	    hdc->putPixel( int( (X-f)+dx+0.5), int(Y+dy+0.5) );
            hdc->putPixel( int( (X+f)-dx+0.5), int(Y+dy+0.5) );
            hdc->putPixel( int( (X+f)-dx+0.5), int(Y-dy+0.5) );
            hdc->putPixel( int( (X-f)+dx+0.5), int(Y-dy+0.5) );
	    
            hdc->Pen=brush;
            l.setCoordinates((X-f)+dx+0.5,Y+dy+0.5,(X+f)-dx+0.5,Y+dy+0.5);
            k.setCoordinates((X+f)-dx+0.5,Y-dy+0.5,(X-f)+dx+0.5,Y-dy+0.5);
            l.show(hdc);
            k.show(hdc);
            hdc->Pen=ptr;
	  }
       
    
}