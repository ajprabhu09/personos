#include "kvga.h"
#include "precond.h"
void kernel_main(void) {
  /* Initialize terminal interface */
  terminal_initialize();
  const char *world = "Hello WOrld";
  uint8_t birt = 0;
  size_t idx = 0;
  terminal_write(&world[idx], 1);
}