#include<stdio.h>
#include<string.h>
struct book
{
	char bn[100],an[100];
	int id,f,ss;
}b[100];
struct student
{
	char sn[100];
	int g,sid,bk[10],tb;
}s[100];
int tot=0,t=0,i,f1;
int ts=0,sc=0,ssid=11;
void add()
{
	int n;
	printf("Enter the No. of Books To be Add: ");
	scanf("%d",&n);
	tot+=n;
	for(i=t;i<tot;i++)
	{
		printf("Enter the Book Name:");
		scanf("%s",b[i].bn);
		printf("Enter the Author Name:");
		scanf("%s",b[i].an);
		printf("Enter the Book ID:");
		scanf("%d",&b[i].id);
		printf("Enter the Total No of Books:");
		scanf("%d",&b[i].ss);
		b[i].f=1;

	}
	printf("\n\t\t\t\tBooks Added Successfuully\n\n");
	t=i;
}
void view()
{
	f1=1;
	if(tot<=0)
	f1=0;
	for(i=0;i<tot;i++)
	{
		if(b[i].ss)
		f1=0;
	}
	if(f1)
	printf("No Books In Shelf\n");
	else
	{
		printf("Book Name\tAuthor Name\tBook ID\tNo of Books\n");
		for(i=0;i<tot;i++)
		{
			if(b[i].ss)
			printf("%s\t\t%s\t\t%d\t%d\n",b[i].bn,b[i].an,b[i].id,b[i].ss);
		}
	}
}
void issue(int ids)
{
	int m,j,idd,f2;
	char a[100];
	f1=0;
	//if(tot<=0)
	//f1=1;
	for(i=0;i<tot;i++)
	{
		if(b[i].ss)
		{
			f1=1;
		}
	}
	if(tot<=0)
	f1=0;
	else
	{
		printf("Enter the No of Books To Issue: ");
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			printf("Enter the Book Name: ");
			scanf("%s",a);
			printf("Enter the Book ID: ");
			scanf("%d",&idd);
			f2=1;
			for(i=0;i<tot;i++)
			{
				if(!strcmp(a,b[i].bn)&&b[i].id==idd&&b[i].ss)
				{
				    s[ids].bk[s[ids].tb++]=b[i].id;
					b[i].f=0;
					b[i].ss--;
					f2=0;
				}
			}
			if(f2)
				printf("Sorry..! Book Not Found\n");
			else
			printf("Book Issued Successfully..\n");
		}
	}
	if(f1==0)
	printf("No Books Remain To Issue..!\n");
}
void ret(int ids)
{
	int m,j,idd,f2;
	char a[100];
	f1=0;
	//if(tot<=0)
	//f1=1;
	for(i=0;i<tot;i++)
	{
		if(b[i].f==0)
		{
			f1=1;
		}
	}
	if(tot<=0)
	f1=0;
	else
	{
		printf("Enter the No of Books To Return: ");
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			printf("Enter the Book Name: ");
			scanf("%s",a);
			printf("Enter the Book ID: ");
			scanf("%d",&idd);
			f2=1;
			for(i=0;i<tot;i++)
			{
				if(!strcmp(a,b[i].bn)&&b[i].id==idd)
				{
				    for(j=0;j<s[ids].tb;j++)
				    {
				        if(s[ids].bk[j]==b[i].id)
				        {
				            s[ids].bk[j]=-1;
				        }
				    }
				    //s[ids].bk[s[ids].tb++]=b[i].id;
					//b[i].f=1;
					b[i].ss++;
					f2=0;
				}
			}
			if(f2)
				printf("Sorry..! Invalid Book Id\n");
			else
			printf("Book Returned Successfully..\n");
		}
	}
	if(f1==0)
	printf("No Books Remain To Return..!\n");
}
void admin()
{
    int opt,n,k,x,y,i,tid,tf;
	char a[100];
    int j;
    printf("\nWelcome To Library\n");
    while(1)
    {
        printf("\nPRESS\n1. Students Details\n2. Book Details\n3. Exit\nEnter the Option: ");
		scanf("%d",&x);
		if(x==1)
		{
		    while(1)
		    {
    			printf("\nPress\n1. Add Students\n2. Remove Students\n3. View Students Details\n4. Exit\n");
    			scanf("%d",&y);
    			if(y==1)
    			{
    				printf("\nEnter No of Students to Add: ");
    				scanf("%d",&n);
    				ts+=n;
    				for(i=sc;i<ts;i++)
    				{
    					printf("Enter Student name:");
    					scanf("%s",s[i].sn);
    					s[i].g=1;
    					s[i].sid=ssid++;
    					s[i].tb=0;
    					printf("Your ID is: %d\n",s[i].sid);
    				}
    				sc=i;
    			}
    			else if(y==2)
    			{
    				tf=1;
    				printf("Enter Student Name to Remove: ");
    				scanf("%s",a);
    				printf("Enter Student Id to Remove: ");
    				scanf("%d",&tid);
    				for(i=0;i<ts;i++)
    				{
    					if(!strcmp(s[i].sn,a)&&s[i].sid==tid&&s[i].g==1)
    					{
    						s[i].g=0;
    						tf=0;
    					}
    				}
    				if(tf)
    				printf("\nInvalid Student Crential\n");
    			}
    			else if(y==3)
    			{
    			    for(i=0;i<ts;i++)
    			    {
    			        if(s[i].g)
    			        {
    			            printf("%s %d\n",s[i].sn,s[i].sid);
    			            for(j=0;j<s[i].tb;j++)
    			            {
    			                for(k=0;k<tot;k++)
    			                {
    			                    if(s[i].bk[j]==b[k].id&&s[i].bk[j]!=-1)
    			                    {
    			                        printf("\nBooks Have: %s\n",b[k].bn);
    			                    }
    			                }
    			            }
    			        }
    			    }
    			}
    			else if(y==4)
    			{
    			    printf("\nThanks for Using\n");
    			    break;
    			}
    			else
    			printf("\nEnter Valid Option\n");
		    }
		}
		else if(x==2)
		{
		    printf("\n1. Add Book\n2. View Book\n");
		    scanf("%d",&y);
		    if(y==1)
		    add();
		    else if(y==2)
		    view();
		    else 
		    printf("\n***Please Enter Valid Option***\n");
		}
		else if(x==3)
		{
		    break;
		}
		else
		printf("\nEnter Valid Option\n");
    }
}
void student()
{
    int hn,nn,f1=0,q;
    printf("Enter Student ID:");
    scanf("%d",&nn);
    for(i=0;i<ts;i++)
    {
        if(nn==s[i].sid)
        {
            hn=i;
            f1=1;
            printf("\n***Welcome to Library***\n");
        }
    }
    if(f1==0)
    {
        printf("\n***Enter Valid Student ID***\n");
    }
    else
    {
        while(1)
        {
            printf("\n1. View Books\n2. Lend Books\n3. Return Books\n4. Exit\n");
            scanf("%d",&q);
            if(q==1)
            view();
            else if(q==2)
            issue(hn);
            else if(q==3)
            ret(hn);
            else if(q==4)
            {
                printf("\nThanks for using this service..\n");
                break;
            }
            else
            printf("\nPlease Enter Valid Option..\n");
        }
    }
}
void main()
{
	int opt,n,x,y,i,tid,tf;
	char a[100];
	while(1)
	{
		printf("PRESS\n1. Admin\n2. Student\n3. Exit\n");
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("Enter Admin Password:\n");
			scanf("%s",a);
			if(!strcmp(a,"k001"))
			admin();
			else
			printf("\nEnter Correct Admin Password\n");
		}
		//admin();
		else if(opt==2)
		student();
		else if(opt==3)
		{
			printf("Thanks for Using");
			break;
		}
		else
		printf("Enter Valid Option");
	}
	
}