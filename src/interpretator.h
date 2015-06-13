/**
 * @file   interpretator.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    interpretator.cpp for implementation.
 */



#ifndef INTERPRETATOR_H
#define	INTERPRETATOR_H

#include <string>
#include <vector>
#include <map>
#include "devicePlot.h"
#include "plotPoint.h"

using namespace std;

/**
 * @brief Class that defines a set of graphic objects and their associated attributes,that affect output.
 * 
 */


class interpretator {
public:
    interpretator();
    interpretator(string fNameIn, string fNameOut);
    void set_size(int,int);
    void doIt();
    
    devicePlot* set_devicePlot( vector<string> );
    
    void check_Limits(int x, int y );
    void init_Lang();
 
/**
*   @brief Several set methods, which use the same parametrs.
* 
*   @param[in] hdc Handle to a device context.
*   @param[in] vector<string> An array, that contains information about.
*   @throw CCoordException When in the input file was used the wrong data format.
*   
*/ 
    void set_beginPoliLine( devicePlot*, vector<string> );
    void set_showPoliLine( devicePlot*, vector<string> );
    void set_poliLineAdd( devicePlot*, vector<string> );
    
    void set_beginPattern( devicePlot*, vector<string> );
    void set_endPattern( devicePlot*, vector<string> );
    void set_copyPattern( devicePlot*, vector<string> );
    
    
    void set_Line( devicePlot*, vector<string> );
    void set_Rectangle( devicePlot*, vector<string> );
    void set_Point(devicePlot*, vector<string>);
    void set_Ellipse(devicePlot*, vector<string>);
/**
*   @brief Function creates a logical brush with the specified char symbol.
*  
*/
    void set_Brush(devicePlot*, vector<string>);
    void set_Pen(devicePlot*, vector<string>);
    void set_clearBrush(devicePlot*, vector<string>);
    void set_clearPen(devicePlot*, vector<string>);
/**
*   @brief Function creates a logical brush that has the specified solid color.
*  
*/
    void set_setColor( devicePlot* hdc, vector<string>);
    
    virtual ~interpretator();
    
private:
    devicePlot *hdc;
    
    int maxX,maxY;
    int numberOfLine;
    string line;
    string fileNameIn, fileNameOut;
    bool isDigit(string &);
    map <string, void (interpretator::*)(devicePlot*, vector<string>)> lang;
    vector<plotPoint>  poliPoints;
    
    //Pattern
    bool patternMode;
    devicePlot *saveHDC;
    devicePlot *patternHDC;
    int patternMaxX, patternMaxY;
    
};

#endif	/* INTERPRETATOR_H */

