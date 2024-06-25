###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetPixelFormatName

Get the human readable name of a pixel format.

## Header File

Defined in [<SDL3/SDL_pixels.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_pixels.h)

## Syntax

```c
const char* SDL_GetPixelFormatName(SDL_PixelFormatEnum format);

```

## Function Parameters

|                |                           |
| -------------- | ------------------------- |
| **format**     | the pixel format to query |

## Return Value

Returns the human readable name of the specified pixel format or
[`SDL_PIXELFORMAT_UNKNOWN`](SDL_PIXELFORMAT_UNKNOWN) if the format isn't
recognized.

## Version

This function is available since SDL 3.0.0.

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

