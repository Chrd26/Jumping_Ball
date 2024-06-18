###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetSurfaceColorKey

Get the color key (transparent pixel) for a surface.

## Header File

Defined in [<SDL3/SDL_surface.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_surface.h)

## Syntax

```c
int SDL_GetSurfaceColorKey(SDL_Surface *surface, Uint32 *key);

```

## Function Parameters

|                 |                                                   |
| --------------- | ------------------------------------------------- |
| **surface**     | the [SDL_Surface](SDL_Surface) structure to query |
| **key**         | a pointer filled in with the transparent pixel    |

## Return Value

Returns 0 on success or a negative error code on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

The color key is a pixel of the format used by the surface, as generated by
[SDL_MapRGB](SDL_MapRGB)().

If the surface doesn't have color key enabled this function returns -1.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_SetSurfaceColorKey](SDL_SetSurfaceColorKey)
* [SDL_SurfaceHasColorKey](SDL_SurfaceHasColorKey)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)
