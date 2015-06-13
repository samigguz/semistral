/**
 * @file   deviceColorPlot.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    deviceColorPlot.cpp for implementation.
 */

#ifndef DEVICECOLORPLOT_H
#define	DEVICECOLORPLOT_H

#include "devicePlot.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Class that supports color drawing.
 * 
 * Class must prepare the device for drawing operations 
 * (such as selecting a line color and a brush color).
 * The class include a palette for defining the set of available colors and deviceColorPlot#default_console.
 * 
 */

class deviceColorPlot: public devicePlot {
public:
    deviceColorPlot();
    deviceColorPlot(int X,int Y);
    
    void print(ofstream &);
    void putPixel(int X, int Y);
    void putPixel(int X, int Y, char );
    
    
     int getColor(int X, int Y);
    
protected:
   string default_console;
   int *colors;
 
};

#endif	/* DEVICECOLORPLOT_H */

