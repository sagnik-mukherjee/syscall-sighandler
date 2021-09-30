// Student name: Sagnik Mukherjee (sm2367)
// Ilab machine used: ilab1.cs.rutgers.edu

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void floating_point_exception_handler(int signum) {

	printf("I am slain!\n");
	
	//0x7fffffffdee8
	//saved rip of arithmetic error frame

	//pointer to signum, reveals handler's frame on stack
	int *p;
	p = &signum;
	
	//0x7fffffffdee8 rip address - 0x7fffffffde1c signum
	//204 offset, int is 4 bytes, so 204/4 = 51-byte offset
	p += 51;
	
	//increment pointer to skip over faulty instructions
	// <+54> exception, <+60> good to go, vars unchanged
	*p += 0x6;
}

int main() {

	int x = 5, y = 0, z = 0;

	signal(SIGFPE, floating_point_exception_handler);

	z = x / y;
	
	printf("I live again!\n");

	return 0;
}
