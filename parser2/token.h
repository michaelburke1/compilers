#ifndef TOKEN_H
#define TOKEN_H
/* init all the TOKENs*/
enum token {
    TOKEN_ADD = 1,
    TOKEN_AND,
    TOKEN_ARRAY,
    TOKEN_BOOLEAN,
    TOKEN_CARAT,
    TOKEN_CHAR,
    TOKEN_CHAR_LITERAL,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_DECREMENT,
    TOKEN_DIGITS,
    TOKEN_DIVIDE,
    TOKEN_ELSE,
    TOKEN_EQUAL,
    TOKEN_EQUIVALENT,
    TOKEN_ERROR,
    TOKEN_FALSE,
    TOKEN_FOR,
    TOKEN_FUNCTION,
    TOKEN_GE,
    TOKEN_GT,
    TOKEN_IDENTIFIER,
    TOKEN_IF,
    TOKEN_INCREMENT,
    TOKEN_INTEGER,
    TOKEN_LBRACK,
    TOKEN_LCURLY,
    TOKEN_LE,
    TOKEN_LPAREN,
    TOKEN_LT,
    TOKEN_MODULO,
    TOKEN_MULTIPLY,
    TOKEN_NOT,
    TOKEN_NOT_EQUAL,
    TOKEN_OR,
    TOKEN_PRINT,
    TOKEN_RBRACK,
    TOKEN_RCURLY,
    TOKEN_RETURN,
    TOKEN_RPAREN,
    TOKEN_SEMI,
    TOKEN_STRING,
    TOKEN_STRING_LITERAL,
    TOKEN_SUBTRACT,
    TOKEN_TRUE,
    TOKEN_VOID,
    TOKEN_WHILE

};

typedef enum token token_t;

#endif
