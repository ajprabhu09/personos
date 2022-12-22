
AS = i686-elf-as
all: build

boot.o: 
	$(AS) boot.S -o boot.o

build: boot.o

clean:
	rm -rf *.o

