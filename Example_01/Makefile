ARMGNU = arm-none-eabi

CFLAGS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -g -c

INC = -I ../

all : kernel.img

start.o : ../start.S
	$(ARMGNU)-as ../start.S -o start.o

main.o : main.c
	$(ARMGNU)-gcc $(CFLAGS) $(INC) main.c -o main.o

lib.o : ../lib.c
	$(ARMGNU)-gcc $(CFLAGS) $(INC) ../lib.c -o lib.o

kernel.elf: main.o lib.o start.o
	$(ARMGNU)-ld main.o lib.o start.o -T ../linker.ld -o kernel.elf

kernel.img: kernel.elf
	$(ARMGNU)-objcopy kernel.elf -O binary kernel.img
	rm -f *.o *.elf


clean:
	rm -f *.o *.elf *.img