# OBJRenderableDemo

This project contains the working OBJImport library and associated tests.

The OBJLoader loads the file.

The mesh builder takes the file data and converts it into the mesh.

There is a vertex cache - this is due to the obj format reading in different indices for positions, texture coordinates and normals.
In order to convert this information into a renderable format this needs reindexing with an index for each vertex which differs in any of the above information.
As searching the vertex buffer would be extremely slow a vertex cache is added.

The mesh contains an index buffer, vertex buffer and primitive command list.

The primitive command list contains triangle or quad information, the index offset and length.

There is also a renderable demo project, but this is sadly empty as I ran out of time to implement the rendering :-)

OBJRenderableTests contains all the tests for the various interfaces.