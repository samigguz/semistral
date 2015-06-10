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
    
private:
    
  vector<string> tokens;
  vector<string> terminators;
   
public:
  
 
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
   addTerminator("\'");
  }


    parser();
    parser(const parser& orig);
    virtual ~parser();
  
  void addTerminator( string rez );
  void flush(string &rez);
  void initTerms();
  bool testTerminators( string );
  
  vector<string> doParsing( string );
  string getTerm(char t );
 };

#endif	/* PARSER_H */

