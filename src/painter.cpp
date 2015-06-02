/* 
 * File:   painter.cpp
 * Author: andrew
 * 
 * Created on 3 Июнь 2015 г., 1:45
 */

#include "painter.h"

painter::painter() {
    
}

void painter::setHDC( devicePlot &h) {
    hdc = h;
}

void painter::paint(plotObjects* a) {
   a->show(hdc); 
}

painter::~painter() {
}

