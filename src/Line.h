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
        //smerovy vektor primky
	 int x,y; // body x a y potrebujeme, abych urcili hranici primky
   public:

    Line():plotPoint(0,0){x=y=0;}
    Line(int x1,int y1, int x2,int y2 );
   /*
   	Parametricke vyjadreni primky je jednou z moznosti,
        jak matematicky popsat primku. 
	Kazda primka v rovine je urcena dvema ruznymi
	body A a B. Tyto body urcuji taky vektor. 
	My tento vektor pojmenujeme a vyuzijeme jej 
	pro zavedeni parametrickeho vyjadreni primky.
   	*/
    void setCoordinates (int x1,int y1, int x2,int y2 );
    void  swap(int &a, int &b);
    virtual void show(devicePlot hdc );
    
  };

#endif	/* LINE_H */

