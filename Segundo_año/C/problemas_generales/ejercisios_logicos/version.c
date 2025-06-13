#include <stdio.h>

int main() {
    #ifdef __STDC_VERSION__
        printf("Version de C: %ld\n", __STDC_VERSION__);
    #else
        printf("Estas usando ANSI C (C89/C90)\n");
    #endif
    return 0;
}
