# Project specification

## Scope

Create a compact C++ homework submission with one standalone example for each
GoF creational pattern and Composite as the only structural pattern.

Use C++20 and CMake with no external dependencies. Do not include CTest, separate
test files, GitHub Actions, lengthy tutorials, diagrams, or unnecessary code
comments.

## Structure

```text
design_patterns/
  .gitignore
  CMakeLists.txt
  README.md
  SPEC.md
  creational/
    factory_method/
      example.cpp
      README.md
    abstract_factory/
      example.cpp
      README.md
    builder/
      example.cpp
      README.md
    prototype/
      example.cpp
      README.md
    singleton/
      example.cpp
      README.md
  structural/
    composite/
      example.cpp
      README.md
```

Each pattern folder contains exactly one self-contained `example.cpp` with its
own `main()` and one brief `README.md` explaining the pattern and its example.
The root README links to the examples and provides build and run commands.

## Examples

| Pattern | Scenario | Required behavior |
|---|---|---|
| Factory Method | Road and sea delivery | A common logistics operation obtains its transport through an overridable factory method. Road and sea creators supply different concrete transports. |
| Abstract Factory | Windows and macOS controls | Each concrete factory supplies a matching button-and-checkbox family through abstract product interfaces. |
| Builder | Meals with optional components | A builder constructs a meal step by step. A director demonstrates a reusable recipe, and client-selected steps demonstrate an optional component. |
| Prototype | Cloning shapes | Cloning through a polymorphic interface preserves the concrete shape type. Modifying the clone does not change the original. |
| Singleton | Application logger | A function-local static instance, private constructor, and disabled copying/moving provide one logger. Separate accesses demonstrate the same instance and visible log output. |
| Composite | Files and directories | Files and directories share a component interface. Directories own child components, including nested directories, and compute recursive total size. |

Use virtual destructors for polymorphic interfaces, value semantics where
appropriate, and `std::unique_ptr` for exclusive polymorphic ownership. Avoid raw
owning pointers, interactive input, external files, and unnecessary configuration.
Output must be deterministic and must not print object addresses.

## Build and validation

CMake must require C++20 with compiler extensions disabled and provide these
executable targets:

- `factory_method`
- `abstract_factory`
- `builder`
- `prototype`
- `singleton`
- `composite`

Build and run directly:

```sh
cmake -S . -B build
cmake --build build
./build/factory_method
./build/abstract_factory
./build/builder
./build/prototype
./build/singleton
./build/composite
```

All six executables must finish successfully. Inspect their output to verify
both delivery methods, both matching UI families, builder-controlled meal
composition, independent prototype copies, shared singleton identity, and
correct nested composite totals. Compilation and exit status alone do not prove
the patterns are demonstrated correctly.

Generated build output must be ignored by Git.

## Commit and publication requirements

Use branch `main` and make eight logical commits:

1. Commit this specification before implementation.
2. Commit the root CMake setup, README, and ignore rules.
3. Commit Factory Method.
4. Commit Abstract Factory.
5. Commit Builder.
6. Commit Prototype.
7. Commit Singleton.
8. Commit Composite.

Each pattern commit includes its source, brief document, CMake registration, and
root README link. Validate each example before committing it and verify the
complete submission before publication.

Create `GTcods/design_patterns` as a private GitHub repository and push the
complete commit history. Confirm private visibility, matching local and remote
`main`, and a clean local worktree. Collaborator invitations are outside scope.
