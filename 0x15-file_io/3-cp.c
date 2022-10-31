#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 *
 * @argc: Num
 * @argv:
 * Return: int.
 */
int main(int argc, char **argv)
{
	int file_from, file_to;
	ssize_t read_from = 1024, write_to;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		/* 2 - STDERR_FILENO */
		exit(97);
	}

	file_from = open(argv[1], O_RDWR);

	if (file_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0664);

	if (file_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while (read_from == BUFFER_SIZE)
	{
		read_from = read(file_from, buffer, BUFFER_SIZE);
		if (read_from == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n",argv[1]);
			exit(98);
		}

		write_to = write(file_to, buffer, read_from);
	}

	if (write_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	close(file_from);
	close(file_to);

	if (close(file_from) == -1 || close(file_to) == -1)
		return (100);

	return (0);
}
