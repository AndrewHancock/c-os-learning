#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "err_msg.h"

void usageErr(const char *format, ...) {
  va_list argList;
  fflush(stdout);

  fprintf(stderr, "Usage: ");
  va_start(argList, format);
  vfprintf(stderr, format, argList);
  va_end(argList);

  fflush(stderr);
  exit(EXIT_FAILURE);
}

void errExit(const char *format, ...) {
  va_list argList;
  char buf[500];  
  
  va_start(argList, format);
  snprintf(buf, 500, format, argList);
  va_end(argList);
  exit(EXIT_FAILURE);  
}
