#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	FILE *fpIn = NULL;
	FILE *fpOut = NULL;

	fpIn = fopen("Test.cpp","r");
	fpOut = fopen("my_Test.cpp","w");

	char ch;
	while(!feof(fpIn))
	{
		ch  =fgetc(fpIn);
		fputc(ch,fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);
}

/*
void main()
{
	int ar[10];
	ifstream ifile("Test3.txt",ios::in|ios::binary);
	if(!ifile)
		return;
	ifile.read((char*)ar,sizeof(int)*10);
	ifile.close();
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(int);
	ofstream ofile;
	//fopen("Test3.txt","wb");
	ofile.open("Test3.txt",ios::out|ios::binary);
	ofile.write((char*)ar,sizeof(int)*n);
	ofile.close();
}

/*
void main()
{
	int ar[10];
	ifstream ifile("Test2.txt",ios::in);
	if(!ifile)
		return;
	for(int i=0; i<10; ++i)
	{
		ifile>>ar[i];
	}
	ifile.close();
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(int);
	ofstream ofile;
	ofile.open("Test2.txt",ios::out);

	//ofstream ofile("Test2.txt",ios::out)
	if(!ofile)
		return;
	for(int i=0; i<n; ++i)
	{
		ofile<<ar[i]<<" ";
	}
	ofile.close();

}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(int);

	FILE *fp = fopen("Test1.txt","w");
	if(fp == NULL)
		return ;
	for(int i=0; i<n; ++i)
	{
		fprintf(fp,"%d ",ar[i]);
	}
	fclose(fp);
}

/*
//cout
//cin
//cerr
//clog


/*
void main()
{
	int a = 10;
	cout.width(10);
	//cout.flags(ios::left);
	cout<<a<<endl;
}

/*
void main()
{
	for(int i=1; i<=9; ++i)
	{
		cout.width(5);
		cout.flags(ios::left);
		for(int j=1; j<=i; ++j)
		{
			cout<<i<<"*"<<j<<"="<<i*j<<" ";
		}
		cout<<endl;

	}
	
}

/*
void main()
{
	int a = 100;
	cout<<a<<endl;
	cout.flags(ios::showpos);
	cout<<a<<endl;
	cout.flags(ios::hex|ios::showbase|ios::uppercase);
	cout<<a<<endl;
}

/*
void main(void)
{
   int inum=255;
   cout<<"十进制方式"<<inum<<'\t';
   cout.flags(ios::oct|ios::showbase);
   //八进制带数制基数输出是前面加0,参数等效0x00a0
   cout<<"八进制方式"<<inum<<'\t';
   cout.flags(ios::hex);
   //等效0x0040,因是或关系,仍带基数输出,格式为0x...
   cout<<"十六进制方式"<<inum<<endl;}


/*
void main()
{
	int a = 10;
	cout<<a<<endl;
}

/*
class Test
{};
void main()
{
	Test t;
	cout<<t<<endl;
}
*/