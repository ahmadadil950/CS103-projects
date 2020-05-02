/*
 * CSc103 Project 5: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Dawen, Ash, Carlos, https://www.youtube.com/watch?v=2SUvWfNJSsM&disableadblock=1
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 */

// TODO: write the program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function

void TOH(short n, short s, short aux, short t);

/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"start",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{0,0,0,0} // this denotes the end of our options.
	};
	// now process the options:
	char c; // to hold the option
	int opt_index = 0;
	short n=0,start=0,end=0; /* to store inputs to the towers function. */
	while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 's': // process option s
				start = atoi(optarg);
				break;
			case 'e': // process option e
				end = atoi(optarg);
				break;
			case 'n': // process option n
				n = atoi(optarg);
				break;
			case '?': // this will catch unknown options.
				// here is where you would yell at the user.
				// although, getopt will already print an error message.
				cout<<" ERROR! "<<"\n";
				return 1;
		}
	}

	/* TODO: now that you have the options and arguments,
	 * solve the puzzle. */
	short aux = 0;
	if(n < 1 || start == end){
		cout << "no change" << "\n";
	}
		TOH(n,start,aux,end);

	return 0;
}
/*This function takes in the # of disks, s - as the starting tower, aux - for the second tower, and 
   t - as the target tower, where we would need to be*/
void TOH(short n, short s, short aux, short t){
	aux = 6 - s -t;
	if(n == 1){						// this is to check if the inputs are equal to 1 then to just return the value
	cout << s << '\t' << t << "\n";
	return;
	}
	else{
	/*This part of the function is where the recursion occurs in the program*/
	TOH(n-1, s, t, aux);
	cout << s << '\t' << t << "\n";
	TOH(n-1, aux, s, t);

}
}