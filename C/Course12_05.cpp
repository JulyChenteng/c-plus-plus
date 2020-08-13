#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/stat.h>

#if 0
int main()
{
	FILE *fp = fopen("test\\1.txt","rb");
	
	int size;
	/*fseek(fp,0,2);
	size = ftell(fp);
	printf("%d\n",size);
	rewind(fp);//fseek(fp,0,0);
	*/
	struct _stat buf;
	_stat("test\\1.txt",&buf);           //获取有关该文件的信息
	size = buf.st_size;
	printf("%d\n",size);
	fclose(fp);
	return 0;
}
#endif

#if 0
void CH(int *a,int root,int len)
{
	int i = 2 * root;
	int t = a[root];
	while(i <= len)
	{
		if(i < len)
		{
			if(a[i] < a[i+1])
				i++;
		}
		if(t >= a[i])
			break;
		else
		{
			a[i/2] = a[i];
			i = 2 * i;
		}
	}
	a[i/2] = t;
}
void sort(int *a,int len)
{
	int i ;
	int t;
	for(i = len/2;i >=1;i--)
		CH(a,i,len);
	for(i = len;i>=1;i--)
	{
		t = a[1];
		a[1] = a[i];
		a[i] = t;
		CH(a,1,i-1);
	}
}
void put(int *a,int len)
{
	int i;
	for(i = 1;i<=len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a[11] = {0,1,3,2,5,6,3,0,9,8,7};
	sort(a,10);
	put(a,10);
	return 0;
}
#endif

#if 1 
/*利用大堆排序给大文件排序，首先按照num排序，如果num相同，则按照time排序*/
typedef struct data
{
	char a[3];
	char num[7];
	char b[24];
	char time[8];
	char c[40];
}Data;

//创建大根堆
void createHeap(Data *d, int root, int len)
{
	int i  = 2 * root;
	Data temp = d[root];

	while (i <= len)
	{
		if (i < len)
		{
			if (strncmp(d[i].num, d[i+1].num, 7) < 0)
			{
				i++;
			}
			else if(strncmp(d[i].num, d[i+1].num, 7) == 0)
			{
				if (strncmp(d[i].time, d[i+1].time, 8) < 0)
				{
					i++;
				}
			}
		}

		if (strncmp(temp.num, d[i].num, 7) > 0)
			break;
		else if (strncmp(temp.num, d[i].num, 8) == 0)
		{
			if (strncmp(temp.time, d[i].time, 8) < 0)
			{
				d[i/2] = d[i];
				i = 2*i;
			}
			else
				break;
		}
		else
		{
			d[i/2] = d[i];
			i = 2 * i;
		}
	}

	d[i/2] = temp;
}

void sort(Data *d,int len)
{
	int i ;
	Data t;
	
	for(i = len/2;i >=1;i--)
		createHeap(d,i,len);

	for(i = len;i>=1;i--)
	{
		t = d[1];
		d[1] = d[i];
		d[i] = t;
		createHeap(d,1,i-1);
	}
}

int main()
{
	FILE *fpr = fopen("test\\1.txt","rb");
	FILE *fpw = fopen("test\\2.txt","wb");

	if (fpr == NULL || fpw == NULL)
	{
		printf("Open file failed!\n");
		return EXIT_FAILURE;
	}

	Data *p = NULL;
	int size,count,i;


	//SEEK_END 2   SEEK_SET 0 SEEK_CUR 1
	fseek(fpr,0,2);
	size = ftell(fpr);
	fseek(fpr,0,0);			
	count = size / sizeof(Data);
	p = (Data*)malloc((count+1)*sizeof(Data));

	for(i = 1;i<=count;i++)
	{
		fread(&p[i],82,1,fpr);
	}

	sort(p, count);

	for(i= 1;i<=count;i++)
	{
		fwrite(&p[i],82,1,fpw);
	}

	free(p);
	p = NULL;

	fclose(fpr);
	fclose(fpw);

	return 0;
}  
#endif