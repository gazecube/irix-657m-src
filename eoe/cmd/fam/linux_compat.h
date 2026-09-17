#ifndef FAM_LINUX_COMPAT_H
#define FAM_LINUX_COMPAT_H

#ifdef __linux__

#include <limits.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned long ulong_t;

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

#endif

#endif
