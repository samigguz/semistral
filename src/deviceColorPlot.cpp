/* 
 * File:   deviceColorPlot.cpp
 * Author: andrew
 * 
 * Created on 6 Июнь 2015 г., 0:46
 */

#include "deviceColorPlot.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

deviceColorPlot::deviceColorPlot():devicePlot() {
     this->default_console = "\033[0m";
     Color=0;
}

deviceColorPlot::deviceColorPlot(int n,int m):devicePlot(n,m){
    this->default_console = "\033[0m";
    colors = new int[m*n];
    for (int i=0; i< m*n; i++)
       colors[i]=0;  
    Color=0;
}

deviceColorPlot::deviceColorPlot(const deviceColorPlot& orig) {
}

deviceColorPlot::~deviceColorPlot() {
}

void deviceColorPlot::print(void)
{
    
    stringstream ss;
    string col[8];
    for (int i=0;i<8;i++) {
        ss.clear();
        ss << "\33[0;" << 30 + i << "m";
        col[i]=ss.str();
    }
    
    
	for(int i=0;i<M;i++)
	  {
	  for (int j=0;j<N;j++)
	  {
                int c = colors[i*N+j];
                if ( c >=0 && c < 8) cout<< col[c];
	  	cout<<array[i][j]<<" ";
	  }
	  cout<<endl;
	 }
     	
   cout << this->default_console << endl;	
}

