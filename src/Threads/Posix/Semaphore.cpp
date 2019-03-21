#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Threads/Semaphore.hpp>

#include <pthread.h>

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
