#include <unistd.h>
#include "test.h"
#include "parser.h"
#include "minishell.h"

void	handler(int signum);

void	ms_excuter(t_cmd *cmd_array, int cmd_size, t_info *info)
{
	t_exnode	*onebuilt;

	if (cmd_size != 1 || \
			!(builtincheck((cmd_array->command)[0])))
		piping(cmd_array, cmd_size, info);
	else
	{
		onebuilt = (t_exnode *)malloc(sizeof(t_exnode));
		if (!onebuilt)
		{
			errormsg(MS_MALLOC, 0);
			return ;
		}
		if (exnodeset(onebuilt, *cmd_array, 0))
			info->status = 1;
		else
		{
			if (!(ft_strcmp((cmd_array->command)[0], "exit")))
				ft_exit(onebuilt, info->envlst, 1);
			info->status = exbuiltin(onebuilt, &(info->envlst), 0, 1);
		}
		printf("i\n");
		exlstfree(onebuilt, 1);
		printf("i\n");
	}
}

int	ft_execute(t_info *info, char *buf)
{
	t_list	*cmd_list;
	t_cmd	*cmd_array;
	int		cmd_size;

	cmd_list = parser(info, buf);
	if (cmd_list == NULL)
		return (0);
	cmd_size = ft_cmdsize(cmd_list);
	cmd_array = ft_convert(cmd_list);
	ft_lstclear(&cmd_list, ft_cmddel);
	if (cmd_array == NULL)
		return (0);
	ms_excuter(cmd_array, cmd_size, info);
	ft_cmdsdel(cmd_array, cmd_size);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	char	*buf;

	ft_termset(&info, argc, argv, envp);
	while (1)
	{
		buf = readline("minishell$ ");
		if (buf)
		{
			ft_execute(&info, buf);
			add_history(buf);
			free(buf);
		}
		else
			break ;
	}
	ft_termexit(&info);
	return (0);
}
/*
1. main 문 인자 envp 를 envset() 함수에 넣어 환경변수 연결리스트 생성
2. while 문 ( 파싱 -> piping() or exbuiltin() -> free(command는 free하지않는다))
2-1. piping()이 아닌 exbuiltin()으로 들어가는 경우는
-> pipeline이 없으면서, builtin 함수일 때. (builtincheck()활용)
3. 종료시그널 발생 시(exit, ctl + D), 1의 리스트 free()
exit 일 때 , cmd_array 할당 해제 추가하기.
*/
