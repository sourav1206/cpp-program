#include<iostream>
#include<conio.h>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
struct dat
{
	int d,m;
};
int clscanf();
struct student 
{
	struct dat dt;
	float f, fine,tot,adv,due;
	char n[50];
	int r,c;
}stud,s;
struct teacher
{
	struct dat dt;
	char n[50];
	float sal ,adv,tot;
	int id,no;
}tech,t;
int chkdat(int,int);
void addrec(int);//for adding record
void modrec(int);//for modifying record
void searchrec(int);//for searching
void delrec(int);//for deleting records
void salary(int);//for salary claculation;
int start();
void fee(int mm);
FILE *fs,*ft;
int mm,dd;
void ext();
int main()
{
	int i,j,k;
	cout<<"\n";
	system("color 7A");
	cout<<"\t#######################################################\n";
	cout<<"\t |                                                    |\n";
	cout<<"\t |**WELCOME TO C++ PROGRAM OF SCHOOL MANAGEMENT SYSTEM|**\n";
	cout<<"\t |       DEVELOPED BY SOURAV CHOUDHARY                  |\n";
	cout<<"\t#######################################################\n";
	for(i=0;i<5;i++)
	{
		cout<<".";
		Sleep(1000);
	}
	system("cls");
	cout<<"\n";
	system("color 6b");
	cout<<"\n\n\t## WELCOME TO CPP PROGRAM SCHOOL BILLING/MANAGEMNET SYSTEM PROJECT ##\n\n\n";
	cout<<"\nPRESS ANY KEY TO START\n";
	for(i=0;i<5;i++)
	{
		cout<<".";
		Sleep(1000);
	}
	fflush(stdin);
	system("cls");
	system("color 3E");
	cout<<"\n\t\t\t\tPLEASE ENTER CURRENT DATE\n\t\t\t\tMM DD\n\t\t\t\t";
	cin>>mm>>dd;
	mm=chkdat(mm,dd);
	start();
	return 0;
}
int start()
{
	int i,j;
	system("cls");
	cout<<"\n\t\tPLEASE SELECT ONE";
	cout<<"\n\t\t1::STUDENT";
	cout<<"\n\t\t2::TEACHER AND STAFF";
	cout<<"\n\t\t3::Exit";
	fflush(stdin);
	cin>>j;
	switch(j)
	{
		case 3:
			ext();
		case 1:
		{
			system("cls");
			cout<<"\n\t\tPLEASE ENTER THE CHOICE";
			cout<<"\n\t\t1::ADD RECORD";
			cout<<"\n\t\t2::SEARCH RECORD";
			cout<<"\n\t\t3::MODIFY RECORD";
			cout<<"\n\t\t4::DELETE RECORD";
			cout<<"\n\t\t5::CALCULATE FEE";
			cout<<"\n\t\t6::EXIT";
			cout<<"\n\nENTER YOUR CHOICE";
			fflush(stdin);
			cin>>i;
			switch(i)
			{
				case 1:
					addrec(j);
					start();
				case 2:
					searchrec(j);
					start();
				case 3:
					modrec(j);
					start();
				case 4:
					delrec(j);
					start();
				case 5:
					fee(j);
					start();
				case 6:
					ext();
				default:
				{
					cout<<"\n\tINVALID ENTRY!!";
					system("pause");
					start();
				}
			}
		}
		case 2:
		{
			system("cls");
			cout<<"\n\t\tPLEASE ENTER YOUR CHOICE";
			cout<<"\n\t\t1::ADD RECORD";
			cout<<"\n\t\t2::SEARCH RECORD";
			cout<<"\n\t\t3::MODIFY RECORD";
			cout<<"\n\t\t4::DELETE RECORD";
			cout<<"\n\t\t5::CALCULATE SALARY";
			cout<<"\n\t\t6::EXIT";
			cout<<"\n\n ENTER YOUR CHOICE";
			fflush(stdin);
			cin>>i;
			switch(i)
			{
				case 1:
					addrec(j);
					start();
				case 2:
					searchrec(j);
					start();
				case 3:
					modrec(j);
					start();
				case 4:
					delrec(j);
				case 5:
					salary(j);
					start();
				case 6:
					ext();
				default:
				{
					cout<<"\n\n\tINVALID ENTRY!!";
					system("pause");
					start();
				}
			}		
		}
		default:
		{
			cout<<"\n\n\tINVALID ENTRY!!";
			system("pause");
			start();
		}
	}
	return 0;
}
void addrec(int j)
{
	int dif,cdat,ddat,month=0;
	float ff;
	char c='y';
	system("cls");
	cout<<"\n\t******************************************************************";
	cout<<"\n\t                     ***************************                  ";
	cout<<"\n\t*********************          ADD RECORD       ******************";
	cout<<"\n\t                     ***************************                  ";
	cout<<"\n\t******************************************************************";
	if(j==1)
	{
		while(c=='y'||c=='Y')
		{
			int a=1;
			cout<<"Enter the name of student: ";
			fflush(stdin);
			scanf("%[^\n]",stud.n);
			cout<<"\n Enter the class: ";
			fflush(stdin);
			stud.c=clscanf();
			cout<<"\nEnter the Roll number: ";
			fflush(stdin);
			scanf("%2d",&stud.r);
			cout<<"\nEnter month and day till which fee is paid: ";
			fflush(stdin);
			scanf("%2d%2d",&cdat,&ddat);
			cdat=chkdat(cdat,ddat);
			stud.dt.m=cdat;
			ff=stud.c/10.0;
			stud.f=1000*(1+ff);
			dif=mm-stud.dt.m;
			stud.fine=(dif*stud.f)*1/100;
			stud.due=(dif)*stud.f;
			if(dif==1)
			{
				stud.tot=stud.f;
				stud.fine=0;
			}
			else
			{
				stud.tot=stud.fine+stud.due;
			}
			fs=fopen("student","ab+");
			fwrite(&stud,sizeof(stud),1,fs);
			fclose(fs);
			cout<<"\n\nDo you want to contine with the process(press y or Y or press eneter to go to the main menu";
			fflush(stdin);
			c=getch();
		}
	}
	if (j==2)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            cout<<"\n\nEnter name of teacher/staff:";
            fflush(stdin);
            scanf("%[^\n]",tech.n);
            cout<<"\nEnter teacher staff id: ";
            fflush(stdin);
            cin>>tech.id;
            cout<<"\nEnter number of class per month:: ";
            cin>>tech.no;
            fflush(stdin);
            cout<<"\n Enter month and day till which salary is paid :: ";
            cin>>tech.dt.m>>tech.dt.d;
            cdat=chkdat(cdat,ddat);
            tech.dt.m=cdat;
            tech.sal=tech.no*500;
            tech.adv=(tech.dt.m-mm-1)*tech.sal;
            if(tech.adv<0)
            {
            	tech.adv=0;
			}
			tech.tot=tech.sal;
			ft=fopen("teacher","ab+");
            fwrite(&tech,sizeof(tech),1,ft);
            fclose(ft);
            cout<<"\n\nDo you want to contine with the process(press y or Y or press eneter to go to the main menu";
			fflush(stdin);
			c=getch();
		}
		fflush(stdin);
		cout<<"\n\n";
		system("pause");
	}
}

void searchrec(int j)
{
	char name[50],namet[50];
	int a=1,choice;
	char c='y';
	if(j==1)
	{
		while(c=='y'||c=='Y')
		{
			int a=1;
			system("cls");
    		cout<<"\n\t******************************************************************";
            cout<<"\n\t                     ***************************                  ";
            cout<<"\n\t*********************       SEARCH RECORD       ******************";
	        cout<<"\n\t                     ***************************                  ";
	        cout<<"\n\t******************************************************************";
			cout<<"\n\n\t\tPLEASE CHOOSE SEARCH TYPE::";
			cout<<"\n\n\t\t1::SEARCH NY NAME::";
			cout<<"\n\n\t\t2::SEARCH BY CLASS::";
			cout<<"\n\n\t\t3::SEARCH BY ROLL NUMBER::";
			cout<<"\n\n\t\t4::EXIT";
			cout<<"\n\n\t\t::Enter your choice:: ";
			fflush(stdin);
			cin>>choice;
			if(choice==1)
			{
				a=1;
				cout<<"\n\nEnter name of student to search: ";
				fflush(stdin);
				scanf("%[^\n]",name);
				fs=fopen("student","rb");
				while(fread(&stud,sizeof(stud),1,fs)==1)
				{
					if(strcmpi(name,stud.n)==0)
					{
						a=0;
						cout<<"\nName :-  "<<stud.n;
						cout<<"\nClass :- "<<stud.c;
						cout<<"\nRoll No. :- "<<stud.r;
						printf("\nmonthy fee =%.2f",stud.f);
                        printf("\nlast fee paid in month =%2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        printf("\n fine=%.2f",stud.fine);
                        printf("\n total=%.2f",stud.tot);
					}
				}
				if(a==1)
				{
					cout<<"\n\n RECORD NOT FOUND";
				}
				cout<<"\n\n";
				system("pause");
				fflush(stdin);
				fclose(fs);
			}
			else if(choice==2)
			{
				int cl;
				a=1;cout<<"\n\n Enter class of student to search: ";
				fflush(stdin);
				cl=clscanf();
				fs=fopen("student","rb");
				while(fread(&stud,sizeof(stud),1,fs)==1)
				{
					if(stud.c==cl)
					{
						a=0;
						cout<<"\nName :-  "<<stud.n;
						cout<<"\nClass :- "<<stud.c;
						cout<<"\nRoll No. :- "<<stud.r;
						printf("\nmonthy fee =%.2f",stud.f);
                        printf("\nlast fee paid in month =%2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        printf("\n fine=%.2f",stud.fine);
                        printf("\n total=%.2f",stud.tot);
					}
				}
				if(a==1)
				{
					cout<<"\n\n RECORD NOT FOUND";
				}
				cout<<"\n\n";
				system("pause");
				fflush(stdin);
				fclose(fs);
			}
			else if(choice==3)
			{
				int rll;
				a=1;
				cout<<"\n\n Enter roll nu. of student to search: ";
				fflush(stdin);
				rll=clscanf();
				fs=fopen("student","rb");
				while(fread(&stud,sizeof(stud),1,fs)==1)
				{
					if(strcmpi(name,stud.n)==0)
					{
						a=0;
						cout<<"\nName :-  "<<stud.n;
						cout<<"\nClass :- "<<stud.c;
						cout<<"\nRoll No. :- "<<stud.r;
						printf("\nmonthy fee =%.2f",stud.f);
                        printf("\nlast fee paid in month =%2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        printf("\n fine=%.2f",stud.fine);
                        printf("\n total=%.2f",stud.tot);
					}
				}
				if(a==1)
				{
					cout<<"\n\nRECORD NOT FOUND";
				}
				cout<<"\n\n";
				system("pause");
				fflush(stdin);
				fclose(fs);
			}
			else if(choice==4)
			{
				ext();
			}
			else
			{
				cout<<"\n\n\t\t INVALID ENTRY!!!\n\n\t\t ";
				system("pause");
				searchrec(1);
			}
			cout<<"\n\nDo you want to continue (press y or Y or press enter to go to the menu"; 
			fflush(stdin);
			c=getch();
		}
	}
	if(j==2)
	{
		while(c=='y'||c=='Y')
		{
			int a=1;
			cout<<"\n\nName of teacher to search: ";
			fflush(stdin);
			scanf("%[^\n]",namet);
            ft=fopen("teacher","rb");
            while(fread(&tech,sizeof(tech),1,ft)==1)
            {
            	if(strcmp(namet,tech.n)==0)
            	{
            		a=0;
            		cout<<"\Name:- "<<tech.n;
            		cout<<"\nTeacher staff id:- "<<tech.id;
            		cout<<"\nMonth till salary is paid:- "<<tech.dt.m;
            		printf("\nmonthy salary = %.2f",tech.sal);
                    printf("\nadvance paid = %.2f",tech.adv);
				}
			}
			if(a==1)
			{
				cout<<"\n\n RECORD NOT FOUND ";
			}
			cout<<"\n\n";
			system("pause");
			fflush(stdin);
			fclose(ft);
			cout<<"\n\nDo you want to continue (press y or Y or press enter to go to the menu"; 
			fflush(stdin);
			c=getch();
		}
	}
}
void modrec(int j)
{
	char name[50];
	int a=1,choice,cl,rolno;
	char c='y';
	if(j==1)
	{
		while(c=='y'||'Y')
		{
			system("cls");
			cout<<"\n\t******************************************************************";
            cout<<"\n\t                     ***************************                  ";
            cout<<"\n\t*********************       MODIFY RECORD       ******************";
	        cout<<"\n\t                     ***************************                  ";
	        cout<<"\n\t******************************************************************";
	        cout<<"\n\n\t\t1PLEASE CHOOSE MODIFY TYPE:: ";
	        cout<<"\n\n\t\t1::Modify by name::  ";
	        cout<<"\n\n\t\t2::Modify by name and class:: ";
	        cout<<"\n\n\t\t3::EXIT";
	        cout<<"\n\n\t\t::Enter your choice:: ";
	        fflush(stdin);
	        cin>>choice;
	        if(choice==1)
	        {
	        	int a=0;
	        	cout<<"\n\nEnter name of student to modify: ";
	        	fflush(stdin);
	        	scanf("%[^\n]",name);
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                	a=1;
                	if(strcmpi(name,stud.n)==0)
                	{
                		a=0;
                		cout<<"\nEnter new name of student: ";
                		fflush(stdin);
                		scanf("%[^\n]",stud.n);
                		cout<<"\n Enter new class of student: ";
                		fflush(stdin);
                		stud.c=clscanf();
                		cout<<"\n Enter new roll no. of student: ";
                		fflush(stdin);
                		cin>>stud.r;
                		fseek(fs,-sizeof(stud),SEEK_CUR);
                		fwrite(&stud,sizeof(stud),1,fs);
                		fclose(fs);
					}
				}
				if (a==1)
				{
					cout<<"\n\n RECORD NOT FOUND";
				}
				else
				{
					cout<<"\n\nRECORD SUCCESSFULLY MODIFIED";
				}
				cout<<"\n\n";
				system("pause");
			}
			else if(choice==2)
			{
				int a=0;
				cout<<"\n\nEnter name of student to modify: ";
				fflush(stdin);
				scanf("%[^\n]",name);
				cout<<"\n\n ENter class of student to modify: ";
				fflush(stdin);
				cl=clscanf();
				fs=fopen("student","rb+");
				while(fread(&stud,sizeof(stud),1,fs)==1)
				{
					a=1;
					if(strcmpi(name,stud.n)==0&&cl==stud.c)
					{
						a=0;
						cout<<"\n Enter new name of student: ";
						fflush(stdin);
						scanf("%[^\n]",stud.n);
						cout<<"\n Enter new class of student: ";
						fflush(stdin);
						stud.c=clscanf();
						cout<<"\n Enter new roll of student: ";
						fflush(stdin);
						cin>>stud.r;
						fseek(fs,-sizeof(stud),SEEK_CUR);
						fwrite(&stud,sizeof(stud),1,fs);
						fclose(fs);
					}
				}
				if(a==1)
				{
					cout<<"\n\n RECORDS NOT FOUND!!";
				}
				else
				{
					cout<<"\n\n RECORDS SUCCESSFULLY MODEFIED ";
				}
				cout<<"\n\n";
				system("pause");
			}
			else if(choice==4)
			{
				ext();
			}
			else
			{
				cout<<"\n\n\t\tINVALID ENTRY!!!\n\n\t\t";
				system("pause");
				modrec(1);
			}
			cout<<"\n\nDo you want to continue (press y or Y or press enter to go to the menu";
			fflush(stdin);
			c=getch();
		}
		getch();
	}
	if(j==2)
	{
		while(c=='y'||c=='Y')
		{
			int a=1;
			cout<<"Enter name of teacher to modify: ";
			fflush(stdin);
			scanf("%[^\n]",name);
            ft=fopen("teacher","rb+");
            while(fread(&tech,sizeof(tech),1,ft)==1)
            {
            	if(strcmpi(name,tech.n)==0)
            	{
            		a=0;
            		cout<<"\n Enter new name of teacher: ";
            		fflush(stdin);
            		scanf("%[^\n]",tech.n);
            		cout<<"\nEnter new id of teacher: ";
            		fflush(stdin);
            		cin>>tech.id;
            		fseek(ft,-sizeof(tech),SEEK_CUR);
            		fwrite(&tech,sizeof(tech),1,ft);
            		fclose(ft);
				}
			}
			if(a==1)
			{
				cout<<"\n\nRECORD NOT FOUND ";
			}
			else
			{
				cout<<"\n\nRECORD SUCCESSFULLY MODEFIED";
			}
			cout<<"\n\n";
			system("pause");
			fflush(stdin);
			
			cout<<"\n\nDo you want to continue (press y or Y or press enter to go to the menu";
			fflush(stdin);
			c=getch();
		}
		getch();
	}
}
void delrec(int j)
{
	system("cls");
	cout<<"\n\t******************************************************************";
    cout<<"\n\t                     ***************************                  ";
    cout<<"\n\t*********************       DELETE RECORD       ******************";
	cout<<"\n\t                     ***************************                  ";      
	cout<<"\n\t******************************************************************";      
    FILE *temp,*t1;
    int a=1;
    char name[50],c='y';
    if(j==1)
    {
    	while(c=='y'||c=='Y')
    	{
    		int a=1;
    		cout<<"\n\n Enter name of student to delete: ";
			fflush(stdin);
			 scanf("%[^\n]",name);
            fs=fopen("student","rb");
            temp=fopen("tempfile","wb");
            while (fread(&stud,sizeof(stud),1,fs)==1)
            {
            	if (strcmp(stud.n,name)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&stud,sizeof(stud),1,temp);
                }
			}
			
			if(a==1)
			{
				cout<<"\n\nRECORD NOT FOUND ";
			}
			else
			{
				cout<<"\n\nRECORD SUCCESSFULLY DELETED ";
			}
			cout<<"\n\n";
			system("pause");
			
			fclose(fs);
			fclose(temp);
			system("del student");
			system("ren tempfile, student");
			cout<<"Do you want to continue with the process (press y or Y or press enter to go the menu ";
			fflush(stdin);
			c=getch();			
		}
		getch();
	}
	if(j==2)
	{
		a=1;
		char namet[50];
		while(c=='y'||c=='Y')
		{
			cout<<"\n\n Enter name of teacher to delete record: ";
			fflush(stdin);
			scanf("%[^\n]",namet);
            ft=fopen("teacher","rb");
            t1=fopen("tempfile1","wb");
            while (fread(&tech,sizeof(tech),1,ft)==1)
            {
                if (strcmp(tech.n,namet)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&tech,sizeof(tech),1,t1);
                }
            }

            if (a==1)
            {
            	cout<<"\n\nRECORD NOT FOUND ";
			}
			else
			{
				cout<<"\n\nRECORD SUCCESSFULLY DELETED";
			}
			cout<<"\n\n";
			system("pause");
			fflush(stdin);
			
			fclose(ft);
            fclose(t1);
            system("del teacher");
            system("ren tempfile1, teacher");
            cout<<"\n\nDo you want to continue with the process(press y or Y or press enter to go to the menu";
            fflush(stdin);
            c=getch();
		}
		getch();
	}
}
void salary(int mm)
{
	system("cls");
	cout<<"\n\t******************************************************************";
    cout<<"\n\t                     ***************************                  ";
    cout<<"\n\t*********************       SALARY      ******************";
	cout<<"\n\t                     ***************************                  ";      
	cout<<"\n\t******************************************************************";
	FILE *f,*t;
    int a=1,day;
    char name[50],c='y';
    int month,dif,id;
    while(c=='y'||c=='Y')
    {
    	int a=1;
        fflush(stdin);
        cout<<"\n\nEnter name:: ";
        scanf("%[^\n]",name);
        cout<<"\n\n Enter id::";
        cin>>id;
        f=fopen("teacher","rb+");
        t=fopen("te","wb+");
        while(fread(&tech,sizeof(tech),1,f)==1)
        {
        	if(strcmp(tech.n,name)==0)
        	{
        		float lsal;
        		a=0;
        		cout<<"\n\nEnter the month till which salary is to be paid:: ";
        		fflush(stdin);
        		cin>>month;
        		month=chkdat(month,day);
        		tech.adv=(month-mm-1)*tech.sal;
                if (tech.adv<0) tech.adv=0;
                lsal=mm-tech.dt.m;
                if(lsal<0) lsal=0;
                tech.tot=tech.adv+tech.sal*(1+lsal);
                if(month==tech.dt.m) tech.tot=0;
                printf("\nmonthy salary left to be paid:: %.2f",lsal);
                printf("\ntotal :: %.2f",tech.tot);
                printf("\nadvance :: %.2f",tech.adv);
                tech.dt.m=month;
                fwrite(&tech,sizeof(tech),1,t);
                fclose(f);
                fclose(t);
                
                if(a==1)
                {
                	cout<<"\n\nRECORD NOT FOUND ";
				}
				cout<<"\n\n";
				system("pause");
                fflush(stdin);
                system("del teacher");
                system("ren te, teacher");
			}
		}
		cout<<"\n\nDo you want to continue with the process(press y or Y or press enter to go to the menu";
        fflush(stdin);
        c=getch();	
	}
	getch();
}
void fee(int mm)
{
	system("cls");
	cout<<"\n\t******************************************************************";
    cout<<"\n\t                     ***************************                  ";
    cout<<"\n\t*********************             FEE           ******************";
	cout<<"\n\t                     ***************************                  ";      
	cout<<"\n\t******************************************************************";
	FILE *f,*t;
	int a=0;
	char name[50],c='y';
	int clas,roll,month,dif;
	while(c=='y'||c=='Y')
	{
		int a=1,day=0;
		fflush(stdin);
		cout<<"\n\n Enter name:: ";
		scanf("%[^\n]",name);
		cout<<"\n\nEnter class:: ";
		fflush(stdin);
		clas=clscanf();
		cout<<"\n\nEnter roll:: ";
		fflush(stdin);
		cin>>roll;
		f=fopen("student","rb+");
        t=fopen("te","wb");
        while(fread(&stud,sizeof(stud),1,f)==1)
        {
        	if(strcmp(stud.n,name)==0&&clas==stud.c&& roll==stud.r)
        	{
        		a=0;
        		cout<<"\n\nEnter the month till which fee to be paid:: ";
        		fflush(stdin);
        		cin>>month;
        		month=chkdat(month,day);
                dif=mm-stud.dt.m;
                stud.fine=(dif*stud.f)*0.01;
                stud.due=(dif)*stud.f;
                if (stud.fine<0) stud.fine=0;
                if (stud.due<0) stud.due=0;
                if (stud.tot<0) stud.tot=0;
                stud.tot=stud.fine+stud.due+stud.adv;
                printf("\nfine :: %.2f",stud.fine);
                printf("\ndue :: %.2f",stud.due);
                printf("\ntotal :: %.2f",stud.tot);
                printf("\nadvance :: %.2f",stud.adv);
                stud.dt.m=month;
                stud.tot=0;
                stud.fine=0;
                stud.due=0;
                fwrite(&stud,sizeof(stud),1,t);
			}
		}
		if(a==1)
		{
			cout<<"\n\n RECORD NOT FOUND";
		}
		cout<<"\n\n";
		system("pause");
		fflush(stdin);
		
		fclose(f);
		fclose(t);
		system("del student");
		system("ren te, student");
		cout<<"\n\nDo you want to continue with the process(press y or Y or press enter to go to the menu";
        fflush(stdin);
        c=getch();
	}
	getch();
}
void ext()
{
	int i; 
	system("color 7c");
	cout<<"\n\n\t\t Thanks For using cpp program school billing system\n\n\t\t MADE BY SOURAV CHOUDHARY";
	system("pause");
	system("cls");
	cout<<"\n\n\t\t EXITING\n\n";
	for(i=1;i<=5;i++)
	{
		Sleep(100);
		cout<<"*";
	}
	exit(0);
}
int chkdat(int mnt,int dnt)
{
	int mon,day;
	if(mnt>12||mnt<1||dnt<1||dnt>32)
	{
		MessageBox(0,"INVALID DATE!\n ENTER AGAIN","ERROR!",0);
		
		fflush(stdin);
		cin>>mon>>day;
		mon=chkdat(mon,day);
	}
	else
	{
		return (mnt);
	}
}
int clscanf()
{
	int mnt,mon;
	fflush(stdin);
	cin>>mnt;
	if(mnt>12||mnt<1)
	{
		MessageBox(0,"INVALID CLASS!\nEnter class","Erroe!!",0);
		fflush(stdin);
		mon=clscanf();
	}
	else
	{
		return mnt;
	}
}
