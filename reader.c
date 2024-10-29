#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buf[1024];
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, 1024);
    printf("reading from read process: %s\n", buf);
    close(fd);
    return 0;
}
