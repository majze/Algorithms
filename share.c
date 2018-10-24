#include <stdio.h> //printf, fgets, fputs
#include <stdlib.h> //atoi()
#include <unistd.h> //only works on linux
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int readNum();
void writeNum(int x);

int main() {
	int x = 19530;
	char number[8];
	pid_t piddly;
  
	FILE *create;
	create = fopen("num.txt", "w");
	sprintf(number, "%d", x);
	fputs(number, create);
	fclose(create);
	printf("Value of x = %d\n", x);

	for (int i = 0; i < 5; i++) {

		printf("ITERATION: %d\n", i);
		piddly = fork();

		if (piddly == 0) { //child

			x = readNum();
			x -= 5;
			printf("Child: x = %d\n", x);
			writeNum(x);
			exit(42);

		}
		else if (piddly > 0) { //parent

			pid_t wait = waitpid(piddly, NULL, 0); //wait for child to finish
			if (wait < 0) {
				printf("Error, child process did not finish");
				return 3;

			}
			else {

				x = readNum();
				x /= 5;
				printf("Parent: x = %d\n", x);
				writeNum(x);

			}

		}
		else {

			printf("Fork call unsucessful");
			return 4;

		}

		printf("\n");

	}
}

int readNum() {

	char number[8];
	int result;
	FILE *stream;
	stream = fopen("num.txt", "r");
	if (stream == NULL) {

		perror("Cannot open file");
		return (-1);

	}
	result = atoi(fgets(number, 8, stream));
	fclose(stream);
	return result;

}

void writeNum(int x) {

	char number[8];
	sprintf(number, "%d", x);
	FILE *stream;
	stream = fopen("num.txt", "w");
	fputs(number, stream);
	fclose(stream);

}