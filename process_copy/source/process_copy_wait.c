#include <process_copy.h>
int process_copy_wait()
{
	pid_t pid;
	while((pid=waitpid(-1,NULL,WNOHANG))!=-1)
	{
		if(pid>0)
		{
			printf("回收子线程一个\n");
		}
		else
		{
			sleep(2);
		}
	}
	return 0;
}
