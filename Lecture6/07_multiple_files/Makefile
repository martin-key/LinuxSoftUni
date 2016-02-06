obj-m +=kernel_module.o
kernel_module-objs = start.o stop.o module.o
KERNEL_DIR=/lib/modules/$(shell uname -r)/build

all: 
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
