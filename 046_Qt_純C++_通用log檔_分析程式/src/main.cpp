#include<stdio.h>
#include<fstream>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
struct check_struct
{
	char chrfindstring[100];
	char chrlogname[100];
	char chrmessage[100];
	int intcount;
};
int main(int argc, char *argv[])
{
	fstream a;//¥ÎšÓÅªšúlogÀÉ
	fstream checkfile;//¥ÎšÓÅªšú€ÀªR³]©wÀÉ
	char fg[700];//Šs©ñšC€@Šælog
	char filename[80];//Šs©ñlogÀÉªºÀÉŠW
	char check[700];//Šs©ñšC€@Šæ€ÀªR³]©wÀÉžê®Æ,€ñ¹ïŠrŠê
	char *loc;//Šs©ñ€ñžûŠrŠê«áªºµ²ªG
	int intcount=0;//¥ÎšÓ­pºâµ§ŒÆ
	if(argc<2)
	{
		/////////////////////////////////////////
		cout<<"input a File Name ="<<"\t";
		cin.getline(filename,80);
		/////////////////////////////////////////
	}
	else
	{
		strcpy(filename,argv[1]);
	}
	//­pºâ€ÀªR³]©wÀÉªºµ§ŒÆ
	checkfile.open("check.txt",ios::in);
	while(!checkfile.eof())
	{
		checkfile.getline(check,500);
		if(strlen(check)>0)
			intcount++;
	}
	checkfile.close();
	//====
	//°tžm°OŸÐÅéšÃ±N€ÀªR³]©wÀÉžü€J°OŸÐÅé
	char buf0[100],buf1[100],buf2[100];
	struct check_struct *cs;
	cs=new struct check_struct[intcount];
	checkfile.open("check.txt",ios::in);
	intcount=0;
	while(!checkfile.eof())
	{
		checkfile.getline(check,500);
		if(strlen(check)>0)
		{
			sscanf(check,"%[^','],%[^','],%[^','],",buf0,buf1,buf2);
			strcpy((cs+intcount)->chrfindstring,buf0);
			strcpy((cs+intcount)->chrlogname,buf1);
			strcpy((cs+intcount)->chrmessage,buf2);
			(cs+intcount)->intcount=0;
			intcount++;
		}
	}
	checkfile.close();
	///////////////////////////////////////
	//¶iŠæÀÉ®×€ÀªR
	int i;
	a.open(filename,ios::in);
	FILE *pf;
	FILE *pfdata;
	while(!a.eof())
	{
		a.getline(fg,700);
		for(i=0;i<intcount;i++)
		{
			strcpy(check,(cs+i)->chrfindstring);
			loc = strstr(fg, check);
			if(loc!='\0')
			{
				pfdata='\0';
				pfdata=fopen((cs+i)->chrlogname,"a");
				fprintf(pfdata,"%s\n",fg);
				fclose(pfdata);
				pfdata='\0';
				(cs+i)->intcount++;
			}
		}
	}
	pf=fopen("log.txt","w");
	for(i=0;i<intcount;i++)
	{
		fprintf(pf,"%s,%d\n",(cs+i)->chrmessage,(cs+i)->intcount);
	}
	fclose(pf);
	a.close();
	delete []cs;
	return 0;
}
