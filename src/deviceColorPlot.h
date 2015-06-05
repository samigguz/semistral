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
    deviceColorPlot(int n,int m);
    deviceColorPlot(const deviceColorPlot& orig);
    virtual ~deviceColorPlot();
    
    void print(void);
    //void setColor(int a){Color=a;}
    
    void putPixel(int X, int Y) { this->putPixel(X,Y,Pen); }
    void putPixel(int X, int Y, char znak) {
       // cout << "a" << Color << endl;
		  if (  X >=0 && X < N && Y>=0 && Y<M )
		  { 
		    array[Y][X]=znak;
                    colors[Y * N + X] = Color;
		  }  
    }
    
protected:
   string default_console;
   int *colors;
   //int Color;
};

#endif	/* DEVICECOLORPLOT_H */

