###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateThread

Create a new thread with a default stack size.

## Header File

Defined in [<SDL3/SDL_thread.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_thread.h)

## Syntax

```c
SDL_Thread * SDL_CreateThread(SDL_ThreadFunction fn, const char *name, void *data);

```

## Function Parameters

|              |                                                                                 |
| ------------ | ------------------------------------------------------------------------------- |
| **fn**       | the [SDL_ThreadFunction](SDL_ThreadFunction) function to call in the new thread |
| **name**     | the name of the thread                                                          |
| **data**     | a pointer that is passed to `fn`                                                |

## Return Value

Returns an opaque pointer to the new thread object on success, NULL if the
new thread could not be created; call [SDL_GetError](SDL_GetError)() for
more information.

## Remarks

This is equivalent to calling:

```c
SDL_CreateThreadWithStackSize(fn, name, 0, data);
```

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_CreateThreadWithStackSize](SDL_CreateThreadWithStackSize)
* [SDL_WaitThread](SDL_WaitThread)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

