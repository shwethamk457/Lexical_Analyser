#ifndef SAMPLE_H
#define SAMPLE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Global Variable Declaration */
extern int error_flag;

/* Function Declarations */
void lexical_analyze(FILE *fptr);
void check_type(char *line);

/* Token Checking Functions */
int is_keyword(char *token);
int is_number(char *token);

int is_operator(char ch);
int is_special(char ch);
int is_symbol(char ch);
int is_assignment(char ch);

/* Number Type Functions */
int is_bin(char *num);
int is_octal(char *num);
int is_hexa(char *num);

#endif