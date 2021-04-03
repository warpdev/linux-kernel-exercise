
obj-m := mymodule.o
ccflags-y += -I/include
all:
	make -C ~/linux-5.11.5/ M=$(PWD) modules
clean:
	make -C ~/linux-5.11.5/ M=$(PWD) clean

