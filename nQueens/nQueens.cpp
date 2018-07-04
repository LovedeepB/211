#include <iostream>
#include <cmath>
using namespace std; 


bool ok(int q[], int c) {
   for(int i=0; i<c; i++)
    if(q[c]==q[i] || (c-i)==abs(q[c]-q[i]))
    return false;
    return true;
}
int nqueens(int n) {
    int *q=new int[n]; 
    int c=0;
    q[0]=0;
    int ans=0;
while (c>=0){
	c++;
	if (c==n){
		ans++;
		c--;
	} 
	else
	q[c]=-1;
	while(c>=0){
		q[c]++;
		if(q[c]==n){
			c--;
		} 
		else if(ok(q,c)==true)
		break;
		
	}
}
delete []q; 
return ans; 
	
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
} 
/*In the nquens function i make sure i start off my code by looking at the first row and first column which is located at 0,0. Then i go into my first 
while loop and here i have an increment of c to check for all the columns and if it goes to the nth column i know that i have a solution so i 
go to my print function. I also do backtracking since i want more than one solution backtracking will help me find others. And if the columns aren't 
equal to n than it restarts the code from the all the way at the top which mean -1. The second while loop is for the rows and here you increase 
the number of rows by one each time and if the rows is equal to n than you backtrack. Lastly, you need to get out of the while loop and go to the first 
once and in order to do that you need a break. Also since the int q is part of dynamic memory which means that you can set it equal to another variable without defining 
what either of them are. Also once the code is done running you need to delete the q and since q is an array you write delete [] q; and you should put it before the return so it 
deletes it before it goes to the main where it will print out the answers. There is also a bool function so it will return true or false and in it i am checking to make sure that 
the spot the queen is in is okay. Basically the okay function does what the 3 for loops we had for the 2d queens did. It does the upperleft and lowerleft diagonal test as well as 
test to see if the row test is good. */
