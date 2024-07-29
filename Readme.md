# Weird ARM happenings

This is the repository for [this SO issue](http://example.com) (TBA) to
hopefully shed some light onto what the heck is happening. This project is
set up for the STM32 L432KC microcontroller which uses an ARM Cortex M4 chip.
It is a stripped down version of the original project, the most important files
are `stopwatch.c` and `head.S`.

## Dependencies

This project has no dependencies, but requires the arm-none-eabi toolchain.
To install it, run `apt install gcc-arm-none-eabi` or the equivalent for your
package manager, and adjust the name of course. This project uses GNU Make for
building.

## Building

To build the project, run `make` in the command line. You can also
automatically upload it with `make upload`, which requires that the
microcontroller's file system is mounted at `/media/$(USER)/L432KC`. Adjust
the path as needed.