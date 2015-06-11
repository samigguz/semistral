/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:11
 */

#include <cstdlib>
#include <iostream>

//#include "devicePlot.h"
//#include "plotPoint.h"
//#include "Line.h"
//#include "painter.h"
#include "interpretator.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    interpretator mainInterpretator("examples/Mikie_mouse","example1.out");
    mainInterpretator.doIt();
    
        /*painter canvas;
        canvas.setHDC( hdc);*/
	return 0;
}

