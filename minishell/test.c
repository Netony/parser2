#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>

void handler(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
	char	*prompt;

    sigaction(SIGINT, &action, NULL); // SIGINT 시그널 처리

    printf("Waiting for signal...\n");
    while (1)
	{
		prompt = readline("enter : ");
		printf("%s\n", prompt);
		free(prompt);
	}

    return 0;
}

