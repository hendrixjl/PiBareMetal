ARMGNU ?= arm-linux-gnueabihf
#ARMGNU ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -std=c99 -O2 -nostdlib -nostartfiles -ffreestanding



all : demo.bin demo.hex


clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.list
	rm -f *.hex

entry.o : entry.s
	$(ARMGNU)-as entry.s -o entry.o

demo.o : demo.c
	$(ARMGNU)-gcc $(COPS) -c demo.c -o demo.o

demo.elf : memmap entry.o demo.o 
	$(ARMGNU)-ld -e entry entry.o demo.o -T memmap -o demo.elf
	$(ARMGNU)-objdump -DS demo.elf > demo.list

demo.bin : demo.elf
	$(ARMGNU)-objcopy demo.elf -O binary demo.bin

demo.hex : demo.elf
	$(ARMGNU)-objcopy demo.elf -O ihex demo.hex
