/* 
 * File:   plotObjects.h
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:36
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
    
    virtual void show( devicePlot hdc ){};
    virtual void fill( devicePlot hdc,char ){};
    virtual void show( devicePlot *hdc ){};
    
private:

};

#endif	/* PLOTOBJECTS_H */

