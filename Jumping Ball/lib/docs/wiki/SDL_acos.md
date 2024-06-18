###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_acos

Compute the arc cosine of `x`.

## Header File

Defined in [<SDL3/SDL_stdinc.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_stdinc.h)

## Syntax

```c
double SDL_acos(double x);

```

## Function Parameters

|           |                      |
| --------- | -------------------- |
| **x**     | floating point value |

## Return Value

Returns arc cosine of `x`, in radians

## Remarks

The definition of `y = acos(x)` is `x = cos(y)`.

Domain: `-1 <= x <= 1`

Range: `0 <= y <= Pi`

This function operates on double-precision floating point values, use
[SDL_acosf](SDL_acosf) for single-precision floats.

This function may use a different approximation across different versions,
platforms and configurations. i.e, it can return a different value given
the same input on different machines or operating systems, or if SDL is
updated.

## Thread Safety

It is safe to call this function from any thread.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_acosf](SDL_acosf)
* [SDL_asin](SDL_asin)
* [SDL_cos](SDL_cos)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

