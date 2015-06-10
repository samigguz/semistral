/* 
 * File:   plotPoint.cpp
 * Author: andrew
 * 
 * Created on 3 Июнь 2015 г., 0:37
 */

#include "plotPoint.h"
#include "plotObjects.h"


plotPoint::~plotPoint() {
}

 
  void plotPoint::show( devicePlot *hdc ){
        hdc->putPixel(X,Y,hdc->Pen);
    };
