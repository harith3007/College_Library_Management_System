#include<functions.h>
#include<macros.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<struct.h>
book *head3 = NULL;
stud *head2 = NULL;
bs *head4 = NULL;
int validatestudentname1(char *studentname)
{
	for(int i=0;i<strlen(studentname);i++)
	{
		if(isalpha(studentname[i]))
			continue;
		else
			return 0;
	}
}
void Return_books()
{
	FILE *fp = fopen("../data/studentbook.txt","r");
	FILE *fw = fopen("../data/temp.txt","w");
	int no;
	printf("\nEnter the book id to return ");
	scanf("%d",&no);
	int sid , bno,q ;
	char DOI[20];
	fscanf(fp,"%d%d%s",&sid,&bno,DOI);
	
	while(!feof(fp))
	{
		if(bno != no)
		{
			
			
			fprintf(fw,"%d %d %s\n",sid,bno,DOI);
		}
		fscanf(fp,"%d%d%s",&sid,&bno,DOI);
	}
	fclose(fw);
	fclose(fp);
	remove("../data/studentbook.txt");
	rename("../data/temp.txt","../data/studentbook.txt");
}
void Display_books()
{
        /*FILE *fr = fopen("../data/studentbook.txt","r");
	/*while((ch = getchar())!=EOF)
	{
		putc(ch,fr);
	}*/

	/*if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		char doi;
		int studentid,bid;
		printf("\n****************************************\n");
		printf("*           DETAILS OF BOOKS             *");
		printf("\n****************************************\n");
		bs *start=NULL;
		printf("%-10d%-20d%-20s\n","Student ID","Book ID","Issued Date");
		fscanf(fr,"%d%d%s",&studentid,&bid,doi);

		/*while(!feof(fr))
		{
			bs *temp = (bs *) calloc(1,sizeof(bs));
			temp->studentid = studentid;
			
			strcpy(temp->doi,doi);
			
			temp->link = NULL;
			if(start == NULL)
				start = temp;
			else
			{
				bs *q = start;
				while(q->link != NULL)
					q=q->link;
				q->link = temp;
			}
			fscanf(fr,"%d%d%s",&studentid,&bid,doi);
		}
		fclose(fr);
		bs *q = start;*/
		/*while(q!=NULL)
		{
			printf("\n%-10d%-20d%s",q->studentid,q->bid,q->doi);
			q=q->link;
		}*/
       
		
}
void New_User()
{
	printf("\nPlease provide the details ");
	FILE *fp = fopen("../data/student.txt","a");
	stud *temp = (stud *)calloc(1,sizeof(stud));
	while(1)
	{
		printf("\nEnter the Student Id ");
		scanf("%d",&temp->studentid);
                //break;
		if(temp->studentid>100)
			printf("\nPlease enter the student ID between 1 to 100");
		else
			break;
	}
	while(1)
	{
		printf("\nEnter the student Name ");
		scanf("%s",temp->studentname);
		if(validatestudentname1(temp->studentname))
				break;
		else
			printf("student name is not valid ");
	}
	printf("\nEnter the course Name ");
	scanf("%s",temp->coursename);
	temp->link = NULL;
	if(head2 == NULL)
	{
		head2 = temp;
		fprintf(fp,"%d %s %s %d\n",temp->studentid,temp->studentname,temp->coursename,temp->year);

	}
	else
	{
		stud *q = head2;
		while(q->link != NULL)
			q=q->link;
		q->link = temp;
		fprintf(fp,"%d %s %s %d\n",temp->studentid,temp->studentname,temp->coursename,temp->year);
	}
	fclose(fp);
}


void menu_student()
{
	
	
	int choice;
	while(1)
	{
		printf("\n1.Return Books\n2.Display Books\n3.New User\n4.Options\n");
		printf("\nEnter you choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:Return_books();
		               break;
			case 2:Display_books();
		       		break;
			case 3:New_User();
			       break;
			case 4:options();
		}
	}
}
