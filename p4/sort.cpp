/*
 * CSc103 Project 4: Sorting with lists
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Dawen, Azwad, Kyle, Ash, https://www.youtube.com/watch?v=iChalAKXffs (for pointers)
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 14
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;

/* doubly linked list node: */
struct node {
	string data;
	node* prev;
	node* next;
	node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};
/*Function declarations*/
void sorting(node*& s);			// sorting function
bool uniquify(node* a, string b);	// function for checking if list is unique
void printfront(node* a);			// function to print out the list from the front of the list
void printend(node* a);				// the reverse function to print from the end of the linked list
void input(node*& a, string b);		// function that handles the inputs from the user and manages the node

int main(int argc, char *argv[]) {
	/* define long options */
	static int unique=0, reverse=0;
	static struct option long_opts[] = {
		{"unique",   no_argument,       &unique,   'u'},
		{"reverse",  no_argument,       &reverse,  'r'},
		{0,0,0,0} // this denotes the end of our options.
	};
	/* process options */
	char c; /* holds an option */
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'u':
				unique = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case '?': /* this will catch unknown options. */
				return 1;
		}
	}

	/*These are the nodes that are going to be used in the program.
 	Current is the first node that will recieve the string from the user.
	Front is the beginning of the new node next which is what Current will be pointing to.
	End is the end of the new node.*/
	node* current = NULL;
	node* front = NULL;
	node* end = NULL;
	string line;
	
	/* NOTE: at this point, variables 'reverse' and 'unique' have been set
	 * according to the command line.  */
	/* TODO: finish writing this.  Maybe use while(getline(cin,line)) or
	 * similar to read all the lines from stdin. */
	
	/*This is to create the first node in the program */
	getline(cin,line);
	current = new node;
	current->data = line;
	front = current;

	/*our while functions that takes in as many inputs from the user. */
	while(getline(cin,line)){
		if(line == "stop") break;	//implemented to break loop and see output
		/*current->next = new node();
		current->next->prev = current;
		current = current->next;*/
		if(unique == 1){ //checking if the list is unique
			if(uniquify(front,line) == true){ 
				input(current, line);
			}
		}
		else	
	{
		input(current,line);
		//current->data=line;
	}
	end = current; // the ending of the list
	}


	/*Following are the printing functions*/
	if(reverse == 1){ 	// reverse if user enters it
		sorting(front);
		printend(end);
	}
	else{				// printing the node
		sorting(front);
		printfront(front);
	}
	
	return 0;
	delete current;
	delete front;
	delete end;
}

/*The "default" printing function that the program uses. This will print from the beginning to the end
   of the node*/
void printfront(node* a){
	for(node* i = a; i != NULL; i = i->next){
		cout<<((*i).data)<<"\n";
	}
	delete a;
}


/*The uniquify function. This functions iterates throught the nodes and checkes if any repeats are 
  present. Takes in the current node and string and checks them */
bool uniquify(node* a, string b){
	for(node* x = a; x != NULL; x = x->next){
		if(b == (*x).data){
			return false;
		}
}	return true;
	delete a;
}
/*This function sorts the nodes. This iterates through them and checks to see if
   which is greater. The size is determined by the ASCII values.*/
void sorting(node*& s){
	for(node* a = s; a != NULL; a = a->next){
	for(node* b = s; b != NULL; b = b->next){
		if(b->data > a->data){
			swap(a->data,b->data); // swap function for nodes
		}
	}
}
}
/*The main input function. This manages the nodes and their data. Places the data in the next node as well*/
void input(node*& a, string b){
	a->next = new node;
	a->next->prev = a;
	a = a->next;
	a->data = b;
	delete a->next;
}

/*The function for */
void printend(node* a){
	for(node* i = a; i != NULL; i = i->prev){
		cout<<((*i).data)<<"\n";
	}
	delete a;
}