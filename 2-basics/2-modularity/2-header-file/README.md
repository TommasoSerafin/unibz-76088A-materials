# Step: use header files

Goal: from the result of the [previous step](../1-base/), arrive at the typically C modularity approach.

## 0

Problems:

* Imagine if other than `main.c`, the functions from the `spi_bus` and `temperature_sensor` module need to be used in many other source files. The current setup means that we would have to re-declare their public functions and variables in every source file where we use them. What if at some point the signature of some functions from these two modules need to be changed? We have to change all the declarations that we added in each source file. **The code is not DRY (Don't Repeat Yourself).**.

## 1

**CHANGELOG:** To make the code more DRY, we put all the declarations of the public functions and variables in a *header file*.

Let's try to build the whole project

```sh
$ gcc main.c spi_bus.c temperature_sensor.c
# Result: builds successfully!
```

## 2

Now let's say we want to add a configuration to the initialization function of our temperature_sensor.

**CHANGELOG:** Added a public configuration data structure to the `temperature_sensor` module. Passed an instance of the configuration to the in `main.c`.

Let's build.

```sh
$ gcc main.c spi_bus.c temperature_sensor.c
# Result: builds successfully!
```

**Takeaways:**

* Defining user-defined data type using `struct`.
    * As with variables and functions, we put public data structures of a module in the header file.
    * Use of the `.` member access operator to access the field of a `struct`. The same syntax can been seen in many other languages such as Java, JavaScript, Python, etc. to access the member of an object.
* Passing const pointers as a way to avoid copy: C passes everything by value, but our `struct` may become quite big in future. We don't want to make an useless copy. 
* Use of the conditional ternary operator.

## 3

Now let's say we want to add a configuration module that takes care of loading the application configuration from NVM (non-volatile memory). It gathers the configurations from other modules into a single `struct`.

**CHANGELOG:** Added configuration module (the pair `configuration.c/.h` files)

**Takeaways:**

* Use of the `->` operator as a shorthand for dereference + member access. E.g. `(*foo).bar` is equivalent to `foo->bar`.

Let's build.

```sh
$ gcc main.c spi_bus.c temperature_sensor.c configuration.c
# Result: compilation error: redefinition of ‘struct temperature_sensor_config’
# ...
```

**CHANGELOG:** Added header guards

**Takeaways:**

* Some constructs that are typically put in a header file are repeatable (e.g. declaration of functions), but some other constructs should appear only once (e.g. definition of a `struct`). To ensure that a header file is included only once in a translation unit, we have to use header guards.
    * A header guide is a case of [conditional compilation](https://en.cppreference.com/w/c/preprocessor/conditional) using preprocessor directives.
    * A more succinct and commonly supported alternative to header guards is `#pragma once`, but it is not standard-compliant.
