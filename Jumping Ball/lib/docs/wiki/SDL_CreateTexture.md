###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateTexture

Create a texture for a rendering context.

## Header File

Defined in [<SDL3/SDL_render.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_render.h)

## Syntax

```c
SDL_Texture* SDL_CreateTexture(SDL_Renderer *renderer, SDL_PixelFormatEnum format, int access, int w, int h);

```

## Function Parameters

|                  |                                                                            |
| ---------------- | -------------------------------------------------------------------------- |
| **renderer**     | the rendering context                                                      |
| **format**       | one of the enumerated values in [SDL_PixelFormatEnum](SDL_PixelFormatEnum) |
| **access**       | one of the enumerated values in [SDL_TextureAccess](SDL_TextureAccess)     |
| **w**            | the width of the texture in pixels                                         |
| **h**            | the height of the texture in pixels                                        |

## Return Value

Returns a pointer to the created texture or NULL if no rendering context
was active, the format was unsupported, or the width or height were out of
range; call [SDL_GetError](SDL_GetError)() for more information.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_CreateTextureFromSurface](SDL_CreateTextureFromSurface)
* [SDL_CreateTextureWithProperties](SDL_CreateTextureWithProperties)
* [SDL_DestroyTexture](SDL_DestroyTexture)
* [SDL_QueryTexture](SDL_QueryTexture)
* [SDL_UpdateTexture](SDL_UpdateTexture)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

