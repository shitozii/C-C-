#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include<stdbool.h>
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONGTRAI 0
#define TUONGPHAI 50
#define TUONGTREN 0
#define TUONGDUOI 20
void gotoxy(int x, int y) {
 static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

int wherex() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int wherey() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}
typedef struct{
 int x;
 int y;
}Toado;
Toado Dotran[300];
int sodot=3;
Toado ran2[400];
int sodotp2=3;
void Vetuong()
{
    for(int i=0;i<=TUONGDUOI;i++)
    {
        for(int j=0;j<=TUONGPHAI;j++)
        {
           if(i==TUONGTREN||i==TUONGDUOI)
            {gotoxy(j,i);
             printf("%c",219);

            }
           else
           {
            if(j==TUONGTRAI||j==TUONGPHAI)
            {
            gotoxy(j,i);
             printf("%c",219);
            }

           }
        }
        printf("\n");
    }
}
void khoitaoran2()
{
ran2[0].x=13;
ran2[1].x=14;
ran2[2].x=15;
ran2[0].y=ran2[1].y=ran2[2].y=16;
}
Toado dichuyenran2(int huong2,int chedo)
{
    Toado dotdaucu2=ran2[0];
    for(int i=0;i<sodotp2-1;i++)
      ran2[i]=ran2[i+1];
    switch(huong2)
    {
    case PHAI:
        {ran2[sodotp2-1].x++;
          break;}
    case TRAI:
        {ran2[sodotp2-1].x--;
          break;}
    case XUONG:
        {
        ran2[sodotp2-1].y++;
        break;
        }
    case LEN:
        {
        ran2[sodotp2-1].y--;
        break;
        }

    }
    if(chedo==3||chedo==5)
    {
        if(ran2[sodotp2-1].x==TUONGPHAI)
           ran2[sodotp2-1].x=TUONGTRAI+1;
        if(ran2[sodotp2-1].x==TUONGTRAI)
          ran2[sodotp2-1].x=TUONGPHAI-1;
        if(ran2[sodotp2-1].y==TUONGTREN)
            ran2[sodotp2-1].y=TUONGDUOI-1;
        if(ran2[sodotp2-1].y==TUONGDUOI)
            ran2[sodotp2-1].y=TUONGTREN+1;
    }

    return dotdaucu2;
}
void hienthiran2(Toado dotdaucu2)
{
    gotoxy(dotdaucu2.x,dotdaucu2.y);
    printf(" ");
    for(int i=0;i<sodotp2;i++)
    {
        gotoxy(ran2[i].x,ran2[i].y);
        printf("#");
    }

}
void themdotran2(Toado dotdaucu2)
{
    sodotp2++;
    for(int i=sodotp2-1;i>=1;i--)
     ran2[i]=ran2[i-1];
    ran2[0]=dotdaucu2;

}
void khoitaoran()
{
 Dotran[0].x=13;
 Dotran[1].x=14;
 Dotran[2].x=15;
 Dotran[0].y=Dotran[1].y=Dotran[2].y=3;
}
void hienthiran(Toado Dotdaucu)
{
    gotoxy(Dotdaucu.x,Dotdaucu.y);
    printf(" ");
    for(int i=0;i<sodot;i++)
       {
         gotoxy(Dotran[i].x,Dotran[i].y);
         printf("%c",'o');
       }

}
void autodichuyen(int *huong,Toado moi)
{
    if(ran2[sodotp2-1].x<moi.x)
    {
        if(*huong==TRAI)
            *huong=TRAI;
        else
         *huong=PHAI;
    }
    else if(ran2[sodotp2-1].x>moi.x)
    {
        if(*huong==PHAI)
            *huong=PHAI;
        else
             *huong=TRAI;
    }
    else if(ran2[sodotp2-1].x==moi.x)
    {
        if(ran2[sodotp2-1].y<moi.y)
        {
            if(*huong==LEN)
                *huong=LEN;
            else
                *huong=XUONG;
        }
        else if(ran2[sodotp2-1].y>moi.y)
        {
            if(*huong==XUONG)
                *huong=XUONG;
            else
                *huong=LEN;
        }

    }
}
Toado hienthimoi2(){
Toado moi;
srand(time(NULL));
moi.x=TUONGTRAI+1 +rand()%(TUONGPHAI-TUONGTRAI-1);
moi.y=TUONGTREN+1 +rand()%(TUONGDUOI-TUONGTREN-1);
gotoxy(moi.x,moi.y);
printf("*");
return moi;
}
bool ran2damoi(Toado moi){
if(moi.x==ran2[sodotp2-1].x&&moi.y==ran2[sodotp2-1].y)
    return true;
return false;
}
Toado dichuyen(int huong,int chedo)
{
    Toado Dotdaucu=Dotran[0];
    for(int i=0;i<sodot-1;i++)
    {
        Dotran[i]=Dotran[i+1];

    }
    switch(huong)
    {
    case XUONG:
        {
        Dotran[sodot-1].y++;
        break;}
    case PHAI:
        {Dotran[sodot-1].x++;
        break;}
    case LEN:
        {Dotran[sodot-1].y--;
        break;}
    case TRAI:
        {Dotran[sodot-1].x--;
        break;}
    }
    if(chedo==1||chedo==3||chedo==5)
    {
        if(Dotran[sodot-1].x==TUONGPHAI)
           Dotran[sodot-1].x=TUONGTRAI+1;
        if(Dotran[sodot-1].x==TUONGTRAI)
          Dotran[sodot-1].x=TUONGPHAI-1;
        if(Dotran[sodot-1].y==TUONGTREN)
            Dotran[sodot-1].y=TUONGDUOI-1;
        if(Dotran[sodot-1].y==TUONGDUOI)
            Dotran[sodot-1].y=TUONGTREN+1;
    }
    return Dotdaucu;

    }
void batsukien(int *huong,int *huong2)
{  int key=0;
    if(kbhit())
    { key=getch();
        switch(key)
        {
            case 119:
                {if(*huong==XUONG)
                *huong=XUONG;
                else
                *huong=LEN;}
                break;
            case 115:
                 {if(*huong==LEN)
                 *huong=LEN;
                 else
                *huong=XUONG;}
                break;
            case 97:
                 {if(*huong==PHAI)
                 *huong=PHAI;
                 else
                *huong=TRAI;}
                break;
            case 100:
                 {if(*huong==TRAI)
                  *huong=TRAI;
                  else
                *huong=PHAI;}
                break;
                case 105:
                {if(*huong2==XUONG)
                *huong2=XUONG;
                else
                *huong2=LEN;}
                break;
            case 107:
                 {if(*huong2==LEN)
                 *huong2=LEN;
                 else
                *huong2=XUONG;}
                break;
            case 106:
                 {if(*huong2==PHAI)
                 *huong2=PHAI;
                 else
                *huong2=TRAI;}
                break;
            case 108:
                 {if(*huong2==TRAI)
                  *huong2=TRAI;
                  else
                *huong2=PHAI;}
                break;
        }



    }
}

bool kiemtrathua(){
if(Dotran[sodot-1].y==TUONGTREN||Dotran[sodot-1].y==TUONGDUOI)
    return true;
if(Dotran[sodot-1].x==TUONGPHAI||Dotran[sodot-1].x==TUONGTRAI)
    return true;
for(int i=0;i<sodot-1;i++)
{if(Dotran[sodot-1].x==Dotran[i].x&&Dotran[sodot-1].y==Dotran[i].y)
 return true;
}
return false;
}
void xulythua(){

        Sleep(500);
        system("cls");
        printf("Gameover");


}
Toado hienthimoi(int a){
srand(time(NULL));
Toado moi;
int k;
do{
k=1;
moi.x=TUONGTRAI+1 +rand()%(TUONGPHAI-TUONGTRAI-1);
moi.y=TUONGTREN+1 +rand()%(TUONGDUOI-TUONGTREN-1);
for(int i=0;i<sodot;i++)
{if(moi.x==Dotran[i].x&&moi.y==Dotran[i].y)
   {k=0;
    break;}
}
}
while(k!=1);
gotoxy(moi.x,moi.y);
if(a%5==4)
printf("%c",219);
else
printf("%c",'*');
return moi;
}
bool kiemtraanmoi(Toado moi)
{
    if(Dotran[sodot-1].x==moi.x&&Dotran[sodot-1].y==moi.y)
        return true;
    return false;
}
void themdot(Toado dotdaucu)
{
    sodot++;
    for(int i=sodot-1;i>=1;i--)
        Dotran[i]=Dotran[i-1];
    Dotran[0]=dotdaucu;
}
void Chedobox(int timesleep,int chedo){
int diem=0;
int huong=4;
int timemoilon=0;
int timemat=10000/timesleep;
Vetuong();
khoitaoran();
Toado moicu;
Toado moi=hienthimoi(timemoilon);
while(1)
{
int huong2=0;
Toado dotdaucu = dichuyen(huong,chedo);
batsukien(&huong,&huong2);
hienthiran(dotdaucu);
if(timemoilon%5==0&&timemoilon!=0)
    {timemat-=1;
      gotoxy(TUONGPHAI+5,TUONGTREN+5);
      printf("%d",timemat);
      }
if(kiemtraanmoi(moi)==true||timemat==0)
{
    if(timemat==0)
    {
        timemat=10000/timesleep;
        gotoxy(moicu.x,moicu.y);
        printf(" ");
        gotoxy(TUONGPHAI+5,TUONGTREN+10);
        printf("    ");
        timemoilon=0;
        moi=hienthimoi(timemoilon);
        moicu=moi;
    }
    else
    {
    moi=hienthimoi(timemoilon);
    moicu=moi;
    themdot(dotdaucu);
    timemoilon++;
    if(timemoilon%5==1&&timemoilon!=1)
      {diem+=timemat;
       gotoxy(TUONGPHAI+5,TUONGTREN+5);
        printf("    ");
       timemat=10000/timesleep;
       timemoilon=0;}
     else
      diem+=5;
    gotoxy(TUONGPHAI+5,TUONGTREN);
    printf("Score: %d",diem);}
}
if(kiemtrathua()==true)
{
    break;
}
Sleep(timesleep);
}
xulythua();
}

void Chedotaydoi(int sleeptime,int chedo){
int huong1=PHAI;
int huong2=PHAI;
Vetuong();
int diem1=0;
int diem2=0;
Toado moicu;
int timemat=10000/sleeptime;
int timemoilon=0;
khoitaoran();
khoitaoran2();
Toado moi=hienthimoi(timemoilon);
while(1)
{   Toado dotdaucu=dichuyen(huong1,chedo);
    Toado dotdaucu2=dichuyenran2(huong2,chedo);
    if(chedo==3)
    autodichuyen(&huong2,moi);
    if(chedo==5)
    batsukien(&huong1,&huong2);
    hienthiran(dotdaucu);
    hienthiran2(dotdaucu2);
    if(timemoilon%5==0&&timemoilon!=0)
    {timemat-=1;
      gotoxy(TUONGPHAI+5,TUONGTREN+10);
      printf("%d",timemat);
      }
        if(timemat==0)
    {
        timemat=10000/sleeptime;
        gotoxy(moicu.x,moicu.y);
        printf(" ");
        gotoxy(TUONGPHAI+5,TUONGTREN+10);
        printf("    ");
        timemoilon=0;
        moi=hienthimoi(timemoilon);
        moicu=moi;
    }
    if(ran2damoi(moi)==true)
    {
        moi=hienthimoi(timemoilon);
        moicu=moi;
        if(chedo==5)
            themdotran2(dotdaucu2);
        timemoilon++;
      if(timemoilon%5==1&&timemoilon!=1)
      {diem2+=timemat;
       gotoxy(TUONGPHAI+5,TUONGTREN+10);
        printf("    ");
       timemat=10000/sleeptime;
       timemoilon=0;}
     else
      diem2+=5;
    gotoxy(TUONGPHAI+5,TUONGTREN+2);
    printf("Score 2:%d",diem2);

    }
    else if(kiemtraanmoi(moi)==true)
    {
        moi=hienthimoi(timemoilon);
        moicu=moi;
        if(chedo==5)
            themdot(dotdaucu);
        timemoilon++;
      if(timemoilon%5==1&&timemoilon!=1)
      {diem1+=timemat;
       gotoxy(TUONGPHAI+5,TUONGTREN+10);
        printf("    ");
       timemat=10000/sleeptime;
       timemoilon=0;}
     else
      diem1+=30;
    gotoxy(TUONGPHAI+3,TUONGTREN);
    printf("Score 1:%d",diem1);

    }
    Sleep(sleeptime);

}
}
int main()
{
int luachondaugame;
int luachonmucdo;
int timesleep;
int luachonchedo;
do{
system("cls");
gotoxy(32,10);
printf("GAME RAN SAN MOI");
gotoxy(34,11);
printf("1.Choi game");
gotoxy(33,12);
printf("2.High Score");
gotoxy(36,13);
printf("3.Exit");
gotoxy(34,14);
printf("Ban chon:  ");
scanf("%d",&luachondaugame);
if(luachondaugame==1||luachondaugame==2||luachondaugame==3)
    break;
}
while(luachondaugame!=1||luachondaugame!=2||luachondaugame!=3);
if(luachondaugame==3)
    return 0;
do{
system("cls");
printf("MOI BAN CHON MUC DO:\n");
printf("1.Sieu de\n");
printf("2.De\n");
printf("3.Vua\n");
printf("4.Kho\n");
printf("5.Sieu kho\n");
printf("Ban chon :");
scanf("%d",&luachonmucdo);
}while(luachonmucdo<1||luachonmucdo>5);
if(luachonmucdo==1)
 timesleep=100;
else if(luachonmucdo==2)
 timesleep=80;
else if(luachonmucdo==3)
timesleep=60;
else if(luachonmucdo==4)
timesleep=50;
else if(luachonmucdo==5)
timesleep=40;

switch(luachondaugame)
{
  case 1:
  do{
  system("cls");
  printf("Ban chon che do choi\n");
  printf("1.Kinh Dien\n");
  printf("2.Box\n");
  printf("3.Dau tay doi\n");
  printf("4.Tranh chuong ngai vat va thu thach\n");
  printf("5.2 player\n");
  printf("Ban chon: ");
  scanf("%d",&luachonchedo);
  }
  while(luachonchedo<1||luachonchedo>5);
  if(luachonchedo==1)
  {
      system("cls");
      Chedobox(timesleep,luachonchedo);

  }
  else if(luachonchedo==2)
  { system("cls");
    Chedobox(timesleep,luachonchedo);
  }
  else if(luachonchedo==3)
  {
      system("cls");
      Chedotaydoi(timesleep,luachonchedo);
  }
  else if(luachonchedo==5)
    system("cls");
     Chedotaydoi(timesleep,luachonchedo);
   break;
}

}



