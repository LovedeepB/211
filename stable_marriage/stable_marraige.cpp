#include<iostream>
using namespace std;

bool ok(int q[], int c) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences

   int newm = c;    
   int neww = q[c]; 
    
    for (int w = 0; w < c; w++) {
        int x = w;    
        int b = q[w]; 
        if((b==neww)||(mp[x][neww]<mp[x][b])&&(wp[neww][x]<wp[neww][newm])) return false;
        if((mp[newm][b]<mp[newm][neww])&&(wp[b][newm]<wp[b][x])) return false;
     }
    return true;
}
/*In my oky funtion i used a for loop that has two if statments. If i wanted i could have made one huge one but i did it this way so it was easier for me to see my code. Before the for loop i created two int values. One was the new male 
which was equal to c or the index of the array. While the new female was equal to the number stored in that index within the array q. Then i made x which was the currect male and than b which was the currect female. I created these 
four varaibles so i could compare them in my if statments. In my first if statement i say that if the male likes the current woman for than the new one and the woman likes the new man more than the currect one that marriage isn't 
stable so it doesn't work. Then i have another statement next to that connect with an or that says that the new woman the the currect woman we are checking can't be the same person. After that if statement it goes into the other 
one that says if the male likes another mans wife more than he likes his own and if the woman likes the new man less than her currect man than return false again.*/
void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for(int i=0; i<3; i++)
		cout << i << '\t' << q[i] << endl;

	cout << endl;
}
/*So in the print function i have a for loop that will print out the numbers. For man teh numbers that will be print out are 0,1,2 and than for the corresponding male the female that matches them will be printed. So for the male 
you just need to print out the i and for each i you print out q[i] which will give you the number that is in taht location in the array. Then in the cout i need to create a space between the i and q[i] so i used '\t' instead of " "
because that would just make a small space between the i and q[i] numbers when i need a tab for the q[i] to go under the word woman. Thats why i used '\t'  instead of '\t'*/


int main() {
 int q[3] = {};   
   int c=0;
   q[0]=0;
   while (c >= 0) { 
   	 c++;
      if(c==3){
        print(q);
        c--;
      }
      else{
      q[c]=-1;
    }
      while (c >= 0) {
         q[c]++;
         if(q[c]==3){
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
while loop and here i have an increment of c to check for all the columns and if it goes to the 3th column i know that i have a solution so i 
go to my print function. I also do backtracking since i want more than one solution backtracking will help me find others. And if the columns aren't 
equal to 3 than it restarts the code from the all the way at the top which mean -1. The second wile loop is for the rows and here you increase 
the number of rows by one each time and if the rows is equal to 3 than you backtrack. Lastly, you need to get out of the while loop and go to the first 
once and in order to do that you need a break. Thats why i have that if the okay function says that its good that it goes and tries to find another 
place where the stabel marrigae will be true. */
