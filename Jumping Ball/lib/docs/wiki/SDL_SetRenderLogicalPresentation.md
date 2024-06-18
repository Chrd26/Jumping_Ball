###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_SetRenderLogicalPresentation

Set a device independent resolution and presentation mode for rendering.

## Header File

Defined in [<SDL3/SDL_render.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_render.h)

## Syntax

```c
int SDL_SetRenderLogicalPresentation(SDL_Renderer *renderer, int w, int h, SDL_RendererLogicalPresentation mode, SDL_ScaleMode scale_mode);

```

## Function Parameters

|                    |                                      |
| ------------------ | ------------------------------------ |
| **renderer**       | the rendering context                |
| **w**              | the width of the logical resolution  |
| **h**              | the height of the logical resolution |
| **mode**           | the presentation mode used           |
| **scale_mode**     | the scale mode used                  |

## Return Value

Returns 0 on success or a negative error code on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Remarks

This function sets the width and height of the logical rendering output. A
render target is created at the specified size and used for rendering and
then copied to the output during presentation.

You can disable logical coordinates by setting the mode to
[SDL_LOGICAL_PRESENTATION_DISABLED](SDL_LOGICAL_PRESENTATION_DISABLED), and
in that case you get the full pixel resolution of the output window.

You can convert coordinates in an event into rendering coordinates using
[SDL_ConvertEventToRenderCoordinates](SDL_ConvertEventToRenderCoordinates)().

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_ConvertEventToRenderCoordinates](SDL_ConvertEventToRenderCoordinates)
* [SDL_GetRenderLogicalPresentation](SDL_GetRenderLogicalPresentation)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

