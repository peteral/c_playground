#include <stdio.h>
#include "filter.h"

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