/* 
 * File:   deviceColorPlot.h
 * Author: andrew
 *
 * Created on 6 Июнь 2015 г., 0:46
 */

#ifndef DEVICECOLORPLOT_H
#define	DEVICECOLORPLOT_H

#include "devicePlot.h"
#include <string>
#include <iostream>
using namespace std;

class deviceColorPlot: public devicePlot {
public:
    deviceColorPlot();
    deviceColorPlot(int X,int Y);
    deviceColorPlot(const deviceColorPlot& orig);
    virtual ~deviceColorPlot();
    
    void print(void);
    void putPixel(int X, int Y);
    void putPixel(int X, int Y, char );
    
protected:
   string default_console;
   int *colors;
};

#endif	/* DEVICECOLORPLOT_H */

