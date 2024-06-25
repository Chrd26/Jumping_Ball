###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_CreateColorCursor

Create a color cursor.

## Header File

Defined in [<SDL3/SDL_mouse.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_mouse.h)

## Syntax

```c
SDL_Cursor* SDL_CreateColorCursor(SDL_Surface *surface,
                                  int hot_x,
                                  int hot_y);

```

## Function Parameters

|                 |                                                                       |
| --------------- | --------------------------------------------------------------------- |
| **surface**     | an [SDL_Surface](SDL_Surface) structure representing the cursor image |
| **hot_x**       | the x position of the cursor hot spot                                 |
| **hot_y**       | the y position of the cursor hot spot                                 |

## Return Value

Returns the new cursor on success or NULL on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_CreateCursor](SDL_CreateCursor)
* [SDL_CreateSystemCursor](SDL_CreateSystemCursor)
* [SDL_DestroyCursor](SDL_DestroyCursor)
* [SDL_SetCursor](SDL_SetCursor)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

