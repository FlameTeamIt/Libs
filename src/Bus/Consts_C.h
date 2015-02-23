#ifndef CONSTS_C
#define CONSTS_C

// all keywords
#define C_KW_AUTO      "auto"
#define C_KW_BREAK     "break"
#define C_KW_CASE      "case"
#define C_KW_CONST     "const"
#define C_KW_CONTINUE  "continue"
#define C_KW_DEFAULT   "default"
#define C_KW_DO        "do"
#define C_KW_ELSE      "else"
#define C_KW_ENUM      "enum"
#define C_KW_FOR       "for"
#define C_KW_GOTO      "goto"
#define C_KW_IF        "if"
#define C_KW_INLINE    "inline"
#define C_KW_REGISTER  "register"
#define C_KW_RESTRICT  "restrict"
#define C_KW_RETURN    "return"
#define C_KW_SIZEOF    "sizeof"
#define C_KW_STATIC    "static"
#define C_KW_STRUCT    "struct"
#define C_KW_SWITCH    "switch"
#define C_KW_TYPEDEF   "typedef"
#define C_KW_UNION     "union"
//#define C_KW_VOLATILE  "volatile"
#define C_KW_WHILE     "while"
//#define C_KW_ ""

// other
#define C_OTHER_ASM     "asm"
#define C_OTHER_FORTRAN "fortran"

// early types
#define C_ETYPE_VOID     "void"
#define C_ETYPE_SHORT    "short"
#define C_ETYPE_CHAR     "char"
#define C_ETYPE_INT      "int"
#define C_ETYPE_LONG     "long"
#define C_ETYPE_FLOAT    "float"
#define C_ETYPE_DOUBLE   "double"

#define C_ETYPE_UNSIGNED "unsigned"
#define C_ETYPE_SIGNED   "signed"

// preprocessor
#define C_PRE_IF      "#if"
#define C_PRE_ELIF    "#elif"
#define C_PRE_ELSE    "#else"
#define C_PRE_ENDIF   "#endif"
#define C_PRE_DEFINED "defined"
#define C_PRE_IFDEF   "#ifdef"
#define C_PRE_IFNDEF  "#ifndef"
#define C_PRE_DEFINE  "#define"
#define C_PRE_UNDEF   "#indef"
#define C_PRE_INCLUDE "#include"
#define C_PRE_LINE    "#line"
#define C_PRE_ERROR   "#error"
#define C_PRE_PRAGMA  "#pragma"

// operators and symbols
#define C_OP_PROGBRON  "{"
#define C_OP_PROGBROFF "}"

#define C_OP_BRON      "("
#define C_OP_BROFF     ")"

#define C_OP_BRLE      "<"
#define C_OP_BRMO      ">"
#define C_OP_EQ        "=="
#define C_OP_NEQ       "!="

#define C_OP_AMPERSANT "&"
#define C_OP_STAR      "*"
#define C_OP_PERSENT   "%"
#define C_OP_SLASH     "/"
#define C_OP_DASH      "-" // hyphen
#define C_OP_PLUS      "+"
#defile C_OP_POINT     "."
#define C_OP_ASSIGN    "="
#define C_OP_QUOTE     "\'"
#define C_OP_DQUOTE     "\""

#define C_OP_PAPPEAL   "->"
#define C_OP_APPEAL    C_OP_POINT

#endif // CONSTS_C
