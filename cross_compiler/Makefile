Nothing:


GCC_VERSION = 9.3.0
BINUTILS_VERSION = 2.35



cleandeps:
	rm -rf binutils*.gz gcc*.gz *.html


verclean: cleandeps
	rm -rf *.log

binutils-$(BINUTILS_VERSION).tar.gz:
	wget https://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.gz
gcc-$(GCC_VERSION).tar.gz:	
	wget https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.gz


clonedeps: binutils-$(BINUTILS_VERSION).tar.gz gcc-$(GCC_VERSION).tar.gz


	
unzip:
	tar -xvf binutils-$(BINUTILS_VERSION).tar.gz
	tar -xvf gcc-$(GCC_VERSION).tar.gz

check:
	# Check deps here https://wiki.osdev.org/GCC_Cross-Compiler
	# TODO: make this automatic


build:
	BINUTILS_VERSION=${BINUTILS_VERSION} GCC_VERSION=${GCC_VERSION} sh ./buildbintools.sh