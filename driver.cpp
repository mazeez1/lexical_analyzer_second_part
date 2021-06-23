//*****************************************************************************
// CSE 4713 / 6713 Assignment 2 Driver File
// Copyright: Mississippi State University
//*****************************************************************************
#include <stdio.h>
#include "lexer.h"

extern "C"
{
// Instantiate global variables
extern FILE *yyin;         // input stream
extern FILE *yyout;        // output stream
extern int   yyleng;       // length of current lexeme
extern char *yytext;       // text of current lexeme
extern int   yylex();      // the generated lexical analyzer
}

// Do the analysis
int main( int argc, char* argv[] )
{
  int token;   // hold each token code

  // Set the input and output streams
  yyin = stdin;
  yyout = stdout;
 
  // Do the lexical parsing
  while( (token = yylex()) && token != TOK_EOF ) 
  {
    // What did we find?
    printf("lexeme: |%s|, length: %d, token: %d\n", yytext, yyleng, token);
    if( token == TOK_UNKNOWN ) printf("   ERROR: unknown token\n");
  }
}
