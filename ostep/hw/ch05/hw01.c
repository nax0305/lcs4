#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "create fork process failed\n");
    } else if (rc == 0) {
        x = x + 1;
        printf("I am child, the value of x is %d\n", x);
    } else {
        x = x + 2;
        printf("I an parent, the value of x is %d\n", x);
    }
    return 0;
}
