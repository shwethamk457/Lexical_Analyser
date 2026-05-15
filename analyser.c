#include "header.h"

extern int error_flag = 0;

/* Keywords */
char* keyword[] = {
    "goto","char","int","float","double","break","continue","return",
    "if","else","while","void","for","do","switch","case","default",
    "typedef","struct","union","enum","extern","static","volatile",
    "const","unsigned","signed","short","long","NULL","sizeof",
    "auto","register"
};

/* Token sets */
char operator[] = {'+','-','/','%','^','!','~','*',','};
char symbol[]   = {'{','}','[',']'};
char special[]  = {'(',')',';'};
char delim[]    = {'\n','\t',' '};

/* ================= MAIN ANALYZER ================= */

void lexical_analyze(FILE* fptr)
{
    char line[150];

    while(fscanf(fptr, "%[^\n]\n", line) != EOF)
    {
        if(line[0] == '#')
        {
            printf("\nHeader file detected\n");
            continue;
        }
        check_type(line);
    }
}

/* ================= TOKEN ANALYSIS ================= */

void check_type(char* line)
{
    char *temp = line;
    char arr[50];

    while(*temp)
    {
        if(strchr(delim, *temp))
        {
            temp++;
            continue;
        }

        int i = 0;

        /* STRING */
        if(*temp == '"')
        {
            temp++;
            while(*temp && *temp != '"')
                arr[i++] = *temp++;

            arr[i] = '\0';
            printf("%-20s : STRING\n", arr);

            if(*temp == '"') temp++;
            continue;
        }

        /* CHARACTER */
        if(*temp == '\'')
        {
            temp++;
            arr[i++] = *temp++;

            if(*temp == '\'')
            {
                printf("%-20c : CHAR\n", arr[0]);
                temp++;
            }
            else
            {
                printf("ERROR: Invalid character\n");
                error_flag = 1;
            }
            continue;
        }

        /* OPERATORS */
        if(is_operator(*temp))
        {
            printf("%-20c : OPERATOR\n", *temp++);
            continue;
        }

        /* SPECIAL */
        if(is_special(*temp))
        {
            printf("%-20c : SPECIAL\n", *temp++);
            continue;
        }

        /* ASSIGNMENT */
        if(is_assignment(*temp))
        {
            printf("%-20c : ASSIGNMENT\n", *temp++);
            continue;
        }

        /* SYMBOL */
        if(is_symbol(*temp))
        {
            printf("%-20c : SYMBOL\n", *temp++);
            continue;
        }

        /* WORD / NUMBER */
        while(*temp && !strchr(delim,*temp) &&
              !is_operator(*temp) &&
              !is_special(*temp) &&
              !is_symbol(*temp) &&
              !is_assignment(*temp))
        {
            arr[i++] = *temp++;
        }

        arr[i] = '\0';

        if(strlen(arr) > 0)
        {
            if(is_keyword(arr)) continue;
            if(is_digit(arr)) continue;
            if(is_bin(arr)) continue;
            if(is_octal(arr)) continue;
            if(is_hexa(arr)) continue;

            printf("%-20s : IDENTIFIER\n", arr);
        }
    }
}

/* ================= SUPPORT FUNCTIONS ================= */

int is_keyword(char* token)
{
    for(int i=0;i<32;i++)
    {
        if(strcmp(token, keyword[i]) == 0)
        {
            printf("%-20s : KEYWORD\n", token);
            return 1;
        }
    }
    return 0;
}

int is_digit(char* token)
{
    int dot = 0;

    for(int i=0;i<strlen(token);i++)
    {
        if(token[i] == '.') dot++;
        else if(token[i] < '0' || token[i] > '9')
            return 0;
    }

    if(dot == 0)
        printf("%-20s : INTEGER\n", token);
    else if(dot == 1)
        printf("%-20s : FLOAT\n", token);
    else
    {
        printf("ERROR: Invalid number %s\n", token);
        error_flag = 1;
    }

    return 1;
}

int is_operator(char ch)
{
    for(int i=0;i<9;i++)
        if(ch == operator[i]) return 1;
    return 0;
}

int is_assignment(char ch)
{
    return (ch == '=');
}

int is_symbol(char ch)
{
    for(int i=0;i<4;i++)
        if(ch == symbol[i]) return 1;
    return 0;
}

int is_special(char ch)
{
    for(int i=0;i<3;i++)
        if(ch == special[i]) return 1;
    return 0;
}

int is_bin(char* num)
{
    if(strncmp(num,"0b",2)==0)
    {
        printf("%-20s : BINARY\n", num);
        return 1;
    }
    return 0;
}

int is_octal(char* num)
{
    if(num[0]=='0' && num[1] != 'x')
    {
        printf("%-20s : OCTAL\n", num);
        return 1;
    }
    return 0;
}

int is_hexa(char* num)
{
    if(strncmp(num,"0x",2)==0)
    {
        printf("%-20s : HEXADECIMAL\n", num);
        return 1;
    }
    return 0;
}