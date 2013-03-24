#ifndef RTL_H
#define RTL_H

#include <stddef.h>
int rtl_strcmpl(const char *a, const char *b);
int rtl_strncmpl(const char *a, const char *b, size_t size);
char * rtl_strlwr(char * str);

#include "config.h"
#if defined(HAVE_STRINGS_H)
#include <strings.h>
#define strcmpl(a, b) strcasecmp(a, b)
#define memicmp(a, b, n) strncasecmp(a, b, n)
#else
#define memicmp(a, b, n) rtl_strncmpl(a, b, n)
#if defined(HAVE__STRICMP)
#define strcmpl(a, b) _stricmp(a, b)
#elif defined(HAVE_STRICMP)
#define strcmpl(a, b) stricmp(a, b)
#else
#define strcmpl(a, b) rtl_strcmpl(a, b)
#endif
#endif

#if defined(HAVE_DIRECT__MKDIR)
#include <direct.h>
#define mkdir(a) _mkdir(a)
#elif defined(HAVE_DIRECT_MKDIR)
#include <direct.h>
#define mkdir(a) mkdir(a)
#elif defined(HAVE_SYS_STAT_MKDIR)
#include <sys/stat.h>
#define mkdir(a) mkdir(a, 0777)
#endif

#if !defined(HAVE_STRLWR)
#define strlwr(a) rtl_strlwr(a)
#endif

#endif