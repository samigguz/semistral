/**
 * @file   interpretator.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    interpretator.h for declaration.
 */
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include "interpretator.h"
#include "parser.h"
#include "devicePlot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "CCoordException.h"
#include "deviceColorPlot.h"

using namespace std;

//vychozi nastaveni Brush na mezeru a Pen na hvezdicku
interpretator::interpretator():Brush(' '),Pen('*'),numberOfLine(0) {
    this->init_Lang();
}

interpretator::interpretator(string fNameIn, string fNameOut):Brush(' '),Pen('*'),numberOfLine(0) {
    this->fileNameIn = fNameIn;
    this->fileNameOut= fNameOut;
    this->init_Lang();
}

void interpretator::init_Lang(){
    //lang["setSize"]=set_devicePlot;
    lang["useBrush"]=&interpretator::set_Brush;
    lang["usePen"]=&interpretator::set_Pen;
    lang["setColor"]=&interpretator::set_setColor;
        
    lang["clearBrush"]=&interpretator::set_clearBrush;
    lang["Line"]=&interpretator::set_Line;
    lang["Rectangle"]=&interpretator::set_Rectangle;
    lang["Square"]=&interpretator::set_Rectangle;
        
    lang["Point"]=&interpretator::set_Point;
    lang["Ellipse"]=&interpretator::set_Ellipse;
    lang["Circle"]=&interpretator::set_Ellipse;
    lang["clearPen"]=&interpretator::set_clearPen;
    
    //PolilIne
    lang["beginPoliline"]=&interpretator::set_beginPoliLine;
    lang["showPoliline"]=&interpretator::set_showPoliLine;
    lang["poliLineAdd"]=&interpretator::set_poliLineAdd;
    
}


void interpretator::check_Limits(int X, int Y) {
    string sout = line + "---OutOfRange";
    if (X>=maxX || X<0 || Y>=maxY || Y<0) throw CCoordException(sout,numberOfLine);
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
      numberOfLine++;
      line=s;
      ///<del comments
      size_t pos = s.find_first_of("//");
      if ( pos != string::npos) {
          s.erase(pos, s.size()-pos);
          cout <<s << endl;
      }
      vector<string> tokens = par.doParsing(s);
      if ( tokens.size() == 0) continue;
      
      if ( start) { 
         if (  tokens[0] != "setSize") {
          cout << " Error! Not set size" << endl;
          exit;
         } else {
             start = false;
             hdc = this->set_devicePlot( tokens );
             if ( hdc == NULL ) {
                 throw CCoordException(line,numberOfLine," not defined size ");
                 //cout << "error init devicePlot " << endl;
            //     exit;
             }
         }
      }  else {
        
          if ( lang.find(tokens[0]) != lang.end() ) {
            //если есть такой токен то вызываем ссответсвующую функцию
            (this->*lang[tokens[0]])(hdc, tokens);  
              
          } else {
            //если токен не известен вызываем ошибку  
            throw CCoordException(line,numberOfLine," not defined");   
          }
        
      } 
      
      
    }
    
    hdc->print();
    
    fout.close();
    fin.close();
    
}



/*

void interpretator::doIt2() {
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
      numberOfLine++;
      line=s;
      ///<del comments
      size_t pos = s.find_first_of("//");
      if ( pos != string::npos) {
          s.erase(pos, s.size()-pos);
          cout <<s << endl;
      }
      vector<string> tokens = par.doParsing(s);
      if ( tokens.size() == 0) continue;
      
      if ( start) { 
         if (  tokens[0] != "setSize") {
          cout << " Error! Not set size" << endl;
          exit;
         } else {
             start = false;
             hdc = this->set_devicePlot( tokens );
             if ( hdc == NULL ) {
                 throw CCoordException(line,numberOfLine);
                 //cout << "error init devicePlot " << endl;
                 exit;
             }
         }
      }  else {
        
        if ( tokens[0] == "useBrush") set_Brush( hdc, tokens);
        if ( tokens[0] == "usePen") set_Pen( hdc, tokens);
        if ( tokens[0] == "setColor") set_setColor( hdc, tokens);
        
        if ( tokens[0] == "clearBrush") set_clearBrush( hdc, tokens);
        if ( tokens[0] == "Line") set_Line( hdc, tokens);
        if ( tokens[0] == "Rectangle" ||tokens[0] == "Square" ) set_Rectangle( hdc, tokens);
        
        if ( tokens[0] == "Point") set_Point( hdc, tokens);
        if ( tokens[0] == "Ellipse" || tokens[0] == "Circle" ) set_Ellipse( hdc, tokens);
        if ( tokens[0] == "clearPen" ) set_clearPen( hdc, tokens);
        
      } 
      
      
    }
    
    hdc->print();
    
    fout.close();
    fin.close();
    
}
*/
devicePlot* interpretator::set_devicePlot(vector<string> a) {
  cout << a.size() << endl;  
  if ( a.size() != 6) { 
      throw CCoordException(line,numberOfLine);
      return NULL;
  }  
  
  if (!isDigit(a[2])||!isDigit(a[4])) throw CCoordException(line,numberOfLine);
  int x = atoi(a[2].c_str());
  int y = atoi(a[4].c_str());
  if (x<=0 || x>1000 || y>1000|| y<=0 ) throw CCoordException(line,numberOfLine);
  set_size(x,y);
  return new deviceColorPlot(x,y);
}
void interpretator::set_size(int X,int Y)
{
    maxX=X;
    maxY=Y;
}

interpretator::interpretator(const interpretator& orig) {
}

interpretator::~interpretator() {
}




void interpretator::set_beginPoliLine( devicePlot* hdc, vector<string> a)
{ 
    
    if ( a.size() != 1) {
        throw CCoordException(line,numberOfLine);
    }    
    
    this->poliPoints.clear();
    
}

void interpretator::set_showPoliLine( devicePlot* hdc, vector<string> a)
{ 
    
    if ( a.size() != 1) {
        throw CCoordException(line,numberOfLine);
    }    
    
   if ( this->poliPoints.size() == 1 )  {
       //особый случай когда одна точка
       poliPoints[0].show( hdc );
   }
    
   if ( this->poliPoints.size() > 1 )  { 
     Line l;
     for( int i=0; i<poliPoints.size()-1;i++) {
        l.setCoordinates( poliPoints[i].getX(), 
                          poliPoints[i].getY(), 
                          poliPoints[i+1].getX(), 
                          poliPoints[i+1].getY()
                        ); 
       l.show(hdc); 
     }
       
   }
    
}

void interpretator::set_poliLineAdd( devicePlot* hdc, vector<string> a)
{ 
    cout << " poliadd " << poliPoints.size() << endl; 
    if ( a.size() != 6) {
        throw CCoordException(line,numberOfLine," bad syntax");
    }    
    int x =  atoi( a[2].c_str());
    int y =  atoi( a[4].c_str());
    plotPoint b(x,y);
    poliPoints.push_back( b );
    
}




void interpretator::set_Brush( devicePlot* hdc, vector<string> a)
{ 
    
    if ( a.size() != 6) {
        throw CCoordException(line,numberOfLine);
    }    
    
    Brush=a[3][0];

    hdc->Brush=Brush;
    
}
void interpretator::set_Pen( devicePlot* hdc, vector<string> a)
{ 
    if ( a.size() != 6) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
    
    
    Pen=a[3][0];
    
    hdc->Pen=Pen;
}

void interpretator::set_setColor( devicePlot* hdc, vector<string> a)
{ 
    if ( a.size() != 4) {
        throw CCoordException(line,numberOfLine);
    }    
    cout << atoi( a[2].c_str()) << endl;
    
    hdc->setColor( atoi( a[2].c_str()) );
}

void interpretator::set_clearBrush( devicePlot* hdc, vector<string> a)
{
    if ( a.size() != 1) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
    
    Brush=' ';
    hdc->Brush=Brush;
    
}
void interpretator::set_clearPen( devicePlot* hdc, vector<string> a)
{
    if ( a.size() != 1) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
    
    Pen='*';
    hdc->Pen=Pen;
    
}
void interpretator::set_Line( devicePlot* hdc, vector<string> a){
   
    if ( a.size() != 10) {
        throw CCoordException(line,numberOfLine);
    }    
    
    if (!isDigit(a[2]) || !isDigit(a[4]) ||!isDigit(a[6]) ||!isDigit(a[8])) throw CCoordException(line,numberOfLine);
    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    int x2 = atoi(a[6].c_str());
    int y2 = atoi(a[8].c_str());
    
    check_Limits(x1,y1);
    check_Limits(x2,y2);
    
    Line l(x1,y1,x2,y2);
    
    l.show( hdc );
    
}
void interpretator::set_Point(devicePlot* hdc, vector<string> a)
{
     
    if ( a.size() != 6) {
        throw CCoordException(line,numberOfLine);
    }    
    
    if (!isDigit(a[2]) || !isDigit(a[4])) throw CCoordException(line,numberOfLine);

    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    
    check_Limits(x1,y1);
    
    
    plotPoint l( x1, y1);
    
    l.show( hdc );
    
    
}
void interpretator::set_Ellipse(devicePlot* hdc, vector<string> a)
{
     
    if ( a.size() != 10) {
       throw CCoordException(line,numberOfLine);
    }    
    if (!isDigit(a[2]) || !isDigit(a[4]) ||!isDigit(a[6]) ||!isDigit(a[8])) throw CCoordException(line,numberOfLine);

    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    int x2 = atoi(a[6].c_str());
    int y2 = atoi(a[8].c_str());
    
    check_Limits(x1,y1);
    check_Limits(x2,y2);
    
    
    Ellipse l( x1,y1,x2,y2);
    
    if (hdc->Brush!=' ') l.fill( hdc,hdc->Brush);
    l.show( hdc);
}
void interpretator::set_Rectangle( devicePlot* hdc, vector<string> a){
    cout << a.size() << endl;
    if ( a.size() != 10) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
    
    if (!isDigit(a[2]) || !isDigit(a[4]) ||!isDigit(a[6]) ||!isDigit(a[8])) throw CCoordException(line,numberOfLine);

    int x1 = atoi(a[2].c_str());
    int y1 = atoi(a[4].c_str());
    int x2 = atoi(a[6].c_str());
    int y2 = atoi(a[8].c_str());
    
    check_Limits(x1,y1);
    check_Limits(x2,y2);
    
    Rectangle l(x1,y1,x2,y2);
    
    if (hdc->Brush!=' ') l.fill(x1,y1,x2,y2,hdc);
    l.show( hdc);
    
}


 bool interpretator::isDigit(string &a)
 {
     
     if (a=="") return false;
     for (unsigned i=0;i<a.size();i++)
         if (!isdigit(a[i])) return false;
     
     return true;
     
 }