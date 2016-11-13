
struct db2_sort
{
	char domain_id[4];
	char current[10];
	char oney[10];
	char twoy[10];
	db2_sort *next;
};
struct db3_sort
{
	char name[60];
	char branch[10];
	char domain[10];
	char avg[10];
	char low[10];
	char high[10];
	char dif[4];
	db3_sort *next;
};
db2_sort *start=NULL;
db3_sort *top=NULL;
void bubblesort(db2_sort *start);
void bubblesort(db3_sort *top,char k_dif,int m);
void bubblesort(db3_sort *top,float k_sal);
int delete_company_details(char cname[50])
{  
	system("cls");
    ifstream ifs("backend/db1.csv");
    ofstream ofs("backend/temp.csv");
    char extract[150];
    ifs>>extract;
    char temp[60];int flag=0;
    while(!ifs.eof())
    {
    	int i=0;
    	for(;extract[i]!=',';i++)
    	temp[i]=extract[i];
    	
    	temp[i]='\0';
    
    	if(strcmpi(temp,cname)==0)
    	{
    		flag=1;
		}
		else
		{
			ofs<<extract<<endl;
		}
		ifs>>extract;
	}
	ifs.close();
	ofs.close();
	remove("backend/db1.csv");
	rename("backend/temp.csv","backend/db1.csv");
	if(flag==1)
	{
		ifs.open("backend/db3.csv");
		ofs.open("backend/temp.csv");
		ifs>>extract;
		char temp[60];int flag=0;
    while(!ifs.eof())
    {
    	int i=0;
    	for(;extract[i]!=',';i++)
    	temp[i]=extract[i];
    	temp[i]='\0';
    	if(strcmpi(temp,cname)==0)
    	{
    		flag=1;
		}
		else
		{
			ofs<<extract<<endl;
		}
		ifs>>extract;
	}
	ifs.close();
	ofs.close();
	remove("backend/db3.csv");
	rename("backend/temp.csv","backend/db3.csv");
	
	system("cls");
	gotoxy(40,6);
	cout<<"Details deleted for the company.Press any key to continue.";
	getch();
	
	
	}
	else
	{
		system("cls");
		gotoxy(40,7);
		cout<<"Invalid Company name. Press any to return to main menu.";
		getch();
	}
	return flag;
}

void sort_domains(int basis)
{
	ifstream ifs("backend/db2.csv");
	start=NULL;
	char extract[100];
	ifs>>extract;
	ifs>>extract;
	while(!ifs.eof())
	{   
	    db2_sort *temp= new db2_sort;
	    temp->next=NULL;
		int i=0;
	    int k=0;
	    for(;extract[i]!=',';i++)
	    temp->domain_id[k++]=extract[i];
	    temp->domain_id[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->current[k++]=extract[i];
	    temp->current[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->oney[k++]=extract[i];
	    temp->oney[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->twoy[k++]=extract[i];
	    temp->twoy[k]='\0';
	    i++;k=0;
	    if(start==NULL)
	    start=temp;
	    else
	    {
	    	temp->next=start;
	    	start=temp;
		}
		ifs>>extract;
	    
	    
	}
	ifs.close();
    
	bubblesort(start);


	system("cls");
	gotoxy(40,5);
	cout<<"Displaying Domain Current Employment (Domain wise sorted) ";
	gotoxy(40,6);
	cout<<"____________________________________________________________";
	gotoxy(30,8);
	cout<<" Domain                                          Current Year Employment";
	gotoxy(30,9);
	cout<<"___________________________________________________________________________";
	int line =0;
	db2_sort *temp=start;
	temp=start;domain_c d;
	while(temp!=NULL)
	{
		gotoxy(32,10+ ++line);
		{
			int integer=temp->domain_id[0]-'0';
			cout<<d.domain[integer];
		}
		gotoxy(85,10+line);
		cout<<temp->current;
		temp=temp->next;
		
	}
	
	gotoxy(30,27);
	cout<<"Data query processed. Press any key to continue. ";
	getch();
	
	
	
}
void sort_db3(int basis)
{
	ifstream ifs("backend/db3.csv");
	top=NULL;
	char extract[150];
	ifs>>extract;
	ifs>>extract;
	while(!ifs.eof())
	{   
	    db3_sort *temp= new db3_sort;
	    temp->next=NULL;
		int i=0;
	    int k=0;
	    
	    for(;extract[i]!=',';i++)
	    temp->name[k++]=extract[i];
	    temp->name[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->branch[k++]=extract[i];
	    temp->branch[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->domain[k++]=extract[i];
	    temp->domain[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->avg[k++]=extract[i];
	    temp->avg[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->low[k++]=extract[i];
	    temp->low[k]='\0';
	    i++;k=0;
	    for(;extract[i]!=',';i++)
	    temp->high[k++]=extract[i];
	    temp->high[k]='\0';
	    i++;;k=0;
	    for(;extract[i]!='\0';i++)
	    temp->dif[k++]=extract[i];
	    temp->dif[k]='\0';
	    if(top==NULL)
	    top=temp;
	    else
	    {
	    	temp->next=top;
	    	top=temp;
		}
		ifs>>extract;
	    
	    
	}
	ifs.close();
    
   

   char dis_content[100];
   if(basis==2)
   {
   	strcpy(dis_content,"Companies Sorted on basis of their difficulties");
   	bubblesort(top,'2',4);
   }
   else
  {
   strcpy(dis_content,"Companies Sorted on basis of their Highest Pay");
   bubblesort(top,3.5);
}

	system("cls");
	gotoxy(40,5);
	cout<<dis_content;
	gotoxy(28,6);
	cout<<"___________________________________________________________________________________________________";
	gotoxy(30,8);
	cout<<"Company_Name    Branch  Domains      Highest Pay      Difficulty";
	gotoxy(30,9);
	cout<<"____________________________________________________________________ ";
	int line =0;
	db3_sort *temp=top;
	domain_c d;
	while(temp!=NULL)
	{
		gotoxy(30,10+ ++line);
		{
			cout<<temp->name;
		}
		gotoxy(48,10+line);
		cout<<temp->branch;
		gotoxy(55,10+line);
		cout<<temp->domain;
		gotoxy(68,10+line);
		cout<<temp->high;
		gotoxy(85,10+line);
		cout<<temp->dif;
		
		
		temp=temp->next;
		
	}
	
	
	streams s;
	s.printbranch(100,8);
	domain_c c;
	c.printdomain(100,17);
	gotoxy(30,30);
	cout<<"Data query processed. Press any key to continue. ";
	getch();
	
	
	
}
void bubblesort(db2_sort *start)
{
	db2_sort *temp=start;
	db2_sort *temp2=start;
	while(temp!=NULL)
	{ 
		temp2=start;
		while(temp2->next!=NULL)
		{  int first=atoi(temp2->current);
		    int sec=atoi(temp2->next->current);
		    
			if(first<sec)
			{
				db2_sort *temp3;
				strcpy(temp3->current,temp2->current);
				strcpy(temp3->domain_id,temp2->domain_id);
				strcpy(temp3->oney,temp2->oney);
				strcpy(temp3->twoy,temp2->twoy);
				strcpy(temp2->current,temp2->next->current);
				strcpy(temp2->domain_id,temp2->next->domain_id);
				strcpy(temp2->oney,temp2->next->oney);
				strcpy(temp2->twoy,temp2->next->twoy);
				strcpy(temp2->next->current,temp3->current);
				strcpy(temp2->next->domain_id,temp3->domain_id);
				strcpy(temp2->next->oney,temp3->oney);
				strcpy(temp2->next->twoy,temp3->twoy);
				
                
           }
           
           temp2=temp2->next;
		}
		temp=temp->next;
	}
}
void bubblesort(db3_sort *top,char k_dif,int m)
{
	db3_sort *temp=top;
	db3_sort *temp2=top;
	while(temp!=NULL)
	{ 
		temp2=top;
		while(temp2->next!=NULL)
		{  float first=atof(temp2->dif);
		    float sec=atof(temp2->next->dif);
		    
			if(first<sec)
			{
				db3_sort *temp3;
				strcpy(temp3->name,temp2->name);
				strcpy(temp3->branch,temp2->branch);
				strcpy(temp3->domain,temp2->domain);
				strcpy(temp3->avg,temp2->avg);
				strcpy(temp3->high,temp2->high);
				strcpy(temp3->low,temp2->low);
				strcpy(temp3->dif,temp2->dif);
				strcpy(temp2->name,temp2->next->name);
				strcpy(temp2->branch,temp2->next->branch);
				strcpy(temp2->domain,temp2->next->domain);
				strcpy(temp2->avg,temp2->next->avg);
				strcpy(temp2->high,temp2->next->high);
				strcpy(temp2->low,temp2->next->low);
				strcpy(temp2->dif,temp2->next->dif);
				strcpy(temp2->next->name,temp3->name);
				strcpy(temp2->next->branch,temp3->branch);
				strcpy(temp2->next->domain,temp3->domain);
				strcpy(temp2->next->avg,temp3->avg);
				strcpy(temp2->next->high,temp3->high);
				strcpy(temp2->next->low,temp3->low);
				strcpy(temp2->next->dif,temp3->dif);
			
                
           }
           
           temp2=temp2->next;
		}
		temp=temp->next;
	}
}
void bubblesort(db3_sort *top,float k_sal)
{
	db3_sort *temp=top;
	db3_sort *temp2=top;
	while(temp!=NULL)
	{ 
		temp2=top;
		while(temp2->next!=NULL)
		{  float first=atof(temp2->high);
		    float sec=atof(temp2->next->high);
		    
			if(first<sec)
			{
				db3_sort *temp3;
				strcpy(temp3->name,temp2->name);
				strcpy(temp3->branch,temp2->branch);
				strcpy(temp3->domain,temp2->domain);
				strcpy(temp3->avg,temp2->avg);
				strcpy(temp3->high,temp2->high);
				strcpy(temp3->low,temp2->low);
				strcpy(temp3->dif,temp2->dif);
				strcpy(temp2->name,temp2->next->name);
				strcpy(temp2->branch,temp2->next->branch);
				strcpy(temp2->domain,temp2->next->domain);
				strcpy(temp2->avg,temp2->next->avg);
				strcpy(temp2->high,temp2->next->high);
				strcpy(temp2->low,temp2->next->low);
				strcpy(temp2->dif,temp2->next->dif);
				strcpy(temp2->next->name,temp3->name);
				strcpy(temp2->next->branch,temp3->branch);
				strcpy(temp2->next->domain,temp3->domain);
				strcpy(temp2->next->avg,temp3->avg);
				strcpy(temp2->next->high,temp3->high);
				strcpy(temp2->next->low,temp3->low);
				strcpy(temp2->next->dif,temp3->dif);
			
                
           }
           
           temp2=temp2->next;
		}
		temp=temp->next;
	}
}




	 void strict_up(int x,int y)
    	{
    		gotoxy(x,y);
    			for(int i=1;i<=14;i++)
	{
		for(int j=1;j<=14;j++)
	   { 
		 if(i+j==15&&i!=1)
		  
		 cout<<"/";
		 else
	    if(i==14)
	    cout<<"_";
	    else
	    if(j==1)
	    cout<<"|";
	    else
	    if(i==1&&j==13)
	    cout<<"_";
	    else
	    if(i==2&&j==14)
	    cout<<"|";
	    else
	    cout<<" ";
	    
	    
	    
	    
	}
	gotoxy(x,++y);
}
gotoxy(x+7,++y);
   cout<<"Years incresing ->";
   gotoxy(x-25,y-10);
   cout<<"Number of Employment";
   gotoxy(x+3,y+3);
   cout<<"This particular domain has Increasing employment rate.";
}
void strict_down(int x,int y)
    	{
    		gotoxy(x,y);
    			for(int i=1;i<=14;i++)
	{
		for(int j=1;j<=14;j++)
	   { 
		 if(i==j&&i!=1&&i!=14)
		  cout<<"\\";
		 else
	    if(i==14)
	    cout<<"_";
	    else
	    if(j==1)
	    cout<<"|";
	    else
	    if(i==13&&j==12)
	    cout<<"_";
	    else
	    if(i==13&&j==14)
	    cout<<"/";
	    else
	    cout<<" ";
	    
	    
	    
	    
	}
	gotoxy(x,++y);
}
gotoxy(x+7,++y);
   cout<<"Years incresing ->";
   gotoxy(x-25,y-10);
   cout<<"Number of Employment";
   gotoxy(x+3,y+3);
   cout<<"This particular domain has decreasing employment rate.";
}
void fluct(int x,int y)
    	{
    		gotoxy(x,y);
    			for(int i=1;i<=14;i++)
	{
		for(int j=1;j<=14;j++)
	   { 
		 if(i+j==15&&i>=6)
		  cout<<"/";
		 else
	    if(i==14)
	    cout<<"_";
	    else
	    if(j==1)
	    cout<<"|";
	    else
	   if(j==10&&i==6||j==10&&i==7||j==10&&i==8)
	   cout<<"|";
	   else
	   if(i==8&&j==10)
	   cout<<"/";
	   else
	   if(i==7&&j==11)
	   cout<<"/";
	   else
	   if(i==6&&j==12)
	   cout<<"/";
	   else
	   if(i==5&&j==13)
	   cout<<"/";
	   else
	   if(i==4&&j==14)
	   cout<<"/";
	   else
	   if(i==4&&j==13)
	   cout<<"_";
	   else
	   if(i==5&&j==14)
	   cout<<"|";
	   else
	   cout<<" ";
	   
	    
	    
	    
	    
	}
	gotoxy(x,++y);
}
   gotoxy(x+7,++y);
   cout<<"Years incresing ->";
   gotoxy(x-25,y-10);
   cout<<"Number of Employment";
   gotoxy(x+3,y+3);
   cout<<"This particular domain has fluctuating employment rate.";
}

