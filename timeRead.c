/*
 * Sagnik Mukherjee
 * CS416 - timeRead.c
 * <use in terminal> xfs_mkfile 512000000 test.txt
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	char filename[] = "test.txt";
	size_t count = 4000;
	char buffer[count];
	long fileSize = 512000000;
	int r;
	int file = open(filename, O_RDONLY, 0);
	struct timeval start, end;

	gettimeofday(&start, NULL);

	if (file)
		while ((r = read(file, buffer, count)) > 0)

	gettimeofday(&end, NULL);
	
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	float avg = micros / (fileSize * 1.0);
	
	printf("Syscalls Performed: %ld\nTotal Elapsed Time: %ld microseconds\nAverage Time Per Syscall: %f microseconds\n",
		(fileSize/count), micros, avg);

	close(file);	
	return 0;
}
