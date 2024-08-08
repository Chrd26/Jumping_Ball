###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_SetBooleanProperty

Set a boolean property on a set of properties.

## Header File

Defined in [<SDL3/SDL_properties.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_properties.h)

## Syntax

```c
int SDL_SetBooleanProperty(SDL_PropertiesID props, const char *name, SDL_bool value);

```

## Function Parameters

|               |                                    |
| ------------- | ---------------------------------- |
| **props**     | the properties to modify           |
| **name**      | the name of the property to modify |
| **value**     | the new value of the property      |

## Return Value

Returns 0 on success or a negative error code on failure; call
[SDL_GetError](SDL_GetError)() for more information.

## Thread Safety

It is safe to call this function from any thread.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetBooleanProperty](SDL_GetBooleanProperty)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

