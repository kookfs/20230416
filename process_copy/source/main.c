#include <process_copy.h>
int main(int argc,char* argv[])
{
	int pronum=0;
	if(argc<=3)
	{
		//默认4个线程
		pronum=4;
	}
	else
	{
		pronum=atoi(argv[3]);
	}
	int ok=process_copy_checkpram(argc,argv[1],pronum);
	if(!ok)
	{
		printf("参数错误\n");
		return 0;
	}
	int blocksize=process_copy_blocksize(argv[1],pronum);
	process_copy_create(argv[1],argv[2],pronum,blocksize);
	process_copy_wait();
	return 0;
}

