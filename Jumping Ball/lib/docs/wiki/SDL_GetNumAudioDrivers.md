###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetNumAudioDrivers

Use this function to get the number of built-in audio drivers.

## Header File

Defined in [<SDL3/SDL_audio.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_audio.h)

## Syntax

```c
int SDL_GetNumAudioDrivers(void);

```

## Return Value

Returns the number of built-in audio drivers.

## Remarks

This function returns a hardcoded number. This never returns a negative
value; if there are no drivers compiled into this build of SDL, this
function returns zero. The presence of a driver in this list does not mean
it will function, it just means SDL is capable of interacting with that
interface. For example, a build of SDL might have esound support, but if
there's no esound server available, SDL's esound driver would fail if used.

By default, SDL tries all drivers, in its preferred order, until one is
found to be usable.

## Thread Safety

It is safe to call this function from any thread.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetAudioDriver](SDL_GetAudioDriver)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

