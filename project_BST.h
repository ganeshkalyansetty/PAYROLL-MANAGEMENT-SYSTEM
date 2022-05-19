#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	char name[100];
	char address[100];
	char date[15];
	char mobile_no[15];
	char grade[10];
	struct node *lchild,*rchild;
};
struct node *root=NULL;
struct node* insert(struct node*,int,char[],char[],char[],char[],char[]);
void inorder(struct node*);
int inorder_search(struct node*,int);
void preorder(struct node*);
void postorder(struct node*);
int count()
{
	FILE *ft;
	char nname[100],naddress[100],ndate[15],nmobile_no[15],ngrade[10];
	int length=1,uid;
	ft=fopen("employee_list.txt","r");
	while(fscanf(ft,"%d%s%s%s%s%s",&uid,nname,nmobile_no,naddress,ndate,ngrade)!=EOF)
	{
		length++;	   
	}
	fclose(ft);
	return length;
}
struct node* getnode(int id,char name[100],char mobile_no[100],char address[15],char date[15],char grade[10])
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=id;
		strcpy(newnode->name,name);
		strcpy(newnode->mobile_no,mobile_no);
		strcpy(newnode->address,address);
		strcpy(newnode->date,date);
		strcpy(newnode->grade,grade);
		newnode->lchild=NULL;
		newnode->rchild=NULL;
		return (newnode);
}
FILE *ft;
	char name[100],address[100],date[15],mobile_no[15],grade[10],psw[15];
	int id;
void BST_insert()
{
	int high=count();
	int low=1;
	int mid;
    ft=fopen("employee_list.txt","r");
		mid=(high+low)/2;
	    while(fscanf(ft,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
		{
			if(id==mid)
			{
	    		root=insert(root,id,name,mobile_no,address,date,grade);
	    	}
	    }
	    fclose(ft);
	    ft=fopen("employee_list.txt","r");
	    while(fscanf(ft,"%d%s%s%s%s%s",&id,name,mobile_no,address,date,grade)!=EOF)
	    {
	    	if(id==mid)
	    	continue;
	    	root=insert(root,id,name,mobile_no,address,date,grade);
		}
	fclose(ft);
}
struct node* insert(struct node *root,int id,char name[100],char mobile_no[100],char address[15],char date[15],char grade[10])
{
	struct node *temp=root;
	if(root==NULL)
	{
		root=getnode(id,name,mobile_no,address,date,grade);
		return(root);
	}
	while(1)
	{
		if(temp->data>id)
		{
			if(temp->lchild==NULL)
			{
				temp->lchild=getnode(id,name,mobile_no,address,date,grade);
				break;
			}
			else
			temp=temp->lchild;
		}
		else
		{
			if(temp->rchild==NULL)
			{
				temp->rchild=getnode(id,name,mobile_no,address,date,grade);
				break;
			}
			else
				temp=temp->rchild;
		}
	}
	return(root);
}
int inorder_search(struct node *root,int id)
{
	if(root->lchild!=NULL)
	inorder_search(root->lchild,id);
	{
		if(root->data==id)
		{
			printf("\nNAME\t\t:%s\nDATE\t\t:%s\nADDRESS\t\t:%s\nID\t\t:%d\nMOBILE NUMBER\t:%s\nGRADE\t\t:%s\n",root->name,root->date,root->address,root->data,root->mobile_no,root->grade);
			return 0;
		}
	}
	if(root->rchild!=NULL)
	inorder_search(root->rchild,id);
	return 0;
}
void del_BST(struct node *root)
{
	root=NULL;
}