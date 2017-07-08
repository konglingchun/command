#ifndef __COMMAND_H_
#define __COMMAND_H_

#define CMD_LENGTH(x) (sizeof(x)/sizeof(x[0]))

//声明command_func为函数指针
typedef void (*command_func)(int argc, char *argv[]);

//定义命令结构体
typedef struct cmd
{
	char *cmd_name;		//命令名称
	command_func cmd_func;//命令处理函数
}command_t;

//分析、分配命令
extern int execute_command(char *command, command_t *list, int list_size);


#endif
