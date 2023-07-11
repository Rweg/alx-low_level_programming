#include "main.h"
#include <fcntl.h>

/**
 * create_file - Creates a file with given text content
 * @filename: The name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
        int fd, w, len = 0;

        if (!filename)
                return (-1);

        if (text_content)
        {
                while (text_content[len])
                        len++;
        }

        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd == -1)
                return (-1);

        if (text_content)
        {
                w = write(fd, text_content, len);
                if (w == -1 || w != len)
                {
                        close(fd);
                        return (-1);
                }
        }

        close(fd);

        return (1);
}
