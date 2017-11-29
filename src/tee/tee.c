#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../lib/err_msg.h"

int main(int argc, char *const argv[]) {
  int opt_result, write_flags, output_fd;
  mode_t write_mode;
  char *file_name;
  ssize_t num_read;
  char buf[1024];

  
  write_flags = O_CREAT | O_WRONLY;

  opt_result = getopt(argc, argv, "a:");

  if(opt_result == 'a' && argc == 3) {
   write_flags = write_flags |  O_APPEND;  
   file_name = optarg;
  }
  else if (argc == 2 && opt_result == -1) {
    file_name = argv[1];
  }
  else
    usageErr("[-a] filename");

  write_mode = S_IRWXU | S_IRWXG;
  output_fd = open(file_name, write_flags, write_mode);
  if(output_fd == -1) {
    errExit("Opening file %s", file_name);
  }

  while((num_read = read(STDIN_FILENO, buf, 1024)) > 0) {
    if(write(output_fd, buf, num_read) != num_read)
      fatal("Couldn't write whole buffer to file");

    if(write(STDOUT_FILENO, buf, num_read) != num_read)
      fatal("Couldn't write whole buffer to stdout");
  }

  if(num_read == -1) 
    errExit("read");

  if(close(output_fd) == -1)
    errExit("close output");

  exit(EXIT_SUCCESS);
 
}
