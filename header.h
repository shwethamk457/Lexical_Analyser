#ifndef HEADER_H      
#define HEADER_H

/* Standard Library Includes */
#include <stdio.h>
#include <string.h>

/* ================= FUNCTION DECLARATIONS ================= */

/* Main function to perform lexical analysis on input file */
void lexical_analyze(FILE *fptr);

/* Function to identify and print token type */
void check_type(char *token);

/* Check if token is a keyword */
int is_keyword(char *token);

/* Check if token is a digit/number */
int is_digit(char *token);

/* Check if character is a special symbol */
int is_special(char ch);

/* Check if character is an operator (+, -, *, etc.) */
int is_operator(char token);

/* Check if character is assignment operator (=) */
int is_assignment(char ch);

/* Check if character is a symbol (like ; , () etc.) */
int is_symbol(char ch);

/* Check if number is octal */
int is_octal(char *number);

/* Check if number is binary */
int is_bin(char *number);

/* Check if number is hexadecimal */
int is_hexa(char *number);

#endif   // End of HEADER_H