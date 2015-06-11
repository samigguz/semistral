/**
 * @file   Rectangle.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    Rectangle.cpp for implementation.
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include "Line.h"
#include<cmath>

/**
 * @brief Class that draws an arbitrary rectangle.
 * 
 * The Rectangle class represents a rectangle defined by two opposite locations (x, y)
 * It is formed from base class Line.
 * It has three protected attributes of class Line: Rectangle#b,
 * Rectangle#c and Rectangle#d.
 * The rectangle is outlined by using the current pen 
 * and filled by using the current brush.
 */


 
class Rectangle: public Line{
	
	protected:
		Line b,c,d;
	public:
/**
*   @brief Constructor with arguments.
*   
* @param[in] nLeftRect The x-coordinate, in logical coordinates, of the upper-left corner of the rectangle.
* @param[in] nTopRect The y-coordinate, in logical coordinates, of the upper-left corner of the rectangle.
* @param[in] nRightRect The x-coordinate, in logical coordinates, of the lower-right corner of the rectangle.
* @param[in] nBottomRect The y-coordinate, in logical coordinates, of the lower-right corner of the rectangle.
*/
	    Rectangle(int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);
/**
*   @brief Virtual function that displays the object on the 2D-Canvas.
* 
*   @param[in] hdc Handle to a device context.
*   
*/
   
            virtual void show (devicePlot *hdc); 
/**
* @brief The virtual function fills a rectangle by using the specified brush. 
*  
*/
            void fill(int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,devicePlot* hdc);
   
   
   
};

#endif	/* RECTANGLE_H */

