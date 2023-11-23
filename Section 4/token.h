/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_WHILE = 258,             /* TOKEN_WHILE  */
    TOKEN_ADD = 259,               /* TOKEN_ADD  */
    TOKEN_SUB = 260,               /* TOKEN_SUB  */
    TOKEN_LESS = 261,              /* TOKEN_LESS  */
    TOKEN_GREATER = 262,           /* TOKEN_GREATER  */
    TOKEN_EQUAL = 263,             /* TOKEN_EQUAL  */
    TOKEN_MULTIPLY = 264,          /* TOKEN_MULTIPLY  */
    TOKEN_SQRT = 265,              /* TOKEN_SQRT  */
    TOKEN_BRACKET1 = 266,          /* TOKEN_BRACKET1  */
    TOKEN_BRACKET2 = 267,          /* TOKEN_BRACKET2  */
    TOKEN_SQUARE_BRACKET1 = 268,   /* TOKEN_SQUARE_BRACKET1  */
    TOKEN_SQUARE_BRACKET2 = 269,   /* TOKEN_SQUARE_BRACKET2  */
    TOKEN_QUOTE = 270,             /* TOKEN_QUOTE  */
    TOKEN_SEMICOLON = 271,         /* TOKEN_SEMICOLON  */
    TOKEN_COLON = 272,             /* TOKEN_COLON  */
    TOKEN_SINGLEQUOTE = 273,       /* TOKEN_SINGLEQUOTE  */
    TOKEN_DOLLARSIGN = 274,        /* TOKEN_DOLLARSIGN  */
    TOKEN_SLASH = 275,             /* TOKEN_SLASH  */
    TOKEN_COMMA = 276,             /* TOKEN_COMMA  */
    TOKEN_DOT = 277,               /* TOKEN_DOT  */
    TOKEN_DOUBLE = 278,            /* TOKEN_DOUBLE  */
    TOKEN_FOR = 279,               /* TOKEN_FOR  */
    TOKEN_IF = 280,                /* TOKEN_IF  */
    TOKEN_INT = 281,               /* TOKEN_INT  */
    TOKEN_PRINT = 282,             /* TOKEN_PRINT  */
    TOKEN_ELSE = 283,              /* TOKEN_ELSE  */
    TOKEN_IMPORT = 284,            /* TOKEN_IMPORT  */
    TOKEN_IDENT = 285,             /* TOKEN_IDENT  */
    TOKEN_NUMBER = 286,            /* TOKEN_NUMBER  */
    TOKEN_STRING = 287,            /* TOKEN_STRING  */
    TOKEN_VOID = 288,              /* TOKEN_VOID  */
    TOKEN_MAIN = 289,              /* TOKEN_MAIN  */
    TOKEN_PARENTHESES1 = 290,      /* TOKEN_PARENTHESES1  */
    TOKEN_PARENTHESES2 = 291,      /* TOKEN_PARENTHESES2  */
    TOKEN_ERROR = 292              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
