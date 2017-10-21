#include <stdio.h>
#include <string.h>

#include "command.h"

void command_func_demo(int argc, char *argv[])
{
	int i;

	for(i=0; i<argc; i++)
	{
		printf("argv[%d]=[%s]\r\n", i, argv[i]);
	}
}

//�������飺�������� �������ʹ�������
command_t command_list_demo[]=
{	
	{"demo", command_func_demo},
};

//��������������
int execute_command(char *command, command_t *list, int list_size)

{
	char *argv[128] = {NULL};
	unsigned char argc = 0;
	unsigned char i = 0;
	
	if(strlen(command)==0)
	{
		return 0;
	}
		
	argv[0] = command;
	while((argv[argc]=strtok(argv[argc], " \r\n"))!=NULL)//���ڱ��ָ���ַ����з��ַָ��ַ�ʱ�������ַ���Ϊ'\0'��
	{
        //printf("argv[%d] = %s\n", argc, argv[argc]);
        argc++;
		if(argc > 128)//Too many argument
		{
			return -2;
		}
	}

	if(argc == 0)//No orders
	{
		return -1;
	}

	for(i=0;i<list_size;i++)
	{
		//��������
		if(strcmp(list[i].cmd_name, argv[0])==0)
		{
			//ִ������
			list[i].cmd_func(argc, argv);
			return 0;
		}
	}	
	return -1;
}

