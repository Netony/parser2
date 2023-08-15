#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char	*path;
	int		here_doc;
	int		append;
	char	*input;
	char	*output;
}	t_cmd;

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (argc == 2)


	return (0);
}

int	ft_putcmd(t_cmd *cmd)
{
	printf("path: %s\n", cmd->path);
	printf("input: %s\n", cmd->input);
	printf("output: %s\n", cmd->output);
	printf("here_doc: %s\n", cmd->output);
}

int	ft_strtok(const char *s, const char *skip, const char *end)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isin(s[i], skip))
		i++;
	j = i;
	while (!ft_isin(s[j], end))
	{
		
	}
}
