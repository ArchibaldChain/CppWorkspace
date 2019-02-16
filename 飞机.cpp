#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 35
void print(int [][N]);//????
void movebul(int [][N]);//??????
void movepla(int [][N]);//??????
void setting(void);//????
void menu(void);//????
int scr[22][N]={0},pl=9,width=24,speed=3,density=30,score=0,death=0;//????:?????????????????????????????
main(void)
{
    menu();
    
int i=0,j=0;
    scr[21][pl]=1;
    scr[0][5]=3;
    
    while(1)
    {
  if(kbhit())
  switch(getch())//???????????
      {
      case 'a':case 'A':
       if(pl>0)
      scr[21][pl]=0,scr[21][--pl]=1;
   break;
          case 'd':case 'D':
       if(pl<width-2)
      scr[21][pl]=0,scr[21][++pl]=1;
               break;
          case 'w':case 'W':
       scr[20][pl]=2;
       break;
  case 27 :
      setting();
              break;
      }
      
  if(++j%density==0)//?????????
      {
     j=0;srand(time(NULL));
         scr[0][rand()%width]=3;
      }
      if(++i%speed==0)//????????,?????????
         movepla(scr);
      movebul(scr);
      
      print(scr);
      if(i==30000)
     i=0;//??i ??
      
   }
  
}
void print(int a[][N])
{
   system("cls");
   int i,j;
   for(i=0;i<22;i++)
   {
     a[i][width-1]=4;
     for(j=0;j<width;j++)
 {
   if(a[i][j]==0)
      printf(" ");
       if(a[i][j]==1)
          printf("\5");//???????
       if(a[i][j]==2)
      printf(".");//??
       if(a[i][j]==3)
      printf("\3"); //??????
       if(a[i][j]==4)
      printf("|");
       if(i==0&&j==width-1)
      printf("??:%d",score);//???????
       if(i==1&&j==width-1)
      printf("??:%d",death);
       if(i==2&&j==width-1)
      printf("??:Esc");
       if(i==3&&j==width-1)
      printf("Copyright:Berlin");
     }
     printf("\n");
  }
}
void movebul(int a[][N])
{
    int i,j;
    for(i=0;i<22;i++)
        for(j=0;j<width;j++)
        {
          if(i==0&&a[i][j]==2)
     a[i][j]=0;
      if(a[i][j]==2)
          {
             if(a[i-1][j]==3)
    score+=10,printf("\7");
             a[i][j]=0,a[i-1][j]=2;
          }
        }
}
void movepla(int a[][N])
{
    int i,j;
    for(i=21;i>=0;i--)//??????????????????????
        for(j=0;j<width;j++)
        {
           if(i==21&&a[i][j]==3)
      a[i][j]=0;//????0 ?????
           if(a[i][j]==3)
      a[i][j]=0,a[i+1][j]=3;
        }
    if(a[20][pl]==3&&a[21][pl]==1)
  death++;
}
void setting(void)
{
     int sw=0,i,j;
     system("cls");
     do{sw=0;printf("\n ???????:1.?2.?>> ");
     switch(getche())
     {
         case '1':
    width=34;
break;
         case '2':
    width=24;
break;
         default:
     printf("\n ??,?????...\n");
         sw=1;
     }
   }
    while(sw);
    do
    {
      sw=0;
      printf("\n ???????:1.?2.?3.?>> ");
      switch(getche())
      {
          case '0':
     density=10;
             break;
          case '1':
     density=20;
             break;
 case '2':
     density=30;
             break;
 case '3':
     density=40;
 break;
         default:
     printf("\n ??,?????...\n");
         sw=1;
     }
  }while(sw);
  do
  {
     sw=0;
     printf("\n ???????:1.?2.?3.?>> ");
     switch(getche())
     {
       case '1':
  speed=2;
          break;
       case '2':
     speed=3;
         break;
       case '3':
     speed=4;
         break;
       default:
     printf("\n ??,?????...\n");
       sw=1;
    }
  }while(sw);
  for(i=0;i<22;i++)
     for(j=0;j<45;j++)
       scr[i][j]=0;
   scr[21][pl=9]=1;
   printf("\n ??????...");
   getch();
}
void menu(void)
{
   printf("??:?A D ????????,W ????\n ??:??Esc\n ????:???\n      ");
   if(getch()==27)
   setting();
}
 
