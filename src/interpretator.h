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
    void set_size(int,int);
    void doIt();
    
    devicePlot* set_devicePlot( vector<string> );
    
    void check_Limits(int x, int y );
    
    void set_Line( devicePlot*, vector<string> );
    void set_Rectangle( devicePlot*, vector<string> );
    void set_Point(devicePlot*, vector<string>);
    void set_Ellipse(devicePlot*, vector<string>);
    void set_Brush(devicePlot*, vector<string>);
    void set_Pen(devicePlot*, vector<string>);
    void set_clearBrush(devicePlot*, vector<string>);
    void set_clearPen(devicePlot*, vector<string>);
    void set_setColor( devicePlot* hdc, vector<string> a);
    
    virtual ~interpretator();
private:
    int maxX,maxY;
    char Brush;
    char Pen;
    int numberOfLine;
    string line;
    std::string fileNameIn, fileNameOut;
    bool isDigit(string &);
};

#endif	/* INTERPRETATOR_H */

