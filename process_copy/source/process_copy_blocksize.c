#include <process_copy.h>
int process_copy_blocksize(char* srcfile,int pronum)
{
	int fd=open(srcfile,O_RDONLY);
	if(fd==-1)
	{
		return -1;
	}
	int size=lseek(fd,0,SEEK_END);
	printf("size=%d\n",size);
	int work=size%pronum;
	int workcount=0;
	if(work>0)
	{
		workcount=size/pronum+1;
	}
	else
	{
		workcount=size/pronum;
	}
	return workcount;	
}
