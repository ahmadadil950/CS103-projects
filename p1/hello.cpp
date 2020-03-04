/*
 * CSc103 Project 1: (hello_world++)
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 */

#include <iostream> // referenced this from lecture 1 and
#include <string>   // professor Li's lecture 1
using std::cin;     // from project template
using std::cout;
using std::string;
using std::endl;    //endl from professor Li lecture 3
int main()
{
  string name;      // string name for user's name
  string relative;  // string name for user's relative
  cout<<"Enter your name"<<endl;  // asks user's for name
  getline(cin,name);              // gets user's name
  cout<<"Enter a relative"<<endl; // asks for relative name
  getline(cin,relative);          // gets relative name
  cout<<"Hello. My name is "<< name << "."; //
  cout<<" You killed my "<< relative <<" prepare to die."<<endl;
 /*This is the output that adds the strings and messages together for the line.*/
  return 0;   // program compiled successfully.
}

