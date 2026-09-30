#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void show_process(int time);

int main(int argc, char *argv[]){
	int cnt = 10;
	while (cnt--) {
		show_process(cnt);
	}
	return 0;
}

void show_process(int time){
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "this error of creating process occurs\n");
	} else if (rc == 0) {
		// f = 1;
		// s = 0;
		printf("%d time, child: hello\n", time);
	} else {
		wait(NULL);
		printf("%d time, parent: goodbye\n", time);
	}
}
