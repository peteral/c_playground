#include <stdio.h>
#include "filter.h"

int main(int argc, const char* argv[]) {
    return filter(argc, argv, stdin, stdout);
}