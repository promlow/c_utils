/*
 * Copyright 2019 Paul Romlow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __PRINT_UTILS_H_
#define __PRINT_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

/* To enable VPRINT
 *#define VERBOSE 1
 * to disable VPRINT
 *#define VERBOSE 0
 */
#define VERBOSE 1
#define VPRINT(msg, args...) do {                       \
  if(VERBOSE)                                           \
    printf("%s:%d (in function '%s'): " msg, __FILE__,  \
	 __LINE__, __FUNCTION__, ##args);               \
}while(0);

#define STAT_FATAL EXIT_FAILURE
#define STAT_WARN 0

#define ERR_HANDLE(stat, msg, args...) do {    \
  fprintf(stderr, msg, ##args);                \
  if(!stat) continue;                          \
  exit(stat);                                  \
}while(0);

#define FATAL(errmsg, args...) do {                               \
    ERR_HANDLE(STAT_FATAL, "FATAL %s:%d (in function '%s'): "	  \
	       errmsg, __FILE__, __LINE__, __FUNCTION__, ##args); \
  }while(0);

#define WARN(errmsg, args...) do {                              \
    ERR_HANDLE(STAT_WARN, "WARNING %s:%d (in function '%s'): "	\
	     errmsg, __FILE__, __LINE__, __FUNCTION__, ##args); \
  }while(0);


#endif /* __PRINT_UTILS_H_ */
