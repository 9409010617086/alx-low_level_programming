#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * append_text_to_file - Append_text_to_file.
 *
 * @filename:
 * @text_content:
 * Return: int 
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	int count = 0; /* To count the chars in  text_content */
	int append_file;

	if (filename == NULL)
		return (-1);
    
	fd = open(filename, O_WRONLY | O_APPEND);

	/* If there is an error fr = -1 */
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (*(text_content + count) != '\0')
			count++;
        
		append_file = write(fd, text_content, count);
	}

	if (append_file == -1)
		return (-1);

	return (1);
}
