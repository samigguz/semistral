/**
 * @file   plotObjects.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 */

#ifndef PLOTOBJECTS_H
#define	PLOTOBJECTS_H

#include <iostream>
#include "devicePlot.h"


class plotObjects {
public:
    plotObjects();
    plotObjects(const plotObjects& orig);
    virtual ~plotObjects();
    virtual void show( devicePlot *hdc ){};
    
private:

};

#endif	/* PLOTOBJECTS_H */

