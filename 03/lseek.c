#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 128 //1024

int main(void) {
    char buf[BUF_SIZE];
    int fd = open("./lseek.c", O_RDONLY);
    ssize_t r = read(fd, buf, BUF_SIZE);
    off_t cur = lseek(fd, 0, SEEK_CUR);
    printf("%ld\n", cur);
    off_t set = lseek(fd, 0, SEEK_SET);
    printf("%ld\n", set);
    off_t end = lseek(fd, 0, SEEK_END);
    printf("%ld\n", end);
    cur = lseek(fd, 0, SEEK_CUR);
    printf("%ld\n", cur);
    int len = end - set;
    cur = lseek(fd, -len, SEEK_END);
    printf("%ld\n", cur);
    cur = lseek(fd, len, SEEK_SET);
    printf("%ld\n", cur);
    r = read(fd, buf, BUF_SIZE);
    printf("%d\n", r); // EOF
}
