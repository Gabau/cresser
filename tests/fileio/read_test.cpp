#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "operations.h"


int main(int argc, char** argv) {
  string read = rfrom(argv[1]);
  wrto("tmpfile", read);
  int res = fork();
  if (res == 0) {
    execlp("diff", "diff", argv[1], "tmpfile", NULL);
  }
  int status;
  waitpid(res, &status, 0);
  if (WIFEXITED(status)) {
    return WEXITSTATUS(status);
  }
  fprintf(stderr, "Child did not exit.\n");
  return -1;

}