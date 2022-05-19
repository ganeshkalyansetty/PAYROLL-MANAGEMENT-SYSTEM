#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node1{
	int data;
	char name[10];
	char mobile_no[15];
	char address[100];
	char date[15];
	char grade[10];
	struct node1 *link;
};
struct node1 *head,*tail,*cr;
struct node1 *a[10];
int hash(char[]);
void insert(int,struct node1*);
void display_h();
void H_insert();
void adv_search();
int hash(char k[])
{
	if(!strcmp(k,"A"))
	return 0;
	else if(!strcmp(k,"B"))
	return 1;
	else if(!strcmp(k,"C"))
	return 2;
	else if(!strcmp(k,"O"))
	return 3;
	return 0;
}

void insert(int i,struct node1 *cr)
{	
	struct node1 *temp;
	temp=a[i];
	if(a[i]==NULL)
	{
		a[i]=cr;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=cr;
	}
}

void display_h()
{
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	int g;
	char ch[10];
	printf("\n\tENTER GRADE TO DISPLAY EMPLOYEE LIST\n");
	scanf("%s",ch);
	if(!strcmp(ch,"A"))
	g=0;
	else if(!strcmp(ch,"B"))
	g=1;
	else if(!strcmp(ch,"C"))
	g=2;
	else if(!strcmp(ch,"O"))
	g=3;
	for(int i=0;i<4;i++)
	{
		if(i==g)
		{
			cr=a[i];
			printf("\t\t\tEMPLOYEES WITH %s GRADE ARE :\n",ch);
			if(cr==NULL)
			{
				printf("\n\t\tTHERE ARE NO EMPLOYEES IN GRADE %s\n",ch);
			}
			while(cr!= NULL)
			{
				printf("-----------------------------------------------------------------------------------------------------\n");
				printf("\nNAME\t\t:%s\nDATE\t\t:%s\nADDRESS\t\t:%s\nID\t\t:%d\nMOBILE NUMBER\t:%s\nGRADE\t\t:%s\n",cr->name,cr->date,cr->address,cr->data,cr->mobile_no,cr->grade);
				cr=cr->link;
			}
			printf("-----------------------------------------------------------------------------------------------------\n");
			printf("\n");
		}
	}
}
void H_insert()
{
	char name[10],address[100],date[15],mobile_no[15],grade[10];
	int id,i;
	FILE *ft=fopen("employee_list.txt","r");
	while(fscanf(ft,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
	{
		i = hash(grade);
		cr = (struct node1*)malloc(sizeof(struct node1));
		cr->data=id;
		strcpy(cr->name,name);
		strcpy(cr->mobile_no,mobile_no);
		strcpy(cr->address,address);
		strcpy(cr->date,date);
		strcpy(cr->grade,grade);		
		cr->link=NULL;
		insert(i,cr);
	}
}
void adv_search()
{
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	int ch;
	char gr[10],name[15];
	printf("Enter grade to search: ");
	scanf("%s",gr);
	if(!strcmp(gr,"A"))
	ch=0;
	else if(!strcmp(gr,"B"))
	ch=1;
	else if(!strcmp(gr,"C"))
	ch= 2;
	else if(!strcmp(gr,"O"))
	ch=3;
	int g=65;
	for(int i=0;i<4;i++){
		if(i==ch)
		{
			cr=a[i];
			printf("Enter name to search: ");
			scanf("%s",name);
			while(cr!= NULL)
			{
				if(!strcmp(cr->name,name))
				{
					printf("-----------------------------------------------------------------------------------------------------\n");
					printf("\nNAME\t\t:%s\nDATE\t\t:%s\nADDRESS\t\t:%s\nID\t\t:%d\nMOBILE NUMBER\t:%s\nGRADE\t\t:%s\n",cr->name,cr->date,cr->address,cr->data,cr->mobile_no,cr->grade);
				}
				cr=cr->link;
			}
			printf("-----------------------------------------------------------------------------------------------------\n");
			//g++;
		}
	}
}
void del_hash()
{
	for(int i=0;i<4;i++)
	{
		a[i]=NULL;
	}
}