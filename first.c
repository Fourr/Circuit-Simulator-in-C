#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<ctype.h>
typedef struct node node;
typedef struct Lnode Lnode;
struct node
{
	int num;
	char* alpha;
	struct node * next;
	char * grayCode;

};

struct Lnode
{

	int num;
	struct Lnode * next;
	char * grayCode;



};

Lnode *LcreateNode()
{	
	Lnode *bust = (Lnode *) calloc(1,sizeof(Lnode) );
	//Lnode *bust = (Lnode *) calloc(1,sizeof(Lnode) );
	bust->next=NULL;	
	bust->num =0;
	bust->grayCode = (char *) calloc(1,sizeof(char ) );
	return bust;


};

node *createNode()
{	
	node *bust = (node *) calloc(1,sizeof(node) );
	bust->next =NULL;
	bust->num =0;
	bust->grayCode = (char *) calloc(1,sizeof(char ) );
	bust->alpha = (char *) calloc(1,sizeof(char ) );
	return bust;
}
//node *final;
node *root;
node *rootOut;

void readOut(FILE *fp1)
{

	rootOut = createNode();
//	int b;
	int a;
	int j;
	char *data = (char *)malloc (90 *sizeof(char) );
	node * ptr;
	node *temp;
	fscanf(fp1, "%s",data); //gets INPUTVAR
	fscanf(fp1, "%s", data); //gets first number
	a = atoi(data);
	fscanf(fp1, "%s", data); //gets first letter
        rootOut =createNode();
	strcpy(rootOut->alpha, data);	//sets letter to node created
	ptr = rootOut;									
	for(j=0; j<a-1; j++)
	{
		temp=NULL;		
		fscanf(fp1, "%s", data);	//reads letters
		temp =createNode();	//creates a new node for letter
		strcpy(temp->alpha, data);	//sets data
		ptr->next = temp; 	//makes the pointer's next to temp
		ptr= ptr->next;	//sets the pointer to temp/pointer's next
	}


	free(data);

}
void readAlpha(FILE *fp1)
{
	root = createNode();
	int a;
	int j;
	char *data = (char *)malloc(90 *sizeof(char) );
	node * ptr;
	node *temp;
	fscanf(fp1, "%s",data); //gets INPUTVAR
	fscanf(fp1, "%s", data); //gets first number
	a = atoi(data);
	fscanf(fp1, "%s", data); //gets first letter
        root =createNode();
	strcpy(root->alpha, data);	//sets letter to node created
	ptr = root;									
	for(j=0; j<a-1; j++)
	{
		temp=NULL;		
		fscanf(fp1, "%s", data);	//reads letters
		temp =createNode();	//creates a new node for letter
		strcpy(temp->alpha, data);	//sets data 
		ptr->next = temp; 	//makes the pointer's next to temp
		ptr= ptr->next;	//sets the pointer to temp/pointer's next
	}
	free(data);
}
void print(node *ptr)
{
	if(ptr==NULL)
	{
		printf("root is null\n");
	return;
	}

	for(;ptr!=NULL; ptr=ptr->next)
	{
		printf("char %s, num %d\n", ptr->alpha, ptr->num);	
	}
	printf("\n");
}
void Lprint(Lnode *ptr)
{
	if(ptr==NULL)
	{
		printf("root is null\n");
	return;
	}
						
	for(;ptr!=NULL; ptr=ptr->next)
	{
		printf("gray %s, num %d\n", ptr->grayCode, ptr->num);	
	}
	printf("\n");
}

void freell(node *head)
{

	if(head->next)
	{
		freell(head->next);

	}
	free(head->grayCode);
	free(head->alpha);
	free(head);
	return;


}


void and(FILE *fp)
{	int i;
	node *ptr4 = NULL;
	node *ptr3=root;
	node *ptr2 =root;
	node *ptr=root;
	char *data2 = (char *)malloc(90 *sizeof(char) );
	char *data1 = (char *)malloc(90 *sizeof(char) );	
	char *data = (char *)malloc(90 *sizeof(char) );
	fscanf(fp, "%s", data);
	fscanf(fp, "%s", data1);
	//printf("data = %s data1 = %s\n", data, data1);	
	while(1)
	{	
			
		if((i = strcmp(data, ptr->alpha)) ==0)
		{
			break;	
		}
		ptr=ptr->next;
		if(ptr==NULL)
		{
			break;
		}
	}
	i=1;
	while(2)	
	{
		if((i = strcmp(data1, ptr2->alpha)) ==0)
		{
			break;
		}
		ptr2=ptr2->next;
		if(ptr2==NULL)
		{
			break;	
		}
	}

	while(ptr3->next!=NULL)
	{
		ptr3=ptr3->next;
	}
	//printf("is digit bullshit = %d and for data1 %d\n", isdigit(data[0]), isdigit(data1[0]));
	if(isdigit(data[0])!=0 && isdigit(data1[0])!=0)
	{
		//printf("asdf\n");
		if(atoi(data)==1 && atoi(data1) ==1)
		{	fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num =1;
			strcpy(ptr4->alpha, data2);	//sets data 	
			ptr3->next=ptr4;
		}
		else
		{

			fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num = 0;
			strcpy(ptr4->alpha, data2);	//sets data 
			ptr3->next=ptr4;
		
		}
	



	}
	else if(isdigit(data[0])!=0)
	{	
	//	printf("gotttt in else\n");
		if(atoi(data)==1 && ptr2->num ==1)
		{	fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num =1;
			strcpy(ptr4->alpha, data2);	//sets data 	
			ptr3->next=ptr4;
		}
		else
		{

			fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num = 0;
			strcpy(ptr4->alpha, data2);	//sets data 
			ptr3->next=ptr4;
		
		}
	
	}
	else if(isdigit(data1[0])!=0)
	{
	//	printf("g00t in else\n");
		if(atoi(data1)==1 && ptr->num ==1)
		{	fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num =1;
			strcpy(ptr4->alpha, data2);	//sets data 	
			ptr3->next=ptr4;
		}
		else
		{

			fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num = 0;
			strcpy(ptr4->alpha, data2);	//sets data 
			ptr3->next=ptr4;
		
		}
	
	
	}
	else
	{//	printf("got in else\n");
		if(ptr->num ==1 && ptr2->num ==1)
		{	fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num =1;
			strcpy(ptr4->alpha, data2);	//sets data 	
			ptr3->next=ptr4;
		
		}
		else
		{	fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num = 0;
			strcpy(ptr4->alpha, data2);	//sets data 
			ptr3->next=ptr4;
		}
	}
//	printf("finished and\n");
	free(data);
	free(data1);
	free(data2);
}
void not(FILE *fp)
{	node *ptr1;
	int i;
	//printf("not\n");
	node *ptr= root;
 	char *data1 = (char *)malloc(90 *sizeof(char) );	
	char *data = (char *)malloc(90 *sizeof(char) );
	fscanf(fp, "%s", data);
	fscanf(fp, "%s", data1);
	if(isdigit(data[0])!=0)
	{
		if(atoi(data)==1)
		{
			ptr1=createNode();
			strcpy(ptr1->alpha, data1);
			ptr1->num =0;
				
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;	
			
			}
			ptr->next = ptr1;
			return;


	
		}
		else
		{
			ptr1=createNode();
			strcpy(ptr1->alpha, data1);
			ptr1->num =1;
			while(ptr->next!=NULL)
			{
			ptr=ptr->next;	
		
			}
			ptr->next=ptr1;
			return;


		}

	}
	 
	while(1)
	{
		if((i=strcmp(data,ptr->alpha))==0)
		{
		break;
		}
		ptr=ptr->next;	
	}
	i=1;
	ptr1 = createNode();
	strcpy(ptr1->alpha, data1);	//sets data 
		
//	ptr1->alpha = data1;
	if(ptr->num==1)
	{
		ptr1->num =0;
	}
	else if(ptr->num ==0)
	{
		ptr1->num=1;
	}		
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;	
		
	}

	ptr->next = ptr1;
	free(data);
	free(data1);
	//printf("finished not\n");
}
void or(FILE *fp)
{	
	int i;
	node *ptr4 = NULL;
	node *ptr3=root;
	node *ptr2 =root;
	node *ptr=root;
	char *data2 = (char *)malloc(90 *sizeof(char) );
	char *data1 = (char *)malloc(90 *sizeof(char) );	
	char *data = (char *)malloc(90 *sizeof(char) );
	//printf("and\n");
	fscanf(fp, "%s", data);
	fscanf(fp, "%s", data1);
	//printf("%s %s\n", data, data1);
	if(isdigit(data[0])!=0 && isdigit(data1[0])!=0)	
	{
	
		if(atoi(data) ==1 || atoi(data)==1)
		{
			fscanf(fp, "%s", data2);
			ptr4= createNode();
			ptr4->num =1;
			strcpy(ptr4->alpha, data2);
			while(ptr->next !=NULL)
			{
				ptr3=ptr3->next;
			}
			ptr3->next = ptr4;
			}
		else
		{
			fscanf(fp, "%s", data2);
			ptr4= createNode();
			ptr4->num=0;
			strcpy(ptr4->alpha, data2);
			while(ptr->next !=NULL)
			{
				ptr3=ptr3->next;
			}
			ptr3->next = ptr4;
			
		}	

	}
	else if (isdigit(data[0])!=0)
	{
		//printf("in here\n");
		fscanf(fp, "%s", data2);
		ptr4= createNode();
		
		strcpy(ptr4->alpha, data2);	//sets data 	
	//		
		if(atoi(data) ==1)
		{	
	//	printf("data = %s\n",data);
	//		printf("in here\n");
			ptr4->num=1;
		
		}	
		else
		{
			
			while(1)
			{
				if(strcmp(data2, ptr->alpha))
				{
					break;	
				}
				ptr=ptr->next;
			}
			if(ptr->num ==1)
			{
				ptr4->num=1;
			}	
			else
			{	
				ptr4->num=0;
			}		
		}	
		
		while(ptr3->next!=NULL)
		{
			ptr3=ptr3->next;
		}	
		ptr3->next=ptr4;

	}
	else if (isdigit(data1[0]) !=0)
	{
		fscanf(fp, "%s", data2);
		ptr4= createNode();
		strcpy(ptr4->alpha, data2);	//sets data 	
	//		
		if(atoi(data1) ==1)
		{
			ptr4->num=1;
		
		}	
		else
		{
			
			while(1)
			{
				if(strcmp(data2, ptr->alpha))
				{
					break;	
				}
				ptr=ptr->next;
			}
			if(ptr->num ==1)
			{
				ptr4->num=1;
			}	
			else
			{	
				ptr4->num=0;
			}		
		}	
		
		while(ptr3->next!=NULL)
		{
			ptr3=ptr3->next;
		}	
		ptr3->next=ptr4;


	}
	else 
	{		
		while(1)
		{	
			
		//	printf("ptr's alpha: %s\n", ptr->alpha);
			if((i = strcmp(data, ptr->alpha)) ==0)
			{
				break;	
			}
			ptr=ptr->next;
			//printf("i = %d\n",i);
		}
		//printf("ptr->alpha %s\n", ptr->alpha);
		//ptr2=root;
		i=1;
		while(2)	
		{
//			printf("ptr2's alpha: %s\n", ptr2->alpha);
			if((i = strcmp(data1, ptr2->alpha)) ==0)
			{
				break;
			}
			ptr2=ptr2->next;
		}
	
		while(ptr3->next!=NULL)
		{
			ptr3=ptr3->next;
		}
		//printf("first alpha: %s second alpha: %s\n", ptr->alpha, ptr2->alpha);	

		if(ptr->num ==1 || ptr2->num ==1)
		{	
			fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num =1;
			strcpy(ptr4->alpha, data2);	//sets data 	
	//		ptr4->alpha = data2;
			ptr3->next=ptr4;
		
		}
		else
		{	fscanf(fp, "%s", data2);
			ptr4=createNode();
			ptr4->num = 0;
			strcpy(ptr4->alpha, data2);	//sets data 	
	//		ptr4->alpha = data2;
			ptr3->next=ptr4;
		}
	}
	free(data);
	free(data1);
	free(data2);
}


void fixOut(node *ptr, node *ptr2)
{
	node *ptr3=ptr;
	
	int i;
	while(ptr2!=NULL)
	{
//		ptr2=ptr2->next;
		ptr=ptr3;	

		while(ptr!=NULL)
		{
			i = strcmp(ptr2->alpha, ptr->alpha);
			if(i==0)
			{
				ptr2->num = ptr->num;
				break;	
			}
			ptr=ptr->next;
		}

	ptr2=ptr2->next;	
	}


}

void Lgraycode(Lnode *ptr,int a)
{
	char gray[32];
	int max=(1<<a) - 1;  
	int b, i, j;
	gray[a]= '\0';
	for(i=0; i<=max; i++)
	{
		memset(gray, '0', a);
		b=(i>>1)^i; 
		j=0;
		while(b>0)   
		{
			gray[a-j-1]=b%2+'0';
			b=b/2;
			j++;
		}
		strcpy(ptr->grayCode, gray);
	//	printf("%s\n", gray);
		ptr=ptr->next;
		
	}
}
 
void graycode(node *ptr,int a)
{
	char gray[32];
	int max=(1<<a) - 1;     
	int b, i, j;
	gray[a]= '\0';
	for(i=0; i<=max; i++)
	{
		memset(gray, '0', a);
		b=(i>>1)^i;             
		j=0;
		while(b>0)              
		{
			gray[a-j-1]=b%2+'0';
			b=b/2;
			j++;
		}
		strcpy(ptr->grayCode, gray);
		//printf("%s\n", gray);
		ptr=ptr->next;
		
	}
}
 
void decoder(FILE *fp)
{	
	int i; 
	int j;
	node *ptr2;
	node *output;
	node *beef;
	node *temp;
	node *ptr;
	node *input;
	double a;
	int b;
	double c;
	char *data = (char *)malloc(999 *sizeof(char ) );	
	fscanf(fp,"%s", data);
	a = atoi(data);
	input =createNode();
	fscanf(fp, "%s", data);
	if (isdigit(data[0]) !=0)	
	{
		input->num = atoi(data);	
	}
	else
	{
		strcpy(input->alpha, data);
	}
	for(b=1; b<a; b++)
	{
		temp = createNode();
		fscanf(fp,"%s", data);
	//	printf("data = %s\n", data);
		if(isdigit(data[0]) ==0)
		{
			strcpy(temp->alpha,data);
		}
		else
		{
			temp->num = atoi(data);
		}
		if(input->next==NULL)
		{
			input->next=temp;
			//linked=temp;
		}	
		else
		{
			for(ptr=input; ptr->next!=NULL; ptr=ptr->next)
			{
				
			}
			ptr->next=temp;	
		}
	
	}
	output=createNode();
	temp = createNode();
	fscanf(fp, "%s", data);
	strcpy(output->alpha, data);
	strcpy(temp->alpha, data);
	for(ptr =root; ptr->next!=NULL; ptr=ptr->next)
	{
	}
	ptr->next=temp;	
	c = pow(2,a);
	for(b=0; b<c-1; b++)
	{
		temp = createNode();
		fscanf(fp,"%s", data);
		strcpy(temp->alpha, data);
		beef= createNode();
		strcpy(beef->alpha, data);
		if(output==NULL)
		{
			output->next=beef;
		}
		else
		{
			for(ptr2= output; ptr2->next!=NULL; ptr2=ptr2->next)
			{
			}
			ptr2->next=beef;	
		}	
		for(ptr=root; ptr->next!=NULL; ptr=ptr->next)
		{
		}
		ptr->next=temp;	
	}
	
	
	
	fixOut(root, input);
	
	graycode(output,a);
	i=0;
	//print(output);	
	for(ptr=output; ptr!=NULL; ptr=ptr->next)
	{ i=0;
				
	
		for(ptr2=input; ptr2!=NULL; ptr2=ptr2->next)
		{
			if(i<a)
			{	
				j=ptr->grayCode[i] - '0';
			//	printf("graycode for %s = %d, %s num = %d\n", ptr->alpha, j,ptr2->alpha, ptr2->num);
				if(j!=ptr2->num)
				{
					break;
				}
			
				if(j==ptr2->num && i==a-1)
				{
				//printf("input = %s ouput = %s input num = %d\n", ptr2->alpha, ptr->alpha, j);	
				//printf("in here\n");
					ptr->num =1;
				}
			}
			i++;
		}
				
		
		
	}
			
	fixOut(output,root);	
	//print(output);
	//print(input);
	//print(root);
	free(data);
	freell(input);
	freell(output);

}


void multiplexer(FILE *fp)
{
	fixOut(root,rootOut);
	int j;
	int i;
	//int c;
	int a;
	int b;
	node *temp2;	
	node *ptr3;
	Lnode *select;
	Lnode *Lptr;
	Lnode *Lptr2;
	Lnode *input;
	node *ptr;
	Lnode *temp;
	char *data = (char *)malloc(999 *sizeof(char ) );
	fscanf(fp, "%s", data);
	a=atoi(data);
	b=(log(a)/log(2));
	fscanf(fp, "%s", data);
	if(isdigit(data[0])!=0)
	{
		input = LcreateNode();
		input->num = atoi(data);
	}
	
	else
	{	
		for(ptr=root; ptr!=NULL; ptr=ptr->next)
		{
			if(strcmp(ptr->alpha, data)==0)
			{
				break;	
			}
		}	
		input = LcreateNode();	
		input->num = ptr->num;
	}
	

	for(i=1; i<a; i++)
	{
		fscanf(fp, "%s", data);
		if(isdigit(data[0])!=0)
		{
			
			temp = LcreateNode();
			temp->num = atoi(data);
			if(input->next ==NULL)
				{
					input->next=temp;
				}
			else
			{
				for(Lptr=input; Lptr->next!=NULL; Lptr=Lptr->next)
				{ }
				Lptr->next=temp;

			}

			
		}
		else
		{

			for(ptr=root; ptr!=NULL; ptr=ptr->next)
			{
				if(strcmp(ptr->alpha, data)==0)
				{
					break;	
				}
			}	
			temp = LcreateNode();	
			temp->num = ptr->num;
			if(input->next==NULL)
			{
				input->next=temp;
			}
			else
			{
				for(Lptr=input; Lptr->next!=NULL; Lptr=Lptr->next)
				{ }
				Lptr->next=temp;

			}
			
		
		}			
	}
	Lgraycode(input,b);
	//Lprint(input);
	fscanf(fp, "%s", data);
	
	//printf("data = %s\n", data);
	select = LcreateNode();
	//c = atoi(data);
//	printf("c = %d\n", c);
	if(isdigit(data[0])!=0)
	{
		//printf("in here\n");
		select->num = atoi(data);	
	}
	else
	{
		for(ptr=root; ptr!=NULL; ptr=ptr->next)	
		{
			if(strcmp(ptr->alpha, data)==0)
			{
				break;			
			}
		}
		select->num = ptr->num;	
	}
	
//	printf("select num %d\n", select->num);
	for(i =0; i<b-1; i++)
	{	

		fscanf(fp, "%s", data);	
		if(isdigit(data[0])!=0)
		{
			temp=LcreateNode();
			temp->num = atoi(data);
			if(select->next ==NULL)
			{
				select->next=temp;	
			}
			else
			{
				for(Lptr=select; Lptr->next!=NULL; Lptr=Lptr->next)
				{}
				Lptr->next=temp;	
			}
		}
		else
		{
	

			for(ptr=root; ptr!=NULL; ptr=ptr->next)
			{
				if(strcmp(ptr->alpha, data)==0)
				{
					break;	
				}
			}
			temp=LcreateNode();	
			temp->num = ptr->num;
			if(select->next ==NULL)
			{
				select->next =temp;
			}
			else
			{
				for(Lptr=select; Lptr->next!=NULL; Lptr=Lptr->next)
				{}
				Lptr->next=temp;
			}
		}
	}	
//	Lprint(select);
	ptr3=root;
	for(Lptr=input; Lptr!=NULL; Lptr=Lptr->next)
	{
		i=0;
		for(Lptr2=select; Lptr2!=NULL; Lptr2=Lptr2->next)
		{
			if(i<b)
			{	
				j=Lptr->grayCode[i] - '0';
				if(j!=Lptr2->num)
				{
					break;
				}
				else if(j==Lptr2->num && i==b-1)
				{
					//printf("lptr2 = %d\n", Lptr2->num);
					temp2 = createNode();
					temp2->num = Lptr->num;
					fscanf(fp,"%s",data);
					//printf("data = %s\n", data);
					strcpy(temp2->alpha, data);
				}	
			}
			i++;
		}
		
	}
	for(ptr3=root; ptr3->next!=NULL; ptr3=ptr3->next)
	{}
	ptr3->next=temp2;	
//	printf("temp2 = %s %d \n", temp2->alpha, temp2->num);	

//print(root);
}
int readInt(FILE *fp2,int j)
{	

	char *data = (char *)malloc(99 *sizeof(char ) );
	int a;
	char *data1 = (char *)malloc(99 *sizeof(char ) );
	node * ptr;
	for(ptr=root; ptr!=NULL; ptr=ptr->next)
	{
		j=fscanf(fp2, "%s", data); //gets number
		strcpy(data1, data);
		a = atoi(data1);
		ptr->num = a;	//sets number to node created
	
	}
	free(data);
	free(data1);

	return j;
}

void finalPrint(node *ptr)
{
	
	for(; ptr!=NULL; ptr=ptr->next)
	{
		printf("%d ", ptr->num);	
	}
	printf("\n");


}




int main(int argc, char** argv )
{
	if (argc ==3)
	{	int i=0;
		int j=0;
		char *data = (char *)malloc (10 *sizeof(char ) );	
		FILE *circ;
		FILE *inp;
		circ = fopen(argv[1], "r");
		inp = fopen(argv[2], "r");
		if (circ==NULL || inp==NULL)
		{
			printf("error");
			return 0;
		}
		else
		{
			
			while(j!=EOF)
			{
	
		
				if(i==EOF)
				{
					circ = fopen(argv[1], "r");	
				}
				readAlpha(circ);
				j=readInt(inp,j);
				if (j==EOF)
				{
					break;
				}
				readOut(circ);
				while(1)
				{
					i=fscanf(circ, "%s", data);
					if(i!=EOF)
					{
						switch(data[0])
						{
							case 'N' :
							not(circ);	
							break;
						
							case 'O':
							or(circ);
							break;
					
							case 'A' :
							and(circ);
							break;
				
							case 'D' :
							decoder(circ);
							break;

							case 'M' :
							multiplexer(circ);	
							break;
						
							default :
							break;
						}

					}
					if(i==EOF)
					{
						
						break;
					}
				}
				fixOut(root,rootOut);
				//print(root);
				finalPrint(rootOut);
				freell(root);
				freell(rootOut);
                       	        fclose(circ);
				free(data);
                               	
			}
		free(data);
		freell(root);
		freell(rootOut);
		}
		fclose(inp);
	}
	return 0;
}
