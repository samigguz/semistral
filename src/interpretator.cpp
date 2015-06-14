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
#include <string>
#include "interpretator.h"
#include "parser.h"
#include "devicePlot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "CCoordException.h"
#include "deviceColorPlot.h"

using namespace std;

interpretator::interpretator():numberOfLine(0) {
    this->init_Lang();
    
    this->patternMode = false;
    this->saveHDC = NULL;
    this->patternHDC = NULL;
    
}

interpretator::interpretator(string fNameIn, string fNameOut):numberOfLine(0) {
    this->fileNameIn = fNameIn;
    this->fileNameOut= fNameOut;
    this->init_Lang();
    
    this->patternMode = false;
    this->saveHDC = NULL;
    this->patternHDC = NULL;
    
}

void interpretator::init_Lang(){
    
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
    
    //Poliline
    lang["beginPoliline"]=&interpretator::set_beginPoliLine;
    lang["showPoliline"]=&interpretator::set_showPoliLine;
    lang["poliLineAdd"]=&interpretator::set_poliLineAdd;
    
    //pattern
    lang["beginPattern"]=&interpretator::set_beginPattern;
    lang["endPattern"]=&interpretator::set_endPattern;
    lang["copyPattern"]=&interpretator::set_copyPattern;
    
}


void interpretator::check_Limits(int X, int Y) {
  if ( !this->patternMode ) {  
    if (X>=maxX || X<0 || Y>=maxY || Y<0) throw CCoordException(line,numberOfLine,"---OutOfRange");
  } else {
    if (X>=this->patternMaxX || X<0 || Y>=this->patternMaxY || Y<0) throw CCoordException(line,numberOfLine,"---Pattern OutOfRange");  
  }  
}

void interpretator::doIt() {
    ifstream fin;
    string error;
    fin.open(fileNameIn.c_str());
    if (!fin.is_open())
    {
        error="Couldn't open the file \"";

        error+=fileNameIn;error+="\".";
        throw CCoordException(error);
    }
    ofstream fout;
    fout.open(fileNameOut.c_str());
    if (!fout.is_open())
    {
        error="Couldn't open the file \"";
        error+=fileNameOut;error+="\".";
        throw CCoordException(error);
    }
    
    parser par;
    par.initTerms();
    
    
    
    
    bool start = true;
    
    while ( !fin.eof()) {
      string s;
      getline(fin,s);
      numberOfLine++;
      line=s;
      //del comments
      size_t pos = s.find_first_of("//");
      if ( pos != string::npos) {
          s.erase(pos, s.size()-pos);
      }
      vector<string> tokens = par.doParsing(s);
      if ( tokens.size() == 0) continue;
      
      if ( start) { 
         if (  tokens[0] != "setSize") {
          throw CCoordException("Error! Not set size.");
         } else {
             start = false;
             hdc = this->set_devicePlot( tokens );
             
             if ( hdc == NULL ) {
                 throw CCoordException(line,numberOfLine," not defined size ");
             }
             hdc->tmp = "global";
             
         }
      }  else {
        
          if ( lang.find(tokens[0]) != lang.end() ) {
            //if the token exists, call the appropriate function
            (this->*lang[tokens[0]])(hdc, tokens);  
              
          } else {
            //if the token doesn't exist
            throw CCoordException(line,numberOfLine,"not defined");   
          }
        
      } 
      
      
    }
    
    hdc->print(fout);
    
    fout.close();
    fin.close();
    
}

devicePlot* interpretator::set_devicePlot(vector<string> a) {
    
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


interpretator::~interpretator() {
    delete hdc;
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
       //special case when only one point
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
    if ( a.size() != 6) {
        throw CCoordException(line,numberOfLine);
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
    
    hdc->Brush=a[3][0];
    
}
void interpretator::set_Pen( devicePlot* hdc, vector<string> a)
{ 
    if ( a.size() != 6) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
    hdc->Pen=a[3][0];
}

void interpretator::set_setColor( devicePlot* hdc, vector<string> a)
{ 
    if ( a.size() != 4 && a.size()!=6) {
        
        throw CCoordException(line,numberOfLine);
    }    
    if (a.size()==6 && (a[2]!="\"" || a[4]!="\""))  throw CCoordException(line,numberOfLine);
    if (a.size()==4 && a[2].size()>1) throw CCoordException(line,numberOfLine);
    if (a.size()==4) hdc->setColor( a[2]);
    else hdc->setColor( a[3]);
}

void interpretator::set_clearBrush( devicePlot* hdc, vector<string> a)
{
    if ( a.size() != 1) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
    hdc->Brush=' ';
    
}
void interpretator::set_clearPen( devicePlot* hdc, vector<string> a)
{
    if ( a.size() != 1) {
        throw CCoordException(line,numberOfLine);
        return;
    }    
  
    hdc->Pen='*';
    
}
void interpretator::set_Line( devicePlot* hdc, vector<string> a){
   
    if ( a.size() != 10) {
        throw CCoordException(line,numberOfLine);
    }    
    
    if (!isDigit(a[2]) || !isDigit(a[4]) ||!isDigit(a[6]) ||!isDigit(a[8])) throw CCoordException(line,numberOfLine," bad coordinates");
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


void interpretator::set_beginPattern( devicePlot* hdc, vector<string> a){
    //if we recall "beginPattern" but have not closed the previous pattern
    if ( this->patternMode ) throw CCoordException(line,numberOfLine," active patternMode");
    
    if ( a.size() != 6) { 
      throw CCoordException(line,numberOfLine);
      
    }  
  
  if (!isDigit(a[2])||!isDigit(a[4])) throw CCoordException(line,numberOfLine);
  int x = atoi(a[2].c_str());
  int y = atoi(a[4].c_str());
  
  this->patternMaxX = x;
  this->patternMaxY = y;
  
  //delete
  if ( this->patternHDC != NULL) delete this->patternHDC;
  
  this->hdc->tmp = "global";
  //set the operation mode in patern
  this->patternMode = true;
  //keep the device context
  this->saveHDC =  this->hdc;
  
  //replace the global hdc to the pattern
  this->hdc = new deviceColorPlot(x,y);
  
  this->hdc->tmp = "pattern";
  // duplicate patternHDC
  // it stores patern
  this->patternHDC = this->hdc; 
  
  
}

void interpretator::set_endPattern( devicePlot* hdc, vector<string> a){
  
  if ( !this->patternMode ) throw CCoordException(line,numberOfLine,"close not opened Pattern");  
  
  if ( a.size() != 1) { 
      throw CCoordException(line,numberOfLine);
   }  
  
  // restoring the old
  this->hdc = this->saveHDC;
 
  
  this->patternMode = false;
}

void interpretator::set_copyPattern( devicePlot* hdc, vector<string> a){
    
   if ( this->patternMode ) throw CCoordException(line,numberOfLine,"active Pattern mode!");  
  
  if ( a.size() != 6) { 
      throw CCoordException(line,numberOfLine);
   }  
   
   if (!isDigit(a[2])||!isDigit(a[4])) throw CCoordException(line,numberOfLine);
   int x = atoi(a[2].c_str());
   int y = atoi(a[4].c_str());   
  
   for(int i=0; i < this->patternMaxY; i++) {
      for(int j=0; j < this->patternMaxX; j++) { 
         //read from patern
          char point = this->patternHDC->getPixel(j,i);
          this->hdc->Color = this->patternHDC->getColor(j,i);
          if (this->patternHDC->array[i][j]!=' ') hdc->putPixel(x + j,y + i,point);
       }
       
   }
  
   
   
}


 bool interpretator::isDigit(string &a)
 {
     
     if (a=="") return false;
     for (unsigned i=0;i<a.size();i++)
         if (!isdigit(a[i])) return false;
     
     return true;
     
 }

 
