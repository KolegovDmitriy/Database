#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include<iostream.h>
#include<io.h>
#include<stdio.h>
#include<conio.h>
#include<sys\stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int zag(void)
{
textcolor(1);cprintf("N#");textcolor(2);cprintf(" F.I.O ");textcolor(3);cprintf("  God vipuska");textcolor(4);cprintf("  Specialnost");textcolor(5);cprintf("  Adress");textcolor(6);cprintf("  Tel.");textcolor(7);cprintf("  Mesto raboti");textcolor(10);cprintf("  Doljnost");textcolor(11);cprintf("  Gorod\n");textcolor(9);
}

int menu(void)
{
clrscr();
textcolor(9);
gotoxy(20,8);
cout<<"1.Vivod na ekran svedenii obo vsex vipusknikax";
gotoxy(20,9);
cout<<"  uporyadochennix po F.I.O";
gotoxy(20,11);
cout<<"2.Vivod spiska tolko zadannogo goda vipuska";
gotoxy(20,13);
cout<<"3.Vivod spiska tolko zadannoi specialnosti";
gotoxy(20,15);
cout<<"4.Vvod dannix o novom vipusknike";
gotoxy(20,17);
cout<<"5.Izmenenie dannix o vipusknike";
gotoxy(20,19);
cout<<"6.Poisk po F.I.O.";
gotoxy(20,21);
cout<<"7.Vivod menu";
gotoxy(20,23);
cout<<"8.Exit";

}


struct persrec
{
int ind;
char name[30],spec[30],doma[30],rab[30],dolj[30],g[30];
int gv,tel;
};

int sort(void)
{
int h=open("vip.dat",O_RDONLY|O_BINARY);
long n=filelength(h);
int m=n/sizeof(struct persrec);
struct persrec *p=new struct persrec[m];

int i;
while(!eof(h))
read(h,p+i,sizeof(persrec));
int k;
for(i=0;i<m-1;i++)
for(k=i+1;k<m;k++)
if(p[k].name[0]<p[i].name[0])
{
struct persrec tmp=p[k];
p[k]=p[i];
p[i]=tmp;
}
int q=("db.tmp",O_CREAT|O_BINARY|O_RDWR,S_IWRITE);
write(q,p,m*sizeof(persrec));
close(q);
remove("pers.dat");
rename("db.tmp","vip.dat");

}


int pokaz(void)
{
struct persrec pr;
int m=open("vip.dat",O_RDONLY|O_BINARY);
zag();
while(!eof(m))
    {
     read(m,& pr,sizeof(pr));
     cout<<pr.ind<<"\t";
     cout<<pr.name<<"\t";
     cout<<pr.gv<<"\t";
     cout<<pr.spec<<"\t";
     cout<<pr.doma<<"\t";
     cout<<pr.tel<<"\t";
     cout<<pr.rab<<"\t";
     cout<<pr.dolj<<"\t";
     cout<<pr.g<<"\t"<<endl;
    }
     close(m);

}


int vgv(void)
{
	  int a;
	  cout<<"Vvedite god vipuska\n";
	  cin>>a;
	  int h=open("vip.dat",O_RDONLY|O_BINARY);
	   zag();
	  while(!eof(h))
	    {
	   struct persrec pr;
	    read(h,& pr,sizeof(struct persrec));
	    if(pr.gv==a)
	       {
		 cout<<pr.ind<<"\t";
		 cout<<pr.name<<"\t";
		 cout<<pr.gv<<"\t";
		 cout<<pr.spec<<"\t";
		 cout<<pr.doma<<"\t";
		 cout<<pr.tel<<"\t";
		 cout<<pr.rab<<"\t";
		 cout<<pr.dolj<<"\t";
		 cout<<pr.g<<"\t"<<endl;
	       }
	     }

	     close(h);
}


int vvod(void)
{
	   struct persrec pr;
	   int h=open("vip.dat",O_WRONLY|O_CREAT|O_BINARY|O_APPEND,S_IWRITE);
	   cout<<"skolko zapisei xotite dobavit?";
	   int i,w;
	   cin>>w;
	  for(i=0;i<w;i++)
	  {
	    clrscr();
	    pr.ind=i;
	    cout<<"vvedite f.i.o\n";
	    gets(pr.name);
	    cout<<"vvedite god vipuska\n";
	    cin>>pr.gv;
	    cout<<"vvedite specialnost vipuska\n";
	    gets(pr.spec);
	    cout<<"vvedite domashnii adress\n";
	    gets(pr.doma);
	    cout<<"vvedite telefon\n";
	    cin>>pr.tel;
	    cout<<"vvedite mesto raboti\n";
	    gets(pr.rab);
	    cout<<"vvedite doljnost\n";
	    gets(pr.dolj);
	    cout<<"vvedite gorod\n";
	    gets(pr.g);
	    write(h,& pr,sizeof(pr));
	  }
	close(h);
}

int vs(void)
{
	  clrscr();
	  cout<<"Vvedite specialnost\n";
	  char  r[30];
	  cin>>r;
	  int h=open("vip.dat",O_RDONLY|O_BINARY);
	  zag();

	  while(!eof(h))
	    {
	     struct persrec pr;
	     read(h,& pr,sizeof(struct persrec));
	     if(!strcmp(pr.spec,r))
	       {
		 cout<<pr.ind<<"\t";
		 cout<<pr.name<<"\t";
		 cout<<pr.gv<<"\t";
		 cout<<pr.spec<<"\t";
		 cout<<pr.doma<<"\t";
		 cout<<pr.tel<<"\t";
		 cout<<pr.rab<<"\t";
		 cout<<pr.dolj<<"\t";
		 cout<<pr.g<<"\t"<<endl;
	       }
	     }
	close(h);
}

int vname(void)
{
	  clrscr();
	  cout<<"Vvedite F.I.O\n";
	  char p[30];
	  cin>>p;
	  int o=open("vip.dat",O_RDONLY|O_BINARY);
	  zag();
	  while(!eof(o))
	    {
	     struct persrec pr;
	     read(o,& pr,sizeof(struct persrec));
	     if(!strcmp(pr.name,p))
	       {
		 cout<<pr.ind<<"\t";
		 cout<<pr.name<<"\t";
		 cout<<pr.gv<<"\t";
		 cout<<pr.spec<<"\t";
		 cout<<pr.doma<<"\t";
		 cout<<pr.tel<<"\t";
		 cout<<pr.rab<<"\t";
		 cout<<pr.dolj<<"\t";
		 cout<<pr.g<<"\t"<<endl;
	       }
	     }
	close(o);
}

int idov(void)
{
persrec pr;
char d[30];
cout<<"vvedite F.I.O";
cin>>d;
int h=open("vip.dat",O_BINARY|O_RDONLY);
int notfound=1,cnt=0;
 while(!eof(h))
   {
     read(h,& pr,sizeof(struct persrec));
     if(strcmp(pr.name,d))
       {
	notfound=0;
	break;
       }
     cnt++;
   }
   close(h);
 if(notfound)cout<<"zapis ne naidena";else
     {
	    cout<<"vvedite god vipuska\n";
	    cin>>pr.gv;
	    cout<<"vvedite specialnost vipuska\n";
	    gets(pr.spec);
	    cout<<"vvedite domashnii adress\n";
	    gets(pr.doma);
	    cout<<"vvedite telefon\n";
	    cin>>pr.tel;
	    cout<<"vvedite mesto raboti\n";
	    gets(pr.rab);
	    cout<<"vvedite doljnost\n";
	    gets(pr.dolj);
	    cout<<"vvedite gorod\n";
	    gets(pr.g);
	    int  h=open("vip.dat",O_RDWR|O_BINARY,S_IWRITE);
	   // lseek(h,o,end*sizeof(struct persrec));
	    write(h,& pr,sizeof(struct persrec));
	    close(h);
      }
}



int _tmain(int argc, _TCHAR* argv[]) 
{
int q;ch:menu();
char c=getch();
  switch(c)
       {
	case'1':clrscr();pokaz();
	  cout<<"\nDlya vizova menu vvedite 7\n";cin>>q;if(q==7)goto ch;
	case'2':clrscr();vgv();
	  cout<<"\nDlya vizova menu vvedite 7\n";cin>>q;if(q==7)goto ch;
	case'3':clrscr();vs();
	  cout<<"\nDlya vizova menu vvedite 7\n";cin>>q;if(q==7)goto ch;
	case'4':clrscr();vvod();
	  cout<<"\nDlya vizova menu vvedite 7\n";cin>>q;if(q==7)goto ch;
	case'5':clrscr();idov();
	  cout<<"\nDlya vizova menu vvedite 7\n";cin>>q;if(q==7)goto ch;
	case'6':clrscr();vname();
	  cout<<"\nDlya vizova menu vvedite 7\n";cin>>q;if(q==7)goto ch;
	case'7':goto ch;
	case'8':goto ch1;
       }
goto ch;ch1:

}
