#include "minishell.h"

void	handler(int signum)
{
	(void)signum;
	printf("minishell$ \n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

int	ft_termset(t_info *info, int argc, char **argv, char **envp)
{
	struct termios	term;

	(void)argc;
	(void)argv;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	info->envlst = envlist(envp);
	info->status = 0;
	return (0);
}

int	ft_termexit(t_info *info)
{
	printf("\033[10C");
	printf("\033[1A");
	printf(" exit\n");
	envlstfree(info->envlst);
	return (0);
}
