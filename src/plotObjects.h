/* 
 * File:   plotObjects.h
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:36
 */

#ifndef PLOTOBJECTS_H
#define	PLOTOBJECTS_H

#include "devicePlot.h"

class plotObjects {
public:
    plotObjects();
    plotObjects(const plotObjects& orig);
    virtual ~plotObjects();
    
    void show( devicePlot hdc ){};
    void fill( devicePlot hdc,char ){};
    
private:

};

#endif	/* PLOTOBJECTS_H */

