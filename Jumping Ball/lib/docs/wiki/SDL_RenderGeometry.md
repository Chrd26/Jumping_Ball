###### (This is the documentation for SDL3, which is under heavy development and the API is changing! [SDL2](https://wiki.libsdl.org/SDL2/) is the current stable version!)
# SDL_RenderGeometry

Render a list of triangles, optionally using a texture and indices into the vertex array Color and alpha modulation is done per vertex ([SDL_SetTextureColorMod](SDL_SetTextureColorMod) and [SDL_SetTextureAlphaMod](SDL_SetTextureAlphaMod) are ignored).

## Header File

Defined in [<SDL3/SDL_render.h>](https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_render.h)

## Syntax

```c
int SDL_RenderGeometry(SDL_Renderer *renderer,
                       SDL_Texture *texture,
                       const SDL_Vertex *vertices, int num_vertices,
                       const int *indices, int num_indices);

```

## Function Parameters

|                      |                                                                                                                              |
| -------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| **renderer**         | The rendering context.                                                                                                       |
| **texture**          | (optional) The SDL texture to use.                                                                                           |
| **vertices**         | Vertices.                                                                                                                    |
| **num_vertices**     | Number of vertices.                                                                                                          |
| **indices**          | (optional) An array of integer indices into the 'vertices' array, if NULL all vertices will be rendered in sequential order. |
| **num_indices**      | Number of indices.                                                                                                           |

## Return Value

Returns 0 on success, or -1 if the operation is not supported

## Version

This function is available since SDL 3.0.0.

## See Also

* [SDL_RenderGeometryRaw](SDL_RenderGeometryRaw)

----
[CategoryAPI](CategoryAPI), [CategoryAPIFunction](CategoryAPIFunction)

