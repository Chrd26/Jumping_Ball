###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GL_SwapWindow

Update a window with OpenGL rendering.

## Header File

Defined in [<SDL3/SDL_video.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_video.h)

## Syntax

```c
int SDL_GL_SwapWindow(SDL_Window *window);

```

## Function Parameters

|                |                      |
| -------------- | -------------------- |
| **window**     | the window to change |

## Return Value

Returns 0 on success or a negative error code on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

This is used with double-buffered OpenGL contexts, which are the default.

On macOS, make sure you bind 0 to the draw framebuffer before swapping the
window, otherwise nothing will happen. If you aren't using
glBindFramebuffer(), this is the default and you won't have to do anything
extra.

## Version

This function is available since SDL 3.0.0.

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

