/* 
 * File:   interpretator.cpp
 * Author: andrew
 * 
 * Created on 4 Июнь 2015 г., 2:36
 */
#include <string>
#include <fstream>
#include <iostream>
#include "interpretator.h"
#include "parser.h"
#include "devicePlot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "CCoordException.h"

using namespace std;

interpretator::interpretator():Brush(' '),Pen('*') {
}

interpretator::interpretator(std::string fNameIn, std::string fNameOut):Brush(' '),Pen('*') {
    this->fileNameIn = fNameIn;
    this->fileNameOut= fNameOut;
}

void interpretator::doIt() {
    ifstream fin;
    fin.open(fileNameIn.c_str());
    ofstream fout;
    fout.open(fileNameOut.c_str());
    fout << "Hi" << endl;
    
    parser par;
    par.initTerms();
    
    devicePlot *hdc;
    
    
    bool start = true;
    
    while ( !fin.eof()) {
      string s;
      getline(fin,s);
      //cout <<s << endl;
      //del comments
      size_t pos = s.find_first_of("//");
      if ( pos != string::npos) {
          s.erase(pos, s.size()-pos);
          cout <<s << endl;
      }
      vector<string> tokens = par.doParsing(s);
      if ( tokens.size() == 0) continue;
      
      //cout << tokens[0] << endl;
      
      if ( start) { 
         if (  tokens[0] != "setSize") {
          cout << " Error! Not set size" << endl;
          exit;
         } else {
             start = false;
             hdc = this->set_devicePlot( tokens );
             if ( hdc == NULL ) {
                 cout << "error init devicePlot " << endl;
                 exit;
             }
         }
      }  else {
        
        if ( tokens[0] == "useBrush") set_Brush( hdc, tokens);
        if ( tokens[0] == "usePen") set_Pen( hdc, tokens);
        if ( tokens[0] == "clearBrush") set_clearBrush( hdc, tokens);
        if ( tokens[0] == "Line") set_Line( hdc, tokens);
        if ( tokens[0] == "Rectangle" ||tokens[0] == "Square" ) set_Rectangle( hdc, tokens);
        
        if ( tokens[0] == "Point") set_Point( hdc, tokens);
        if ( tokens[0] == "Ellipse" || tokens[0] == "Circle" ) set_Ellipse( hdc, tokens);
      } 
      
      
    }
    
    hdc->print();
    
    fout.close();
    fin.close();
    
}

devicePlot* interpretator::set_devicePlot(vector<string> a) {
  cout << a.size() << endl;  
  if ( a.size() != 6) {
      cout << " Error setSize " << endl;
      return NULL;
  }  
  int x = atoi(a[2].c_str());
  int y = atoi(a[4].c_str());
  set_size(x,y);
  return new devicePlot(x,y);
}
void interpretator::set_size(int M,int N)
{
    m=M;
    n=N;
}

interpretator::interpretator(const interpretator& orig) {
}

interpretator::~interpretator() {
}

void interpretator::set_Brush( devicePlot* hdc, vector<string> a)
{
    cout << "Brush " << a.size() << endl;  
    if ( a.size() != 6) {
        cout << " Error in Brush " << endl;
        return;
    }    
    
    Brush=a[3][0];
    hdc->Brush=Brush;
    
}
void interpretator::set_Pen( devicePlot* hdc, vector<string> a)
{
    cout << "Pen " << a.size() << endl;  
    if ( a.size() != 6) {
        cout << " Error in Pen " << endl;
        return;
    }    
    
    Pen=a[3][0];
    hdc->Pen=Pen;
}
void interpretator::set_clearBrush( devicePlot* hdc, vector<string> a)
{
    cout << "Pen " << a.size() << endl;  
    if ( a.size() != 1) {
        cout << " Error in Pen " << endl;
        return;
    }    
    
    Brush=' ';
    hdc->Brush=Brush;
    
}
void interpretator::set_Line( devicePlot* hdc, vector<string> a){
    cout << "Line " << a.size() << endl;  
    if ( a.size() != 10) {
        cout << " Error in Line " << endl;
        return;
    }    
    
    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    int x2 = atoi(a[6].c_str());
    int y2 = atoi(a[8].c_str());
    
     //if (  X >=0 && X < N && Y>=0 && Y<M )
    if (x1>m || x1<0 || x2>m || x2<0) throw CCoordException("Line");
    if (y1>n || y1<0 || y2>n || y2<0) throw CCoordException("Line");
    Line l(x1,y1,x2,y2);
    
    l.show( *hdc );
    
}
void interpretator::set_Point(devicePlot* hdc, vector<string> a)
{
    
    cout << "Point " << a.size() << endl;  
    if ( a.size() != 6) {
        cout << " Error in Point " << endl;
        return;
    }    
    
    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    
   if (x1>m || x1<0 || y1>n || y1<0) throw CCoordException("Line");
   
    
    plotPoint l( x1, y1);
    
    l.show( *hdc );
    
    
}
void interpretator::set_Ellipse(devicePlot* hdc, vector<string> a)
{
    
    cout << "Ellipse " << a.size() << endl;  
    if ( a.size() != 10) {
        cout << " Error in Ellipse " << endl;
        return;
    }    
    
    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    int x2 = atoi(a[6].c_str());
    int y2 = atoi(a[8].c_str());
    
    if (x1>m || x1<0 || x2>m || x2<0) throw CCoordException("Ellipse");
    if (y1>n || y1<0 || y2>n || y2<0) throw CCoordException("Ellipse");
    
    Ellipse l( x1,y1,x2,y2);
    
    l.show( *hdc );
    
    
}
void interpretator::set_Rectangle( devicePlot* hdc, vector<string> a){
    cout << "Rect " << a.size() << endl;  
    if ( a.size() != 10) {
        cout << " Error in Rectangle " << endl;
        return;
    }    
    
    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    int x2 = atoi(a[6].c_str());
    int y2 = atoi(a[8].c_str());
    
    if (x1>m || x1<0 || x2>m || x2<0) throw CCoordException("Rectangle");
    if (y1>n || y1<0 || y2>n || y2<0) throw CCoordException("Rectangle");
    Rectangle l(x1,y1,x2,y2);
    
    l.show( *hdc);
    
}