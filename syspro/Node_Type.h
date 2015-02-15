
#define NUMBER 26
#define N 5
typedef struct Leaf *leafptr;
typedef struct Node *nodeptr;
typedef struct Node {

	char value;	//the value of each node
	nodeptr child[NUMBER];	//the number of childs for each node
	nodeptr parent;	//the parent of each node
	leafptr leaf;
	leafptr common_words[N]; //references to the N most common words with this prefix
}Node;

typedef struct Trie * trieptr;
typedef struct Trie {
	
	nodeptr root;

}Trie;


typedef struct Leaf *leafptr;
typedef struct Leaf{
	char papaki;
	int freq;
	nodeptr parent;

}Leaf;

void create_trie(trieptr *);
void delete_trie(trieptr *);
void insert_trie(trieptr*, char*);
void delete_node(trieptr*, nodeptr*);
int search_trie(trieptr*, char*);
char* print_word(leafptr);



int getchar_silent();
int input_function(FILE*, trieptr*);


////////////////



