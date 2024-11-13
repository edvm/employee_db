#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "db.h"

int validate_args(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{

    if (validate_args(argc, argv)) return -1;

    struct database_t db = load_db(argv[1]);
    if (db.fd <= 0) return -1;

    print(&db.header);

    close(db.fd);

    return 0;
}
