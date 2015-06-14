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

/**
 * @brief Abstract base class.
 * 
 */
class plotObjects {
public:
    plotObjects();
    virtual void show( devicePlot *hdc ){};
    void  swap(int &a, int &b);
private:

};

#endif	/* PLOTOBJECTS_H */

