#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * create_file - Creates a file.
 *
 * @filename: Name of the file to create.
 * @text_content: NULL terminated string to write to the file.
 * Return: int.
 */
int create_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	int write_file;
	int count = 0; /* For the size of text_content */

	if (filename == NULL)
		return (-1);

	/* Create the file if it does not exist with rw-------, else
	truncate ita with it current permissions. */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	/* Add text_content to filename if it is not empty */
	if (text_content != NULL)
	{
		while (*(text_content + count) != '\0')
			count++;

		write_file = write(fd, text_content, count);
	}
	if (write_file == -1)
		return (-1);

	close (fd);
	return (1);
}
