sss#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

int main ( int argc, char *argv[])
{
    struct stat FileAttrib;

    if (argc != 2)
        printf("Usage: <executable> <file>\n");
    else
    {
        if (stat(argv[(argc - 1)], &FileAttrib) < 0)
            printf("File Error Message = %s\n", strerror(errno));
        else
        {
            tm *pTm = gmtime(&FileAttrib.st_atime);
            printf("File last accessed on: %.2i/%.2i/%.2i at %.2i:%.2i:%.2i GMT\n",
                     (pTm->tm_mon + 1),
                     pTm->tm_mday,
         (pTm->tm_year % 100),
         pTm->tm_hour,
         pTm->tm_min,
         pTm->tm_sec);
        }
    }
    return 0;
}
