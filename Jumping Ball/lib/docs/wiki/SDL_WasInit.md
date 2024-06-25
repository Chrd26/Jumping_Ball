###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_WasInit

Get a mask of the specified subsystems which are currently initialized.

## Header File

Defined in [<SDL3/SDL_init.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_init.h)

## Syntax

```c
Uint32 SDL_WasInit(Uint32 flags);

```

## Function Parameters

|               |                                                                                        |
| ------------- | -------------------------------------------------------------------------------------- |
| **flags**     | any of the flags used by [SDL_Init](SDL_Init)(); see [SDL_Init](SDL_Init) for details. |

## Return Value

Returns a mask of all initialized subsystems if `flags` is 0, otherwise it
returns the initialization status of the specified subsystems.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_Init](SDL_Init)
* [SDL_InitSubSystem](SDL_InitSubSystem)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

