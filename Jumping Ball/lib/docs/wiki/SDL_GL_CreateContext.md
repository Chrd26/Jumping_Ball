###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GL_CreateContext

Create an OpenGL context for an OpenGL window, and make it current.

## Header File

Defined in [<SDL3/SDL_video.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_video.h)

## Syntax

```c
SDL_GLContext SDL_GL_CreateContext(SDL_Window *window);

```

## Function Parameters

|                |                                          |
| -------------- | ---------------------------------------- |
| **window**     | the window to associate with the context |

## Return Value

Returns the OpenGL context associated with `window` or NULL on error; call
[SDL_GetError](SDL_GetError)() for more details.

## Remarks

Windows users new to OpenGL should note that, for historical reasons, GL
functions added after OpenGL version 1.1 are not available by default.
Those functions must be loaded at run-time, either with an OpenGL
extension-handling library or with
[SDL_GL_GetProcAddress](SDL_GL_GetProcAddress)() and its related functions.

[SDL_GLContext](SDL_GLContext) is an alias for `void *`. It's opaque to the
application.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GL_DeleteContext](SDL_GL_DeleteContext)
* [SDL_GL_MakeCurrent](SDL_GL_MakeCurrent)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

