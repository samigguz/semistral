/**
 * @file   parser.cpp
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function implementation.
 * @see    parser.h for declaration.
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
  
void parser::flush(string &rez) {
    if ( rez.size() > 0 ) {
      tokens.push_back( rez );
      rez="";
    } 
  }

bool parser::testTerminators( string rez ) {
    for (unsigned int i=0; i < terminators.size(); i++) {
      if ( terminators[i] == rez ) return true;
    }
    return false;
  }
  

vector<string> parser::doParsing( string str ) { 
    tokens.clear();
    string rez; 
     for (unsigned int i=0; i < str.size(); i++) {
       
       if ( str[i]==' ' || str[i]=='\n' || str[i]=='\r') {
	 flush(rez);
	 continue;
       } 	 
       string a="";
       a+=str[i];
       if ( testTerminators( a) ) {
	 flush(rez);
	 tokens.push_back( a );
       } else {
	 rez += str[i];
       }
       
     } 
     
     flush(rez);
    return tokens; 
  }
  

string parser::getTerm(char t ) {
    string rez ="";
    string tt="";
    tt += t;
    vector<string>::iterator it;

    it = find (terminators.begin(), terminators.end(), tt);
    if (it != terminators.end()) {
      rez = *it;
    }
    return rez;
  }
  

void parser::initTerms() {
   addTerminator(":");
   addTerminator(",");
   addTerminator("(");
   addTerminator(")");
   addTerminator("\'");
   addTerminator("\"");
  }

