#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include"project_BST.h"
#include"project_hash.h"
struct employee{
	char name[10];
	int id;
	char mobile_no[15];
	char address[100];
	char date[15];
	char grade[10];
	struct employee *link;
};
struct login
{
	char username[15];
	char password[15];	
};
struct payslip{
	int id;
	int basic;
	int hra;
	int da;
	int lta;
	int pa;
	int misc;
	int ma;
	int ca;
	int other;
	int pp;
	int tax;
	int pf;
	int earnings;
	int deductions;
	int ttotal;
};
struct payslip A;
struct payslip B;
struct payslip C;
struct payslip O;
FILE *fp;
int total=24;
struct employee e1;
void convert();
void display();
void modify();
void tmd();
void delte();
void dll();
int count();
void payslip(int);
void details(int);
void ulogin();
void acreate();
void payslip_modification();
void add_q();
void enqueu(int);
void dequeu();
void push(int,char[],char[],char[],char[],char[]);
void pop();
int isfull();
int count1();
void gradec(char grade[],int leaves,FILE *mt,int id);
void xcel(FILE *mt,int uid,FILE *xt);
struct employee *first=NULL,*last,*cur,*front=NULL,*rear,*start=NULL,*end;
int main()
{
	int c;
	do
	{
		system("cls");
		system("color 06");
		printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
		printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		tmd();
		printf("\n\t1.ADMIN LOGIN\n\t2.EMPLOYEE LOGIN\n\t3.EXIT");
	    printf("\nenter the choice:");
	    scanf("%d",&c); 
	    switch(c)
	    {
	    	case 1:
	    		acreate();
	    		break;
	    	case 2:
	    		ulogin();
	    		break;
	    	case 3:
	    		exit(0);
		}
	}while(1);
}
void convert()
{
	FILE *ft=fopen("employee_list.txt","r");
    char name[100],mobile_no[15],address[100],date[15],grade[10];
    int id;
	while(fscanf(ft,"%d%s%s%s%s%s",&id,&name,&mobile_no,&address,&date,&grade)!=EOF)
	{
		if(first==NULL)
		{
			cur=(struct employee*)malloc(sizeof(struct employee));
			strcpy(cur->name,name);
			strcpy(cur->date,date);
			strcpy(cur->address,address);
			strcpy(cur->grade,grade);
			cur->id=id;
			strcpy(cur->mobile_no,mobile_no);
			cur->link=NULL;
			first=cur;
			last=cur;
		}
		else
		{
	        cur=(struct employee*)malloc(sizeof(struct employee));
	        strcpy(cur->name,name);
			strcpy(cur->date,date);
			strcpy(cur->address,address);
			strcpy(cur->grade,grade);
			cur->id=id;
			strcpy(cur->mobile_no,mobile_no);
	        cur->link=NULL;
	        last->link=cur;
	        last=cur;
	    }
    }
    fclose(ft);
}
void display()
{
	struct employee *temp;
	temp=first;
	printf("\n");
	while(temp!=NULL)
	{
		printf("-----------------------------------------------------------------------------------------------------\n");
		printf("\nNAME\t\t:%s\nDATE\t\t:%s\nADDRESS\t\t:%s\nID\t\t:%d\nMOBILE NUMBER\t:%s\nGRADE\t\t:%s\n",temp->name,temp->date,temp->address,temp->id,temp->mobile_no,temp->grade);
		printf("----------------------------------------------------------------------------------------------------------\n");
		temp=temp->link;
	}
}
void modify()	
{
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	FILE *fs=fopen("employee_list.txt","r");
	FILE *ft=fopen("temp.txt","w");
	char nname[10],naddress[100],ndate[15],nmobile_no[15],ngrade[10];
    char name[100],address[100],date[15],mobile_no[15],grade[10];
	int ch,uid,id;
	printf("\nEnter an ID to modify : ");
	scanf("%d",&uid);
	while(fscanf(fs,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
	{
		if(uid==id)
		{
			do
			{
				system("color 06");
			    printf("\t1.name modification\n\t2.address modification\n\t3.date moddification\n\t4.mobile number modification\n\t5.grade modification\n\t6.EXIT");
				printf("\nENTER YOUR CHOICE: ");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1:
						printf("\nEnter new name to modify: ");
						scanf("%s",nname);
						fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,nname,mobile_no,address,date,grade);
						break;
					case 2:
					    printf("\nEnter new adddress to modify");
						scanf("%s",naddress);
						fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,mobile_no,naddress,date,grade);
						break;
					case 3:
					    printf("\nEnter new date to modify");
						scanf("%s",ndate);
						fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,mobile_no,address,ndate,grade);
						//strcpy(temp->date,ndate);
						break;
					case 4:
					    printf("\nEnter new mobile number to modify");
						scanf("%s",nmobile_no);
						fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,nmobile_no,address,date,grade);
						//strcpy(temp->mobile_no,nmobile_no);
						break;
					case 5:
						printf("\nEnter the new grade of the employee");
						scanf("%s",ngrade);
						fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,nmobile_no,address,date,grade);
						break;					
				}
				printf("\n\tMODIFICATIONS ARE DONE\n");
		    }while(ch<6);
		}
		else
		{
			fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,mobile_no,address,date,grade);
		}
	}
	fclose(fs);
	fclose(ft);
	remove("employee_list.txt");
	rename("temp.txt","employee_list.txt");
}
void delte()	
{
	char name[10],address[100],date[15],mobile_no[15],grade[10];
	int ch,uid,id;
	struct employee *temp,*temp2;
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    do{
	printf("\n\t1.DELETE AN EMPLOYEE\n\t2.UNDO\n\t3.delete permanently\n\t4.exit");
    printf("\n\tEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
	{
	    case 1:
	    	{
				FILE *fs=fopen("employee_list.txt","r");
				FILE *ft=fopen("temp.txt","w");
				FILE *dt=fopen("deleted_list.txt","a");
				printf("\nEnter an ID to delete");
				scanf("%d",&uid);
				while(fscanf(fs,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
				{
					if(uid==id)
					{
						if(!isfull())
						{
							printf("\n\temployee record with ID %d is deleted\n",id);
							push(id,name,mobile_no,address,date,grade);	//pushing into stack
						}
						else
						{
							printf("\tCANNOT DELETE EMPLOYEES RECORD AS THE STACK IS ALREADY FULL! PLEASE TRY AGAIN\n");
							temp=start;
							while(temp!=NULL)
							{
								temp2=temp;
								fprintf(dt,"%d\n%s\n%s\n%s\n%s\n%s\n",temp->id,temp->name,temp->mobile_no,temp->address,temp->date,temp->grade);
								temp=temp->link;
								start=start->link;
								free(temp2);
							}
							fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,mobile_no,address,date,grade);
						}	
					}
					else
					{
						fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",id,name,mobile_no,address,date,grade);
					}
				}
				fclose(fs);
				fclose(ft);
				fclose(dt);
				remove("employee_list.txt");
				rename("temp.txt","employee_list.txt");
			}
			break;
		case 2:
	    	pop();	//popping out of the stack into original file
			break;
		case 3:
			FILE *dp=fopen("deleted_list.txt","a");
			temp=start;
			while(temp!=NULL)
			{
				fprintf(dp,"%d\n%s\n%s\n%s\n%s\n%s\n",temp->id,temp->name,temp->mobile_no,temp->address,temp->date,temp->grade);
							temp2=temp;
							temp=temp->link;
							start=start->link;
							free(temp2);
			}				
			fclose(dp);
			break;
	}
	}while(ch<4);
    	
}
void dll()
{
	struct employee *temp=first;
	struct employee *nn;
	while(temp!=NULL)
	{
		nn=temp;
		temp=temp->link;
		nn->link=NULL;
		free(nn);
	}
	first=NULL;
	last=NULL;	
}
void payslip(int uid)
{
	system("cls");
		system("color 06");
		printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
		printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
	char name[100],address[100],date[15],mobile_no[15],grade[10];
	int id,month;
	FILE *mt;
	FILE *ft=fopen("employee_list.txt","r");
	FILE *xt=fopen("payslip.csv","w");
	if(xt==NULL)
	{
		printf("error\n");
	}
	else
	{
		printf("Enter a month: ");
		scanf("%d",&month);
		while(fscanf(ft,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
		{
			if(uid==id)
			{	
				switch(month)
				{
					case 1:
						mt=fopen("january.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month JANUARY is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : JANUARY\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 2:
						mt=fopen("february.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month FEBRUARY is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : FEBRUARY\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 3:
						mt=fopen("march.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month MARCH is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : MARCH\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 4:
						mt=fopen("april.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month APRIL is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : APRIL\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 5:
						mt=fopen("may.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month MAY is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : MAY\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 6:
						mt=fopen("june.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month JUNE is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : JUNE\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 7:
						mt=fopen("july.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month JULY is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : JULY\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 8:
						mt=fopen("august.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month AUGUST is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : AUGUST\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 9:
						mt=fopen("september.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month SEPTEMBER is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : SEPTEMBER\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 10:
						mt=fopen("october.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month OCTOBER is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : OCTOBER\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 11:
						mt=fopen("november.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month NOVEMBER is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : NOVEMBER\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
					case 12:
						mt=fopen("december.txt","r");
						if(mt==NULL)
						{
							printf("\t\tpayslip for the month DECEMBER is not available\n");
						}
						else
						{
							fprintf(xt,",,,,GYAAN pvt. ltd.\n");
							fprintf(xt,",,PAYSLIP GENERATED FOR THE MONTH : DECEMBER\n");
							fprintf(xt,"ID,'%d',,,NAME,'%s'\nMOBILE NUMBER,'%s',,,ADDRESS,'%s'\nDATE,'%s',,,GRADE,'%s'\n",id,name,mobile_no,address,date,grade);
							fprintf(xt,"\n\n\n\n");
							xcel(mt,uid,xt);
						}
						fclose(mt);
						break;
				}
			}
		}
		printf("\n\t\t\tPAYSLIP IS GENERATED\n");
	}
	fclose(xt);
	fclose(ft);
}
void tmd()
{
	time_t t;
	time(&t);
	printf("\t\t\t\t\t\t\t\t\t\tDATE AND TIME: %s",ctime(&t));
}
void acreate()
{
	system("cls");
		system("color 06");
		printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
		printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
	struct login a;
	int c,uid;
	char nus[15],npwd[15];
	FILE *ft=fopen("admin.txt","r");
	fscanf(ft,"%s%s",a.username,a.password);
	printf("Enter Username: ");
	scanf("%s",nus);
	printf("Enter Password: ");
	scanf("%s",npwd);
	if((!strcmp(a.username,nus))&&(!strcmp(a.password,npwd)))
	{
		//int c;
		do
		{
			printf("\n\t1.ADDITION OF AN EMPLOYEE\n\t2.MODIFICATION OF AN EMPLOYEE\n\t3.DELETION OF EMPLOYEE RECORD\n\t4.DISPLAY ALL EMPLOYEE RECORDS\n\t5.DISPLAYING RECORD OF A PARTICULAR EMPLOYEE\n\t6.PAYSLIP GENERATION\n\t7.DISPLAYING EMPLOYEE RECORDS ACCORDING TO THEIR GRADE\n\t8.TWO LEVEL SEARCH USING HASH TABLE\n\t9.exit");
	    	printf("\nenter the choice:");
	    	scanf("%d",&c);
	    	switch(c)
	    	{
	    		case 1:
	    			add_q();
	    			break;
	    		case 2:
	    			modify();
	    			break;
	    		case 3:
	    			delte();
	    			break;
	    		case 4:
	    			system("cls");
					system("color 06");
					printf("------------------------------------------------------------------------------------------------------------------------");
					printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
					printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
					printf("------------------------------------------------------------------------------------------------------------------------\n");
	    			dll();
	    			convert();
	    			display();
	    			break;
	    		case 5:
	    			system("cls");
					system("color 06");
					printf("------------------------------------------------------------------------------------------------------------------------");
					printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
					printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
					printf("------------------------------------------------------------------------------------------------------------------------\n");
	    			printf("enter Id to display:\n");
	    			scanf("%d",&uid);
	    			del_BST(root);
	    			BST_insert();
	    			inorder_search(root,uid);
	    			break;
	    		case 6:
	    			dll();
	    			convert();
	    			payslip_modification();
	    			break;
	    		case 7:
	    			system("cls");
					system("color 06");
					printf("------------------------------------------------------------------------------------------------------------------------");
					printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
					printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
					printf("------------------------------------------------------------------------------------------------------------------------\n");
	    			del_hash();
	    			H_insert();
	    			display_h();
	    			break;
	    		case 8:
	    			del_hash();
	    			H_insert();
	    			adv_search();
	    			break;
			}
		//tmd();
		}while(c<9);
	}
	else
	{
		printf("INVALID LOGIN CREDENTIALS\n");
	}
	fclose(ft);
}
void ulogin()
{
	system("cls");
		system("color 06");
		printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
		printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
	char name[100],address[100],date[15],mobile_no[15],grade[10],psw[15];
	int c,uid,id;
	printf("\nEnter ID: ");
	scanf("%d",&uid);
	printf("\nEnter password: ");
	scanf("%s",psw);
	FILE *ft=fopen("employee_list.txt","r");
	while(fscanf(ft,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
	{
		if(id==uid&&(!strcmp(mobile_no,psw)))
		{
			do{
				printf("\n\t\t\t\t\tWELCOME %s !!\n",name);
				printf("\t1.EMPLOYEE DETAILS\n\t2.PAYSLIP\n\t3.EXIT\n");
				printf("Enter your choice: ");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						system("cls");
						system("color 06");
						printf("------------------------------------------------------------------------------------------------------------------------");
						printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
						printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
						printf("------------------------------------------------------------------------------------------------------------------------\n");
						del_BST(root);
	    				BST_insert();
	    				inorder_search(root,uid);
						break;
					case 2:
						payslip(uid);
						break;
				}
			}while(c<3);
		}
	}
	fclose(ft);
}
void payslip_modification()
{
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	FILE *mt;
	int uid,month,leaves,rem=0;
	A.basic=15000;
	B.basic=12000;
	C.basic=10000;
	struct employee *temp=first;
	printf("Enter ID to generate payslip: ");
	scanf("%d",&uid);
	while(temp!=NULL)
	{
		if(uid==temp->id)
		{
			printf("Enter a month to generate: ");
			scanf("%d",&month);
			switch(month)
			{
				case 1:
					printf("Enter number of leaves taken by the employee with ID %d in JANUARY:",uid);
					scanf("%d",&leaves);
					mt=fopen("january.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 2:
					printf("Enter number of leaves taken by the employee with ID %d in FEBRUARY:",uid);
					scanf("%d",&leaves);
					mt=fopen("february.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 3:
					printf("Enter number of leaves taken by the employee with ID %d in MARCH:",uid);
					scanf("%d",&leaves);
					mt=fopen("march.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 4:
					printf("Enter number of leaves taken by the employee with ID %d in APRIL:",uid);
					scanf("%d",&leaves);
					mt=fopen("april.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 5:
					printf("Enter number of leaves taken by the employee with ID %d in MAY:",uid);
					scanf("%d",&leaves);
					mt=fopen("may.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 6:
					printf("Enter number of leaves taken by the employee with ID %d IN JUNE:",uid);
					scanf("%d",&leaves);
					mt=fopen("june.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 7:
					printf("Enter number of leaves taken by the employee with ID %d in JULY:",uid);
					scanf("%d",&leaves);
					mt=fopen("july.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 8:
					printf("Enter number of leaves taken by the employee with ID %d in AUGUST:",uid);
					scanf("%d",&leaves);
					mt=fopen("august.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 9:
					printf("Enter number of leaves taken by the employee with ID %d in SEPTEMBER:",uid);
					scanf("%d",&leaves);
					mt=fopen("september.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 10:
					printf("Enter number of leaves taken by the employee with ID %d in OCTOBER:",uid);
					scanf("%d",&leaves);
					mt=fopen("october.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 11:
					printf("Enter number of leaves taken by the employee with ID %d in NOVEMBER:",uid);
					scanf("%d",&leaves);
					mt=fopen("november.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
				case 12:
					printf("Enter number of leaves taken by the employee with ID %d in DECEMBER:",uid);
					scanf("%d",&leaves);
					mt=fopen("december.txt","a");
					gradec(temp->grade,leaves,mt,temp->id);
					fclose(mt);
					break;
			}
		}
		temp=temp->link;
	}
}
void gradec(char grade[10],int leaves,FILE *mt,int id)
{
	int rem=0,sel;
//	int total_sal,gross_earnings,gross_deductions;
	A.basic=15000;
	A.da=A.basic/10;
	A.hra=(A.basic*3)/40;
	A.ma=500;
	A.other=(A.basic*3)/20;
	A.pf=(A.basic*5)/40;
	A.tax=250;
	
	B.basic=12000;
	B.da=B.basic/10;
	B.hra=(B.basic*3)/40;
	B.ma=500;
	B.other=(B.basic*3)/20;
	B.pf=(B.basic*5)/40;
	B.tax=250;
	
	C.basic=10000;
	C.da=C.basic/10;
	C.hra=(C.basic*3)/40;
	C.ma=500;
	C.other=(C.basic*3)/20;
	C.pf=(C.basic*5)/40;
	C.tax=250;
	
	O.basic=20000;
	O.da=A.basic/10;
	O.hra=(A.basic*3)/40;
	O.ma=500;
	O.other=(A.basic*3)/20;
	O.pf=(A.basic*5)/40;
	O.tax=250;
	if(!strcmp(grade,"A"))
	sel=1;
	else if(!strcmp(grade,"B"))
	sel=2;
	else if(!strcmp(grade,"C"))
	sel=3;
	else if(!(strcmp(grade,"O")))
	sel=4;
	switch(sel)
	{    
		case 1:
			A.earnings=A.basic+A.da+A.ma+A.hra+A.other;
			A.deductions=A.pf+A.tax;
			A.ttotal=A.earnings-A.deductions;
			if(leaves>=2)
			{
				total-=2;
				rem=leaves-2;				    
			}
			else
				total=total-leaves;
			fprintf(mt,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",id,A.basic,A.da,A.hra,A.ma,A.other,A.pf,A.tax,A.earnings,A.deductions);
			fprintf(mt,"%d\n%d\n%d\n",A.ttotal,A.ttotal-(rem*483),leaves);
			break;
		case 2:
			B.earnings=B.basic+B.da+B.ma+B.hra+B.other;
			B.deductions=B.pf+B.tax;
			B.ttotal=B.earnings-B.deductions;
			if(leaves>=2)
			{
				total-=2;
				rem=leaves-2;				    
			}
			else
				total=total-leaves;
			fprintf(mt,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",id,B.basic,B.da,B.hra,B.ma,B.other,B.pf,B.tax,B.earnings,B.deductions);
			fprintf(mt,"%d\n%d\n%d\n",B.ttotal,B.ttotal-(rem*387),leaves);
			
			break;
		case 3:
			C.earnings=C.basic+C.da+C.ma+C.hra+C.other;
			C.deductions=C.pf+C.tax;
			C.ttotal=C.earnings-C.deductions;
			if(leaves>=2)
			{
				total-=2;
				rem=leaves-2;				    
			}
			else
				total=total-leaves;
				fprintf(mt,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",id,C.basic,C.da,C.hra,C.ma,C.other,C.pf,C.tax,C.earnings,C.deductions);
				fprintf(mt,"%d\n%d\n%d\n",C.ttotal,C.ttotal-(rem*322),leaves);
			break;
		case 4:
			O.earnings=O.basic+O.da+O.ma+O.hra+O.other;
			O.deductions=O.pf+O.tax;
			O.ttotal=O.earnings-O.deductions;
			if(leaves>=2)
			{
				total-=2;
				rem=leaves-2;				    
			}
			else
				total=total-leaves;
				fprintf(mt,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",id,O.basic,O.da,O.hra,O.ma,O.other,O.pf,O.tax,O.earnings,O.deductions);
				fprintf(mt,"%d\n%d\n%d\n",O.ttotal,O.ttotal-(rem*645),leaves);
			break;
	}
}
void xcel(FILE *mt,int uid,FILE *xt)
{
	time_t t;
	int id,basic,da,hra,ma,other,pf,tax,earnings,deductions,ttotal,total,leaves;
	while(fscanf(mt,"%d%d%d%d%d%d%d%d%d%d%d%d%d",&id,&basic,&da,&hra,&ma,&other,&pf,&tax,&earnings,&deductions,&ttotal,&total,&leaves)!=EOF)
	{
		if(id==uid)
		{
			fprintf(xt,"TOTAL LPO's TAKEN,,,,,%d\n,,EARNINGS\nBASIC SALARY,,,,,%d\nDEARNESS ALLOWANCE,,,,,%d\nHOUSE RENT ALLOWANCE,,,,,%d\nMEDICAL ALLOWACE,,,,,%d\nOTHER ALLOWANCES,,,,,%d\nTOTAL EARNINGS,,,,,%d\n,,DEDUCTIONS\nPROVIDENT FUND,,,,,%d\nTAX,,,,,%d\nTOTAL DEDUCTIONS,,,,,%d\n\nTOTAL SALARY,,,,,%d\n",leaves,basic,da,hra,ma,other,earnings,pf,tax,deductions,total);
			time(&t);
			fprintf(xt,"\n,%s",ctime(&t));	
		}
	}
}
void add_q()
{
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	int size,i,c,cnt,coun;
	cnt=count1();
	c=count();
	coun=cnt+c;
	printf("Enter the number of employees you want to enter: ");
	scanf("%d",&size);
	i=size;
	while(size)
	{
		enqueu(coun);
		coun++;
		size--;
	}
	dequeu();
}
void enqueu(int c)
{
	system("cls");
	system("color 06");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tGYAAN PVT.LTD.\n");
	printf("\t\t\t\t\t  PAYROLL MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	struct employee *ptr;     
    ptr=(struct employee*)malloc(sizeof(struct employee));  
	ptr->id=c;
	printf("--------------------------------------------------------------------------------\n");
	printf("----------------------enter the data of employee-----------------------------");
	printf("\n--------------------------------------------------------------------------------");
	printf("\nyour ID is : %d",ptr->id);
	printf("\nenter name of an employee: ");
	scanf("%s",ptr->name);
	fflush(stdin);
	printf("\nenter mobile no.: ");
	scanf("%s",ptr->mobile_no);
	fflush(stdin);
	printf("\nenter address: ");
	scanf("%s",ptr->address);
	fflush(stdin);
	printf("\nenter date of joining: ");
	scanf("%s",ptr->date);
	fflush(stdin);
	printf("\nenter grade: ");
	scanf("%s",ptr->grade);   
    if(front==NULL)  
    {  
        front=ptr;  
        rear=ptr;   
        front->link=NULL;  
        rear->link=NULL;  
    }  
    else   
    {  
        rear->link=ptr;  
        rear=ptr;  
        rear->link=NULL;  
    }  
}
void dequeu()
{
	struct employee *temp1,*temp2;
	FILE *ft;
	ft=fopen("employee_list.txt","a");
	temp1=front;
	while(temp1!=NULL)
	{
		fprintf(ft,"%d\n%s\n%s\n%s\n%s\n%s\n",temp1->id,temp1->name,temp1->mobile_no,temp1->address,temp1->date,temp1->grade);
		temp2=temp1;
		temp1=temp1->link;
		front=front->link;
		free(temp2);
	}
	fclose(ft);
	
}
void push(int id,char name[15],char mobile_no[15],char address[15],char date[10],char grade[10])
{
	struct employee *nn;
	if(start==NULL)
	{
			nn=(struct employee*)malloc(sizeof(struct employee));
			nn->id=id;
			strcpy(nn->name,name);
			strcpy(nn->mobile_no,mobile_no);
			strcpy(nn->address,address);
			strcpy(nn->date,date);
			strcpy(nn->grade,grade);
			nn->link=NULL;
			start=nn;
			end=nn;
	}	
	else
	{
		nn=(struct employee*)malloc(sizeof(struct employee));
			nn->id=id;
			strcpy(nn->name,name);
			strcpy(nn->mobile_no,mobile_no);
			strcpy(nn->address,address);
			strcpy(nn->date,date);
			strcpy(nn->grade,grade);
			nn->link=NULL;
			end->link=nn;
			end=nn;
	}
}
void pop()
{
	FILE *pt;
	struct employee *temp1,*temp2;
	pt=fopen("employee_list.txt","a");
	if(start==NULL)
	printf("\tCANNOT UNDO !\n");
	else
	{
		//printf("\tpoppo\n");
		temp1=start;
		while(temp1->link!=NULL)
		{
			temp2=temp1;
			temp1=temp1->link;
		}
		fprintf(pt,"%d\n%s\n%s\n%s\n%s\n%s\n",temp1->id,temp1->name,temp1->mobile_no,temp1->address,temp1->date,temp1->grade);
		printf("\tEMPLOYEE WITH %d ID IS POPPED BACK INTO THE FILE",temp1->id);
		free(temp1);
		temp2->link=NULL;
		temp1=NULL;
	}
	fclose(pt);
}
int isfull()
{
	int c;
	struct employee *temp=start;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	if(c==2)
	return 1;
	else
	return 0;
}
int count1()
{
	char name[100],address[100],date[15],mobile_no[15],grade[10];
	int cou,id;
	FILE *ft=fopen("deleted_list.txt","r");
	if(ft==NULL)
	{
		cou=0;
		return cou;
	}
	else
	{
		while(fscanf(ft,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
		{
			cou++;
		}
		return cou;
	}
	fclose(ft);
}