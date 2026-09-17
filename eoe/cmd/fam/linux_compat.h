#ifndef FAM_LINUX_COMPAT_H
#define FAM_LINUX_COMPAT_H

#ifdef __linux__

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef unsigned long ulong_t;

enum FAMCodes {
    FAMChanged = 1,
    FAMDeleted = 2,
    FAMStartExecuting = 3,
    FAMStopExecuting = 4,
    FAMCreated = 5,
    FAMMoved = 6,
    FAMAcknowledge = 7,
    FAMExists = 8,
    FAMEndExist = 9
};


#ifndef NGROUPS_UMAX
# ifdef NGROUPS_MAX
#  define NGROUPS_UMAX NGROUPS_MAX
# else
#  define NGROUPS_UMAX 65536
# endif
#endif

#ifndef SGI_NOHANG
#define SGI_NOHANG 1
#endif

int sgikopt(const char *option, char *buf, int buflen);
int syssgi(int request, ...);
int _daemonize(int flags, int fd0, int fd1, int fd2);

static inline int oserror()
{
    return errno;
}

static inline int getdtablehi()
{
    return getdtablesize();
}

#endif

#endif
