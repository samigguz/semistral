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
    virtual ~painter();
    void paint ( plotObjects *);
    void setHDC( devicePlot &h);
    
private:
    devicePlot hdc;
};

#endif	/* PAINTER_H */

