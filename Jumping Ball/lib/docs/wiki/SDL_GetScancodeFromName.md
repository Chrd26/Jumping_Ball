###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetScancodeFromName

Get a scancode from a human-readable name.

## Header File

Defined in [<SDL3/SDL_keyboard.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_keyboard.h)

## Syntax

```c
SDL_Scancode SDL_GetScancodeFromName(const char *name);

```

## Function Parameters

|              |                                  |
| ------------ | -------------------------------- |
| **name**     | the human-readable scancode name |

## Return Value

Returns the [SDL_Scancode](SDL_Scancode), or
[`SDL_SCANCODE_UNKNOWN`](SDL_SCANCODE_UNKNOWN) if the name wasn't
recognized; call [SDL_GetError](SDL_GetError)() for more information.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetKeyFromName](SDL_GetKeyFromName)
* [SDL_GetScancodeFromKey](SDL_GetScancodeFromKey)
* [SDL_GetScancodeName](SDL_GetScancodeName)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

