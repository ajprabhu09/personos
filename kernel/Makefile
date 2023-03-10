
ARCH = i386
INC_DIR = inc

SRC_DIR = src

ARCH_DIR = arch/${ARCH}


BUILD_SRC_DIR = build/c
BUILD_ASM_DIR = build/asm



CC=i686-elf-gcc
AS=i686-elf-as


CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -mno-red-zone -I$(INC_DIR)

# Modify this to add object files

OBJS = $(BUILD_SRC_DIR)/kernel.o $(BUILD_ASM_DIR)/boot.o $(BUILD_SRC_DIR)/kvga.o $(BUILD_ASM_DIR)/crti.o $(BUILD_ASM_DIR)/crtn.o


all: $(OBJS) build/boot.bin

cb: clean $(OBJS) build/boot.bin 

$(BUILD_SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC)  -c $< -o $@ $(CFLAGS)

$(BUILD_SRC_DIR)/%.o: $(ARCH_DIR)/src/%.c
	$(CC)  -c $< -o $@ $(CFLAGS)

$(BUILD_ASM_DIR)/%.o: $(ARCH_DIR)/%.S
	$(AS) $< -o $@ 


clean:
	rm -rf $(OBJS) *.iso build/*.bin build/personos/

setup:
	mkdir -p $(BUILD_ASM_DIR) $(BUILD_SRC_DIR)

build/boot.bin: $(OBJS)
	$(CC) -T $(ARCH_DIR)/linker.lds -o build/boot.bin -ffreestanding -O2 -nostdlib $(OBJS) -lgcc

iso:
	mkdir -p personos/boot/grub
	cp build/boot.bin personos/boot/boot.bin
	cp grub.cfg personos/boot/grub/grub.cfg
	grub-mkrescue -o personos.iso personos/
	rm -rf personos/

# --------------------TESTING HELPERS-----------------------------
run_iso:
	qemu-system-i386 -display curses  personos.iso

run:
	qemu-system-i386 -display curses -s -S -kernel build/boot.bin

killemu:
	killall qemu-system-i386

format: 
	find ./ -iname *.h -o -iname *.c | xargs clang-format -i