###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_HINT_WINDOW_ACTIVATE_WHEN_RAISED

A variable controlling whether the window is activated when the [SDL_RaiseWindow](SDL_RaiseWindow) function is called.

## Header File

Defined in [<SDL3/SDL_hints.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_hints.h)

## Syntax

```c
#define SDL_HINT_WINDOW_ACTIVATE_WHEN_RAISED    "SDL_WINDOW_ACTIVATE_WHEN_RAISED"
```

## Remarks

The variable can be set to the following values:

- "0": The window is not activated when the
  [SDL_RaiseWindow](SDL_RaiseWindow) function is called.
- "1": The window is activated when the [SDL_RaiseWindow](SDL_RaiseWindow)
  function is called. (default)

This hint can be set anytime.

## Version

This hint is available since SDL 3.0.0.

----
[CategoryAPI](CategoryAPI), [CategoryAPIMacro](CategoryAPIMacro)

