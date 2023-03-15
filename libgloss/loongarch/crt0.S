#include "newlib.h"
#include "regs.S"

  .text
  .global _start
  .type   _start, @function
_start:
  # Clear the bss segment
  la      a0, __bss_start
  la      a1, _end
  sub.d   a1, a1, a0
  la      ra, memset
  jirl    ra, ra, 0

  la      a0, __libc_csu_fini   # Register global termination functions
  la      ra, atexit
  jirl    ra, ra, 0             # to be called upon exit

  ld.d    a0, sp, 0             # a0 = argc
  addi.d  a1, sp, 8             # a1 = argv
  move    a2, zero              # a2 = envp = NULL
  la      ra, __libc_csu_init   # Run global initialization functions
  jirl    ra, ra, 0

  ld.d    a0, sp, 0             # a0 = argc
  addi.d  a1, sp, 8             # a1 = argv
  move    a2, zero              # a2 = envp = NULL
  bstrins.d sp, zero, 3, 0      # adjust sp for 16bytes-aligned
  la      ra, main
  jirl    ra, ra, 0

  la      ra, exit
  jirl    ra, ra, 0
  .size  _start, .-_start
