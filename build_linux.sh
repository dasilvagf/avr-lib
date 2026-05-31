# Build lib objects
rm -rf build
mkdir build

avr-gcc -I. -Os -DF_CPU=16000000 -mmcu=atmega328p -c src/avr-base/SPI.c -o build/spi.o
avr-gcc -I. -Os -DF_CPU=16000000 -mmcu=atmega328p -c src/boards/arduino/arduino.c -o build/arduino.o

# Create lib
rm -rf bin
mkdir bin
avr-ar rcs bin/libavr.a build/spi.o build/arduino.o