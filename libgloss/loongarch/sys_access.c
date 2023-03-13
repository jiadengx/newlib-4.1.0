#include <machine/syscall.h>
#include "internal_syscall.h"

#define AT_FDCWD -100
/* Permissions of a file (by name).  */
int
_access(const char *file, int mode)
{
  return syscall_errno (SYS_faccessat, 3, AT_FDCWD, file, mode, 0, 0, 0);
}
