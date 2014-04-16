
#ifndef __MINICSV_H__
#define __MINICSV_H__

#include <stddef.h>

char * minicsv_parse_line(char * const buf, char ** const cols,
                          size_t * const cols_count_p, const size_t cols_max);

void minicsv_trim_cols(char ** const cols, const size_t cols_count);

#endif
