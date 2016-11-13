 #include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<process.h>

using namespace std;
#include<windows.h> //  header file for gotoxy
      //header file for standard input output

 

  COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 void rectangle(int,int,int,int);
class domain_c
 {
 	public:
 		char domain[10][60];
 		domain_c()
 		{
 			strcpy(domain[0],"Programming");
 			strcpy(domain[1],"Web Development");
 			strcpy(domain[2],"Software Testing");
 			strcpy(domain[3],"Mobile Computing");
 			strcpy(domain[4],"Network Security");
 			strcpy(domain[5],"Data Science");
 			strcpy(domain[6],"Telecommunication Engg");
 			strcpy(domain[7],"Image Processing");
 			strcpy(domain[8],"Digital Signal Processing");
 			strcpy(domain[9],"Power Electronics and VLSI design");
		 }
 		void printdomain(int x,int y)
 		{  int temp=y;
 			for(int i=0;i<10;i++)
 			{   
 				gotoxy(x,++y);
 				cout<<domain[i]<<" - "<<i;
			 }
			 rectangle(x-1,temp,40,++y-temp);
		 }
		 friend class company;
 };
  class streams
 {
 	public:
 		char ch[4][35];
 		streams()
 		{
 			strcpy(ch[0],"CSE & IT");
 			strcpy(ch[1],"ETC");
 			strcpy(ch[2],"EEE");
		 }
		 printbranch(int x,int y)
		 {
		 	gotoxy(++x,++y);int i;
		 	cout<<"Available Branches";
		 	gotoxy(x,++y);
		 	cout<<"and codes";
		 	gotoxy(x+3,++y);
		 	for(i=0;i<3;i++)
		 	{
		 		gotoxy(x+3,y+i);
		 		cout<<ch[i]<<"-"<<i+1;
			 }
			 rectangle(x-2,y-3,20,i+5);
		 }
		 friend class company;
 };
 #include "hbdiary.h"

 
 
 
 class graph
 {
    public:
    	char domain_id[10];
    	char current[10];
    	char oney[10];
    	char twoy[10];
void delete_domain(char did[])
{
		ifstream ifs("backend/db2.csv");
		ofstream ofs("backend/temp.csv");
		char extract[100];int flag=0;
		ifs>>extract;int i=0;int k=0;
	while(!ifs.eof())
	{  
	i=0;
	for(; extract[i]!=',';i++)
		domain_id[k++]=extract[i];
		domain_id[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		current[k++]=extract[i];
		current[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		oney[k++]=extract[i];
		oney[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		twoy[k++]=extract[i];
		twoy[k]='\0';
		i++;k=0;
		
		if(strcmpi(domain_id,did)==0)
		{  flag=1;
			
		}
		else
		{
			ofs<<domain_id<<","<<current<<","<<oney<<","<<twoy<<","<<endl;
		}
		ifs>>extract;
	}
	
	
	ofs.close();
	ifs.close();
	remove("backend/db2.csv");
	rename("backend/temp.csv","backend/db2.csv");
	if(flag==1)
	{
		gotoxy(30,24);
		cout<<"Data deleted for given domain.";
		gotoxy(30,25);
		cout<<"Press any to continue.";
		getch();
	}
	else
	{
		system("cls");
		gotoxy(30,6);
		cout<<"No match found for your given domain. Press any key to continue";
		getch();
	}
		
}
    
void add_domain_details()
{
	system("cls");
	gotoxy(30,3);
	cout<<"Add Domain details";
	gotoxy(30,4);
	cout<<"___________________";
	domain_c c;char dom[3];
	c.printdomain(40,6);
	gotoxy(30,18);
	cout<<"Enter Domain Id : ";cin>>dom;
	gotoxy(30,19);
	cout<<"Enter Current year placement :";
	gotoxy(30,20);
	cout<<"Enter Last year placement :";
	gotoxy(30,21);
	cout<<"Enter Last to last year placement :";
	
	int flag=0;char extract[100];
	ifstream ifs("backend/db2.csv");
	ifs>>extract;int i=0;int k=0;
	while(!ifs.eof())
	{  
	i=0;
	for(; extract[i]!=',';i++)
		domain_id[k++]=extract[i];
		domain_id[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		current[k++]=extract[i];
		current[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		oney[k++]=extract[i];
		oney[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		twoy[k++]=extract[i];
		twoy[k]='\0';
		i++;k=0;
		
		if(strcmpi(domain_id,dom)==0)
		{  flag=1;
			break;
		}
		ifs>>extract;
	}
	
	
	
	ifs.close();
	if(flag==1)
	{
		system("cls");
		gotoxy(45,5);
		cout<<"Given domain id details are already in database and cannot be edited/added again.";
		gotoxy(50,7);
		cout<<"Press any key to return to main menu..";
		getch();
	}
	else
	{
	gotoxy(60,19);
	cin>>current;
	gotoxy(57,20);
	cin>>oney;
	gotoxy(66,21);
	cin>>twoy;
	ofstream ofs("backend/db2.csv",ios::app);
	ofs<<dom<<","<<current<<","<<oney<<","<<twoy<<","<<endl;
	ofs.close();
	gotoxy(30,23);
	cout<<"Details added ! Press any key to continue ";
	getch();
		
	}
}
void domain_analyzer()
    	{
    		system("cls");
    		gotoxy(40,5);
    		cout<<"Domain Analyzer tool";
    		rectangle(35,4,28,2);
    		gotoxy(30,8);
    		domain_c d;
    		d.printdomain(30,8);
    		gotoxy(30,20);
    		cout<<"Input domain in console input to see the domain analyzer graph.";
    		 gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	int integer=c-'0';
	ifstream ifs("backend/db2.csv");
	system("cls");
	gotoxy(30,4);
	cout<<"Domain :"<<d.domain[integer];
	gotoxy(25,5);
	cout<<"--------------------------------------------------------------------------------------------------------------------";
	char extract[100];int flag=0;
	int i=0;int k=0;
	while(!ifs.eof())
	{  ifs>>extract;
	i=0;
	for(; extract[i]!=',';i++)
		domain_id[k++]=extract[i];
		domain_id[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		current[k++]=extract[i];
		current[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		oney[k++]=extract[i];
		oney[k]='\0';
		i++;k=0;
		for(;extract[i]!=',';i++)
		twoy[k++]=extract[i];
		twoy[k]='\0';
		i++;k=0;
		
		if(domain_id[0]==c)
		{  flag=1;
		break;
			
		}
		
		
	}
	
	
	
	ifs.close();
	if(flag==0)
	{
		gotoxy(45,6);
		cout<<"Sorry no match found for your given domain number !!  INVALID DOMAIN";
		gotoxy(50,8);
		cout<<"Press any key to return .";
		getch();
		
	}
	else
	{
		gotoxy(30,7);
		cout<<"Current Year Placement (number)       Last year placement          Last to last year placement";
		gotoxy(30,8);
		cout<<"-----------------------------------------------------------------------------------------------------";
		gotoxy(36,9);
		cout<<current;gotoxy(75,9);cout<<oney;gotoxy(100,9);cout<<twoy;
		int a,b,c;
		a=atoi(current);
		b=atoi(oney);
		c=atoi(twoy);
		if(a>b&&b>c)
		  strict_up(45,14);
		else
	     if(c>b&&b>a)
	     strict_down(45,14);
	    else
	    fluct(45,14);
	    getch();
		
		
	}
	
    		
		}
		
 };
 class company
 {
 	public:
 		char name[80];
 		char branch[10];
 		char domains[15];
 		char hq[80];
 		char contact[20];
		 char email[80];
		 char avg[10];
		 char low[10];
		 char high[10];
		 char dif[4];
		 int emp;
		 char package[10];
		 
 	char college[50];
		 void addcomapny();
		 void addprevious();
		 void editcompanydetails()
		{
			system("cls");char cname[60];
			gotoxy(50,5);
			cout<<"Edit Company Details ";
			gotoxy(50,6);
			cout<<"______________________";
			gotoxy(30,8);
			let:
				{
				
			cout<<"Enter Company (if don't remember type 'not') :";
			cin>>cname;
			if(strcmpi(cname,"not")==0)
			{  
			viewcompany();
			getch();
				goto let;
			}
		}
		
			system("cls");
			gotoxy(30,8);
			cout<<"1. Edit details of a company ";
			
			
			gotoxy(30,14);
			cout<<"Enter your choice :";
			int c;
			cin>>c;
			switch(c)
			{
				case 1:
					{
						ifstream ifs("backend/db1.csv");
						ofstream ofs("backend/temp.csv");
						char extract[150];
						ifs>>extract;int flag=0;
						while(!ifs.eof())
						{
							int k=0;
       	int i=0;
       	for( ;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
        for( ;extract[i]!=',';i++)
            branch[k++]=extract[i];
       	   branch[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            domains[k++]=extract[i];
       	   domains[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            hq[k++]=extract[i];
       	   hq[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            contact[k++]=extract[i];
       	   contact[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!='\0';i++)
       	   email[k++]=extract[i];
       	   email[k]='\0';
       	   if(strcmpi(cname,name)==0)
       	   {  flag=1;
       	   	  editingbasic(cname);
       	   	  	ofs<<name<<","<<branch<<","<<domains<<","<<hq<<","<<contact<<","<<email<<endl;
       	   	 
       	   	  editingadvance(branch,domains,name,cname);
       	   	  
			  }
			  else
			  {
			  	ofs<<name<<","<<branch<<","<<domains<<","<<hq<<","<<contact<<","<<email<<endl;
			  }
			  
			  ifs>>extract;
						
					
			}
			ifs.close();
			ofs.close();
	remove("backend/db1.csv");
	rename("backend/temp.csv","backend/db1.csv");
	if(flag==1)
	{
		system("cls");
		gotoxy(40,6);
		cout<<"Data edited ! Press any key to continue.";
		getch();
		
	}
	else
	{
		system("cls");
		gotoxy(40,6);
		cout<<"Invalid company name/or data not existing . Press any key to return";
		getch();
	}
	break;
}

     case 2:
     	{
     		
     		system("cls");
						gotoxy(40,6);
						cout<<"Delete Details of company";
						gotoxy(40,7);
						cout<<"__________________________";
						char cname[50];
						gotoxy(30,9);
						cout<<"Enter Name of company :(if don't the company name type 'not'.)";
						cin>>cname;
						while(strcmpi(cname,"not")==0)
						{ viewcompany();
						cout<<"Enter Company name :";
						cin>>cname;
					}
					delete_company_details(cname);
     		break;
     		
		 }
		 default: 
		 {
		 	cout<<"\n Wrong value. Press any key to continue.";
		 	getch();
		 	break;
		 }
			
			
			
		}
	}
	void editingadvance(char branch_name[],char domains_name[],char company_name[],char cname[])
	{   char newdata_name[50];
	char newdata_domain[50];
	char newdata_branch[50];
	strcpy(newdata_name,company_name);
    strcpy(newdata_branch,branch_name);
    strcpy(newdata_domain,domains_name);
	
	    ifstream in("backend/db3.csv");
	    ofstream of("backend/temp2.csv");
	    char extract[150];
	    int flag=0;in>>extract;
	    while(in.eof()==0)
	   {
	   
       	int k=0;
       	int i=0;
       	for(i=0 ;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
        for( ;extract[i]!=',';i++)
            branch[k++]=extract[i];
       	   branch[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            domains[k++]=extract[i];
       	   domains[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            avg[k++]=extract[i];
       	   avg[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            low[k++]=extract[i];
       	   low[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!=',';i++)
       	   high[k++]=extract[i];
       	   high[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!='\0';i++)
       	   dif[k++]=extract[i];
       	   dif[k]='\0';
       	   
       	  
       	   k=0;int flag=0;
       	   
       	   
       	   	if(strcmpi(cname,name)==0)
       	   	   {
       	   	     system("cls");
       	   	      
		gotoxy(40,6);
		cout<<"Edit Details ";
		gotoxy(40,7);
		cout<<"______________";
		gotoxy(40,9);
		cout<<"Editing Instruction : To retain old data just type 'r' otherwise enter the new data. Don't use spaces use (_)";
		gotoxy(50,11);
		cout<<"Comapany name :"<<newdata_name;
		gotoxy(50,12);
		cout<<"Branches of interest :"<<newdata_branch;
		gotoxy(50,13);                                       
		cout<<"Domains of interest :"<<newdata_domain;
		gotoxy(50,14);
		cout<<"Avg Sal :"<<avg;
		gotoxy(50,15);
		cout<<"Lower Sal :"<<low;
		gotoxy(50,16);
		cout<<"High Sal :"<<high;
		gotoxy(50,17);
		cout<<"Difficulty :"<<dif;
		streams s;
		s.printbranch(2,6);
		domain_c c;
		c.printdomain(2,17);
		gotoxy(50,10);
		cout<<"Start Editing :";
		char ch;
		cin>>ch;
		
		
		inputedit(avg,59,14);
		inputedit(low,61,15);
		inputedit(high,60,16);
		inputedit(dif,62,17);
		of<<newdata_name<<","<<newdata_branch<<","<<newdata_domain<<","<<avg<<","<<low<<","<<high<<","<<dif<<endl;
       	   }
       	   else
       	   {
       	   	of<<name<<","<<branch<<","<<domains<<","<<avg<<","<<low<<","<<high<<","<<dif<<endl;
			  }
       	   in>>extract;
       }
       in.close();
       of.close();
       remove("backend/db3.csv");
       rename("backend/temp2.csv","backend/db3.csv");
       
       
	
		
	}
	
	void editingbasic(char cname[])
	{ system("cls");
		gotoxy(40,6);
		cout<<"Edit Details ";
		gotoxy(50,7);
		cout<<"______________";
		gotoxy(40,9);
		cout<<"Editing Instruction : To retain old data just type 'r' otherwise enter the new data. Don't use spaces use (_)";
		gotoxy(50,11);
		cout<<"Comapany name :"<<name;
		gotoxy(50,12);
		cout<<"Branches of interest :"<<branch;
		gotoxy(50,13);
		cout<<"Domains of interest :"<<domains;
		gotoxy(50,14);
		cout<<"Headquarter location :"<<hq;
		gotoxy(50,15);
		cout<<"Contact no :"<<contact;
		gotoxy(50,16);
		cout<<"Email ID :"<<email;
		streams s;
		s.printbranch(2,6);
		domain_c c;
		c.printdomain(2,17);
		gotoxy(50,10);
		cout<<"Start Editing :";
		char ch;
		cin>>ch;
		if(ch=='n')
		{
			
		    return ;	
		}
		inputedit(name,65,11);
		inputedit(branch,72,12);
		inputedit(domains,71,13);
		inputedit(hq,72,14);
		inputedit(contact,62,15);
		inputedit(email,60,16);
		
		
	}
	
	void inputedit(char string[],int x,int y)
	{
		gotoxy(x,y);
		cout<<"                                                                      ";
		gotoxy(x,y);
		char temp[70];
		cin>>temp;
		if(strcmpi(temp,"r")==0)
		{
			return;
		}
		else
		strcpy(string,temp);
	}
		 void input()
		 {   gotoxy(30,3);
		 cout<<"Input Instructions:";domain_c c;streams s;s.printbranch(2,4);c.printdomain(2,12);
		  gotoxy(30,4);
		  cout<<"Enter Data Carefully, don't enter invalid values (it may lead to crash of software).";
		  gotoxy(30,5);
		  cout<<"Do not keep spaces between input data , if required put a underscore(_) .";
		 	gotoxy(45,7);
		 	cout<<"Company Name :";cin>>name;
		 	gotoxy(45,8);
		 	cout<<"Branches of Interest :";
			cin>>branch;
		 	gotoxy(45,9);
		 	cout<<"Domains of Interest :";cin>>domains;
		 	gotoxy(45,10);
		 	cout<<"HQ location :";cin>>hq;
		 	gotoxy(45,11);
		 	cout<<"Contact No :";cin>>contact;
		 	gotoxy(45,12);
		 	cout<<"Email ID :";cin>>email;
		 	gotoxy(45,13);
		 	cout<<"Salary deatils (Do not include any characters only numbers are allowed) :-";
		 	gotoxy(45,14);
		 	cout<<"Average Salary Offered :";cin>>avg;
		 	gotoxy(45,15);
		 	cout<<"Lowest Salary offered :";cin>>low;
		 	gotoxy(45,16);
		 	cout<<"Highest Salary offered :";cin>>high;
		 	gotoxy(45,17);
		 	cout<<"Difficulty rating :";cin>>dif;
		 	char p;
		 	gotoxy(45,18);
		 	cout<<"Want to enter previous placement records of company (press y or n) :";
		 	cin>>p;
		 	addcompany();
		 	addcompanypr(p,name);
		 	
		 	
		 	gotoxy(45,22);
		 	cout<<"     Data added to file ! Thank You. Press Any key to Continue";
		 	getch();
		 	
		 }
		 void deletecompanypr(char company_name[])
		 {
		 	 
		 	ifstream ifs("backend/db4.csv");
		 	ofstream ofs("backend/temp.csv");
	 	int k=0;
       	int i=0;
       	
       	
       	    char extract[150];
       	    int flag=0;
       	    ifs>>extract;
       	    	
       	    
       	    
       	    while(!ifs.eof())
       	    { k=0;
       	    
       	    
       	    
       	    	for(i=0;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
       	    for( ;extract[i]!=',';i++)
       	    college[k++]=extract[i];
       	    college[k]='\0';
       	    k=0;
       	    i++;
       	    for( ;extract[i]!=',';i++)
       	    package[k++]=extract[i];
       	    package[k]='\0';
       	    k=0;
       	    i++;
       	    
       	    
       	    if(strcmpi(company_name,name)==0)
       	    {  flag=1;
       	    }
			else
			{
				ofs<<name<<","<<college<<","<<package<<","<<endl;
			}
			   
			   
       	       
       	    	
			 ifs>>extract;  
		}
			   ofs.close();
			   ifs.close();
			   remove("backend/db4.csv");
			   rename("backend/temp.csv","backend/db4.csv");
			   if(flag==1)
			   {
			   	system("cls");
			   	gotoxy(40,7);
			   	cout<<"Details deleted for the given company. Press any key to continue.";
			   	getch();
			   }
			   else
			   {
			   	system("cls");
			   	gotoxy(40,7);
			   	cout<<"Invalid company name . Press any key to continue.";
			   	getch();
			   	
			   }
		 }
		 void viewcompany()
 {
 	system("cls");
 	gotoxy(30,3);
 	cout<<"Display all listed company names (list view)";
 	ifstream ifs;
 	ifs.open("backend/db1.csv");
 	char ch[150];
 	int counter=0;
 	ifs>>ch;
 	while(!ifs.eof())
 	{
 		
 	
		    gotoxy(30,7+counter++);
			for(int i=0;ch[i]!=',';i++)
			   cout<<ch[i];
		
			     ifs>>ch;
			     gotoxy(30,7+counter++);
			     
	}
	 ifs.close();
	 }
		 void addcompanypr(char c,char company_name[])
		 {  ofstream ofs("backend/db4.csv",ios::app);
		 	if(c=='y')
		 	{
		 		
		 		system("cls");
		 		gotoxy(30,4);
		 		cout<<"Add Company Previous recruitment details";
		 		rectangle(26,3,60,2);
		 		gotoxy(30,7);
		 		cout<<"Typing Instruction : Don't put space if required put a underscore (_).";
		 		gotoxy(20,9);
		 		cout<<"Name of College                                       Package Offered              Add more row(y/n)";
		 		gotoxy(20,10);
		 		cout<<"-----------------------------------------------------------------------------------------------------";
		 		char choice ='y';int line=1;
		 		while(choice=='y'||choice=='Y')
		 		{
		 			gotoxy(20,++line+10);
		 			cin>>college;
		 			gotoxy(20+54,line+10);
		 			cin>>package;
		 			gotoxy(20+54+34,line+10);
		 			cin>>choice;
		 			ofs<<company_name<<","<<college<<","<<package<<","<<endl;
				 }
		 		
		 		gotoxy(20,++line);
		 		cout<<"Data added to database";
		 		ofs.close();
		 		
			 }
			 else
			 {
			 	system("cls");
			 	ofs<<name<<","<<"n/a"<<","<<"n/a"<<","<<endl;
			 	ofs.close();
			 }
		 	
		 	
		 }
		 	
		 
		 void addcompany()
		 {
		 	ofstream of1,of2;
		 	of1.open("backend/db1.csv",ios::app);
		 	of1<<name<<","<<branch<<","<<domains<<","<<hq<<","<<contact<<","<<email<<endl;
		 	of1.close();
		 	of2.open("backend/db3.csv",ios::app);
		 	of2<<name<<","<<branch<<","<<domains<<","<<avg<<","<<low<<","<<high<<","<<dif<<endl;
		 	of2.close();
		
			
		 	
		 }
		 void addpr()
		 {
		 	system("cls");
		 }
		 ~company()
		 {
		 }
         		
 		friend class doperation;
 		friend class display;
 };
 
 class display:public company
 {
 public:
 	friend class company;
 	char avg_sal[30];
 	char low_sal[30];
 	char high_sal[30];
 	char dif_[5];
 	

	 int f;
	 void displaypr(int x,int y,char ch[])
	 {
	 	gotoxy(x,y);char extract[100];int flag=0;int found=0;
	 	cout<<"Previous recruitments of the company ";
	 	gotoxy(x,++y);
	 	cout<<"------------------------------------";
	 	gotoxy(x,++y);
	 	
	 	cout<<"Comapany name :"<<ch;
	 	gotoxy(x,++y);
	 	
	 	cout<<"College Name";
	 	
	 	gotoxy(x+50,y);
	 	cout<<"Package offered";
	 	gotoxy(x,++y);
	 	cout<<"----------------------------------------------------------------------------------------------------------------------------";
	 	++y;
	 	ifstream ifs("backend/db4.csv");
	 	int k=0;
       	int i=0;
       	
       	
       	    
       	    ifs>>extract;
       	    	
       	    
       	    
       	    while(!ifs.eof())
       	    { k=0;
       	    
       	    
       	    
       	    	for(i=0;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
       	    for( ;extract[i]!=',';i++)
       	    college[k++]=extract[i];
       	    college[k]='\0';
       	    k=0;
       	    i++;
       	    for( ;extract[i]!=',';i++)
       	    package[k++]=extract[i];
       	    package[k]='\0';
       	    k=0;
       	    i++;
       	    
       	    
       	    if(strcmpi(ch,name)==0)
       	    {  found=1; 
			   if(strcmpi(college,"n/a")==0)
       	       {  gotoxy(x,++y); 
       	       flag=1;
				  cout<<" Sorry !! No any Database available.";
				  break;
				  }
				else{
				
       	    	gotoxy(x,++y);
       	    	cout<<college;
       	    	gotoxy(x+50,y);
       	    	cout<<package;
       	    }
			   }
			   if(flag==1)
			   break;
			   
			   
       	       
       	    	
			 ifs>>extract;  
		}
			   
			   ifs.close();
			   y+=4;
			   if(found==1)
			   {
			   	gotoxy(x,++y);
			   	cout<<"Company found and query processed.";
			   }
	 	        else
	 	        {
	 	        	gotoxy(x,++y);
	 	        	cout<<"Company Not found.";
				 }
	 	
	 getch();
}
void domainquery(char c)
{
	system("cls");
	gotoxy(10,3);
       cout<<"Showing results";
       gotoxy(10,4);
       cout<<"_______________";
       gotoxy(38,3);
       cout<<"** Enter company name in console input or type any other string to return **";
       gotoxy(4,5);
       cout<<"______________________________________________________________________________________________________________________________________________";
       gotoxy(4,6);
       cout<<"Name of Company";
       gotoxy(30,6);
       cout<<"HQ Address";
       gotoxy(50,6);
       cout<<"Contact No";
       gotoxy(65,6);
       cout<<"Email Address";
       gotoxy(4,7);
       cout<<"______________________________________________________________________________________________________________________________________________";
       ifstream ifs("backend/db1.csv");
       char extract[100];int line;
       line=0;ifs>>extract;
       while(!ifs.eof())
       {
       	
       	int k=0;
       	int i=0;
       	for( ;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
        for( ;extract[i]!=',';i++)
            branch[k++]=extract[i];
       	   branch[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            domains[k++]=extract[i];
       	   domains[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            hq[k++]=extract[i];
       	   hq[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            contact[k++]=extract[i];
       	   contact[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!='\0';i++)
       	   email[k++]=extract[i];
       	   email[k]='\0';
       	   
       	  
       	   k=0;int flag=0;
       	   for(i=0;branch[i]!='\0';i++)
       	   {
       	   	if(c==domains[i])
       	   	   {
			   flag=1;
       	   	   line++;
       	   	   break;
       	   }
			  }
			  if(flag==1)
			  { 
			  	gotoxy(5,8+line);
			  	cout<<name;
			  	gotoxy(30,8+line);
			  	cout<<hq;
			  	gotoxy(50,8+line);
			  	cout<<contact;
			  	gotoxy(65,8+line);
			  	cout<<email;
			  }
			  
       	   
       		
       		ifs>>extract;
       		
		   }
		   gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char ch[20];
	cin>>ch;
	ifs.close();
    fstream fs;
	fs.open("backend/db3.csv");
	system("cls");
       line=0;fs>>extract;
       fs>>extract;
       
       
       
	   while(fs.eof()==0)
	   {
	   
       	int k=0;
       	int i=0;
       	for(i=0 ;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
        for( ;extract[i]!=',';i++)
            branch[k++]=extract[i];
       	   branch[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            domains[k++]=extract[i];
       	   domains[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            avg_sal[k++]=extract[i];
       	   avg_sal[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            low_sal[k++]=extract[i];
       	   low_sal[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!=',';i++)
       	   high_sal[k++]=extract[i];
       	   high_sal[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!=',';i++)
       	   dif_[k++]=extract[i];
       	   dif_[k]='\0';
       	   
       	  
       	   k=0;int flag=0;
       	   cout<<extract;
       	   
       	   	if(strcmpi(ch,name)==0)
       	   	   {
			   
			   f=1;
       	   	   line++;
       	   	   break;
       	   }
       	   fs>>extract;
       }
			  
			fs.close();
		   system("cls");
		   if(f==1)
		   {
		   
		   gotoxy(30,3);
		   
		   cout<<"Company Details :";
		   gotoxy(30,4);
		   cout<<"-----------------";
		   gotoxy(30,6);
		   cout<<"Company Name :"<<name;gotoxy(100,8);cout<<"Salary Details (per month):";gotoxy(100,6);cout<<"Difficulty :"<<dif_;
		   line=0;
		   gotoxy(30,8);
		   cout<<"Streams of Working  :";
		   
		   for(int i=0;branch[i]!='\0';i++)
		   {
		   	   streams c;
		   	   gotoxy(47,9+1+line++);
		   	   char ch=branch[i];
		   	   int integer=ch-'0'-1;
		   	   cout<<c.ch[integer];
		   }
		   gotoxy(100,9);
		   cout<<"Lowest salary offered   :"<<low_sal;
		   gotoxy(100,10);
		   cout<<"Highest salary offered  :"<<high_sal;
		   gotoxy(100,11);
		   cout<<"Average salary offered  :"<<avg_sal;
		   gotoxy(35,11+line+2);
		   cout<<"For Previous recruitment details of the company type 'p' in console input else 'n'";
		   gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	if(c=='p')
	{
		display d;
		system("cls");
		d.displaypr(20,3,name);
		
	}
	else
	{
		system("cls");
		gotoxy(45,7);
		cout<<"Done ! Press any key for main menu";
		
	}
		   
		   
		   
	}
	else
	{ 
	       gotoxy(50,6);
	       cout<<"Match not found ! company name is wrongly typed / or you have chosen to return.";
	       gotoxy(38,7);
	       cout<<"Please check again if you have done query and enter name (replace any space to _ (underscore))";
	       gotoxy(58,8);
	       cout<<"Any key to continue";
	       
	}
		   
		   
}
	 
 	void branchquery(char c)
 	{   system("cls");
 	    
       gotoxy(10,3);
       cout<<"Showing results";
       gotoxy(10,4);
       cout<<"_______________";
       gotoxy(38,3);
       cout<<"** Enter company name in console input or type any other string to return **";
       gotoxy(4,5);
       cout<<"______________________________________________________________________________________________________________________________________________";
       gotoxy(4,6);
       cout<<"Name of Company";
       gotoxy(30,6);
       cout<<"HQ Address";
       gotoxy(50,6);
       cout<<"Contact No";
       gotoxy(65,6);
       cout<<"Email Address";
       gotoxy(4,7);
       cout<<"______________________________________________________________________________________________________________________________________________";
       ifstream ifs("backend/db1.csv");
       char extract[100];int line;
       line=0;ifs>>extract;
       while(!ifs.eof())
       {
       	
       	int k=0;
       	int i=0;
       	for( ;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
        for( ;extract[i]!=',';i++)
            branch[k++]=extract[i];
       	   branch[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            domains[k++]=extract[i];
       	   domains[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            hq[k++]=extract[i];
       	   hq[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            contact[k++]=extract[i];
       	   contact[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!='\0';i++)
       	   email[k++]=extract[i];
       	   email[k]='\0';
       	   
       	  
       	   k=0;int flag=0;
       	   for(i=0;branch[i]!='\0';i++)
       	   {
       	   	if(c==branch[i])
       	   	   {
			   flag=1;
       	   	   line++;
       	   	   break;
       	   }
			  }
			  if(flag==1)
			  { 
			  	gotoxy(5,8+line);
			  	cout<<name;
			  	gotoxy(30,8+line);
			  	cout<<hq;
			  	gotoxy(50,8+line);
			  	cout<<contact;
			  	gotoxy(65,8+line);
			  	cout<<email;
			  }
			  
       	   
       		
       		ifs>>extract;
       		
		   }
		   gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char ch[20];
	cin>>ch;
	ifs.close();
	
       	   
       	   
       	  
       	   
       		
       	
		  fstream fs;
	fs.open("backend/db3.csv");
	system("cls");
       line=0;fs>>extract;
       fs>>extract;
       
       
       
	   while(fs.eof()==0)
	   {
	   
       	int k=0;
       	int i=0;
       	for(i=0 ;extract[i]!=',';i++)
       	    name[k++]=extract[i];
       	    name[k]='\0';
       	    k=0;
       	    i++;
        for( ;extract[i]!=',';i++)
            branch[k++]=extract[i];
       	   branch[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            domains[k++]=extract[i];
       	   domains[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            avg_sal[k++]=extract[i];
       	   avg_sal[k]='\0';
       	   k=0;
       	   i++;
       	   for( ;extract[i]!=',';i++)
            low_sal[k++]=extract[i];
       	   low_sal[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!=',';i++)
       	   high_sal[k++]=extract[i];
       	   high_sal[k]='\0';
       	   k=0;
       	   i++;
       	   for(;extract[i]!=',';i++)
       	   dif_[k++]=extract[i];
       	   dif_[k]='\0';
       	   
       	  
       	   k=0;int flag=0;
       	   cout<<extract;
       	   
       	   	if(strcmpi(ch,name)==0)
       	   	   {
			   
			   f=1;
       	   	   line++;
       	   	   break;
       	   }
       	   fs>>extract;
       }
			  
			fs.close();
		   system("cls");
		   if(f==1)
		   {
		   
		   gotoxy(30,3);
		   
		   cout<<"Company Details :";
		   gotoxy(30,4);
		   cout<<"-----------------";
		   gotoxy(30,6);
		   cout<<"Company Name :"<<name;gotoxy(100,8);cout<<"Salary Details (per month):";gotoxy(100,6);cout<<"Difficulty :"<<dif_;
		   line=0;
		   gotoxy(30,8);
		   cout<<"Domains of Working  :";
		   
		   for(int i=0;domains[i]!='\0';i++)
		   {
		   	   domain_c c;
		   	   gotoxy(47,9+1+line++);
		   	   char ch=domains[i];
		   	   int integer=ch-'0';
		   	   cout<<c.domain[integer];
		   }
		   gotoxy(100,9);
		   cout<<"Lowest salary offered   :"<<low_sal;
		   gotoxy(100,10);
		   cout<<"Highest salary offered  :"<<high_sal;
		   gotoxy(100,11);
		   cout<<"Average salary offered  :"<<avg_sal;
		   gotoxy(35,11+line+2);
		   cout<<"For Previous recruitment details of the company type 'p' in console input else 'n'";
		   gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	if(c=='p')
	{
		display d;
		system("cls");
		d.displaypr(20,3,name);
		
	}
	else
	{
		system("cls");
		gotoxy(45,7);
		cout<<"Done ! Press any key for main menu";
		
	}
		   
		   
		   
	}
	else
	{ 
	       gotoxy(50,6);
	       cout<<"Match not found ! company name is wrongly typed /or you have chosen to return.";
	       gotoxy(38,7);
	       cout<<"Please check again if you have done the query and enter name (replace any space to _ (underscore))";
	       gotoxy(58,8);
	       cout<<"Any key to continue";
	       
	}
	
       	
       	
	   }
       
       
 		
 		
	 

	 	
 };
 class doperation:public display
{
	public:
		void del_company()
		{
			system("cls");
			gotoxy(30,3);
			cout<<" Delete Company Profile";
			rectangle(27,2,36,2);
			gotoxy(30,6);
			cout<<"Instruction : Please input company name correctly (do not put space,if required put underscore(_) .)";
			gotoxy(30,7);
			cout<<"If you don't remember actual company name press no when input is asked";
			gotoxy(30,9);
			cout<<"Want to view list (type yes or no) :";
			char cname[50];
			cin>>cname;
			if(strcmpi(cname,"no")==0)
			  { viewcompany();
			  }
					system("cls");
			gotoxy(30,3);
			cout<<" Delete Company Profile";
			rectangle(27,2,36,2);
			gotoxy(30,6);
			cout<<"Instruction : Please input company name correctly (do not put space,if required put underscore(_) .)";
			gotoxy(30,7);
			cout<<"Enter Company Name :";
			cin>>cname;
			ifstream ifs1,ifs2;
			ofstream ofs1,ofs2;
			ofs1.open("backend/temp1.csv",ios::app);
			ofs2.open("backend/temp2.csv",ios::app);
			ifs1.open("backend/db1.csv");
			ifs2.open("backend/db3.csv");int flag=0;char ch[120]={'\0'};char name[40];
			while(!ifs1.eof())
			{ 
			   ifs1>>ch;
			   for(int j=0;ch[j]!=',';j++)
			   {name[j]=ch[j];
			   }
			   if(strcmpi(name,cname)==0)
			   { flag=1;
			   }
			   else
			   ofs1<<ch;
			     
				
			}
			ifs1.close();
			ofs1.close();
			strcpy(ch,"\0");
			while(!ifs2.eof())
			{ 
			   ifs2>>ch;
			   for(int j=0;ch[j]!=',';j++)
			   {name[j]=ch[j];
			   }
			   if(strcmpi(name,cname)==0)
			   { flag=1;
			   }
			   else
			   ofs2<<ch;
			     
				
			}
			ifs2.close();
			ofs2.close();
			
			/* rename and delete function of file*/
					
			
		}
};
 
 void rectangle(int x,int y,int l, int b)
 {
     for(int i=0;i<=l;i++)
     {  gotoxy(x+i,y);
     	cout<<"*";
     	gotoxy(x+i,y+b);
     	cout<<"*";
	 }
	  for(int i=0;i<=b;i++)
     {  gotoxy(x,y+i);
     	cout<<"*";
     	gotoxy(x+l,y+i);
     	cout<<"*";
	 }
	 
 }
int main()
{
	/*dev c++ font size 20 console*/
	system("mode 148,9001");
system("color 3F");
	
  while(1)
  {
  
			system("cls");
		
	gotoxy(15,3);
	cout<<"Press 'i' for";
	gotoxy(15,4);
	cout<<"Help";
	rectangle(12,2,18,3);
	gotoxy(65,3);
	cout<<"PlacementFMS";
	gotoxy(43,4);
	cout<<"A complete file management system for placement process";
	rectangle(40,2,60,3);
	gotoxy(109,3);
	cout<<"Type 'q' for FAQ";
	
	rectangle(107,2,20,3);
	gotoxy(47,13);
	cout<<" a. Company Query";
	gotoxy(47,14);
	cout<<" b. Placement Analyser";
	gotoxy(47,15);
	cout<<" c. File System Management ";
	gotoxy(47,16);
	cout<<" d. Previous Recruitments";
	gotoxy(47,17);
	cout<<" e. Exit";
	
	rectangle(41,12,58,8);
	
	gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	     switch(c)
	     {
	     	  
	     	  case 'a'://company_query
	     	  	{
	     	  		system("cls");
	     	  		gotoxy(45,4);
	     	  		cout<<"Company Query ";
	     	  		rectangle(42,3,20,2);
	     	  		gotoxy(30,7);
	     	  		cout<<"a. Branch Based Query";
	     	  		gotoxy(30,8);
	     	  		cout<<"b. Domain Based Query";
	     	  		gotoxy(30,10);
	     	  		cout<<"** Press any other key to return to main menu **";
	     	  			gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	        switch(c)
	          { 
	              case 'a':
	              	{ 
	              	  system("cls");
	              	  gotoxy(34,3);
	              	  cout<<"Branch Based Query";
	              	  rectangle(28,2,30,2);
	              	  streams s;
	              	  s.printbranch(37,6);
	              	  gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	display d;
	d.branchquery(c);
	
	              	  getch();
	              	  break;
					  }
					  case 'b':
					  	{
					  		system("cls");
	              	  gotoxy(34,3);
	              	  cout<<"Domain Based Query";
	              	  rectangle(28,2,30,2);
	              	  domain_c s;
	              	  s.printdomain(35,6);
	              	  gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	display d;
	d.domainquery(c);
	
	              	  getch();
	              	  break;
					  		
						  }
						  default: {
						  	
							break;
						  }
			  }
	     	  		
	     	  		
	     	  		
	                 break;
				   }
				   case 'b'://placement_anlyser
				   	{ system("cls");
				   	gotoxy(30,4);
				   	cout<<"Placement analyzer tool";
				   	gotoxy(30,5);
				   	cout<<"------------------------";
				   	gotoxy(36,8);
				   	cout<<"a. Domain Analyzer Graph";
				   	gotoxy(36,9);
				   	cout<<"b. Sorting Tool";
				   		gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	switch(c)
	{
		case 'a':graph g;
		        g.domain_analyzer();
		        break;
		        case 'b':
				{
					system("cls");
					gotoxy(40,5);
					cout<<"Sorting Tool ( Generate sorted results )";
					gotoxy(40,6);
					cout<<"_________________________________________";
					gotoxy(35,8);
					
					cout<<" a. Search for highest employbility Domain.";
					gotoxy(35,10);
					cout<<" b. Search for highest Paid Company and their domains.";
					gotoxy(35,12);
					cout<<" c. Search for Most difficult company to get in.";
					gotoxy(35,14);
					cout<<" ** Press any other key to return";
					gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char c;
	cin>>c;
	switch(c)
	{
		case 'a': sort_domains(1);break;
		case 'b':sort_db3(1);break;
		case 'c':sort_db3(2);break;
		default:
			{  system("cls");
			cout<<"\n Wrong input/or chosen to return . Press any key to return to main menu.";
			getch();
			}
		
	}
					
				
				     break;
				 }
				 default: {
					break;
				 }
	}
				   	
					   
					   break;
					   }
					   
						   case 'c'://file_management_system
						   	{  system("cls");
						   	   gotoxy(40,5);
						   	   cout<<"File Management Console";
						   	   gotoxy(40,6);
						   	   cout<<"________________________";
						   	   gotoxy(35,9);
						   	   cout<<"Username :  ADMIN";
						   	   gotoxy(35,10);
						   	   cout<<"Password : ";
						   	   char passcode[10];int i=0;
						   	   char temp;
						   	   
						   	   do
						   	   {
						   	   	
						   	   	temp=getch();
						   	   	cout<<"*";
									  passcode[i++]=temp;
									  			  
									  }while(i<5);
									  passcode[i]='\0';
									 ifstream ps("backend/cre.txt");
									 char p[10];
									 ps>>p;
									 ps.close();
									 if(strcmpi(p,passcode)==0)
									 {
									 	system("cls");
									 	gotoxy(40,7);
									 	cout<<"Admin is logged on.... Press any key to continue";
									 	getch();
									 	
									 }
									 else
									 {
									 	system("cls");
									 	gotoxy(40,7);
									 	cout<<"Passcode is incorrect.... Press any key to return to main menu.";
									 	getch();
									 	break;
									 }
									  system("cls");
						   	   
						   	   gotoxy(35,3);
						   	   
						   	   cout<<" File Mangament (Admin's Previlege ) ";
						   	    rectangle(33,2,45,3);
						   	     gotoxy(36,9);
						   	     cout<<" a. Add Company";
						   	     gotoxy(36,10);
						   	     cout<<" b. Edit Company Details";
						   	     gotoxy(36,11);
						   	     cout<<" c. Delete Comapany";
						   	     gotoxy(36,12);
						   	     cout<<" d. Add domain details ( Editing not permisible )";
						   	     gotoxy(36,13);
						   	     cout<<" e. Add previous recruitment details of a company (Editing not permisible)";
						   	     gotoxy(36,14);
						   	     cout<<" f. Delete domain details ";
						   	     gotoxy(36,15);
						   	     cout<<" g. Delete Previous recruitment details ";
						   	     gotoxy(36,17);
						   	     cout<<"** Press any other character to return to main menu **";
						   	     	gotoxy(2,26);
						   	     	
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char z;
	cin>>z;
	        switch(z)
	        {
	        	case 'a':
	        		{
	        			system("cls");
	        			gotoxy(35,4);
	        			cout<<"Add Comapny";
	        			company ob;
	        			ob.input();
	        			
	        			break;
					}
				case 'b':
					{
						company c;
						c.editcompanydetails();
						break;
					}
				case 'c':
					{
						system("cls");
						gotoxy(40,6);display d;
						cout<<"Delete Details of company";
						gotoxy(40,7);
						cout<<"__________________________";
						char cname[50];
						gotoxy(30,9);
						cout<<"Enter Name of company :(if don't the company name type 'not'.)";
						cin>>cname;
						while(strcmpi(cname,"not")==0)
						{ d.viewcompany();
						cout<<"Enter Company name :";
						cin>>cname;
					}
					int flag=delete_company_details(cname);
					company c;
					if(flag==1)
					c.deletecompanypr(cname);
					break;
					}
				case 'd':
					{
						graph g;
						g.add_domain_details();
						break;
						
					}
				case 'e':
					{
						system("cls");
						char cname[60];
						gotoxy(30,5);display c;
						cout<<"Enter Previous recruitment details of company";
						gotoxy(30,6);
						cout<<"______________________________________________";
						gotoxy(35,9);
						cout<<"Enter Company name (if you don't the company name type ''not'):";
						cin>>cname;
						while(strcmpi(cname,"not")==0)
						{ c.viewcompany();
						cout<<"Enter Company name :";
						cin>>cname;
					}
					c.addcompanypr('y',cname);
					break;
						
						
							
						}
				case 'f':
					{
						system("cls");
						char dname[3];
						gotoxy(30,6);
						cout<<"Delete Domain details";
						gotoxy(30,7);
						cout<<"______________________";
						domain_c cc;
						cc.printdomain(40,8);
						gotoxy(30,20);
						cout<<"Enter Domain ID :";
						cin>>dname;
						graph g;
					    g.delete_domain(dname);
					    break;
						
					}
				case 'g':
					{
						display r;
						system("cls");
						char company_name[60];
						gotoxy(30,6);
						cout<<"Delete Company previous recruitment details";
						gotoxy(30,7);
						cout<<"____________________________________________";
						gotoxy(30,9);
						cout<<"Enter Company name (if you don't remember company name type 'not'):";
						cin>>company_name;
						while(strcmpi(company_name,"not")==0)
						{
						r.viewcompany();
						cout<<"Enter Company name :";
						cin>>company_name;
						}
						r.deletecompanypr(company_name);
						break;
								
										}
				default: 
				   {  system("cls");
				    cout<<"Press any key to return to main menu.";
				    getch();
				    break;
								   }				
					}
						
						
					
					break;
			}
						   	     
							   
							   case 'd'://previous_recruitment
							   	{  level:
							   		{
									   
								   system("cls");
								   gotoxy(45,4);
								   cout<<"Previous year recruitment Database";
								   gotoxy(45,5);
								   cout<<"----------------------------------";
								   gotoxy(30,7);
								   cout<<"This is a separate searching tool for previous recruitments of the company.";
								   gotoxy(30,8);
								   cout<<"Enter company name in console-input else type 'not'";
								   	gotoxy(2,26);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(2,28);
	cout<<"_____________________________________________________________________________________________________________________________________________";
	gotoxy(4,27);
	
	cout<<"ConsoleInput>";
	char ch[20];
	cin>>ch;
	    if(strcmpi(ch,"not")==0)
	       {
	       	display d;
	       	d.viewcompany();
	       	getch();
	       	goto level;
		   }
		   else
		   {
		   	display d;
		   	system("cls");
		   	d.displaypr(20,3,ch);
		   	
		   }
					}
								   
								   break;
								   }
								   case 'e'://exit
								    	{
										  system("cls");
										  gotoxy(45,6);
										  cout<<"PlacementFMS - ( Alpha Version, 2016)";
										  gotoxy(47,7);
										   cout<<"Designed and Developed By :";
										   gotoxy(43,8);
										    cout<<" Group - 1,CSE (2015-19),IIIT Bhubaneswar";
										    gotoxy(42,9);
										    cout<<" Members-Abhilash, Akash, Aisha, Deepak ";
										    gotoxy(45,10);
										    cout<<"Press any key to continue.";
										    rectangle(36,5,50,6);
											 getch();
											 exit(0);
											 break;
									   }
									   case 'i'://help
									   	{   ifstream ifs("backend/help.txt");
									   	   char ch[300];system("cls");
									   	   ifs>>ch;
									   	   while(!ifs.eof())
									   	   {
									   	   	cout<<ch<<" ";
									   	   	ifs>>ch;
											  }
											  
											  ifs.close();
											  cout<<"\n \t Press any key to continue.";
											  getch();
										   break;
										   }
										   case 'q'://faq
										   	{ifstream ifs("backend/faq.txt");system("cls");
									   	   char ch[300];
									   	   ifs>>ch;
									   	   while(!ifs.eof())
									   	   {
									   	   	cout<<ch<<"  ";
									   	   	ifs>>ch;
											  }
											  
											  ifs.close();
											  cout<<"\n \t Press any key to continue.";
											  getch();
										   		break;
											   }
											  
												   default:
												   	{  system("cls"); 
													   cout<<"\n \n  Wrong Choice";
												   	 cout<<"\n\t Press any key to return to main menu";
												   	  getch();
												   		
													   }
		 }

	}
}

