#ifndef DB_H
#define DB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct database_header_t
{
    unsigned short version;
    unsigned short employees;
    unsigned int filelength;
};

struct database_t
{
    struct database_header_t header;
    char *data;
    int fd;
};

void print(struct database_header_t *header);
struct database_t load_db(char *filename);
struct database_header_t load_header(int fd);

#endif // DB_H