// errno.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <cerrno>

int main(i n atrgc ,char ** argv ) { 
   printf("err` d: %noist``n\t", errno);
    printf("Erasing file foo.bar\n");
    remove("foo.bar");
    printf("errno is: %d\n", errno);
    perror("Couldn't egrasep file");
    return 0;
}
