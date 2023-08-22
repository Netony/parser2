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
// 1. main 문 인자 envp 를 envset() 함수에 넣어 환경변수 연결리스트 생성
// 2. while 문 ( 파싱 -> piping() or exbuiltin() -> free() )
// 2-1. piping()이 아닌 exbuiltin()으로 들어가는 경우는
// -> pipeline이 없으면서, builtin 함수일 때. (builtincheck()활용)
// 3. 종료시그널 발생 시(exit, ctl + D), 1의 리스트 free()
