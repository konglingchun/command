#include <stdio.h>

#include "command.h"

void command_learn(int argc, char *argv[])
{
	int i;

	for(i=0; i<argc; i++)
	{
		printf("argv[%d]=[%s]\r\n", i, argv[i]);
	}
}

//命令数组：用来保存 命令名和处理函数名
command_t command_learn_list[]=
{	
	{"ww", command_learn},
};

int main(int argc, char *argv[])
{
	char command_buffer[256] = "ww 1 2 3 4\n";

	if(execute_command(command_buffer, command_learn_list, CMD_LENGTH(command_learn_list)) < 0)
	{
		printf("commmand error: unsupported command!\r\n");
	}
	return 0;
}

