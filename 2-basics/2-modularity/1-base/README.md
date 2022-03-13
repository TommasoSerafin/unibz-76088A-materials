# Step: base

## Initial observations

* Arrays decay into pointers. Typically the size of the array is passed along.
* Relationship between array and pointers and the equivalence of the "subscript operator" with "pointer arithmetic + dereference". E.g. `a[i]` is equivalence to `*(arr + i)`.
* Historically C did not have the boolean data type. `stdbool.h` was added in C99.
* Use of fixed width integer types from `stdint.h` (since C99) for better portability. See more on [cppreference](https://en.cppreference.com/w/c/types/integer).

## What we did

```sh
$ gcc main.c spi_bus.c temperature_sensor.c
# Result: compiler error: `is_in_error` undeclared
```

* We added the declaration `bool is_in_error;` in main.

```sh
$ gcc main.c spi_bus.c temperature_sensor.c -pedantic-errors -std=c99
# Result: compiler error: implicit declaration of functions
```
```sh
$ gcc main.c spi_bus.c temperature_sensor.c
# Result: linker error: multiple definitions
```

* We added the declaration of the functions used in the `main` function in `main.c`.

```sh
$ gcc main.c spi_bus.c temperature_sensor.c -pedantic-errors -std=c99
# Result: linker error: multiple definitions
```
Just the same as:
```sh
$ gcc main.c spi_bus.c temperature_sensor.c
# Result: linker error: multiple definitions
```

* We added prefixes to the functions

```sh
$ gcc main.c spi_bus.c temperature_sensor.c
# Result: compiles!
```

## Takeaways

* Prior to C99, functions could be used undeclared by the compilers assumes its type is `int f()`, meaning that anything can be passed to it and it return and `int`.
     * This behaviour has been removed in C99, but GCC issues only warnings rather than errors unless we use `-pedantic-errors`.
* The difference between declaration and definition.
* File scope identifiers can have *internal linkage* or *external linkage*.
    * Identifiers with *external linkage* refer to 
    * Identifiers with *internal linkage* refer to 
    * By default they have external linkage.
    * We can use the `static` *storage qualifier* to declare that an identifier shall have internal linkage.
* Identifiers with external linkage must be unique in the whole program (i.e. among all the translation units). See C99, Paragraph 6.2.2.2.
* Naming convention (e.g. using prefix) is the only solution to avoid conflicts of identifiers with external linkage
