#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"input_functions.h"
#include"Node_Type.h"

#define MAXSTRING 30

int main(int argc, char *argv[])
{
	trieptr t;
	char buffer[MAXSTRING];
	FILE *fp;
	
	if (argc==3)
	{
		if ( strcmp(argv[1],"-d")==0)
		{
			if ((fp = fopen(argv[2],"r+")) == NULL)	
			{	printf("Problem loading the file1");
        			return -1;	
			}
		}
	}
	else if (argc==1){
		if ((fp = fopen("dictionary.txt","r")) == NULL)	
		{	printf("Problem loading the file2");
        		return -1;	
		}
	}	
	else {	
		printf("Problem loading the file3\n");
       		return -1;
	}	

	create_trie(&t);			//dhmiourgia tou dedrou
	while(fgets(buffer,MAXSTRING, fp)!=NULL)	
	{	
		printf("\nThe word is  :   %s\n", buffer);
		insert_trie(&t,buffer);	//eisage to kathe string tou le3ikou sto dedro
		//bzero(buffer, MAXSTRING);
		printf("End of word\n");
	}
	printf("\nThe dictionary load finished\n");
	
	input_function(fp,&t);
	//printf("2222222222222 %d \n",(t->root)->leaf );
	fclose(fp);
	delete_node(&t, &((t)->root));
	delete_trie(&t);
	
	return 0;

}







