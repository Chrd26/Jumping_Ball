###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateRenderer

Create a 2D rendering context for a window.

## Header File

Defined in [<SDL3/SDL_render.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_render.h)

## Syntax

```c
SDL_Renderer * SDL_CreateRenderer(SDL_Window *window, const char *name, Uint32 flags);

```

## Function Parameters

|                |                                                                                                                    |
| -------------- | ------------------------------------------------------------------------------------------------------------------ |
| **window**     | the window where rendering is displayed                                                                            |
| **name**       | the name of the rendering driver to initialize, or NULL to initialize the first one supporting the requested flags |
| **flags**      | 0, or one or more [SDL_RendererFlags](SDL_RendererFlags) OR'd together                                             |

## Return Value

Returns a valid rendering context or NULL if there was an error; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

If you want a specific renderer, you can specify its name here. A list of
available renderers can be obtained by calling
[SDL_GetRenderDriver](SDL_GetRenderDriver) multiple times, with indices
from 0 to [SDL_GetNumRenderDrivers](SDL_GetNumRenderDrivers)()-1. If you
don't need a specific renderer, specify NULL and SDL will attempt to choose
the best option for you, based on what is available on the user's system.

By default the rendering size matches the window size in pixels, but you
can call
[SDL_SetRenderLogicalPresentation](SDL_SetRenderLogicalPresentation)() to
change the content size and scaling options.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_CreateRendererWithProperties](SDL_CreateRendererWithProperties)
* [SDL_CreateSoftwareRenderer](SDL_CreateSoftwareRenderer)
* [SDL_DestroyRenderer](SDL_DestroyRenderer)
* [SDL_GetNumRenderDrivers](SDL_GetNumRenderDrivers)
* [SDL_GetRenderDriver](SDL_GetRenderDriver)
* [SDL_GetRendererInfo](SDL_GetRendererInfo)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

