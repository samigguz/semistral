/* 
 * File:   painter.h
 * Author: andrew
 *
 * Created on 3 Июнь 2015 г., 1:45
 */

#ifndef PAINTER_H
#define	PAINTER_H

#include "devicePlot.h"
#include "plotObjects.h"

class painter {
public:
    painter();
   
    void paint( plotObjects * a);
    void setHDC( devicePlot &h);
    
    virtual ~painter();
private:
    devicePlot hdc;
};

#endif	/* PAINTER_H */

