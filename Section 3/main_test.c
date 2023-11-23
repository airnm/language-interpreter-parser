#include "token.h"
// https://github.com/sheredom/utest.h/blob/master/utest.h
#include "utest.h"
#include <stdio.h>

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern int yyrestart(FILE *);
extern YY_BUFFER_STATE yy_scan_buffer(char *str, int i);
extern YY_BUFFER_STATE yy_scan_string(char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern FILE *yyin;
extern int yylex();
extern char *yytext;

UTEST_MAIN();

struct token_st
{
  token_t t;
  char *p;
};

UTEST(scanner, identifier)
{
  token_t t;
  // Must include the null character to terminate input
  char string[] = "test\0";
  YY_BUFFER_STATE buffer = yy_scan_buffer(string, sizeof(string));

  ASSERT_EQ(TOKEN_IDENT, (t = yylex()));
  ASSERT_STREQ("test", yytext);

  ASSERT_EQ(TOKEN_EOF, (t = yylex()));
  ASSERT_STREQ("", yytext);

  yy_delete_buffer(buffer);
}

UTEST(scanner, assignment)
{
  token_t t;
  // Must include the null character to terminate input
  char string[] = "=\0";
  YY_BUFFER_STATE buffer = yy_scan_buffer(string, sizeof(string));

  ASSERT_EQ(TOKEN_EQUAL, (t = yylex()));
  ASSERT_STREQ("=", yytext);

  ASSERT_EQ(TOKEN_EOF, (t = yylex()));
  ASSERT_STREQ("", yytext);

  yy_delete_buffer(buffer);
}

UTEST(scanner, Quadractic_Function)
{
  struct token_st tokens[] = {
      {TOKEN_IMPORT, "import"},
      {TOKEN_STRING, "\"dart:math\""},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_VOID, "void"},
      {TOKEN_IDENT, "main"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "a"},
      {TOKEN_EQUAL, "="},
      {TOKEN_NUMBER, "1"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "b"},
      {TOKEN_EQUAL, "="},
      {TOKEN_SUB, "-"},
      {TOKEN_NUMBER, "5"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "c"},
      {TOKEN_EQUAL, "="},
      {TOKEN_NUMBER, "6"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "discriminant"},
      {TOKEN_EQUAL, "="},
      {TOKEN_IDENT, "b"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "b"},
      {TOKEN_SUB, "-"},
      {TOKEN_NUMBER, "4"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "a"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "c"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IF, "if"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "discriminant"},
      {TOKEN_GREATER, ">"},
      {TOKEN_NUMBER, "0"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "root"},
      {TOKEN_NUMBER, "1"},
      {TOKEN_EQUAL, "="},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "b"},
      {TOKEN_ADD, "+"},
      {TOKEN_IDENT, "sqrt"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "discriminant"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SLASH, "/"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_NUMBER, "2"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "a"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "root"},
      {TOKEN_NUMBER, "2"},
      {TOKEN_EQUAL, "="},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "b"},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "sqrt"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "discriminant"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SLASH, "/"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_NUMBER, "2"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "a"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},

      {TOKEN_STRING,"\"Root 1: $root1\""},
      {TOKEN_PARENTHESES2, ")"},

      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},

      {TOKEN_STRING,"\"Root 2: $root2\""},


      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_ELSE, "else"},
      {TOKEN_IF, "if"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "discriminant"},
      {TOKEN_EQUAL, "="},
      {TOKEN_EQUAL, "="},
      {TOKEN_NUMBER, "0"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "root"},
      {TOKEN_EQUAL, "="},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "b"},
      {TOKEN_SLASH, "/"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_NUMBER, "2"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "a"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_STRING, "\"Root: $root\""},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_ELSE, "else"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "realPart"},
      {TOKEN_EQUAL, "="},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "b"},
      {TOKEN_SLASH, "/"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_NUMBER, "2"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "a"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_DOUBBLE, "double"},
      {TOKEN_IDENT, "imaginaryPart"},
      {TOKEN_EQUAL, "="},
      {TOKEN_IDENT, "sqrt"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "discriminant"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SLASH, "/"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_NUMBER, "2"},
      {TOKEN_MULTIPLY, "*"},
      {TOKEN_IDENT, "a"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_STRING, "\"Root 1: $realPart + ${imaginaryPart}i\""},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_STRING, "\"Root 2: $realPart - ${imaginaryPart}i\""},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_BRACKET2, "}"}, // Quadractic_Function.dart ends
      {TOKEN_EOF, ""}        // End of file
  };

  yyin = fopen("samples/Quadratic_Function.dart", "r");
  yyrestart(yyin);
  ASSERT_TRUE(yyin);

  int index = 0;
  token_t t;
  do
  {
    // t = yylex();
    // printf ("<>%d<>",index);
    // printf("<>%d %d %s<>",index, tokens[index].t, tokens[index].p);
    // EXPECT_TRUE_MSG(tokens[index].t == t, itoa(index));  // pass!
    ASSERT_EQ(tokens[index].t, (t = yylex()));
    ASSERT_STREQ(tokens[index].p, yytext);
    ++index;
  } while (t != TOKEN_EOF);
}

UTEST(scanner, sorting_algorithm)
{
  struct token_st tokens[] = {
      {TOKEN_VOID, "void"},
      {TOKEN_IDENT, "bubbleSort"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "List"},
      {TOKEN_LESS, "<"},
      {TOKEN_INT, "int"},
      {TOKEN_GREATER, ">"},
      {TOKEN_IDENT, "arr"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_INT, "int"},
      {TOKEN_IDENT, "n"},
      {TOKEN_EQUAL, "="},
      {TOKEN_IDENT, "arr"},
      {TOKEN_DOT, "."},
      {TOKEN_IDENT, "length"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_FOR, "for"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_INT, "int"},
      {TOKEN_IDENT, "i"},
      {TOKEN_EQUAL, "="},
      {TOKEN_NUMBER, "0"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "i"},
      {TOKEN_LESS, "<"},
      {TOKEN_IDENT, "n"},
      {TOKEN_SUB, "-"},
      {TOKEN_NUMBER, "1"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "i"},
      {TOKEN_ADD, "+"},
      {TOKEN_ADD, "+"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_FOR, "for"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_INT, "int"},
      {TOKEN_IDENT, "j"},
      {TOKEN_EQUAL, "="},
      {TOKEN_NUMBER, "0"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "j"},
      {TOKEN_LESS, "<"},
      {TOKEN_IDENT, "n"},
      {TOKEN_SUB, "-"},
      {TOKEN_IDENT, "i"},
      {TOKEN_SUB, "-"},
      {TOKEN_NUMBER, "1"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "j"},
      {TOKEN_ADD, "+"},
      {TOKEN_ADD, "+"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_IF, "if"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "arr"},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_IDENT, "j"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_GREATER, ">"},
      {TOKEN_IDENT, "arr"},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_IDENT, "j"},
      {TOKEN_ADD, "+"},
      {TOKEN_NUMBER, "1"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_INT, "int"},
      {TOKEN_IDENT, "temp"},
      {TOKEN_EQUAL, "="},
      {TOKEN_IDENT, "arr"},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_IDENT, "j"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "arr"},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_IDENT, "j"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_EQUAL, "="},
      {TOKEN_IDENT, "arr"},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_IDENT, "j"},
      {TOKEN_ADD, "+"},
      {TOKEN_NUMBER, "1"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "arr"},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_IDENT, "j"},
      {TOKEN_ADD, "+"},
      {TOKEN_NUMBER, "1"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_EQUAL, "="},
      {TOKEN_IDENT, "temp"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_VOID, "void"},
      {TOKEN_IDENT, "main"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_IDENT, "List"},
      {TOKEN_LESS, "<"},
      {TOKEN_INT, "int"},
      {TOKEN_GREATER, ">"},
      {TOKEN_IDENT, "numbers"},
      {TOKEN_EQUAL, "="},
      {TOKEN_SQUARE_BRACKET1, "["},
      {TOKEN_NUMBER, "64"},
      {TOKEN_COMMA, ","},
      {TOKEN_NUMBER, "34"},
      {TOKEN_COMMA, ","},
      {TOKEN_NUMBER, "25"},
      {TOKEN_COMMA, ","},
      {TOKEN_NUMBER, "12"},
      {TOKEN_COMMA, ","},
      {TOKEN_NUMBER, "22"},
      {TOKEN_COMMA, ","},
      {TOKEN_NUMBER, "11"},
      {TOKEN_COMMA, ","},
      {TOKEN_NUMBER, "90"},
      {TOKEN_SQUARE_BRACKET2, "]"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_STRING, "\"Original array: $numbers\""},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_IDENT, "bubbleSort"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_IDENT, "numbers"},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_STRING, "\"Sorted array: $numbers\""},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_EOF, ""}};

  yyin = fopen("samples/sorting_algorithm.dart", "r");
  yyrestart(yyin);
  ASSERT_TRUE(yyin);

  int index = 0;
  token_t t;
  do
  {
    //printf("<>%d %d %s<>",index, tokens[index].t, tokens[index].p);
    ASSERT_EQ(tokens[index].t, (t = yylex()));
    ASSERT_STREQ(tokens[index].p, yytext);
    ++index;
  } while (t != TOKEN_EOF);
}

UTEST(scanner, helloworld)
{
  struct token_st tokens[] = {
      {TOKEN_VOID, "void"},
      {TOKEN_IDENT, "main"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_BRACKET1, "{"},
      {TOKEN_PRINT, "print"},
      {TOKEN_PARENTHESES1, "("},
      {TOKEN_STRING, "\"Hello World!\""},
      {TOKEN_PARENTHESES2, ")"},
      {TOKEN_SEMICOLON, ";"},
      {TOKEN_BRACKET2, "}"},
      {TOKEN_EOF, ""}};

  yyin = fopen("samples/helloworld.dart", "r");
  yyrestart(yyin);
  ASSERT_TRUE(yyin);

  int index = 0;
  token_t t;
  do
  {
    ASSERT_EQ(tokens[index].t, (t = yylex()));
    ASSERT_STREQ(tokens[index].p, yytext);
    ++index;
  } while (t != TOKEN_EOF);
}