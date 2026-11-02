# Composite

Composite arranges objects in a tree and lets clients treat individual objects
and groups through the same interface.

`FileSystemEntry` is the component interface, `File` is a leaf, and `Directory`
owns child entries. The in-memory example contains a 100-byte file and a nested
directory with 200-byte and 300-byte files. Recursive size calculation gives
500 bytes for the nested directory and 600 bytes for the root.

Run from the repository root after building:

```sh
./build/composite
```
