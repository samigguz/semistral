/* 
 * File:   parser.h
 * Author: andrew
 *
 * Created on 4 Июнь 2015 г., 3:04
 */

#ifndef PARSER_H
#define	PARSER_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class parser {
    
  vector<string> tokens;
  
public:
  
  vector<string> terminators;
  
 
  void addTerminator( string rez ) { terminators.push_back( rez ); }
  
  void flush(string &rez) {
    if ( rez.size() > 0 ) {
      tokens.push_back( rez );
      rez="";
    } 
  }
  
  bool testTerminators( string rez ) {
    for (unsigned int i=0; i < terminators.size(); i++) {
      if ( terminators[i] == rez ) return true;
    }
    return false;
  }
  
  vector<string> doParsing( string str ) { 
    tokens.clear();
    string rez; 
     for (unsigned int i=0; i < str.size(); i++) {
       
       if ( str[i]==' ' ) {
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
  
  
  string getTerm(char t ) {
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
  
  
  void initTerms() {
   addTerminator(":");
   addTerminator(",");
   addTerminator("(");
   addTerminator(")");
  
  }


    parser();
    parser(const parser& orig);
    virtual ~parser();
private:

};

#endif	/* PARSER_H */

