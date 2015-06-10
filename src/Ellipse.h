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
#include "Line.h"
#include <iostream>
using namespace std;


class Ellipse : public plotPoint {
protected:
     int x1,y1,x2,y2;  
     double a,b,e,p,c;
     int STEP;
public:
    Ellipse(int,int,int,int);
    void show (devicePlot *);  
    void fill(devicePlot *,char);
};


#endif	/* ELLIPSE_H */

