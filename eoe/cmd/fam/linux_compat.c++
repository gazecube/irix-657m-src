#include "linux_compat.h"

#ifdef __linux__

#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern "C" void
blkclr(void *p, size_t n)
{
    memset(p, 0, n);
}


int
sgikopt(const char *option, char *buf, int buflen)
{
    const char *value;

    if (!option || !buf || buflen <= 0) {
        errno = EINVAL;
        return -1;
    }

    /*
     * IRIX uses sgikopt() here only to ask whether the machine is
     * diskless.  Linux has no equivalent kernel option interface.
     * Permit an override for testing; otherwise report "not found".
     */
    value = getenv("FAM_SGIKOPT_DISKLESS");
    if (value && !strcmp(option, "diskless")) {
        strncpy(buf, value, (size_t)buflen - 1u);
        buf[buflen - 1] = '\0';
        return 0;
    }

    errno = EINVAL;
    return -1;
}

int
syssgi(int request, ...)
{
    (void)request;
    /*
     * SGI_NOHANG changes IRIX NFS timeout semantics.  There is no
     * direct Linux equivalent required for normal FAM operation.
     */
    return 0;
}

int
_daemonize(int flags, int fd0, int fd1, int fd2)
{
    (void)flags;
    (void)fd0;
    (void)fd1;
    (void)fd2;
    return daemon(0, 0);
}

#endif
