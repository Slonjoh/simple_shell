#ifndef G_ETLINE_H
#define G_ETLINE_H


char *get_line(void);
static void rm_buffer(void);
static char read_only(void);
static char *assign_line(int len);
static char *form_line(int line_len);
static char *handle_EOL(int line_len);

#endif/*G_ETLINE_H*/
