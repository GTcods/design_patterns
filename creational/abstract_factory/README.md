# Abstract Factory

Abstract Factory creates families of related objects without exposing their
concrete classes to the client.

`GUIFactory` creates abstract `Button` and `Checkbox` products. `WindowsFactory`
and `MacOSFactory` each provide a matching family. `renderInterface()` works with
either family through the same abstract interfaces.

Run from the repository root after building:

```sh
./build/abstract_factory
```
