#include<stdio.h>
#include<stdlib.h>
typedef struct dnode dnode;
struct dnode
{
 dnode *Llink;
 int index;
 char data;
 dnode *Rlink;
};
dnode *first=NULL,*last=NULL;
dnode *p;
void insertAt(int temp,char c);
void initialize();
void printTable();
void easyGame();
int checkHorizontal(int temp,char c);
int checkVertical(int temp,char c);
int checkDiagonal(int temp,char c);
//void hardGame();
int mainMenu();
int newGameSubMenu();
int optionsSubMenu();
int main()
{
	int n,c1,c2,c3,c3_1,temp;
	label1:/*In case if the user wishes to go back to the main menu*/
	system("cls");
	c1=mainMenu();
	switch(c1)
	{
		case 1:
			c2=newGameSubMenu();
			if(c2==-1)
				goto label1;/*In case if the user wishes to go back to the main menu*/
				switch(c2)
				{
					case 1:
						easyGame();
						break;
					case 2:
						//hardGame();
						break;
				}
			break;
		case 2:
			c3=optionsSubMenu();
			if(c3==-1)
				goto label1;
			switch(c3)
			{
				case 1:
					system("cls");
					printf("\t\t\t\tINSTRUCTIONS\n");
					printf("\nThere will be a Square grid displayed on the screen. The first turn will be of player 1's whose mark is X\n");
					printf("\nThe player has to enter the position as 1,2,3,....9 or 16 or upto 25 depending on the difficulty\n");
					printf("\nand then the next player has to make their move until there is a horizontal, vertical, diagonal row of one of the marks\n");
					printf("\nIn a 3X3, 4X4 or 5X5 grid the number of marks in horizontal, vertical or diagonal rows should be 3, 4 or 5 respectively\n");
					printf("\n If there is no mark left till the end of the game, the game is declared to be a draw");
					printf("\n\t\t\tEnter -1 to go back ");
					scanf("%d",&temp);
					if(temp==-1)
					goto label1;
				case 2:
					system("cls");
					printf("\t\t\t\t\t\tSelect STYLE\n");
					printf("\n\t\t\t\t\t\t1.Classic\n");
					printf("\n\t\t\t\t\t\t2.Standard\n");
					printf("\n\t\t\t\t\t\t3.Dynamic\n");
					printf("\n\t\t\t\t\t\t4.Vibrant\n");
					scanf("%d",&c3_1);
					switch(c3_1)
					{
						case 1:
							system("COLOR 70");
							goto label1;
							break;
						case 2:
							system("COLOR 07");
							goto label1;
							break;
						case 3:
							system("COLOR CB");
							goto label1;
						case 4:
							system("COLOR D4");
							goto label1;
					}
			}
			break;
	}
	return 0;
}
int mainMenu()/*Code for the mainMenu(),returns the choice of the user*/
{
	int c1;
	printf("___________________________________________________TIC-TAC-TOE__________________________________________________________");
	printf("\n\n\n\t\t\t\t\t\t  1.Start New Game\n");
	//printf("\n\t\t\t\t\t\t  2.Continue\n");
	printf("\n\t\t\t\t\t\t  2.Options\n");
	printf("\n\t\t\t\t\t\t  3.Quit\n");
	scanf("%d",&c1);/*to scan the choice of the user*/
	if(c1>0&&c1<5)
	{
		return c1;
	}
	else
	{
		printf("Enter valid choice");
	}
}
int newGameSubMenu()
{
	int c2;
	//system("cls");
	//printf("\n\n\t\t\t\t\t\tenter the difficulty level\n");
	//printf("\n\t\t\t\t\t\t1.Easy\n");
	//printf("\n\t\t\t\t\t\t2.Hard\n");
	//printf("\n\t\t\t\t\t\tEnter -1 to go back\n");
	//scanf("%d",&c2);
	return 1;
}
int optionsSubMenu()
{
	int c3;
	system("cls");
	printf("\n\n\t\t\t\t\t\tOPTIONS\n");
	printf("\n\t\t\t\t\t\t1.Instructions\n");
	printf("\n\t\t\t\t\t\t2.Style\n");
	printf("\n\t\t\t\t\t\tEnter -1 to go back\n");
	scanf("%d",&c3);
	return c3;
}
void easyGame()
{
	int temp,h1,v1,d1,h2,v2,d2,cnt=0;
	initialize();
	while(1)
	{
		system("cls");
		printTable();
		printf("PLAYER X:\n");
		scanf("%d",&temp);
		insertAt(temp,'X');
		cnt++;
		system("cls");
		printTable();
		h1=checkHorizontal(temp,'X');
		v1=checkVertical(temp,'X');
		d1=checkDiagonal(temp,'X');
		if(h1==1||v1==1||d1==1)
		{
			printf("\n\n\n\t\t\t\t\t\t    CONGRATULATIONS!");
			printf("\n\n\t\t\t\t\t\tPLAYER X HAS WON THE GAME!");
			break;
		}
		if(cnt==9)
		{
			printf("\n\n\t\t\t\t\t\tTHE GAME IS A DRAW");
			break;
		}
		system("cls");
		printTable();
		printf("PLAYER O:\n");
		scanf("%d",&temp);
		insertAt(temp,'O');
		cnt++;
		system("cls");
		printTable();
		h2=checkHorizontal(temp,'O');
		v2=checkVertical(temp,'O');
		d2=checkDiagonal(temp,'O');
		if(h2==1||v2==1||d2==1)
		{
			printf("\n\n\n\t\t\t\t\t\t    CONGRATULATIONS!");
			printf("\n\n\t\t\t\t\t\tPLAYER O HAS WON THE GAME!");
			break;
		}
	}
}
void initialize()
{
  int i,j,k=1;
  printf("\n\n\n\n\n\n");

  for(i=1;i<=3;i++)
  {
      printf("\t\t\t\t\t\t");
      for(j=1;j<=3;j++,k++)
      {
        p=(dnode*)malloc(sizeof(dnode));
        p->index=k;
        p->data='*';
        printf("%c           ",p->data);
        if(!first)
        {
            first=p;
            last=p;
            first->Llink=NULL;
            first->Rlink=NULL;
        }
        else
        {
            p->Llink=last;
            last->Rlink=p;
            last=p;
            p->Rlink=NULL;
        }
       }
        printf("\n\n\n\n");
  }
}
void insertAt(int temp,char c)
{
	if(temp<0||temp>9)
	{
		printf("Invalid Input");
	}
	p=first;
	while(p->index!=temp)
	{
		p=p->Rlink;
	}
	if(p->data=='*')
	{
		p->data=c;
	}
	else
	{
		printf("INVALID INPUT");
	}
}
void printTable()
{
	p=first;
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("\n\n\t\t\t\t\t\t");
		for(j=0;j<3;j++)
		{
			printf("%c           ",p->data);
			p=p->Rlink;
		}
		printf("\n\n\n\n");
	}
}
int checkVertical(int temp,char c)
{
	dnode *p1;
	if(temp==1 || temp==4 || temp==7)
    {
        p1=first;
        if(p1->data==c)
        {
        while(p1 && p1->index%7!=0)
        {
            p1=p1->Rlink->Rlink->Rlink;
            if(p1->data!=c)
                return 0;

        }
        return 1;
       }
       else
       return 0;
    
    }
     if(temp==2 || temp==5 || temp==8)
     {
        p1=first;
        while(p1->index!=2)
            p1=p1->Rlink;
        if(p1->data==c)
        {
        while(p1 && p1->index%8!=0)
        {
            p1=p1->Rlink->Rlink->Rlink;
            if(p1->data!=c)
                return 0;

        }
        return 1;
		}
		else
		return 0;
     }

	if(temp==3 || temp==6 || temp==9)
     {
        p1=first;
        while(p1->index%3!=0)
            p1=p1->Rlink;
        if(p1->data==c)
        {
        while(p1 && p1->index%9!=0)
        {
            p1=p1->Rlink->Rlink->Rlink;
            if(p1->data!=c)
                return 0;

        }
        return 1;
    }
    else 
    return 0;
     }
}

int checkHorizontal(int temp,char c)
{
   int count=0;
   p=first;
   dnode *p1,*p2;

   while(p->index!=temp)
   {
		p=p->Rlink;
   }

   p1=p,p2=p;


  do
   {
       if(p1->data!=c)
          return 0;

       else
       {
         p1=p1->Llink;
         count++;
       }
   }while(p1 && p1->index%3!=0);


   if(p1==NULL && count==3)
      return 1;

   else if(p1 && p1->index%3==0 && count==3)
      return 1;

   count=0;

   while(p2->index%3!=0)
   {
       p2=p2->Rlink;
       count++;

       if(p2->data!=c)
          return 0;

   }

   printf("%d",p2->index);

   if(p2->index%3==0 && count==3)
      return 1;


   if(!p1 && p2->index%3==0)
      return 1;

   else if(p1->index%3==0 && p2->index%3==0)
      return 1;
}

int checkDiagonal(int temp,char c)
{
  dnode *p1;

  if(temp==1 || temp==5 || temp==9)
  {
      p1=first;

      if(p1->data!=c)
            return 0;

      while(p1 && p1->Rlink)
      {
          p1=p1->Rlink->Rlink->Rlink->Rlink;
          if(p1->data!=c)
            return 0;
      }
      return 1;
  }

  else if(temp==3 || temp==5 || temp==7)
  {
      p1=first;

      while(p1->index%3!=0)
      {
          p1=p1->Rlink;
      }

      if(p1->data!=c)
            return 0;

      while(p1 && p1->index%7!=0)
      {
          p1=p1->Rlink->Rlink;
          if(p1->data!=c)
            return 0;
      }
      return 1;
  }

}
