#ifndef G_ETLINE_H
#define G_ETLINE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



char *get_line(void);
void rm_buffer(void);
char read_only(void);
char *assign_line(int len);
char *form_line(int line_len);
char *handle_EOL(int line_len);


#endif/*G_ETLINE_H*/
