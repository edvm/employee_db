#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

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

void print(struct database_header_t *header)
{
    printf("Version: %d\n", header->version);
    printf("Employees: %d\n", header->employees);
    printf("Filelength: %d\n", header->filelength);
}

struct database_header_t load_header(int fd)
{
    struct database_header_t header = {0};
    read(fd, &header, sizeof(header));
    return header;
}

struct database_t load_db(char *filename)
{
    struct database_t db = {0};

    int fd = open(filename, O_RDONLY);
    db.fd = fd;

    if (db.fd > 0) db.header = load_header(fd);

    return db;
}