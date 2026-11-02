# Prototype

Prototype creates a new object by copying an existing object through a common
cloning interface.

`Shape::clone()` is implemented by `Circle` and `Rectangle`, preserving their
concrete types and dimensions. The client clones shapes without knowing their
types, moves each clone, and prints both objects to show that the originals are
unchanged.

Run from the repository root after building:

```sh
./build/prototype
```
