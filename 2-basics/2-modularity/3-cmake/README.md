# Step: use CMake

Goal: from the result of the [previous step](../2-header-file/), arrive at a setup where we perform automatic and incremental build using CMake

## 0

Problems:

* I don't want to re-build all the translation units whenever I make even the tiniest change.

We know that by passing the `-c` flag, we tell it to compile source files, but not link them into an executable. So we can do this.

```sh
# Compile the source files, but don't link
$ gcc -c main.c spi_bus.c temperature_sensor.c configuration.c
# Link the compiled object files
$ gcc main.o spi_bus.o temperature_sensor.o configuration.o

# If I change a source file, I just need to re-compile the changed source file
$ gcc -c configuration.c
# And then link everything again.
$ gcc main.o spi_bus.o temperature_sensor.o configuration.o
```

But what if a header file is changed? Then I would need to re-compile all the source files that include that header file. The compiler is able to provide such information, so with enough shell scripting we can achieve the goal of "re-compiling what changed", but why reinventing the wheel? 

## 1

**CHANGELOG:** To make building an application easy, we use CMake!

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make 

# Use a different build system, ninja
$ cmake -G Ninja ..
$ ninja
```
