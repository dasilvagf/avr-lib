# Build lib objects
rm -rf build
mkdir build

avr-gcc -I. -Os -DF_CPU=8000000 -mmcu=attiny85 -c src/avr-base/SPI.c -o build/spi.o
avr-gcc -I. -Os -DF_CPU=8000000 -mmcu=attiny85 -c src/avr-base/arduino.c -o build/arduino.o

# Create lib
rm -rf bin
mkdir bin
avr-ar rcs bin/libavr.a build/spi.o build/arduino.o