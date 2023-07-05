# Make process dump core elf file, so that gdb can read it and debug it

## Set unilimited amount of cores to be dumped
	
	ulimit -c unlimited

## In sudo mode:
	
	sudo su
	echo "./core" > /proc/sys/kernel/core_pattern
	exit

## In GDB

	gdb ./file ./core
	# do what you have to do 

