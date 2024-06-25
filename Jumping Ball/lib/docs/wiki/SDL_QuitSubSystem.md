###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_QuitSubSystem

Shut down specific SDL subsystems.

## Header File

Defined in [<SDL3/SDL_init.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_init.h)

## Syntax

```c
void SDL_QuitSubSystem(Uint32 flags);

```

## Function Parameters

|               |                                                                                        |
| ------------- | -------------------------------------------------------------------------------------- |
| **flags**     | any of the flags used by [SDL_Init](SDL_Init)(); see [SDL_Init](SDL_Init) for details. |

## Remarks

You still need to call [SDL_Quit](SDL_Quit)() even if you close all open
subsystems with [SDL_QuitSubSystem](SDL_QuitSubSystem)().

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_InitSubSystem](SDL_InitSubSystem)
* [SDL_Quit](SDL_Quit)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

