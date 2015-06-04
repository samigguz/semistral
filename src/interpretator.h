/* 
 * File:   interpretator.h
 * Author: 
 *
 * Created on 4 Июнь 2015 г., 2:36
 */



#ifndef INTERPRETATOR_H
#define	INTERPRETATOR_H

#include <string>
#include <vector>
#include "devicePlot.h"

using namespace std;



class interpretator {
public:
    interpretator();
    interpretator(std::string fNameIn, std::string fNameOut);
    interpretator(const interpretator& orig);
    
    void doIt();
    
    devicePlot* set_devicePlot( vector<string> );
    
    
    void set_Line( devicePlot*, vector<string> );
    void set_Rectangle( devicePlot*, vector<string> );
    void set_Point(devicePlot*, vector<string>);
    void set_Ellipse(devicePlot*, vector<string>);
    
    virtual ~interpretator();
private:
    std::string fileNameIn, fileNameOut;
};

#endif	/* INTERPRETATOR_H */

