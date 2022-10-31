#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"


/**
 * read_textfile - reads a text file and prints it to the POSIX STDOUT.
 * @filename: Name of file to open.
 * @letter: Number of char in file.
 * Return: ssize_t.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd; /* file descriptor */
	ssize_t read_file, write_file;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char) * letters);

	/* -1 implies an error in opening the file */
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	read_file = read(fd, buf, letters);

	if (read_file == -1)
	{
		free(buf);
		return (0);
	}

	close(fd);

	write_file = write(STDOUT_FILENO, buf, read_file);

	if (write_file == -1)
	{
		free(buf);
		return (0);
	}

	if (write_file != read_file)
		return (0);
	return (read_file);
}
