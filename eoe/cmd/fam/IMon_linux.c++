#include "IMon.h"

#ifdef __linux__

#include "Log.h"

/*
 * Initial Linux backend.
 *
 * Original IRIX FAM uses /dev/imon for immediate kernel notifications.
 * When imon is unavailable, the existing FAM code falls back to Pollster.
 * Preserve that behavior first; an inotify-backed implementation can
 * replace this without changing the rest of FAM.
 */

int IMon::imonfd = -1;
unsigned IMon::count;
IMon::EventHandler IMon::ehandler;

Boolean
IMon::is_active()
{
    return false;
}

IMon::~IMon()
{
    if (count)
        --count;
}

IMon::Status
IMon::express(const char *, struct stat *)
{
    return BAD;
}

IMon::Status
IMon::revoke(const char *, dev_t, ino_t)
{
    return BAD;
}

void
IMon::read_handler(int, void *)
{
}

#endif
