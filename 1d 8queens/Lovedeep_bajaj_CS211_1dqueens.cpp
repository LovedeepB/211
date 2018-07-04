#include <iostream> 
#include <cmath>
using namespace std; 

bool ok(int q[], int c) {
   for (int i=0; i<c ;i++){
     if ((q[c]==q[i])||(c-i)== abs(q[c]-q[i]))
         return false; 
    }
   return true;
}
/*This is a bool function so it will return true or false and in it i am checking to make sure that the spot the queen is in is okay. Basically 
the okay function does what the 3 for loops we had for the 2d queens did. It does the upperleft and lowerleft diagonal test as well as 
test to see if the row test is good.*/
void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   for (int i=0; i<8; i++){
     cout<<q[i];
   }
   cout << "\n";
} 
/*In the print function i am simply printing out the soluntions i find that work. In order to print them i use a for loop and since i am printing out 
the place where the queen is located not the index i use q[i].*/

int main() {
   int q[8] = {0};   
   int c=0;
   q[0]=0;
   while (c >= 0) { 
   	 c++;
      if(c==8){
        print(q);
        c--;
      }
      else{
      q[c]=-1;
    }
      while (c >= 0) {
         q[c]++;
         if(q[c]==8){
           c--;
    }
    else if(ok(q,c) == true){
        break;
        }
	}
    }
   
   return 0;
} 
/*In the main function i make sure i start off my code by looking at the first row and first column which is located at 0,0. Then i go into my first 
while loop and here i have an increment of c to check for all the columns and if it goes to the 8th column i know that i have a solution so i 
go to my print function. I also do backtracking since i want more than one solution backtracking will help me find others. And if the columns aren't 
greater than 7 than it restarts the code from the all the way at the top which mean -1. The second wile loop is for the rows and here you increase 
the number of rows by one each time and if the rows is equal to 8 than you backtrack. Lastly, you need to get out of the while loop and go to the first 
once and in order to do that you need a break. Thats why i have that if the okay function says that its good that it goes and tries to find another 
place where the 8 queens will be true. */
