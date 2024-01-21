#include <process_copy.h>
int process_copy_checkpram(int argc,char* srcfile,int pronum)
{
	if(argc<=4&&argc>=3)
	{
		int ok=access(srcfile,F_OK);
		if(ok==0)
		{
			if(pronum<=10&&pronum>=1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
