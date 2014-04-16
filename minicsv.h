
#ifndef __MINICSV_H__
#define __MINICSV_H__

#include <stddef.h>

char * minicsv_parse_line(char * const line, char ** const cols,
                          size_t * const cols_count_p, const size_t cols_max);

#endif
