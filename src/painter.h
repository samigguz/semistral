/**
 * @file   painter.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
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

