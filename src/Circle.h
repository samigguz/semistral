/**
 * @file   Circle.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

#include "Ellipse.h"
/**
 * @brief Class that draws an arbitrary circle on the 2D-Canvas.
 * 
 * Class is formed from base class Ellipse, because
 * a circle may be defined as a special ellipse 
 * in which the two foci are coincident and the eccentricity is 0.
 * 
 */
class Circle: public Ellipse
{
	public:
/**
*   @brief Basic constructor with arguments
*  (centre coordinates (x, y) and radius r).
*   
*/
	 Circle (int x,int y,int r):Ellipse(x-r,y-r,x+r,y+r){}
		
	
};

#endif	/* CIRCLE_H */

