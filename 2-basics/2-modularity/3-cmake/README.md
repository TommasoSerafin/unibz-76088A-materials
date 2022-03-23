# Step: use CMake

Goal: from the result of the [previous step](../2-header-file/), arrive at a setup where we perform automatic and incremental build using CMake

## 0

Problems:

* I don't want to re-build all the translation units whenever I make even the tiniest change.

We know that by passing the `-c` flag, we tell it to compile source files, but not link them into an executable. So we can do this.

```sh
# Compile the source files, but don't link
$ gcc -c main.c -Ispi_bus/ -Itemperature_sensor -Iconfiguration spi_bus/spi_bus.c temperature_sensor/temperature_sensor.c configuration/common.c configuration/fake_user_input.c
# Link the compiled object files
$ gcc main.o spi_bus.o temperature_sensor.o common.o fake_user_input.o

# If I change a source file, I just need to re-compile the changed source file
# E.g. I change configuration/common.c
$ gcc -c -Itemperature_sensor configuration/common.c
# And then link everything again.
$ gcc main.o spi_bus.o temperature_sensor.o common.o fake_user_input.o
```

But what if a header file is changed? Then I would need to re-compile all the source files that include that header file. The compiler is able to provide the header file dependency information (e.g. on `gcc` using the `-MM` and `-MT` options), so with enough shell scripting we can achieve the goal of "re-compiling what changed", but why reinventing the wheel? 

## 1

**CHANGELOG:** To make building an application easy, we use CMake!

```sh
$ mkdir build
$ cd build
$ cmake -DCONFIGURATION_FAKE_IMPL="" ..
$ make 

# Use a different build system, ninja
$ cmake -G Ninja ..
$ ninja
```
