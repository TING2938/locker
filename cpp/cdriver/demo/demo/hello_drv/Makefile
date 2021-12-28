KVERS = $(shell uname -r)

# Kernel modules
obj-m += hello_drv.o

# Specify flags for the module compilation.
#EXTRA_CFLAGS=-g -O0

build: kernel_modules

kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
	${CROSS_COMPILE}gcc -o hello_drv_test hello_drv_test.c 

clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean
