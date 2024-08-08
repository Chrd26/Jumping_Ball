###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_ResetHint

Reset a hint to the default value.

## Header File

Defined in [<SDL3/SDL_hints.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_hints.h)

## Syntax

```c
SDL_bool SDL_ResetHint(const char *name);

```

## Function Parameters

|              |                 |
| ------------ | --------------- |
| **name**     | the hint to set |

## Return Value

Returns [SDL_TRUE](SDL_TRUE) if the hint was set, [SDL_FALSE](SDL_FALSE)
otherwise.

## Remarks

This will reset a hint to the value of the environment variable, or NULL if
the environment isn't set. Callbacks will be called normally with this
change.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_SetHint](SDL_SetHint)
* [SDL_ResetHints](SDL_ResetHints)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

