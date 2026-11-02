# Builder

Builder separates an object's step-by-step construction from the finished
product.

`MealBuilder` defines construction steps, and `VegetarianMealBuilder` assembles a
`Meal`. `MealDirector` applies a full-meal recipe through the builder interface.
The client also builds a main-course-only meal by omitting the optional steps.
Taking a meal resets the builder so later meals do not inherit earlier components.

Run from the repository root after building:

```sh
./build/builder
```
