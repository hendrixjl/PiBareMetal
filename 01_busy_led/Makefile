ARMGNU ?= arm-linux-gnueabihf
#ARMGNU ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -std=c99 -O2 -nostdlib -nostartfiles -ffreestanding



all : activity.bin activity.hex


clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.list
	rm -f *.hex

entry.o : entry.s
	$(ARMGNU)-as entry.s -o entry.o

activity.o : activity.c
	$(ARMGNU)-gcc $(COPS) -c activity.c -o activity.o

activity.elf : memmap entry.o activity.o 
	$(ARMGNU)-ld -e entry entry.o activity.o -T memmap -o activity.elf
	$(ARMGNU)-objdump -DS activity.elf > activity.list

activity.bin : activity.elf
	$(ARMGNU)-objcopy activity.elf -O binary activity.bin

activity.hex : activity.elf
	$(ARMGNU)-objcopy activity.elf -O ihex activity.hex
