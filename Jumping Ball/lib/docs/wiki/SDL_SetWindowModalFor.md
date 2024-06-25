###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_SetWindowModalFor

Set the window as a modal for another window.

## Header File

Defined in [<SDL3/SDL_video.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_video.h)

## Syntax

```c
int SDL_SetWindowModalFor(SDL_Window *modal_window, SDL_Window *parent_window);

```

## Function Parameters

|                       |                                        |
| --------------------- | -------------------------------------- |
| **modal_window**      | the window that should be set modal    |
| **parent_window**     | the parent window for the modal window |

## Return Value

Returns 0 on success or a negative error code on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Version

This function is available since SDL 3.0.0.

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

