/* 
 * File:   plotPoint.h
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:37
 */

#ifndef PLOTPOINT_H
#define	PLOTPOINT_H

#include "plotObjects.h"


class plotPoint: public plotObjects {
protected:  
     int X, Y;
public:
    plotPoint( int X, int Y):X(X),Y(Y){};
    virtual ~plotPoint();
    
    virtual void show( devicePlot *hdc );
    
    
};


#endif	/* PLOTPOINT_H */

