#ifndef __COMMAND_H_
#define __COMMAND_H_

#define CMD_LENGTH(x) (sizeof(x)/sizeof(x[0]))

//����command_funcΪ����ָ��
typedef void (*command_func)(int argc, char *argv[]);

//��������ṹ��
typedef struct cmd
{
	char *cmd_name;		//��������
	command_func cmd_func;//�������
}command_t;

//��������������
extern int execute_command(char *command, command_t *list, int list_size);


#endif
