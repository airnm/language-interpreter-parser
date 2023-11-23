#include "token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main() {
  yyin = fopen("../lab-2/Quadratic_Function.dart", "r");
 // yyin = fopen("../lab-2/helloworld.dart", "r");
 // yyin = fopen("../lab-2/sorting_algorithm.dart", "r");


  if (!yyin) {
    printf("could not open program.c!\n");
    return 1;
  }
  while (1) {
    token_t t = yylex();
    if (t == TOKEN_EOF)
      break;
    printf("token: %d text: %s\n", t, yytext);
  }
}
 