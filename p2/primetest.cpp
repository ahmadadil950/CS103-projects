/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: https://en.wikipedia.org/wiki/Prime_Number
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

int main()
{
  int n; // the number value that gets the input
  int i;
 /*i is what we will use to test if the inputs are prime or not. This is done by knowing that 2 is the greatest even prime number.   and the prime numbers that are odd will also be tested against this  */
  while(cin>>n) // so the program runs until ctr-c is pressed or a letter is inputed
  {
   /*This if statement is for when the user enters 2 or as input. Before when I was testing the program.*/
   if(n==2 || n==1){
    cout<<"1"<<endl;
   }
   int counter = 0;
   /*This for loop sets i = 2 which is the greatest even prime number. And this sets the condition that the input n, has to be greater than 2 and this allows for the if and else statement to happen.*/
  for(i = 1; i<=n; i++)
   {
   /*This following statment tests if the user entered a even number or an odd number. i is used to as a place holder to divide n by*/
    if(n%i == 0){
    counter++; // this counter variable is to count the number of divisions that occur
   }
  }
   if(counter>2){  // if it is greater than 2, then the number is composite
    cout<<"0"<<endl;
   }
   else{          // if it is equal to 2 then it is a prime number
    cout<<"1"<<endl;
   }
}
 return 0;
}
// final thoughts
/* 2 is the greatest even prime number
   all prime numbers after 5 end in either 1,3,5,7,9
   which allows me to predict the outcome before hand*/

