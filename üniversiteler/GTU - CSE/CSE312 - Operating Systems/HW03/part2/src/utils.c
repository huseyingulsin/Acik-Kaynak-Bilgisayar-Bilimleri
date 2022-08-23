#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>
#include <fcntl.h>
#include "../include/utils.h"

int globalBlockSize = 0;
int globalINodeSize = 100;
char *globalPath = NULL;

const int ONE_KB = 1024;
const int ONE_MB = 1024 * ONE_KB;
/* A constant value that is used to check if the block size and INode size is valid. */
/* Also, This is the my max block size variable */
const int MB_4 = 4 * ONE_MB;

int detectArguments(int argc, char *argv[])
{

  if (argc > 4)
  {
    GLOBAL_ERROR = INVALID_ARGUMENTS;
    return -1;
  }

  if (argc == 3)
  {
    globalBlockSize = atoi(argv[1]);
    globalPath = argv[2];
  }
  else if (argc == 4)
  {
    globalBlockSize = atoi(argv[1]);
    globalINodeSize = atoi(argv[2]);
    globalPath = argv[3];
  }

  dprintf(STDOUT_FILENO, "%s: Program Starting with those values: blockSize: %d, inodeSize: %d, path: %s\n", getTime(), globalBlockSize, globalINodeSize, globalPath);

  return 1;
}

int init()
{

  unsigned char ALL_FILE_SYSTEM[MB_4];
  if (checkAvailableForSpace() == -1)
  {
    GLOBAL_ERROR = INVALID_BLOCK_SIZE;
    return -1;
  }

  int availabeSize = getAvailableSize();
  const int blockCount = availabeSize / (globalBlockSize * ONE_KB);
  const int firstAdressBlock = MB_4 - (blockCount * globalBlockSize * ONE_KB);
  const int firstAdressINode = firstAdressBlock - (globalINodeSize * sizeof(INode));

  SuperBlock super_block;
  super_block.blockSize = globalBlockSize;
  super_block.blockCount = blockCount;
  super_block.INodeCount = globalINodeSize;
  super_block.fileCount = globalBlockSize * (ONE_KB / sizeof(OS_File));
  super_block.blockPosition = firstAdressBlock;
  super_block.INodePosition = firstAdressINode;

  INode root;
  root.linkCount = 1;
  root.type = 0;
  root.size = 2 * sizeof(OS_File);
  root.recentTimeToAccessed = getTime();
  root.direct[0] = 0;

  OS_File file[2];
  file[0].inodeNumber = 0;
  file[0].offsetNumber = 0;
  strcpy(file[0].name, ".");
  file[1].inodeNumber = 1;
  file[1].offsetNumber = 0;
  strcpy(file[1].name, "..");

  FILE *fp;
  if ((fp = fopen(globalPath, "wb+")) == NULL)
  {
    GLOBAL_ERROR = INVALID_PATH;
    return -1;
  }

  if (fwrite(ALL_FILE_SYSTEM, MB_4, 1, fp) != 1)
  {
    GLOBAL_ERROR = FILE_WRITE_ERROR;
    return 0;
  }

  if (fclose(fp) == EOF)
  {
    GLOBAL_ERROR = FILE_CLOSE_ERROR;
    return 0;
  }

  dprintf(STDERR_FILENO, "%s: Block size: %d\n", getTime(), globalBlockSize);
  dprintf(STDERR_FILENO, "%s: Block count: %d\n", getTime(), blockCount);
  dprintf(STDERR_FILENO, "%s: INode count: %d\n", getTime(), globalINodeSize);
  dprintf(STDERR_FILENO, "%s: File count: %d\n", getTime(), super_block.fileCount);
  dprintf(STDERR_FILENO, "%s: First address block: %d\n", getTime(), firstAdressBlock);
  dprintf(STDERR_FILENO, "%s: First address INode: %d\n", getTime(), firstAdressINode);
  dprintf(STDERR_FILENO, "%s: Size of the SuperBlock: %ld\n", getTime(), sizeof(SuperBlock));
  dprintf(STDERR_FILENO, "%s: Size of the INode: %ld\n", getTime(), sizeof(INode));
  dprintf(STDERR_FILENO, "%s: Size of the OS_File: %ld\n", getTime(), sizeof(OS_File));
  dprintf(STDERR_FILENO, "%s: Size of the file system: %d\n", getTime(), MB_4);
  dprintf(STDERR_FILENO, "%s: Size of the file system available: %d\n", getTime(), availabeSize);
  dprintf(STDERR_FILENO, "%s: Size of the file system available for files: %ld\n", getTime(), availabeSize - (globalINodeSize * sizeof(INode)));
  dprintf(STDERR_FILENO, "%s: Time of the Root recentAcessTime: %s\n", getTime(), root.recentTimeToAccessed);

  return 0;
}

char *getTime()
{
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  char *timestamp = asctime(timeinfo);
  timestamp[strlen(timestamp) - 1] = '\0';

  return timestamp;
}

void printError(const int fd)
{
  char *error_message = NULL;
  int show_perror = 1;
  switch (GLOBAL_ERROR)
  {
  case INVALID_MALLOC:
    error_message = "Invalid malloc";
    break;
  case INVALID_ARGUMENTS:
    error_message = "Invalid arguments";
    show_perror = 0;
    printUsage();
    break;
  case FILE_OPEN_ERROR:
    error_message = "File open error";
    break;
  case FILE_WRITE_ERROR:
    error_message = "File write error";
    break;
  case FILE_READ_ERROR:
    error_message = "File read error";
    break;
  case FILE_LOCK_ERROR:
    error_message = "File lock error";
    break;
  case FILE_UNLOCK_ERROR:
    error_message = "File unlock error";
    break;
  case FILE_CLOSE_ERROR:
    error_message = "File close error";
    break;
  case FILE_UNLINK_ERROR:
    error_message = "File unlink error";
    break;
  case ALREADY_RUNNING:
    error_message = "Server already running, If it is not running, delete serverYTemp file.";
    break;
  case FILE_SEEK_ERROR:
    error_message = "File seek error";
    break;
  case INVALID_EXECVE:
    error_message = "Invalid execve";
    break;
  case INVALID_FORK:
    error_message = "Invalid fork";
    break;
  case PIPE_CREATION_ERROR:
    error_message = "Pipe creation error";
    break;
  case FORK_ERROR:
    error_message = "Fork error";
    break;
  case PIPE_READ_ERROR:
    error_message = "Pipe read error";
    break;
  case PIPE_CLOSE_ERROR:
    error_message = "Pipe close error";
    break;
  case PIPE_WRITE_ERROR:
    error_message = "Pipe write error";
    break;
  case INVALID_WAIT:
    error_message = "Invalid wait";
    show_perror = 0;
    break;
  case INVALID_MATRIX:
    error_message = "Invalid matrix. Matrix should be square (NxN). N >= 2";
    show_perror = 0;
    break;
  case PRINT_ERROR:
    error_message = "Print error";
    break;
  case FIRST_INITIALIZE_SERVER:
    error_message = "First start serverY. serverY is not working now.";
    show_perror = 0;
    break;
  case FILE_TRUNCATE_ERROR:
    error_message = "File truncate error";
    break;
  case FILE_MMAP_ERROR:
    error_message = "File mmap error";
    break;
  case UNLINK_ERROR:
    error_message = "Unlink error";
    break;
  case SEMAPHORE_OPEN_ERROR:
    error_message = "Semaphore open error";
    break;
  case SEMAPHORE_CLOSE_ERROR:
    error_message = "Semaphore close error";
    break;
  case SEMAPHORE_UNLINK_ERROR:
    error_message = "Semaphore unlink error";
    break;
  case WAITPID_ERROR:
    error_message = "Waitpid error";
    break;
  case INVALID_THREAD_CREATION:
    error_message = "Invalid thread creation";
    break;
  case INVALID_THREAD_JOIN:
    error_message = "Invalid thread join";
    break;
  case INVALID_THREAD_DETACH:
    error_message = "Invalid thread detach";
    break;
  case SEMAPHORE_GET_ERROR:
    error_message = "Semaphore get error";
    break;
  case SEMAPHORE_OPERATION_FAILED:
    error_message = "Semaphore operation failed";
    break;
  case MUTEX_INIT_ERROR:
    error_message = "Mutex init error";
    break;
  case COND_INIT_ERROR:
    error_message = "Cond init error";
    break;
  case COND_BROADCAST_ERROR:
    error_message = "Cond broadcast error";
    break;
  case COND_WAIT_ERROR:
    error_message = "Cond wait error";
    break;
  default:
    error_message = "Unknown error";
    dprintf(STDERR_FILENO, "Error Number: %d\n", GLOBAL_ERROR);
    break;
  }

  if (show_perror)
    perror(error_message);

  dprintf(fd, "%s\n", error_message);

  // terminate
  // exit(EXIT_FAILURE);
}

void printUsage()
{
  dprintf(STDOUT_FILENO, "Usage: part2 \n");
  dprintf(STDOUT_FILENO, "makeFileSystem <block_size> <INode_count (option, default = 100)> <filepath.dat>\n");
}

void setArrayNthBit(int *array, int nth)
{
  array[nth / 8] |= 1 << (7 - nth % 8);
}

int checkAvailableForSpace()
{

  const int KB_TOTAL_BLOCK_SIZE = ONE_KB * globalBlockSize + 1;
  const int TOTAL_INode_SIZE = globalINodeSize * sizeof(INode);

  if (KB_TOTAL_BLOCK_SIZE + TOTAL_INode_SIZE >= MB_4)
  {
    GLOBAL_ERROR = INVALID_BLOCK_SIZE;
    return -1;
  }

  return 1;
}

int getAvailableSize()
{
  return MB_4 - (sizeof(SuperBlock) + globalINodeSize * sizeof(INode));
}