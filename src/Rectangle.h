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
 *     @brief Class converts relative @p path to absolute.
 *
 *     If path is empty function will return
 *     current working directory in a string.
 *     @return absolute path of given string
 */
/**
    \brief class Rectangle

    Trida reprezentuje obdelnik,
    ktery je zadany dvojici protilehlych rohu 
*/

 
class Rectangle: public Line{
	
	protected:
		Line b,c,d;
	public:
	    Rectangle(int x1,int y1,int x2,int y2);
            void show (devicePlot *); 
            void show (devicePlot);
            void fill(int,int,int,int,devicePlot*);
   
   
   
};

#endif	/* RECTANGLE_H */

