/* 
 * File:   parser.cpp
 * Author: andrew
 * 
 * Created on 4 Июнь 2015 г., 3:04
 */

#include "parser.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
parser::parser() {
}

parser::parser(const parser& orig) {
}

parser::~parser() {
}

void parser::addTerminator( string rez ) { terminators.push_back( rez ); }
  
  

