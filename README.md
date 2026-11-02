# Design patterns

C++20 homework examples of the five GoF creational patterns and the Composite
structural pattern. Each example is a standalone program with a brief description.

See [SPEC.md](SPEC.md) for the agreed requirements.

## Build

Requires a C++20 compiler and CMake 3.20 or newer. No external dependencies.

```sh
cmake -S . -B build
cmake --build build
```

## Examples

| Pattern | Example | Run from the repository root |
|---|---|---|
| [Factory Method](creational/factory_method/) | Road and sea delivery | `./build/factory_method` |
| [Abstract Factory](creational/abstract_factory/) | Matching Windows/macOS controls | `./build/abstract_factory` |
