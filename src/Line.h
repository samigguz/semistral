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
	 int x,y;
   public:

    Line():plotPoint(0,0){x=y=0;}
    Line(int x1,int y1, int x2,int y2 );
    void setCoordinates (int x1,int y1, int x2,int y2 );
    void  swap(int &a, int &b);
    virtual void show(devicePlot hdc );
    virtual void show(devicePlot *hdc );
  };

#endif	/* LINE_H */

