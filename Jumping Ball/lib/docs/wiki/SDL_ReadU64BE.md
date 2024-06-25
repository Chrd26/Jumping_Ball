###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_ReadU64BE

Use this function to read 64 bits of big-endian data from an [SDL_IOStream](SDL_IOStream) and return in native format.

## Header File

Defined in [<SDL3/SDL_iostream.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_iostream.h)

## Syntax

```c
SDL_bool SDL_ReadU64BE(SDL_IOStream *src, Uint64 *value);

```

## Function Parameters

|               |                                        |
| ------------- | -------------------------------------- |
| **src**       | the stream from which to read data     |
| **value**     | a pointer filled in with the data read |

## Return Value

Returns [SDL_TRUE](SDL_TRUE) on successful write, [SDL_FALSE](SDL_FALSE) on
failure; call [SDL_GetError](SDL_GetError)() for more information.

## Remarks

SDL byteswaps the data only if necessary, so the data returned will be in
the native byte order.

## Version

This function is available since SDL 3.0.0.

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

