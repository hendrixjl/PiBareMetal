ARMGNU ?= arm-linux-gnueabihf
#ARMGNU ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -std=c99 -nostdlib -nostartfiles -ffreestanding



all : activity.bin


clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.list

entry.o : entry.s
	$(ARMGNU)-as entry.s -o entry.o

activity.o : activity.c
	$(ARMGNU)-gcc $(COPS) -c activity.c -o activity.o

activity.elf : memmap entry.o activity.o 
	$(ARMGNU)-ld -e entry entry.o activity.o -T memmap -o activity.elf
	$(ARMGNU)-objdump -DS activity.elf > activity.list

activity.bin : activity.elf
	$(ARMGNU)-objcopy activity.elf -O binary activity.bin

