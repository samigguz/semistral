/* 
 * File:   Circle.h
 * Author: andrew
 *
 * Created on 3 Июнь 2015 г., 1:01
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

#include "Ellipse.h"

class Circle: public Ellipse
{
	public:
	 Circle (int x,int y,int r):Ellipse(x-r,y-r,x+r,y+r){}
		
	
};

#endif	/* CIRCLE_H */

