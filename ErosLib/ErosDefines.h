#ifndef EROSDEFINES_H
#define EROSDEFINES_H

#if defined(_WIN32) || defined(_WIN64) || defined(CYGWIN) || defined(WIN32) || defined(WIN64)
#define EROS_WINDOWS 's'
#elif defined(__unix__) || defined(__unix) || defined(unix)
#define EROS_LINUX 's'
#endif



#endif // EROSDEFINES_H
