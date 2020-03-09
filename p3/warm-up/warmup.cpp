#include <vector>
using std::vector;
#include <iostream>
using std::cout;

/*This is our prototyping for the four functions that are being used in the program.*/
void board(vector<vector<bool>> V);		// This function is to used to print the board in the terminal
int countAlive(int i, int j, vector<vector<bool>> V);
/*countAlive is used to check if the surrounding neighbors are either alive or not.*/
void boardupdate();
/*boardupdate is what contins the rules to the game as well as countAlive function to connect the rules of the game
  and the method of counting alive or dead neighbors*/
void generation(int input);
/*The function generation is used to update each generation while applying the rules from boardupdate*/

/*This is our prototype for the first generation*/
vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int n = world.size();		// n = rows
int m = world[0].size();	// m = colums

int main(int argc, char** argv)
{
	if(argc == 2){
		generation(atoi(argv[1]));
	}
	else
	{
		generation(0);
	}
	
	board(world);
	/* NOTE: the vector 'world' above corresponds to the contents
	 * of ../res/tests/0.  TODO: apply the rules to the vector,
	 * write the result to standard output, and compare with the
	 * contents of ../tests/1. */
	return 0;
}

void board(vector<vector<bool>> V) // our board function
{
	// prints board
	for(size_t i = 0; i<n; i++){ // incrementing through rows
		for(size_t j = 0; j<m; j++){ // incrementing through columns
		if(V[i][j] == 1 ){
			cout<<"O"; 			// if one of our board prototype numbers is equal to 1 print 0
		}
		else{
			cout<<"."; 			// if equal to other than 1 then print .
		}
		}
		cout<<"\n";				// prints a new line after
	}
}

	/*This is our counting function which V[i+x] checks the neighbors around the individual and also this function
	wraps around the grid getting all of its neigbors*/
	int countAlive(int i, int j, vector<vector<bool>> V){  // to traverse through the grid
	int lives = 0;
	for(int x = -1; x <= 1; x++){          // the wrap around
		for(int y = -1; y <= 1; y++){
			if(V[(i+x+n)%n][(j+y+m)%m] == 1){ // the condition for checking if its alive
				lives++; 					  // a counter variable
			}
		}
	}
	/*This ignores the one we are counting from*/
    if(V[i][j]==1){
    lives--;
	}
	return lives; // to return the number of lives
	}

/*The function boardupdate is what we use to implement the rules for the game of life. This function also calls
countAlive so that it can count and change which ones should 
be alive or dead.*/
	void boardupdate(){
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
	/*This is our generation function, which gives the generation and calls boardupdate to help with the output
	of the grid.*/
	void generation(int input){
		for(int i = 0; i<input; i++){
		boardupdate();
		}
		}
	
