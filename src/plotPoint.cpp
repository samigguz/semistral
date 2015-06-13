/**
 * @file   plotPoint.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    plotPoint.h for declaration.
 */

#include "plotPoint.h"
#include "plotObjects.h"


plotPoint::~plotPoint() {
}

 
  void plotPoint::show( devicePlot *hdc ){
        hdc->putPixel(X,Y,hdc->Pen);
    };
    
