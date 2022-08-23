#ifndef UTILS_H
#define UTILS_H

#define INODE_SIZE 64

/**
 * @brief Error codes
 */
typedef enum
{
  INVALID_MALLOC = 1,
  FILE_OPEN_ERROR,
  FILE_READ_ERROR,
  FILE_WRITE_ERROR,
  FILE_LOCK_ERROR,
  FILE_UNLOCK_ERROR,
  FILE_CLOSE_ERROR,
  FILE_SEEK_ERROR,
  FILE_UNLINK_ERROR,
  INVALID_ARGUMENTS,
  INVALID_EXECVE,
  INVALID_FORK,
  INVALID_WAIT,
  INVALID_MATRIX,
  ALREADY_RUNNING,
  PIPE_CREATION_ERROR,
  FORK_ERROR,
  PIPE_READ_ERROR,
  PIPE_CLOSE_ERROR,
  PIPE_WRITE_ERROR,
  PRINT_ERROR,
  FIRST_INITIALIZE_SERVER,
  FILE_TRUNCATE_ERROR,
  FILE_MMAP_ERROR,
  UNLINK_ERROR,
  SEMAPHORE_OPEN_ERROR,
  SEMAPHORE_UNLINK_ERROR,
  SEMAPHORE_CLOSE_ERROR,
  WAITPID_ERROR,
  SEMAPHORE_INIT_FAILED,
  INVALID_THREAD_CREATION,
  INVALID_THREAD_DETACH,
  INVALID_THREAD_JOIN,
  SEMAPHORE_GET_ERROR,
  SEMAPHORE_OPERATION_FAILED,
  MUTEX_INIT_ERROR,
  COND_INIT_ERROR,
  COND_BROADCAST_ERROR,
  COND_WAIT_ERROR,

  //
  INVALID_BLOCK_SIZE,
  INVALID_PATH,

  //
  INVALID_EXIT_STATUS,
} Error;

// Global error type to be used in the program
static Error GLOBAL_ERROR;

typedef struct INode
{
  unsigned short direct[INODE_SIZE];
  unsigned short singleI[INODE_SIZE];
  unsigned short doubleI[INODE_SIZE];
  unsigned short tripleI[INODE_SIZE];
  unsigned char linkCount;
  unsigned char type;
  unsigned int size;
  char *recentTimeToAccessed;
} INode;

typedef struct SuperBlock
{
  unsigned short blockSize;
  unsigned short blockCount;
  unsigned short INodeCount;
  unsigned short fileCount;
  unsigned int blockPosition;
  unsigned int INodePosition;
} SuperBlock;

/**
 * @brief Used OS_File instead of File since it would be easier to misunderstand File and FILE when doing file operations
 *
 */
typedef struct OS_File
{
  unsigned int inodeNumber;
  unsigned int offsetNumber;
  char name[50];
} OS_File;

/**
 * @brief Detect arguments and check for validation
 *
 * @param argc Argument count
 * @param argv Argument vector
 * @return int 0 if no error, -1 if error
 */
int detectArguments(int argc, char *argv[]);

/**
 * @brief Initialize the problem expectation parts. Works like kind of main
 *
 * @return int 0 if no error, -1 if error
 */
int init();

/**
 * @brief Free all space and used memory
 *
 * @return int 0 if no error, -1 if error
 */
int freeResources();

/**
 * @brief Print usage and exit
 *
 */
void printUsage();

/**
 * @brief Print error and exit
 *
 * @param fd file descriptor to print error
 */
void printError(const int fd);

/**
 * @brief Get the File Size object
 *
 * @param filename
 * @return off_t
 */
off_t getFileSize(const char *filename);

/**
 * @brief Get the Time object
 *
 * @return char*
 */
char *getTime();

/**
 * @brief Set the Array Nth Bit object
 *
 * @param array Array to set the bit
 * @param nth Nth bit to set
 */
void setArrayNthBit(int *array, int nth);

/**
 * @brief Checks the whater the given values are enough for space
 *
 * @return int
 */
int checkAvailableForSpace();

/**
 * @brief Get the Available Size object
 *
 * @return int
 */
int getAvailableSize();

#endif // UTILS_H