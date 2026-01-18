
#include <stdio.h>
#include <stdlib.h>

#include "minicsv.h"

static void
display_cols(char * const * const cols, const size_t cols_count)
{
    size_t i = (size_t) 0U;
    
    while (i < cols_count) {
        if (i != (size_t) 0U) {
            putchar('\t');
        }
        printf("[%s]", cols[i]);
        i++;
    }
    putchar('\n');
}

int
main(void)
{
    char  *cols[10];
    char   buf[] = "first,line,has,\"comas,\"\"escaped\"\" characters\",and,\"multiple\r\nlines\"\r\n"
        "second,line,\"has\",,empty,,,,columns\r\nremainder";
    char  *r = buf;
    size_t cols_count;
    
    r = minicsv_parse_line(r, cols, &cols_count, sizeof cols / sizeof cols[0]);
    if (cols_count > sizeof cols / sizeof cols[0]) {
        abort();
    }
    display_cols(cols, cols_count);
    
    r = minicsv_parse_line(r, cols, &cols_count, sizeof cols / sizeof cols[0]);
    if (cols_count > sizeof cols / sizeof cols[0]) {
        abort();
    }
    display_cols(cols, cols_count);
    
    printf("Remainder: [%s]\n", r);
    
    return 0;
}
