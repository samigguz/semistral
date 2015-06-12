/**
 * @file   plotPoint.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    plotPoint.cpp for implementation.
 */
#ifndef PLOTPOINT_H
#define	PLOTPOINT_H

#include "plotObjects.h"

/**
 * @brief The Point class defines the x- and y- coordinates of a point.
 * 
 * It is formed from base class plotObjects.
 * Class has a derived classes Circle,Line and Ellipse.
 */

class plotPoint: public plotObjects {
protected:  
     int X, Y;
public:
    plotPoint( int X, int Y):X(X),Y(Y){};
    virtual ~plotPoint();
    
    virtual void show( devicePlot *hdc );
    int getX() {return X;}
    int getY() {return Y;}
    
};


#endif	/* PLOTPOINT_H */

