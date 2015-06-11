/**
 * @file   painter.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    painter.h for declaration.
 */

#include "painter.h"
#include "Line.h"

painter::painter() {
    
}

void painter::setHDC( devicePlot &h) {
    hdc = h;
}

void painter::paint(plotObjects* a) {
   
   a->show(&hdc); 
}

painter::~painter() {
}

