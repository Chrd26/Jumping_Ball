###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_AndroidGetActivity

Retrieve the Java instance of the Android activity class.

## Header File

Defined in [<SDL3/SDL_system.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_system.h)

## Syntax

```c
void * SDL_AndroidGetActivity(void);

```

## Return Value

Returns the jobject representing the instance of the Activity class of the
Android application, or NULL on error.

## Remarks

The prototype of the function in SDL's code actually declares a void*
return type, even if the implementation returns a jobject. The rationale
being that the SDL headers can avoid including jni.h.

The jobject returned by the function is a local reference and must be
released by the caller. See the PushLocalFrame() and PopLocalFrame() or
DeleteLocalRef() functions of the Java native interface:

https://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/functions.html

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_AndroidGetJNIEnv](SDL_AndroidGetJNIEnv)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

