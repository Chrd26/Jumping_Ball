###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_TryLockMutex

Try to lock a mutex without blocking.

## Header File

Defined in [<SDL3/SDL_mutex.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_mutex.h)

## Syntax

```c
int SDL_TryLockMutex(SDL_Mutex *mutex) SDL_TRY_ACQUIRE(0, mutex);

```

## Function Parameters

|               |                          |
| ------------- | ------------------------ |
| **mutex**     | the mutex to try to lock |

## Return Value

Returns 0 or [`SDL_MUTEX_TIMEDOUT`](SDL_MUTEX_TIMEDOUT)

## Remarks

This works just like [SDL_LockMutex](SDL_LockMutex)(), but if the mutex is
not available, this function returns
[`SDL_MUTEX_TIMEDOUT`](SDL_MUTEX_TIMEDOUT) immediately.

This technique is useful if you need exclusive access to a resource but
don't want to wait for it, and will return to it to try again later.

This function does not fail; if mutex is NULL, it will return 0 immediately
having locked nothing. If the mutex is valid, this function will always
either lock the mutex and return 0, or return
[SDL_MUTEX_TIMEOUT](SDL_MUTEX_TIMEOUT) and lock nothing.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_LockMutex](SDL_LockMutex)
* [SDL_UnlockMutex](SDL_UnlockMutex)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

