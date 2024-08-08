###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetKeyName

Get a human-readable name for a key.

## Header File

Defined in [<SDL3/SDL_keyboard.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_keyboard.h)

## Syntax

```c
const char* SDL_GetKeyName(SDL_Keycode key);

```

## Function Parameters

|             |                                                 |
| ----------- | ----------------------------------------------- |
| **key**     | the desired [SDL_Keycode](SDL_Keycode) to query |

## Return Value

Returns a pointer to a UTF-8 string that stays valid at least until the
next call to this function. If you need it around any longer, you must copy
it. If the key doesn't have a name, this function returns an empty string
("").

## Remarks

See [SDL_Scancode](SDL_Scancode) and [SDL_Keycode](SDL_Keycode) for
details.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetKeyFromName](SDL_GetKeyFromName)
* [SDL_GetKeyFromScancode](SDL_GetKeyFromScancode)
* [SDL_GetScancodeFromKey](SDL_GetScancodeFromKey)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

