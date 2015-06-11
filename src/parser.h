/**
 * @file   parser.h
 * @author Samigullina Guzel
 * @date   07 June 2015
 * @brief  File containing function declaration.
 * @see    parser.cpp for implementation.
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

