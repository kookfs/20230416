#include <process_copy.h>
int main(int argc,char* argv[])
{
		int workcount=atoi(argv[3]);
		int pos=atoi(argv[4]);
		printf("pos=%d\n",pos);
		int flag1=open(argv[1],O_RDONLY);
		if(flag1==-1)
		{
			printf("open srcfile error\n");
			return -1;
		}
		int flag2=open(argv[2],O_WRONLY|O_CREAT,0664);
		if(flag2==-1)
		{
			printf("open destfile error\n");
		}
		int len=0;
		lseek(flag1,pos,SEEK_SET);
		lseek(flag2,pos,SEEK_SET);
		printf("workcount=%d\n",workcount);
		/*char* buf=(char*)malloc((workcount+1));
		len=read(flag1,buf,sizeof buf);
		write(flag2,buf,len);
		free(buf);*/
		char buf[1024]="";
		if(1024>workcount)
		{
			int count=read(flag1,buf,sizeof buf);
			write(flag2,buf,count);
		}
		else
		{
			int sum=0;
			int count=0;
			while(1)
			{
				printf("%d sum=%d\n",getpid(),sum);
				if((sum+1024)>workcount)
				{
					int k=workcount-sum;
					int count1=read(flag1,buf,sizeof buf);
					printf("%d k=%d\n",getpid(),k);
					write(flag2,buf,k);
					break;
				}
				count=read(flag1,buf,sizeof buf);
				write(flag2,buf,count);
				sum+=count;
			}
		}
		close(flag1);
		close(flag2);
		return 0;
	
}
