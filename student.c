#include<macros.h>
#include<string.h>
#include<stdlib.h>
#include<functions.h>
#include<stdio.h>
#include<struct.h>
int student( )
{
	FILE *info;
	info = fopen("../data/studentpassword.txt","r");
	if(info == NULL)
	{
		printf("\nFile does not exsits ");
		return 0;
	}
	else
	{
		clear( );
		char user[MAX],pass[MAX],username[MAX],password[MAX];
		fscanf(info,"%s %s",user,pass);
		fclose(info);
		printf("\nEnter the username ");
		scanf("%s",username);
		printf("\nEnter the password ");
		scanf("%s",password);
		if( strcmp(user,username)==0 && strcmp(pass,password)==0 )
		{
			printf("\n******************************************\n");
			printf("\nStudent Login Successfully\n");
			printf("\n******************************************\n");
			return 1;
		}
		else
			return 0;
	}
}


