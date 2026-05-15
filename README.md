# Lexical Analyzer in C
A simple Lexical Analyzer developed in C Programming that scans a .c source file and identifies different tokens such as:

# Keywords
Identifiers
Operators
Symbols
Special Characters
Numbers
Strings
Characters
Binary / Octal / Hexadecimal values
This project demonstrates the fundamental phase of a Compiler Design system.

# Project Overview
A Lexical Analyzer is the first phase of a compiler.
Its main job is to:
Read source code character by character
Break the code into meaningful tokens
Classify tokens into categories
This project performs lexical analysis for a C source file and prints the detected token type.

# Concepts Covered
Compiler Design	First phase of compiler
Lexical Analysis	Token generation
File Handling	Reading .c files
String Processing	Token extraction
Token Classification	Identifying token types
Pattern Matching	Keyword & number detection
Error Handling	Invalid token detection

# Features
✅ Detects Keywords
Recognizes C language keywords such as:
int
float
if
else
while
return
struct
typedef
static
volatile

✅ Detects Identifiers
Example:
marks
sum
avg
main

✅ Detects Operators
Supported operators:
+
-
*
/
%
^
!
~
,

✅ Detects Assignment Operator
=

✅ Detects Special Symbols
(
)
;

✅ Detects Symbols
{
}
[
]

✅ Detects Numbers
Supports:
Integer
Float
Binary
Octal
Hexadecimal
Examples:
123
45.67
0b1010
077
0x1A

✅ Detects Strings
"Hello World"

✅ Detects Characters
'A'
'5'

✅ Error Detection
Detects:
Invalid characters
Invalid numbers
Improper token formats

# Project Structure
Lexical-Analyzer/
│
├── main.c
├── lexical.c
├── header.h
├── sample.c
└── README.md

# File Description
File Name	Description
main.c	Program entry point
lexical.c	Lexical analyzer implementation
header.h	Function declarations
sample.c	Sample input C program
README.md	Project documentation

# Working Principle
Input C File
      │
      ▼
Read Line by Line
      │
      ▼
Break into Tokens
      │
      ▼
Check Token Type
      │
      ├── Keyword
      ├── Identifier
      ├── Operator
      ├── Number
      ├── String
      ├── Symbol
      └── Special Character
      │
      ▼
Display Token Classification

# Compilation & Execution
Linux / Ubuntu
Compile
gcc main.c lexical.c -o lexer
Run
./lexer sample.c

# Sample Input
#include <stdio.h>
int main()
{
    int a = 10;
    float b = 12.5;

    printf("Hello");

    return 0;
}

# Sample Output
Header file detected

int                  : KEYWORD
main                 : IDENTIFIER
(                    : SPECIAL
)                    : SPECIAL
{                    : SYMBOL

int                  : KEYWORD
a                    : IDENTIFIER
=                    : ASSIGNMENT
10                   : INTEGER
;                    : SPECIAL

float                : KEYWORD
b                    : IDENTIFIER
=                    : ASSIGNMENT
12.5                 : FLOAT
;                    : SPECIAL

printf               : IDENTIFIER
(                    : SPECIAL
Hello                : STRING
)                    : SPECIAL
;                    : SPECIAL

return               : KEYWORD
0                    : INTEGER
;                    : SPECIAL

}                    : SYMBOL
