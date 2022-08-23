#ifndef __MYOS__PAGEREPLACEMENT_H
#define __MYOS__PAGEREPLACEMENT_H

#include <common/types.h>
#include <gdt.h>

namespace myos
{
#define PAGE_COUNT 10

  typedef struct
  {
    int data;
    int lastAccessed;
    int rBit;
    int mBit;
  } Page;

  class FIFO
  {
  private:
    Page pageTable[PAGE_COUNT];
    int current = 0;
    int getFirstIndex();

  public:
    FIFO();
    // get a sort function as parameter and inputArr
    void run(int *inputArr, int inputSize, int (*sort)(int *, int), char *msg);
    int pageHitCount = 0;
    int pageMissCount = 0;
  };

  class SecondChance
  {
  private:
    Page pageTable[PAGE_COUNT];
    int current = 0;
    int getFirstIndex();
    int getFirstRMZeroIndex();

  public:
    SecondChance();
    // get a sort function as parameter and inputArr
    void run(int *inputArr, int inputSize, int (*sort)(int *, int), char *msg);
    int pageHitCount = 0;
    int pageMissCount = 0;
  };

  class LRU
  {
  private:
    Page pageTable[PAGE_COUNT];
    int current = 0;
    int getLastAccessedIndex();

  public:
    LRU();
    // get a sort function as parameter and inputArr
    void run(int *inputArr, int inputSize, int (*sort)(int *, int), char *msg);
    int pageHitCount = 0;
    int pageMissCount = 0;
  };

  class PageReplacement
  {
  public:
    PageReplacement();
    FIFO fifo;
    SecondChance secondChance;
    LRU lru;
  };

}

#endif