###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateSemaphore

Create a semaphore.

## Header File

Defined in [<SDL3/SDL_mutex.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_mutex.h)

## Syntax

```c
SDL_Semaphore* SDL_CreateSemaphore(Uint32 initial_value);

```

## Function Parameters

|                       |                                     |
| --------------------- | ----------------------------------- |
| **initial_value**     | the starting value of the semaphore |

## Return Value

Returns a new semaphore or NULL on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

This function creates a new semaphore and initializes it with the value
`initial_value`. Each wait operation on the semaphore will atomically
decrement the semaphore value and potentially block if the semaphore value
is 0. Each post operation will atomically increment the semaphore value and
wake waiting threads and allow them to retry the wait operation.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_DestroySemaphore](SDL_DestroySemaphore)
* [SDL_PostSemaphore](SDL_PostSemaphore)
* [SDL_TryWaitSemaphore](SDL_TryWaitSemaphore)
* [SDL_GetSemaphoreValue](SDL_GetSemaphoreValue)
* [SDL_WaitSemaphore](SDL_WaitSemaphore)
* [SDL_WaitSemaphoreTimeout](SDL_WaitSemaphoreTimeout)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

