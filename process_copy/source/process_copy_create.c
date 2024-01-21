#include <process_copy.h>
int process_copy_create(char* srcfile,char* destfile,int pronum,int blocksize)
{
	int i;
	pid_t pid;
	for(i=0;i<pronum;i++)
	{
		pid=fork();
		if(pid==0)
			break;
	}
	if(pid==0)
	{
		int workcount=blocksize;
		int pos=i*workcount;
		char workcount_cr[40];
		char pos_cr[40];
		printf("pos=%d workcount=%d\n",pos,workcount);
		sprintf(workcount_cr,"%d",workcount);
		sprintf(pos_cr,"%d",pos);
		printf("ss workcount=%s ss pos=%s\n",workcount_cr,pos_cr);
		execl("/home/colin/20230416/process_copy/Mod/copy.exe","copy.exe",srcfile,destfile,workcount_cr,pos_cr,NULL);
	}
	return 0;
}
