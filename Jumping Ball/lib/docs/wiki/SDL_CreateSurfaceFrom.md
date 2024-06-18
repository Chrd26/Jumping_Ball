###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateSurfaceFrom

Allocate a new RGB surface with a specific pixel format and existing pixel data.

## Header File

Defined in [<SDL3/SDL_surface.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_surface.h)

## Syntax

```c
SDL_Surface* SDL_CreateSurfaceFrom(void *pixels, int width, int height, int pitch, SDL_PixelFormatEnum format);

```

## Function Parameters

|                |                                                                                    |
| -------------- | ---------------------------------------------------------------------------------- |
| **pixels**     | a pointer to existing pixel data                                                   |
| **width**      | the width of the surface                                                           |
| **height**     | the height of the surface                                                          |
| **pitch**      | the number of bytes between each row, including padding                            |
| **format**     | the [SDL_PixelFormatEnum](SDL_PixelFormatEnum) for the new surface's pixel format. |

## Return Value

Returns the new [SDL_Surface](SDL_Surface) structure that is created or
NULL if it fails; call [SDL_GetError](SDL_GetError)() for more information.

## Remarks

No copy is made of the pixel data. Pixel data is not managed automatically;
you must free the surface before you free the pixel data.

Pitch is the offset in bytes from one row of pixels to the next, e.g.
`width*4` for [`SDL_PIXELFORMAT_RGBA8888`](SDL_PIXELFORMAT_RGBA8888).

You may pass NULL for pixels and 0 for pitch to create a surface that you
will fill in with valid values later.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_CreateSurface](SDL_CreateSurface)
* [SDL_DestroySurface](SDL_DestroySurface)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

