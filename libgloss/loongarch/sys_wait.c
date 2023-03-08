#include <errno.h>

#undef errno
extern int  errno;

int
_wait (int *status)
{
  errno = ECHILD;
  return -1;                    /* Always fails */

}       /* _wait () */
