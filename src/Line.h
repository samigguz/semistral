/* 
 * File:   Line.h
 * Author: andrew
 *
 * Created on 3 Июнь 2015 г., 0:47
 */

#ifndef LINE_H
#define	LINE_H

#include <cmath>
#include "plotPoint.h"

using namespace std;

class Line : public plotPoint {
	protected:
	/*
   	Parametricke vyjadreni primky je jednou z moznosti,
    jak matematicky popsat primku. 
	Kazda primka v rovine je urcena dvema ruznymi
	body A a B. Tyto body urcuji taky vektor. 
	My tento vektor pojmenujeme a vyuzijeme jej 
	pro zavedeni parametrickeho vyjadreni primky.
   	*/
     //smerovy vektor primky
	 int x,y; // body x a y potrebujeme, abych urcili hranici primky
   public:
    //Jelikoz trida Line je potomkem tridy plotPoint a nase primka ma dve souradnice, do plotPointu dame "levy" pocatek primky
    Line():plotPoint(0,0){
    	x=y=0;
    }
    Line(int x1,int y1, int x2,int y2 ):plotPoint(x1,y1){
       x=x2;
	   y=y2;
       /*
       Jestlize A, B jsou dva ruzne body, pak vektor p = B - A nazyvame smerovy vektor primky AB.
       V nasem pripade smerovy vektor p bubeme mit dve parametricke rovnice (p(p1,p2)):
       x=p1*t+x1 kde t=(x-x1)/p1
       y=p2*t+y1 kde t=(y-y1)/p2
       */
    }
    
    void setCoordinates (int x1,int y1, int x2,int y2 ) {
    	X=x1;
    	Y=y1;
    	
    	x=x2;
	    y=y2;
    }

    void  swap(int &a, int &b) {
    	int tmp = a;
    	a = b;
    	b = tmp;
    }
   virtual void show(devicePlot hdc );
    
    
};

#endif	/* LINE_H */

