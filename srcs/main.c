#include "test.h"
#include "parser.h"
#include <readline/history.h>
#include <readline/readline.h>

int	main(void)
{
	char	*buf;

	while (1)
	{
		buf = readline("minishell$ ");
		if (buf)
			ft_print_cmd(parser(buf));
		else
			break ;
		add_history(buf);
		free(buf);
	}
	return (0);
}
