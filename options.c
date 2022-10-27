#include<stdio.h>
#include<stdlib.h>
#include<functions.h>
void options( )
{
	int choice;
	while(1)
	{
		clear( );
		printf("\nPress 1 for Student ");
		printf("\nPress 2 for Librarian ");
		printf("\nPress 3 for Exit ");
		printf("\nPlease Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:int result1 = student( );
			       if(result1 == 1)
				       menu_student();
			       else
				       printf("\nUsername and Password is incorrect ");
			       break;
			case 2:int result2 = admin( );
			       if(result2 == 1)
			       {
				       menu_librarian( );
			       }
			       else
				       printf("\nUsername and Password is incorrect ");
			case 3:exit(0);
		}
	}
}

