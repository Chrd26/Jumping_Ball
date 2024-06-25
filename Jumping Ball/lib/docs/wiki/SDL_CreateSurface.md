###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateSurface

Allocate a new RGB surface with a specific pixel format.

## Header File

Defined in [<SDL3/SDL_surface.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_surface.h)

## Syntax

```c
SDL_Surface* SDL_CreateSurface(int width, int height, SDL_PixelFormatEnum format);

```

## Function Parameters

|                |                                                                                    |
| -------------- | ---------------------------------------------------------------------------------- |
| **width**      | the width of the surface                                                           |
| **height**     | the height of the surface                                                          |
| **format**     | the [SDL_PixelFormatEnum](SDL_PixelFormatEnum) for the new surface's pixel format. |

## Return Value

Returns the new [SDL_Surface](SDL_Surface) structure that is created or
NULL if it fails; call [SDL_GetError](SDL_GetError)() for more information.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_CreateSurfaceFrom](SDL_CreateSurfaceFrom)
* [SDL_DestroySurface](SDL_DestroySurface)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

