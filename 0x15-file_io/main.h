#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <unistd.h>  /* Include this header for ssize_t */

/* Function prototypes */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
