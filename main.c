#include "test.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_cmd(parser(argv[1]));
	return (0);
}
