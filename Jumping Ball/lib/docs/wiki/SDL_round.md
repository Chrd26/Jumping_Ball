###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_round

Round `x` to the nearest integer.

## Header File

Defined in [<SDL3/SDL_stdinc.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_stdinc.h)

## Syntax

```c
double SDL_round(double x);

```

## Function Parameters

|           |                      |
| --------- | -------------------- |
| **x**     | floating point value |

## Return Value

Returns the nearest integer to `x`

## Remarks

Rounds `x` to the nearest integer. Values halfway between integers will be
rounded away from zero.

Domain: `-INF <= x <= INF`

Range: `-INF <= y <= INF`, y integer

This function operates on double-precision floating point values, use
[SDL_roundf](SDL_roundf) for single-precision floats. To get the result as
an integer type, use [SDL_lround](SDL_lround).

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_roundf](SDL_roundf)
* [SDL_lround](SDL_lround)
* [SDL_floor](SDL_floor)
* [SDL_ceil](SDL_ceil)
* [SDL_trunc](SDL_trunc)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

