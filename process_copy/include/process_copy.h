#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int getB();
int process_copy_checkpram(int argc,char* srcfile,int pronum);
int process_copy_blocksize(char* srcfile,int pronum);
int process_copy_create(char* srcfile,char* destfile,int pronum,int blocksize);
int process_copy_wait(void a，int b);//非阻塞回收
