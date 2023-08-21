#include "parser.h"
#include <stdio.h>

int	ft_print_chunk(t_chunk *chunk)
{
	int	ret;

	ret = printf("chunk->type: %s\n", chunk->type);
	ret = printf("chunk->text: %s\n", chunk->text);
	return (ret);
}

int	ft_print_chunks(t_list *chunks)
{
	while (chunks)
	{
		ft_print_chunk(chunks->content);
		chunks = chunks->next;
	}
	return (0);
}

int	ft_print_cmd(t_list *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		printf("cmd[%d]\n", i++);
		ft_print_chunks(cmd->content);
		printf("-------------------------\n");
		cmd = cmd->next;
	}
	return (0);
}
