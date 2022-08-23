
#include <common/types.h>
#include <gdt.h>
#include <hardwarecommunication/interrupts.h>
#include <hardwarecommunication/pci.h>
#include <drivers/driver.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <drivers/vga.h>
#include <gui/desktop.h>
#include <gui/window.h>
#include <multitasking.h>
#include <multithread.h>
#include <pagereplacement.h>

// #define GRAPHICSMODE

using namespace myos;
using namespace myos::common;
using namespace myos::drivers;
using namespace myos::hardwarecommunication;
using namespace myos::gui;

void printf(char *str)
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

void printfHex(uint8_t key)
{
  char *foo = "00";
  char *hex = "0123456789ABCDEF";
  foo[0] = hex[(key >> 4) & 0xF];
  foo[1] = hex[key & 0xF];
  printf(foo);
}

ThreadManager threadManager;

void yieldHelper(int id)
{
  if (threadManager.yieldModeOpen == true && threadManager.yieldedThread == id)
  {
    while (threadManager.yieldModeOpen == true)
    {
    };
  }
}

int turn;
int flag[2];

void petersonsEnter(int id)
{
  int otherId = id == 0 ? 1 : 0;
  flag[id] = true;
  turn = id;
  while (turn == id && flag[otherId] == true)
    ;
}

void petersonsLeave(int id)
{
  flag[id] = false;
}

void taskA()
{
  while (true)
  {
    yieldHelper(0);
    printf("Task ----------------------------- A --------------\n");
  }
}

void taskB()
{
  while (true)
  {
    yieldHelper(1);
    printf("Task +++++++++++++++ B +++++++++++++++\n");
  }
}

int fish = 0; // this is my product

void producer()
{
  while (true)
  {
    if (fish < 1000000)
      petersonsEnter(0);

    // printf("Producer -----------------------------\n");
    fish++;

    if (fish > 1000000)
    {
      printf("Producer: fish > 1000000\n");
      petersonsLeave(0);
    }
  }
}

void consumer()
{
  while (true)
  {
    if (fish > 0)
      petersonsEnter(1);

    // printf("Consumer -----------------------------\n");
    fish--;

    if (fish < 0)
    {
      printf("Consumer: fish < 0\n");
      petersonsLeave(1);
    }
  }
}

int bubbleSort(int arr[], int n)
{
  int sortTime = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      sortTime++;
      if (arr[j] > arr[j + 1])
      {
        // swap arr[j+1] and arr[j]
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  return sortTime;
}

int insertionSort(int arr[], int n)
{
  int sortTime = 0;
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      sortTime++;
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }

  return sortTime;
}

int partition(int arr[], int low, int high, int *sortTime)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++)
  {
    (*sortTime)++;
    if (arr[j] <= pivot)
    {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}
int quickSortHelper(int arr[], int low, int high)
{
  int sortTime = 0;
  if (low < high)
  {
    int pi = partition(arr, low, high, &sortTime);
    sortTime += quickSortHelper(arr, low, pi - 1);
    sortTime += quickSortHelper(arr, pi + 1, high);
  }

  return sortTime;
}

int quickSort(int arr[], int n)
{
  return quickSortHelper(arr, 0, n - 1);
}

int randomValues[500] = {42, 16, 7, 33, 47, 66, 79, 64, 67, 3, 70, 34, 86, 13, 92, 48, 93, 73, 5, 66, 67, 9, 15, 16, 22, 23, 48, 71, 58, 40, 5, 19, 67, 45, 94, 10, 7, 52, 37, 81, 35, 47, 88, 61, 60, 94, 28, 47, 38, 29, 100, 47, 73, 51, 62, 3, 39, 61, 62, 57, 23, 100, 48, 21, 29, 76, 71, 42, 18, 49, 41, 92, 93, 81, 88, 27, 50, 29, 49, 67, 58, 60, 4, 23, 96, 25, 46, 96, 90, 29, 87, 67, 41, 45, 17, 8, 52, 71, 21, 7, 52, 13, 1, 5, 98, 94, 63, 13, 4, 66, 58, 64, 34, 36, 45, 42, 73, 14, 58, 94, 51, 93, 14, 84, 28, 91, 65, 84, 43, 12, 0, 51, 56, 47, 22, 31, 20, 21, 23, 11, 18, 13, 85, 3, 94, 0, 82, 41, 33, 2, 4, 20, 68, 45, 46, 49, 84, 97, 89, 96, 51, 86, 20, 33, 93, 37, 83, 46, 17, 37, 53, 35, 16, 50, 74, 13, 18, 0, 41, 12, 51, 97, 86, 52, 13, 64, 93, 71, 43, 98, 39, 46, 51, 81, 4, 15, 53, 19, 96, 77, 55, 80, 5, 25, 48, 10, 25, 31, 48, 98, 73, 84, 32, 23, 30, 40, 48, 29, 41, 8, 16, 35, 28, 21, 40, 63, 78, 2, 32, 70, 66, 25, 7, 63, 27, 5, 81, 68, 52, 69, 83, 89, 42, 10, 68, 99, 62, 29, 100, 95, 30, 1, 40, 40, 53, 85, 64, 61, 30, 93, 16, 34, 14, 32, 31, 82, 1, 53, 72, 19, 8, 4, 28, 74, 87, 83, 62, 60, 22, 58, 43, 40, 1, 71, 61, 97, 51, 23, 91, 79, 19, 46, 59, 72, 3, 44, 43, 97, 67, 100, 19, 5, 39, 32, 6, 23, 100, 61, 83, 84, 73, 18, 86, 70, 49, 78, 69, 67, 56, 86, 26, 14, 51, 90, 82, 22, 67, 29, 5, 91, 73, 64, 62, 81, 29, 46, 29, 52, 44, 43, 51, 74, 82, 86, 80, 96, 24, 18, 94, 52, 46, 57, 82, 38, 66, 71, 29, 47, 92, 86, 85, 58, 89, 39, 14, 70, 13, 32, 85, 24, 95, 13, 34, 2, 26, 83, 47, 83, 45, 19, 14, 86, 9, 36, 33, 24, 57, 72, 92, 67, 60, 22, 81, 50, 99, 19, 7, 5, 35, 45, 2, 92, 9, 92, 13, 80, 79, 52, 46, 39, 93, 75, 85, 85, 14, 14, 68, 50, 10, 16, 11, 73, 42, 88, 46, 90, 83, 52, 38, 23, 39, 76, 40, 21, 90, 51, 82, 56, 27, 62, 63, 98, 22, 73, 68, 92, 41, 80, 94, 35, 18, 1, 48, 9, 46, 27, 64, 98, 7, 91, 11, 36, 79, 72, 76, 69, 5, 28, 85, 39, 75, 97, 94, 62, 93, 63, 46, 2, 94, 14, 20, 44, 22, 37, 90, 82, 68, 62, 13, 28, 35, 35, 40, 91, 74, 47, 86, 67, 58, 73};

PageReplacement page;

class PrintfKeyboardEventHandler : public KeyboardEventHandler
{
public:
  void OnKeyDown(char c)
  {
    char *inputBuffer = " ";
    inputBuffer[0] = c;

    if (inputBuffer[0] == '1')
    {
      page.fifo.run(randomValues, 500, bubbleSort, "\n------------------- FIFO Bubble Sort result -----------------------");
      page.fifo.run(randomValues, 500, insertionSort, "\n------------------- FIFO Insertion Sort result -----------------------");
      page.fifo.run(randomValues, 500, quickSort, "\n------------------- FIFO Quick Sort result -----------------------");
    }
    else if (inputBuffer[0] == '2')
    {
      page.secondChance.run(randomValues, 500, bubbleSort, "\n------------------- Second Chance Bubble Sort result -----------------------");
      page.secondChance.run(randomValues, 500, insertionSort, "\n------------------- Second Chance Insertion Sort result -----------------------");
      page.secondChance.run(randomValues, 500, quickSort, "\n------------------- Second Chance Quick Sort result -----------------------");
    }
    else if (inputBuffer[0] == '3')
    {
      page.lru.run(randomValues, 500, bubbleSort, "\n------------------- LRU Bubble Sort result -----------------------");
      page.lru.run(randomValues, 500, insertionSort, "\n------------------- LRU Insertion Sort result -----------------------");
      page.lru.run(randomValues, 500, quickSort, "\n------------------- LRU Quick Sort result -----------------------");
    }
  }
};

class MouseToConsole : public MouseEventHandler
{
  int8_t x, y;

public:
  MouseToConsole()
  {
    uint16_t *VideoMemory = (uint16_t *)0xb8000;
    x = 40;
    y = 12;
    VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0x0F00) << 4 | (VideoMemory[80 * y + x] & 0xF000) >> 4 | (VideoMemory[80 * y + x] & 0x00FF);
  }

  virtual void OnMouseMove(int xoffset, int yoffset)
  {
    static uint16_t *VideoMemory = (uint16_t *)0xb8000;
    VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0x0F00) << 4 | (VideoMemory[80 * y + x] & 0xF000) >> 4 | (VideoMemory[80 * y + x] & 0x00FF);

    x += xoffset;
    if (x >= 80)
      x = 79;
    if (x < 0)
      x = 0;
    y += yoffset;
    if (y >= 25)
      y = 24;
    if (y < 0)
      y = 0;

    VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0x0F00) << 4 | (VideoMemory[80 * y + x] & 0xF000) >> 4 | (VideoMemory[80 * y + x] & 0x00FF);
  }
};

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
  for (constructor *i = &start_ctors; i != &end_ctors; i++)
    (*i)();
}

extern "C" void kernelMain(const void *multiDoot_structure, uint32_t /*multiboot_magic*/)
{
  printf("Hello World! --- MUHAMMED OGUZ\n");

  GlobalDescriptorTable gdt;

  // ! You can test yield and join from here hocam
  // Thread task1(&gdt, taskA, 0);
  // Thread task2(&gdt, taskB, 1);
  // threadManager.CreateThread(&task1);
  // threadManager.CreateThread(&task2);
  // threadManager.Yield(0);
  // threadManager.Yield(1);
  // threadManager.Join(0);
  // threadManager.Join(1);

  // consumer producer test
  // Thread task1(&gdt, producer, 0);
  // Thread task2(&gdt, consumer, 1);
  // threadManager.CreateThread(&task1);
  // threadManager.CreateThread(&task2);

  InterruptManager interrupts(0x20, &gdt, &threadManager);

#ifdef GRAPHICSMODE
  Desktop desktop(320, 200, 0x00, 0x00, 0xA8);
#endif

  DriverManager drvManager;

#ifdef GRAPHICSMODE
  KeyboardDriver keyboard(&interrupts, &desktop);
#else
  PrintfKeyboardEventHandler kbhandler;
  KeyboardDriver keyboard(&interrupts, &kbhandler);
#endif
  drvManager.AddDriver(&keyboard);

#ifdef GRAPHICSMODE
  MouseDriver mouse(&interrupts, &desktop);
#else
  MouseToConsole mousehandler;
  MouseDriver mouse(&interrupts, &mousehandler);
#endif
  drvManager.AddDriver(&mouse);

  PeripheralComponentInterconnectController PCIController;
  PCIController.SelectDrivers(&drvManager, &interrupts);

  VideoGraphicsArray vga;

  drvManager.ActivateAll();

#ifdef GRAPHICSMODE
  vga.SetMode(320, 200, 8);
  Window win1(&desktop, 10, 10, 20, 20, 0xA8, 0x00, 0x00);
  desktop.AddChild(&win1);
  Window win2(&desktop, 40, 15, 30, 30, 0x00, 0xA8, 0x00);
  desktop.AddChild(&win2);
#endif

  interrupts.Activate();

  printf("1-FIFO\n");
  printf("2-Second Chance\n");
  printf("3-LRU\n");

  while (1)
  {
#ifdef GRAPHICSMODE
    desktop.Draw(&vga);
#endif
  }
}
