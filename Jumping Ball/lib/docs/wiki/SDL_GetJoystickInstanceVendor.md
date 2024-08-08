###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_GetJoystickInstanceVendor

Get the USB vendor ID of a joystick, if available.

## Header File

Defined in [<SDL3/SDL_joystick.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_joystick.h)

## Syntax

```c
Uint16 SDL_GetJoystickInstanceVendor(SDL_JoystickID instance_id);

```

## Function Parameters

|                     |                          |
| ------------------- | ------------------------ |
| **instance_id**     | the joystick instance ID |

## Return Value

Returns the USB vendor ID of the selected joystick. If called with an
invalid instance_id, this function returns 0.

## Remarks

This can be called before any joysticks are opened. If the vendor ID isn't
available this function returns 0.

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_GetJoystickVendor](SDL_GetJoystickVendor)
* [SDL_GetJoysticks](SDL_GetJoysticks)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

