#include <sys/types.h>

extern void (*__init_array_start []) (int, char **, char **);
extern void (*__init_array_end []) (int, char **, char **);
extern void (*__fini_array_start []) (void);
extern void (*__fini_array_end []) (void);

__attribute((visibility("hidden"))) void
__libc_csu_init (int argc, char **argv, char **envp)
{
  const size_t size = __init_array_end - __init_array_start;
  for (size_t i = 0; i < size; i++)
      (*__init_array_start [i]) (argc, argv, envp);
}

__attribute((visibility("hidden"))) void
__libc_csu_fini (void)
{
  size_t i = __fini_array_end - __fini_array_start;
  while (i-- > 0)
    (*__fini_array_start [i]) ();
}
