#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
	char buf[100];
 	int fd = open("./hw02.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "the error occur while creating sub process. \n");
	} else if (rc == 0) {
		strcpy(buf,  "i am the child (pid: child), i am writing some text.\n");
		write(fd, buf, strlen(buf));
	} else {
		strcpy(buf,  "i am the parent (pid: parent), i want to write.\n");
		write(fd, buf, strlen(buf));
	}
	close(fd);
	return 0;
}
