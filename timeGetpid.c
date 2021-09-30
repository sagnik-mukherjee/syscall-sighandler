/*
 * Sagnik Mukherjee
 * CS416 - timeGetpid.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	long N = 100000; // 100K iterations
	struct timeval start, end;

	gettimeofday(&start, NULL);
	for (int i = 0; i < N; i++)
		getpid();
	gettimeofday(&end, NULL);
	
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	float avg = micros / (N * 1.0);
	
	printf("Syscalls Performed: %ld\nTotal Elapsed Time: %ld microseconds\nAverage Time Per Syscall: %f microseconds\n", N, micros, avg);
	
	return 0;
}
