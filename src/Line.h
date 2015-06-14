/**
 * @file   Line.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    Line.cpp for implementation.
 */


        
        
#ifndef LINE_H
#define	LINE_H

#include <cmath>
#include "plotPoint.h"

using namespace std;

/**
 * @brief The Line class represents a line segment 
 * in (x, y) coordinate space on the 2D-Canvas.
 * 
 * It has two protected attributes of class Line: 
 * Line#x(the x-coordinate) and Line#y(the y-coordinate).
 * It also contains several member functions
 * and is formed from base class plotPoint.
 * Class has a derived class Rectangle.
 * 
 */

class Line : public plotPoint {
  protected:
	 int x,y;
   public:
/**
*  @brief Default constructor.
* 
*  This constuctor is used to create two points
*  in the origin of coordinates. 
*   
*/
    Line():plotPoint(0,0){x=y=0;}
/**
*   @brief Basic constructor with arguments(pair of opposing coordinates).
*   
*/
    Line(int x1,int y1, int x2,int y2 );
    void setCoordinates (int x1,int y1, int x2,int y2 );
/**
*   @brief Virtual function that displays the line on the 2D-Canvas.
*   
*/
    virtual void show(devicePlot *hdc );
  };

#endif	/* LINE_H */

