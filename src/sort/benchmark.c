#include <time.h> 

#include "benchmark.h"


int get_func_time(void (*func)(int *, int), int *array, int count)
{
  int status;
  struct timespec before, after;
  double elaps_s;
  long elaps_ns, elaps_us;


  status = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &before);
  func(array, count);
  status = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &after);
  
  elaps_s = difftime(after.tv_sec, before.tv_sec);
  elaps_ns = after.tv_nsec - before.tv_nsec;
  elaps_s = (elaps_s + ((double)elaps_ns) / 1.0e9);
  
  return (long)(elaps_s*1000000.0);
}
