#ifndef __FILTER_H
#define __FILTER_H

int read(char* text);
int matches(const char* pattern, const char* text);
int character_matches(char pattern, char text);
int find(const char* text, char pattern, int position);
const char * assert_valid_argument(int argc, const char* argv[]);
int isphone(char c);
int assert_valid_phone(const char * phone);

#endif