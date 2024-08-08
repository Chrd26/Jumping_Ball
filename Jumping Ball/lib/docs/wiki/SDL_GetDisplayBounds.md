###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetDisplayBounds

Get the desktop area represented by a display.

## Header File

Defined in [<SDL3/SDL_video.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_video.h)

## Syntax

```c
int SDL_GetDisplayBounds(SDL_DisplayID displayID, SDL_Rect *rect);

```

## Function Parameters

|                   |                                                                      |
| ----------------- | -------------------------------------------------------------------- |
| **displayID**     | the instance ID of the display to query                              |
| **rect**          | the [SDL_Rect](SDL_Rect) structure filled in with the display bounds |

## Return Value

Returns 0 on success or a negative error code on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

The primary display is always located at (0,0).

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetDisplayUsableBounds](SDL_GetDisplayUsableBounds)
* [SDL_GetDisplays](SDL_GetDisplays)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

