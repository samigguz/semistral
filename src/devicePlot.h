/**
 * @file   devicePlot.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    devicePlot.cpp for implementation.
 */



#ifndef DEVICEPLOT_H
#define	DEVICEPLOT_H
#include <iostream>
#include <map>
#include <ctype.h>
using namespace std;

/**
 * @brief Class that draw and print output.
 * 
 * Class must prepare the device for drawing operations 
 * (such as selecting a line color, a brush pattern and color).
 * Class defines associated attributes of graphic objects, and the graphic modes that affect output. 
 * An application operates on the class indirectly by calling various functions.
 * Gives an application more control over how and whether 
 * clipping occurs in the client area.
 * 
 */

class devicePlot {
public:
        devicePlot();
        devicePlot(int X,int Y);
		
        virtual void putPixel(int X, int Y) { this->putPixel(X,Y,Pen); }
	virtual void putPixel(int X, int Y, char znak);
	virtual	void print(ofstream &);
        virtual void setColor(string &a);
        virtual ~devicePlot();
            
             char **array;///<2-D Canvas
             char Brush;///<brush for painting and filling
             char Pen;///<pen for line drawing
	protected:
		int maxX;///<Maximum value of the X axis(width of the Canvas)
		int maxY;///<Maximum value of the Y axis(height of the Canvas)
                int Color;///<number of color
                map <string, int> map_colors;///<palette for defining the set of available colors
		
	 	

};

#endif	/* DEVICEPLOT_H */

