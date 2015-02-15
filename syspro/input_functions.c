#include <sys/ioctl.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include"Node_Type.h"
#include"input_functions.h"


#define MAXSTRING 30
#define LINESIZE 128
#define BACKSPACE 0x7f

int getchar_silent()
{
    int ch;
    struct termios oldt, newt;

    /* Retrieve old terminal settings */
    tcgetattr(STDIN_FILENO, &oldt);

    /* Disable canonical input mode, and input character echoing. */
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );

    /* Set new terminal settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    /* Read next character, and then switch to old terminal settings. */
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}



int input_function(FILE* fp,trieptr* t)
{	int result=0;
	int length=0;
	int next=0, i=0, j=0;
	char input[MAXSTRING];
    	struct winsize w;

    /* Keep reading one character at a time */
    while ((next = getchar_silent()) != EOF)
    {
        /* Print normal characters */
        if ( ispunct(next) || next == ' ' || next == '\n')
        {	if(&t==NULL)
			printf("1\n");
		if(input == NULL)
			printf("2\n");
		//insert_trie(&t,input);
		//fprintf(fp, "\n%s\n",input);
		
		bzero(input, MAXSTRING);
		j=0;
            	continue;
        }
	else if (isalpha(next))
	{
		
		input[j]=next;	//keep each word for check
		printf("%c!!!!!!!!!!!!!!!!!!",input[j]);
		printf("\nj=%d\n",j);
		//length=strlen(input);	
		//printf(" length %d", length);
		putchar(next);
		
		j++;
            	continue;
	}
        /* Treat special characters differently */
        switch(next) {

        case '\t':              /* Just read a tab */
		input[j]='\0';
		length=strlen(input);
		printf("length : %d\n", length);
		printf(" 1\n");	
			
		
		for(j=0; j<length; j++)
		{
			printf("%c",input[j]);
		}
		printf(" 2\n");	
		printf(" 3\n");	

		result=search_trie(t,input);
		printf("\nresult %d\n", result);
		if (result==2)
		{
////////////////////////////////////////////////////////////////////////////
			//insert_trie_input(&t,input);
			
			//fprintf(fp, "\n%s\n",input);
			//fprintf(stderr, "%s\n", );
		}
		printf(" 4\n");	
		
            	break;

        case BACKSPACE:         /* Just read a backspace */

            /* Move the cursor one step back, print space, and move
             * cursor back once more to imitate backward character
             * deletion.
             */

            	printf("\b \b");
            	break;

        case VEOF:              /* Just read EOF (Ctrl-D) */

            /* The EOF character is recognized only in canonical input
             * mode. In noncanonical input mode, all input control
             * characters such as Ctrl-D are passed to the application
             * program exactly as typed. Thus, Ctrl-D now produces
             * this character instead.
             */
	    
            	printf("\n\nExiting. Bye...");
            	goto THE_END;
        default:
            	continue;
        }
    }
THE_END:
    putchar('\n');
    return EXIT_SUCCESS;
}
