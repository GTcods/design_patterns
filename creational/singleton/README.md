# Singleton

Singleton provides one instance of a class through a shared access point.

`Logger::instance()` returns a function-local static logger. Its constructor is
private, and copying and moving are disabled. The program obtains two references,
shows that they refer to the same instance, and logs messages through both.

Run from the repository root after building:

```sh
./build/singleton
```
