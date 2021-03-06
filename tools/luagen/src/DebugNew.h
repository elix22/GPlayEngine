#ifndef DEBUGNEW_H_
#define DEBUGNEW_H_

#include <new>
#include <exception>

#define TRACK_MEMORY() \
    static struct MemoryTrackerClass { ~MemoryTrackerClass() { printMemoryLeaks(); system("pause"); } } m

// Prints all heap and reference leaks to stderr.
extern void printMemoryLeaks();

// global new/delete operator overloads
#ifdef _MSC_VER
#pragma warning( disable : 4290 ) // C++ exception specification ignored.
#include <yvals.h>
#define NOEXCEPT _NOEXCEPT
#else
#define NOEXCEPT noexcept
#endif

void* operator new (std::size_t size, const char* file, int line);
void* operator new[] (std::size_t size, const char* file, int line);
void* operator new (std::size_t size);
void* operator new[] (std::size_t size);
void* operator new (std::size_t size, const std::nothrow_t& nothrow_value) NOEXCEPT;
void* operator new[](std::size_t size, const std::nothrow_t& nothrow_value) NOEXCEPT;
void operator delete (void* p) NOEXCEPT;
void operator delete[](void* p) NOEXCEPT;
void operator delete (void* p, const char* file, int line) NOEXCEPT;
void operator delete[](void* p, const char* file, int line) NOEXCEPT;

#ifdef _MSC_VER
#pragma warning( default : 4290 )
#endif

// Re-define new to use versions with file and line number
#define DEBUG_NEW new (__FILE__, __LINE__)
#define new DEBUG_NEW

#endif

#if defined(WIN32)

/**
 * Sets whether stack traces are tracked on memory allocations or not.
 * 
 * @param trackStackTrace Whether to track the stack trace on memory allocations.
 */
void setTrackStackTrace(bool trackStackTrace);

/**
 * Toggles stack trace tracking on memory allocations.
 */
void toggleTrackStackTrace();
#endif
