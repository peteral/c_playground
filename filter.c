#include <stdio.h>
#include <string.h>

int read(char* text);
int matches(const char* pattern, const char* text);
int character_matches(char pattern, char text);
int find(const char* text, char pattern, int position);
const char * assert_valid_argument(int argc, const char* argv[]);
int isphone(char c);
int assert_valid_phone(const char * phone);
int main(int argc, const char* argv[]) {
    const char * filter;

    if (!(filter = assert_valid_argument(argc, argv))) 
    {
        return -1;
    }

    char name[100];
    char phone[100];
    int found = 0;

    while (read(name) && read(phone))
    {
        if (!assert_valid_phone(phone))
        {
            return -2;
        }

        if (matches(filter, name) || matches(filter, phone))
        {
            printf("%s, %s\n", name, phone);
            found = -1;
        }
    }

    if (!found)
    {
        printf("Nothing found...\n");
    }

   return 0; 
}

int read(char* text) 
{
    if (!fgets(text, 100, stdin))
    {
        return 0;
    }

    int length = strlen(text);
    if (length < 2)
    {
        return 0;
    }

    text[length - 1] = 0;
    return -1;
}

int matches(const char* pattern, const char* text)
{
    int position = 0;
    while ((position = find(text, pattern[0], position)) >= 0) 
    {
        for (int i=1; i<strlen(pattern); i++)
        {
            if (character_matches(pattern[i], text[position + i]))
            {
                if (i == strlen(pattern) - 1) 
                {
                    return -1;
                }
            }
            else 
            {
                break;
            }
        }
        position++;
    }

    return 0;
}

const char * TABLE[] = (const char *[]){
    /* [0] */ "+",
    /* [1] */ "",
    /* [2] */ "abcABC",
    /* [3] */ "defDEF",
    /* [4] */ "ghiGHI",
    /* [5] */ "jklJKL",
    /* [6] */ "mnoMNO",
    /* [7] */ "pqrsPQRS",
    /* [8] */ "tuvTUV",
    /* [9] */ "wxyzWXYZ",
};

int character_matches(char pattern, char text)
{
    if (pattern <'0' || pattern > '9')
        return 0;

    if (pattern == text)
        return -1;

    const char * additional = TABLE[pattern - '0'];
    for (int i=0; i<strlen(additional); i++)
    {
        if (additional[i] == text)
        {
            return -1;
        }
    }
    return 0;
}

int find(const char* text, char pattern, int position)
{
    for (int i=position; i<strlen(text); i++)
    {
        if (character_matches(pattern, text[i]))
        {
            return i;
        }
    }

    return -1;
}

const char * assert_valid_argument(int argc, const char* argv[]) 
{
    if (argc < 2) 
    {
        printf("Syntax: filter PATTERN < seznam.txt\n");
        return NULL;
    }

    return argv[1];
}

const char * PHONE_CHARS = "+0123456789";

int isphone(char c)
{
    for (int i=0; i<strlen(PHONE_CHARS); i++)
    {
        if (c == PHONE_CHARS[i])
        {
            return -1;
        }
    }

    return 0;
}

int assert_valid_phone(const char * phone)
{
    for (int i=0; i<strlen(phone); i++)
    {
        if (!isphone(phone[i]))
        {
            printf("Invalid phone number [%s], error at position %d!", phone, i+1);
            return 0;
        }
    }

    return -1;
}