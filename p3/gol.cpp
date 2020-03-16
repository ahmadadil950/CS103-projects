/*
 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *	Matt, Ash, Dewan, Steven G.
 * 
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 23
 */

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here */
FILE* fworld = 0; /* handle to file wfilename. */
string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */

vector<vector<bool>> world;

/* NOTE: you don't have to write these functions -- this is just how
 * I chose to organize my code. */
void initFromFile(const string& fname); /* read initial state into vectors. */
void mainLoop();
void dumpState(FILE* f, vector<vector<bool>> &world);
void boardupdate();
int countAlive(int i, int j, vector<vector<bool>> V);

/* NOTE: you can use a *boolean* as an index into the following array
 * to translate from bool to the right characters: */
char text[3] = ".O";

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	/* NOTE: at this point wfilename initfilename and max_gen
	 * are all set according to the command line: */
	//printf("input file:  %s\n",initfilename.c_str());
	//printf("output file: %s\n",wfilename.c_str());
	//printf("fast forward to generation: %lu\n",max_gen);
	/* TODO: comment out 3 lines above once you see what's in them. */
	/* NOTE: if wfilename == "-" you should write to stdout, not a file
	 * named "-"! */

	/* If you wrote the initFromFile function, call it here: */
	initFromFile(initfilename);
	mainLoop();
	return 0;
}

void mainLoop() {
	FILE *f;
    if (wfilename == "-"){
        f = stdout;
    }
    else{
        f = fopen(wfilename.c_str(), "wb");
        if (!f){
            std::cout<<"Error"<<"\n";
            exit(1);
        }
    }

    if (max_gen == 0){
        while (true){
            boardupdate();
			dumpState(f,world);
			sleep(1);
        }
    }
    else{
        for (size_t i = 0; i < max_gen; i++){
			boardupdate();
        }
		dumpState(f,world); // writes the final gen to file/terminal
	}

fclose(f);
}

int countAlive(int i, int j, vector<vector<bool>> V){  // to traverse through the grid
	int lives = 0;
	int m, n;
	n = V.size();
	m = V[0].size();
	for(int x = -1; x <= 1; x++){          // the wrap around
		for(int y = -1; y <= 1; y++){
			if(V[(i+x+n)%n][(j+y+m)%m] == 1){ // the condition for checking if its alive
				lives++; 					  // a counter variable
			}
		}
	}
	if(V[i][j]==1){
    lives--;
	}
	return lives;
}

void boardupdate(){
	int m, n;
	n = world.size();
	m = world[0].size();
		vector<vector<bool>> newearth = world;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int lives = countAlive(i,j,world);
				if(world[i][j] == 1 && (lives < 2 || lives > 3)){
					newearth[i][j] = 0;
				}else if(world[i][j] == 0 && lives == 3){
					newearth[i][j] = 1;
				}
			}
		}
		world = newearth;
	}

void initFromFile(const string& fname){
	FILE *f = fopen(fname.c_str(), "rb"); /* note conversion to char* */
    char d;
    world.push_back(vector<bool>()); /* add a new row */
    size_t rows = 0;                 /* current row we are filling */
    while (fread(&d, 1, 1, f))
    {
        if (d == '\n'){
            rows++;
			world.push_back(vector<bool>());
        }
        else if (d == '.'){
            world[rows].push_back(false); /* dead */
        }
        else{
            world[rows].push_back(true); /* alive*/
        }
    }
    if (world[rows].size() == 0){
        world.pop_back();
	}
fclose(f);
}

void dumpState(FILE* f, vector<vector<bool>> &world){
	char d;
	for(size_t i = 0; i<world.size(); i++){
		for(size_t j = 0; j<world[0].size(); j++){
			if(world[i][j] == 1){
				d = 'O';
				fwrite(&d,1,1,f);
			}
			else{
				d = '.';
				fwrite(&d,1,1,f);
			}
		}
d = '\n';
fwrite(&d,1,1,f);
	}

}