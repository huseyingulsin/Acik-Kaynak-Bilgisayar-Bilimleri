
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

class PrintfKeyboardEventHandler : public KeyboardEventHandler
{
public:
  void OnKeyDown(char c)
  {
    char *foo = " ";
    foo[0] = c;
    printf(foo);
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
  printf("Hello World! --- http://www.AlgorithMan.de\n");

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
  Thread task1(&gdt, producer, 0);
  Thread task2(&gdt, consumer, 1);
  threadManager.CreateThread(&task1);
  threadManager.CreateThread(&task2);

  InterruptManager interrupts(0x20, &gdt, &threadManager);

  printf("Initializing Hardware, Stage 1\n");

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

  printf("Initializing Hardware, Stage 2\n");
  drvManager.ActivateAll();

  printf("Initializing Hardware, Stage 3\n");

#ifdef GRAPHICSMODE
  vga.SetMode(320, 200, 8);
  Window win1(&desktop, 10, 10, 20, 20, 0xA8, 0x00, 0x00);
  desktop.AddChild(&win1);
  Window win2(&desktop, 40, 15, 30, 30, 0x00, 0xA8, 0x00);
  desktop.AddChild(&win2);
#endif

  interrupts.Activate();

  while (1)
  {
#ifdef GRAPHICSMODE
    desktop.Draw(&vga);
#endif
  }
}
