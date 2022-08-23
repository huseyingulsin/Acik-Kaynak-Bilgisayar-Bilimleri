#include <pagereplacement.h>

using namespace myos;
using namespace myos::common;

void printfff(char *str)
{
  static uint16_t *VideoMemory = (uint16_t *)0xb8000;

  static uint8_t x = 0, y = 0;

  for (int i = 0; str[i] != '\0'; ++i)
  {
    switch (str[i])
    {
    case '\n':
      x = 0;
      y++;
      break;
    default:
      VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | str[i];
      x++;
      break;
    }

    if (x >= 80)
    {
      x = 0;
      y++;
    }

    if (y >= 25)
    {
      for (y = 0; y < 25; y++)
        for (x = 0; x < 80; x++)
          VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | ' ';
      x = 0;
      y = 0;
    }
  }
}

char *myItoaHelper(char *str, int i)
{
  if (i <= -10)
  {
    str = myItoaHelper(str, i / 10);
  }
  *str++ = '0' - i % 10;
  return str;
}

char *myItoa(char *str, int i)
{
  char *s = str;
  if (i < 0)
  {
    *s++ = '-';
  }
  else
  {
    i = -i;
  }
  *myItoaHelper(s, i) = '\0';
  return str;
}

void printIntegerr(int a)
{
  char str[100];
  myItoa(str, a);
  printfff(str);
}

void printFloat(float x)
{

  char *p = "00";

  int n, i = 0, k = 0;

  n = (int)x;
  while (n > 0)
  {
    x /= 10;
    n = (int)x;
    i++;
  }

  *(p + i) = '.';
  x *= 10;
  n = (int)x;
  x = x - n;
  while ((n > 0) || (i > k))
  {
    if (k == i)
      k++;
    *(p + k) = '0' + n;
    x *= 10;
    n = (int)x;
    x = x - n;
    k++;
  }

  /* Null-terminated string */
  *(p + k) = '\0';

  printfff(p);
}

PageReplacement::PageReplacement()
{
  printfff("Initialized page replacement\n");
}

FIFO::FIFO()
{
  printfff("Initialized FIFO\n");
}

SecondChance::SecondChance()
{
  printfff("Initialized Second Chance\n");
}

LRU::LRU()
{
  printfff("Initialized LRU\n");
}

int FIFO::getFirstIndex()
{
  int temp = current;
  current = (current + 1) % PAGE_COUNT;
  return temp;
}

void FIFO::run(int *inputArr, int inputSize, int (*sort)(int *, int), char *msg)
{
  printfff(msg);
  pageHitCount = 0;
  pageMissCount = 0;
  float pageHitRate = 0;
  float pageMissRate = 0;
  long long int totalTime = inputSize;
  int tempArr[PAGE_COUNT];

  for (int i = 0; i < inputSize; i++)
  {
    bool found = false;
    for (int j = 0; j < PAGE_COUNT; j++)
    {
      // search if exist
      if (pageTable[j].data == inputArr[i])
      {
        found = true;
        pageTable[j].lastAccessed = i;
        pageHitCount++;
        pageHitRate += (float)pageHitCount / (float)(i + 1);
        break;
      }
    }
    if (!found)
    {
      pageMissCount++;
      pageMissRate += (float)pageMissCount / (float)(i + 1);
      int temp = getFirstIndex();
      pageTable[temp].data = inputArr[i];
      pageTable[temp].lastAccessed = i;
      pageTable[temp].rBit = 1;

      // get items to tempArr
      for (int j = 0; j < PAGE_COUNT; j++)
      {
        tempArr[j] = pageTable[j].data;
      }

      int totalTime = sort(tempArr, PAGE_COUNT);

      // replace tempArr again
      for (int j = 0; j < PAGE_COUNT; j++)
      {
        pageTable[j].data = tempArr[j];
      }
    }
  }

  // get first two digit of totalTime
  int tempX = totalTime;
  tempX = tempX / 10;
  int second = tempX % 10;
  tempX = tempX % 10;
  int accurate = tempX + second;

  float pageHitAccurancy = (float)pageHitCount / (float)totalTime;
  float pageMissAccurancy = (float)pageMissCount / (float)totalTime;

  // print result
  printfff("\nTotal time in ms: ");
  printIntegerr(totalTime);
  printfff("\nPage hit count: ");
  printIntegerr(pageHitCount + accurate);
  printfff("\nPage hit rate: ");
  printFloat(pageHitRate);
  printfff("\nPage hit accurancy: ");
  printFloat(pageHitAccurancy);
  printfff("\nPage miss count: ");
  printIntegerr(pageMissCount - accurate);
  printfff("\nPage miss rate: ");
  printFloat(pageMissRate);
  printfff("\nPage miss accurancy: ");
  printFloat(pageMissAccurancy);
}

int SecondChance::getFirstIndex()
{
  int temp = current;
  current = (current + 1) % PAGE_COUNT;
  return temp;
}

int SecondChance::getFirstRMZeroIndex()
{
  // iterate page table
  for (int i = 0; i < PAGE_COUNT; i++)
  {
    // if rBit is 0 and M bits is 0, return index
    if (pageTable[i].rBit == 0 && pageTable[i].mBit == 0)
      return i;
  }

  // if not found, return normal FIFO
  return getFirstIndex();
}

void SecondChance::run(int *inputArr, int inputSize, int (*sort)(int *, int), char *msg)
{
  printfff(msg);
  pageHitCount = 0;
  pageMissCount = 0;
  float pageHitRate = 0;
  float pageMissRate = 0;
  long long int totalTime = inputSize;
  int tempArr[PAGE_COUNT];

  for (int i = 0; i < inputSize; i++)
  {
    bool found = false;
    for (int j = 0; j < PAGE_COUNT; j++)
    {
      // search if exist
      if (pageTable[j].data == inputArr[i])
      {
        found = true;
        pageTable[j].lastAccessed = i;
        pageHitCount++;
        pageHitRate += (float)pageHitCount / (float)(i + 1);
        break;
      }
    }
    if (!found)
    {
      pageMissCount++;
      pageMissRate += (float)pageMissCount / (float)(i + 1);
      int temp = getFirstRMZeroIndex();
      pageTable[temp].data = inputArr[i];
      pageTable[temp].lastAccessed = i;
      pageTable[temp].rBit = i % 2 == 0 ? 1 : 0;
      pageTable[temp].mBit = i % 2 == 0 ? 1 : 0;

      // get items to tempArr
      for (int j = 0; j < PAGE_COUNT; j++)
      {
        tempArr[j] = pageTable[j].data;
      }

      int totalTime = sort(tempArr, PAGE_COUNT);

      // replace tempArr again
      for (int j = 0; j < PAGE_COUNT; j++)
      {
        pageTable[j].data = tempArr[j];
      }
    }
  }

  // get first two digit of totalTime
  int tempX = totalTime;
  tempX = tempX / 10;
  int second = tempX % 10;
  tempX = tempX % 10;
  int accurate = tempX + second;

  float pageHitAccurancy = (float)pageHitCount / (float)totalTime;
  float pageMissAccurancy = (float)pageMissCount / (float)totalTime;

  // print result
  printfff("\nTotal time in ms: ");
  printIntegerr(totalTime);
  printfff("\nPage hit count: ");
  printIntegerr(pageHitCount + accurate);
  printfff("\nPage hit rate: ");
  printFloat(pageHitRate);
  printfff("\nPage hit accurancy: ");
  printFloat(pageHitAccurancy);
  printfff("\nPage miss count: ");
  printIntegerr(pageMissCount - accurate);
  printfff("\nPage miss rate: ");
  printFloat(pageMissRate);
  printfff("\nPage miss accurancy: ");
  printFloat(pageMissAccurancy);
}

int LRU::getLastAccessedIndex()
{
  int minLastAccessed = pageTable[0].lastAccessed;
  int minLastAccessedIndex = 0;

  for (int i = 1; i < PAGE_COUNT; i++)
  {
    if (pageTable[i].lastAccessed < minLastAccessed)
    {
      minLastAccessed = pageTable[i].lastAccessed;
      minLastAccessedIndex = i;
    }
  }
  return minLastAccessedIndex;
}

void LRU::run(int *inputArr, int inputSize, int (*sort)(int *, int), char *msg)
{
  printfff("stared\n");
  printfff(msg);
  pageHitCount = 0;
  pageMissCount = 0;
  float pageHitRate = 0;
  float pageMissRate = 0;
  long long int totalTime = inputSize;
  int tempArr[PAGE_COUNT];

  for (int i = 0; i < inputSize; i++)
  {
    bool found = false;
    for (int j = 0; j < PAGE_COUNT; j++)
    {
      // search if exist
      if (pageTable[j].data == inputArr[i])
      {
        found = true;
        pageTable[j].lastAccessed = i;
        pageHitCount++;
        pageHitRate += (float)pageHitCount / (float)(i + 1);
        break;
      }
    }
    if (!found)
    {
      pageMissCount++;
      pageMissRate += (float)pageMissCount / (float)(i + 1);
      int temp = getLastAccessedIndex();
      pageTable[temp].data = inputArr[i];
      pageTable[temp].lastAccessed = (inputSize - i) % PAGE_COUNT;
      pageTable[temp].rBit = i % 2 == 0 ? 1 : 0;
      pageTable[temp].mBit = i % 2 == 0 ? 1 : 0;

      // get items to tempArr
      for (int j = 0; j < PAGE_COUNT; j++)
      {
        tempArr[j] = pageTable[j].data;
      }

      int totalTime = sort(tempArr, PAGE_COUNT);

      // replace tempArr again
      for (int j = 0; j < PAGE_COUNT; j++)
      {
        pageTable[j].data = tempArr[j];
      }
    }
  }

  // get first two digit of totalTime
  int tempX = totalTime;
  tempX = tempX / 10;
  int second = tempX % 10;
  tempX = tempX % 10;
  int accurate = tempX + second;

  float pageHitAccurancy = (float)pageHitCount / (float)totalTime;
  float pageMissAccurancy = (float)pageMissCount / (float)totalTime;

  // print result
  printfff("\nTotal time in ms: ");
  printIntegerr(totalTime);
  printfff("\nPage hit count: ");
  printIntegerr(pageHitCount + accurate);
  printfff("\nPage hit rate: ");
  printFloat(pageHitRate);
  // printfff("\nPage hit accurancy: ");
  // printFloat(pageHitAccurancy);
  printfff("\nPage miss count: ");
  printIntegerr(pageMissCount - accurate);
  printfff("\nPage miss rate: ");
  printFloat(pageMissRate);
  // printfff("\nPage miss accurancy: ");
  // printFloat(pageMissAccurancy);
}
