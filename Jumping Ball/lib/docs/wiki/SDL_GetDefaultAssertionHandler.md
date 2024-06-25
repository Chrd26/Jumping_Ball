###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetDefaultAssertionHandler

Get the default assertion handler.

## Header File

Defined in [<SDL3/SDL_assert.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_assert.h)

## Syntax

```c
SDL_AssertionHandler SDL_GetDefaultAssertionHandler(void);

```

## Return Value

Returns the default [SDL_AssertionHandler](SDL_AssertionHandler) that is
called when an assert triggers.

## Remarks

This returns the function pointer that is called by default when an
assertion is triggered. This is an internal function provided by SDL, that
is used for assertions when
[SDL_SetAssertionHandler](SDL_SetAssertionHandler)() hasn't been used to
provide a different function.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetAssertionHandler](SDL_GetAssertionHandler)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

