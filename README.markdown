MiniCSV
=======

A tiny, fast, simple, single-file, BSD-licensed CSV parsing library in C.

Should be able to handle CSV oddities: multi-lines, escaped rows,
escaped characters in escaped rows, empty rows, rows with a variable
number of columns.

Doesn't perform any heap allocations.

Usage
-----

    #include "minicsv.h"

    char  *cols[10];
    char   buf[] = "first,line,has,\"comas,\"\"escaped\"\" characters\",and,\"multiple\r\nlines\"\r\n"
        "second,line,\"has\",,empty,,,,columns\r\nremainder";
    char  *r = buf;
    size_t cols_count;

    /* This parses the first row (which can extend to multiple lines) */
    /* and returns a pointer to the next row */
    r = minicsv_parse_line(r, cols, &cols_count, 10);
    display_cols(cols, cols_count);
    
    /* Second row */
    r = minicsv_parse_line(r, cols, &cols_count, 10);
    display_cols(cols, cols_count);

    /* Whatever is after the second row */
    printf("Remainder: [%s]\n", r);

`minicsv_parse_line()` fills up to `cols_max` pointers in `cols`, and
returns the actual number of colums in `cols_count`, then returns a
pointer to the next row.

    char * minicsv_parse_line(char * const buf, char ** const cols,
                              size_t * const cols_count_p, const size_t cols_max);

