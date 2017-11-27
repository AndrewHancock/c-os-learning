#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "err_msg.h"

static void outputError(const char *format, va_list ap) {
#define ERR_BUF_SIZE 500
  char buf[ERR_BUF_SIZE], userMsg[ERR_BUF_SIZE], errText[ERR_BUF_SIZE];
  
  vsnprintf(userMsg, ERR_BUF_SIZE, format, ap);
  
  fflush(stdout);
  fputs(buf, stderr);
  fflush(stderr);

}

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
  
  va_start(argList, format);
  outputError(format, argList);
  va_end(argList);

  exit(EXIT_FAILURE);  
}

void fatal(const char *format, ...) {
  va_list argList;

  va_start(argList, format);
  outputError(format, argList);
  va_end(argList);

  exit(EXIT_FAILURE);  
}
