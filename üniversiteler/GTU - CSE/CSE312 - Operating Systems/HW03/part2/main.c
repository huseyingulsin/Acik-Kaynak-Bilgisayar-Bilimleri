#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include "include/utils.h"

int main(int argc, char *argv[])
{

  if (detectArguments(argc, argv) == -1)
  {
    printf("Global error in main: %d\n", GLOBAL_ERROR);
    printError(STDERR_FILENO);
    return -1;
  }

  if (init() == -1)
  {
    printf("Global error in main: %d\n", GLOBAL_ERROR);
    printError(STDERR_FILENO);
    return -1;
  }

  dprintf(STDOUT_FILENO, "%s: Program finished\n", getTime());

  return 0;
}