#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Node_Type.h"
#include"input_functions.h"
#define N 5
#define MAXSTRING 30

void create_trie(trieptr *t){
	int i=0;
	*t=malloc (sizeof(Trie));
	if (t==NULL)
		return ;
	(*t)->root = malloc(sizeof(Node));
	if ((*t)->root ==NULL)
		return ;
	((*t)->root)->value= '\0';

	//((*t)->root)->leaf=15;	//0 for internal node
    	
	for( i=0;i<NUMBER;i++)
    	{
        	((*t)->root)->child[i] = NULL;
    	}
}

void delete_trie(trieptr *t)
{
	if(*t == NULL)
		return;
	free(*t);
	*t=NULL;
	return;
}


void delete_node(trieptr* t, nodeptr* temptr)
{
	int i;
    	for( i=0;i<26;i++)
    	{
        	if((*temptr)->child[i] != NULL)
        	{
            		delete_node(t,&((*temptr)->child[i]));
        	}
    	}
	if((*temptr) != NULL)
	{
		free(*temptr);
		(*temptr)=NULL;	//gia na exw aktharo to xwro mou gia thn 
				//anazhthsh na mhn deixnei sta skoupidia
	}
	return;
}

void insert_trie(trieptr* t, char* buffer){
	int j,i=0;
	int num=0;
	int exist=0;
	int length=0;	
	nodeptr new=NULL;
	nodeptr current=NULL;
	leafptr newleaf=NULL;

	current=(*t)->root;
	length=strlen(buffer)-1;
	//printf("mhkos le3hs : %d\n", length);
	printf("inserted the word : ");
	for(i=0; i<length; i++)	
									//while (buffer[i]!=NULL)		//gia kathe string le3hs
	{	//printf("gramma : %c   ", buffer[i]);
		//printf("arithmos grammatos : %d\n", i);
		num= tolower(buffer[i])-'a';				//match the letter with the word
		//printf("NUMMMM%d\n", num);
		//if(current->child[num]==NULL)
		//	printf("katiiiiii\n");
		/*if (exist==1)						//proxwrame ton deikth ston epomeno komvo
		{	
			current=current->child[num];
			exist=0;					//to kanoume 0 gia thn epomenh epanalhyh
		}
			*/
		if (current->child[num]!=NULL)						//an uparxei apo prin to gramma afto
										// kanoume to found=1 kai tha 
								//metaferthoume sto epomeno node afou perasoume sto epomeno gramma me to i++
		{
			exist=1;
			//current->parent =current->child[num];
			//printf("%p parent\n",current->parent );
			current=current->child[num];

		}
		else	//an dn uparxei to gramma sto dedro 
			//dhmiourgoume neo komvo
		{
			new=NULL;
			new= malloc(sizeof(Node));
			new->parent= current;
			current->child[num]=new;
			new->value=buffer[i];
			for( j=0;j<NUMBER;j++)
    			{
        			new->child[j] = NULL;
    			}
			
			current= new;
		}
		printf(" %c" ,current->value);
	}
	
	printf("\n");
	newleaf= malloc(sizeof(Leaf));
	newleaf->parent=current;
	
	current->leaf=newleaf;
	newleaf->papaki='@';
	(newleaf->freq)++;
	
	while (current->value!='\0')
	{
		for(i=0; i<N; i++)//gia kathe thesh tou pinaka efoson eiani kenh deixnw sto fullo
		{
			if(current->common_words[i]==NULL)
			{
				current->common_words[i]=newleaf;
				break;
			}
		}
		
		current = current->parent;
	}
	
}

int search_trie(trieptr* t, char* input){
	int j=0,i=0;
	int num=0;
	int max=0;
	int length=0;
	char **output;	
	char *temp;
	nodeptr current=NULL;
	current=(*t)->root;
	length=strlen(input);
	printf("length : %d\n", length);
	printf("inserted the word : \n");
	for(i=0; i<length; i++)	
	{
		num= tolower(input[i])-'a';	//match the letter with the word
		if (current->child[num]!=NULL)	//an uparxei apo prin to gramma
		{
			printf(" prwtoooooo" );
			printf("CHAR = %c\n", current->value);
			current=current->child[num];
		}
		else	//an dn uparxei to gramma sto dedro 
		//dhmiourgoume neo komvo
		{
			printf("mlkia\n");
		//eisagwgh neas le3hs
			
		}
		
	}//eimaste ston teleutaio komvo tou prothematos sto dedro
	output=malloc(N*sizeof(char*));
	for(i=0; i<N; i++)
	{
		if(current->common_words[i]!=NULL)
		
		{	
			temp = print_word(current->common_words[i]);
			output[i] = malloc(sizeof(strlen(temp)));
			strcpy(output[i], temp);
			
		}
		
	}
	for(i=0; i<N; i++)
	{
		fprintf(stderr,"%s\t", output[i]);
	}
	printf("\n");
	return 0;
}


void insert_trie_input(trieptr* t, char* buffer){
	int j=0,i=0;
	int num=0;
	int exist=0;
	int length=0;	
	nodeptr new=NULL;
	nodeptr current=NULL;
	leafptr newleaf=NULL;

	current=(*t)->root;
	length=strlen(buffer);
	printf("inserted the word : ");
	for(i=0; i<length; i++)	
											//gia kathe string le3hs
	{	
		num= tolower(buffer[i])-'a';				//match the letter with the word
		printf("edw mesa einai to length2 %d",length);
		if(current==NULL)
			printf("!!!!!!!\n");
		if (current->child[num]!=NULL)						//an uparxei apo prin to gramma afto
										// kanoume to found=1 kai tha 
								//metaferthoume sto epomeno node afou perasoume sto epomeno gramma me to i++
		{
			exist=1;
			//current->parent =current->child[num];
			//printf("%p parent\n",current->parent );
			current=current->child[num];

		}
		else	//an dn uparxei to gramma sto dedro 
			//dhmiourgoume neo komvo
		{
			new=NULL;
			new= malloc(sizeof(Node));
			new->parent= current;
			current->child[num]=new;
			new->value=buffer[i];
			for( j=0;j<NUMBER;j++)
    			{
        			new->child[j] = NULL;
    			}
			
			current= new;
		}
		printf(" %c" ,current->value);
	}
	printf("\n");
	newleaf= malloc(sizeof(Leaf));
	newleaf->parent=current;
	
	current->leaf=newleaf;
	newleaf->papaki='@';
	(newleaf->freq)++;
	print_word(newleaf);
}



char* print_word(leafptr l){
	nodeptr current ;//
	current=l->parent;
	char word[25];
	char **output;
	char reversed[25];
	int i=0, length=0, j;
	
	while (current->value!='\0')
	{
		word[i]=current->value;
		i++;
		current = current->parent;
	}
	length=i;
	word[i]='\0';
	j=0;
	for (i=strlen(word)-1 ; i>=0 ; i--) {
		reversed[j] = word[i];
		j++;
	}
	reversed[j] = '\0';
	//fprintf(stderr,"%s\t", reversed);
	return reversed;
		
}


