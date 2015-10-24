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

output.elf: main.o lib.o start.o
	$(ARMGNU)-ld start.o main.o lib.o -T ../linker.ld -Map output.map -o output.elf

kernel.img: output.elf
	$(ARMGNU)-objcopy output.elf -O binary kernel.img
	$(ARMGNU)-objdump -D output.elf > output.list
	$(ARMGNU)-nm -n output.elf > output.symbol
	rm -f *.o

clean:
	rm -f *.o *.elf *.img *.map *.list *.symbol