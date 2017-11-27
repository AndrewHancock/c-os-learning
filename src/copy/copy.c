#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../lib/err_msg.h"


int main(int argc, char *argv[]) {
  int inputFd, outputFd, openFlags;
  mode_t filePerms;
  ssize_t numRead;
  char buf[1024];

  if(argc != 3 || strcmp(argv[1], "--help") == 0)
    usageErr("%s old-file new-file\n", argv[0]);

  /* Open src file */
  inputFd = open(argv[1], O_RDONLY);
  if(inputFd == -1)
    errExit("opening file %s", argv[1]);
  
  /* Open dest file */
  openFlags = O_CREAT | O_WRONLY | O_TRUNC;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH;
  outputFd = open(argv[2], openFlags, filePerms);
  if(outputFd == -1)
    errExit("opening file %s", argv[2]);
  
  /* Read data from the input file and write it to the output */
  while((numRead = read(inputFd, buf, 1024)) > 0)
    if(write(outputFd, buf, numRead) != numRead)
      fatal("couldn't write whole buffer");
  
  if(numRead == -1)
    errExit("read");

  /* Close file descriptors */
  if(close(inputFd) == -1)
    errExit("close input");
  if(close(outputFd) == -1)
    errExit("close output");

  exit(EXIT_SUCCESS);    
}
