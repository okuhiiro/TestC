#include <stdio.h>
#include <inttypes.h>

#include "path.h"

char *path_tail(char *fname)
{
  if (fname == NULL)
  {
    return (char *)"";
  }

  return get_past_head(fname);
}

// パスの先頭の "/" や "c:\" などをSkipした次からのポインタを取得.
char *get_past_head(char *path)
{
  char *retval = path;

#ifdef WIN32
  // "C:"などををSkipする
  if (isalpha(path[0]) && path[1] == ':')
  {
    retval = path + 2;
  }
#endif

  // 不要なパスセパレータをSkipする
  while (vim_ispathsep(*retval))
  {
    ++retval;
  }

  return retval;
}

int vim_ispathsep(int c)
{
#ifdef UNIX
  return c == '/';
#else
  #ifdef BACKSLASH_IN_FILENAME
  return c == ':' || c == '/' || c == '\\';
  #else
  return c == ':' || c == '/';
  #endif
#endif
}
