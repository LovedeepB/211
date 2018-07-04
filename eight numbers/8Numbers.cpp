#include <iostream>
#include <cmath>
using namespace std; 
bool test(int cross[], int x) {
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	for(int i=0; checkList[x][i]!=-1; i++){
		if (abs(cross[checkList[x][i]]-cross[x])==1)
		return false;
	}
	for (int i=0; i<x ;i++){
     if (cross[x]==cross[i])
         return false; 
    } 
return true;
}  
/*in this function what i have done is that i check if there is already a number in that location. I check for if I can place a that numebr in that spot also or if it doesn't pass the diagonal test and the across test. In order to 
test for those I need to know the neighbors of the box I are checking that is why I create a 2d array for the checklist. Also I only check the numbers that go after not the numbers that came before. If you can't place a number there 
becasue the checklist doesn't allow it thatn the first for loop won't allow for it. THe seocnd one will cehck for if there is a number in that box already or not. In both for loops if the if loop is true it will reutrn false however
if both the for loops ran and both the if statments aren't treun than it comes out of the for loops and returns true. */

void print(int cross[], int cap) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}
/*In this function what I do is that we print out the array and I make it in the appear in that cross shape I want. Also i set a counter to show us the amount of times I have printed a cross. The reason my answers are different 
from prof. Waxmans is bc i placed the index of the array to differnt boxes than he did.*/

int main() {
	int cross[8] = {0};   
   int c=0;
   cross[0]=0;
   while (c >= 0) { 
   	 c++;
      if(c==8){
        print(cross,c);
        c--;
      }
      else{
      cross[c]=-1;
    }
      while (c >= 0) {
         cross[c]++;
         if(cross[c]==8){
           c--;
    }
    else if(test(cross,c) == true){
        break;
        } 
	}
    }
   
   return 0;
}
/*In the main function i make sure i start off my code by looking at the first row and first column which is located at 0,0. Then i go into my first  while loop and here i have an increment of c to check for all the columns 
and if it goes to the 8th column i know that i have a solution so i go to my print function. I also do backtracking since i want more than one solution backtracking will help me find others. And if the columns aren't 
greater than 7 than it restarts the code from the all the way at the top which mean -1. The second whlie loop is for the rows and here you increase the number of rows by one each time and if the rows 
is equal to 8 than you backtrack. Lastly, you need to get out of the while loop and go to the first once and in order to do that you need a break. Thats why i have that if the okay function says that its good that it goes
and tries to find another place where the 8 numbers will be true. */
