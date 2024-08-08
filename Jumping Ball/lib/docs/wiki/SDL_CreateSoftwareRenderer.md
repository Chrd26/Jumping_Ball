###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateSoftwareRenderer

Create a 2D software rendering context for a surface.

## Header File

Defined in [<SDL3/SDL_render.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_render.h)

## Syntax

```c
SDL_Renderer* SDL_CreateSoftwareRenderer(SDL_Surface *surface);

```

## Function Parameters

|                 |                                                                                           |
| --------------- | ----------------------------------------------------------------------------------------- |
| **surface**     | the [SDL_Surface](SDL_Surface) structure representing the surface where rendering is done |

## Return Value

Returns a valid rendering context or NULL if there was an error; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

Two other API which can be used to create [SDL_Renderer](SDL_Renderer):
[SDL_CreateRenderer](SDL_CreateRenderer)() and
[SDL_CreateWindowAndRenderer](SDL_CreateWindowAndRenderer)(). These can
_also_ create a software renderer, but they are intended to be used with an
[SDL_Window](SDL_Window) as the final destination and not an
[SDL_Surface](SDL_Surface).

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_DestroyRenderer](SDL_DestroyRenderer)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

