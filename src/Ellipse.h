/**
 * @file   Ellipse.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    Ellipse.cpp for implementation.
 */

#ifndef ELLIPSE_H
#define	ELLIPSE_H

#include <cmath>
#include "plotPoint.h"
#include "Line.h"
#include <iostream>
using namespace std;

/**
 * @brief Class that draws an arbitrary ellipse on the 2D-Canvas.
 * 
 * The Ellipse class represents an ellipse defined by a bounding rectangle.
 * It is formed from base class plotPoint.
 * Class has a derived class Circle.
 * 
 */

class Ellipse : public plotPoint {
protected:
     int x1,y1,x2,y2;  
     double a;///<  major axis
     double b;///<  minor axis
     double e;///< eccentricity   
 /**
 *  The distance to the focal point from the center of the ellipse
 * is sometimes called the linear eccentricity, f, of the ellipse.
 * 
 * Due to the Pythagorean theorem:
 * \f$f^2 = \sqrt{(a)^2+(b)^2}\f$.
 */  
     double f;///<foci, linear eccentricity
     double p;
     bool steep;
     int STEP;
public:
/**
*   @brief Basic constructor with arguments.
*   
*  @param nLeftRect The x-coordinate, in logical coordinates, of the upper-left corner of the bounding rectangle.
*  @param nTopRect The y-coordinate, in logical coordinates, of the upper-left corner of the bounding rectangle.
*  @param nRightRect The x-coordinate, in logical coordinates, of the lower-right corner of the bounding rectangle.
*  @param nBottomRect The y-coordinate, in logical coordinates, of the lower-right corner of the bounding rectangle.
 */
    Ellipse(int nLeftRect,int nTopRect,int nRightRect,int nBottomRect );
/**
*   @brief Virtual function that displays the ellipse on the 2D-Canvas.
* 
*   @param[in] hdc Handle to a device context.
*   
*/
    virtual void show (devicePlot *hdc);  
/**
*  @brief The virtual function fills an ellipse by using the specified brush. 
*   
* @param[in] hdc Handle to a device context.
* @param[in] symbol A handle to the brush used to fill the ellipse.
*/
    void fill(devicePlot *hdc,char symbol);
};


#endif	/* ELLIPSE_H */

