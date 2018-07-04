#include <iostream>
using namespace std; 
int main (){
	int b[8][8]={0}; //creates a 2d array chess board comprised of zero's.
	b[0][0]=1;
	int r; 
	int c=0;
	nextCol: 
	c++;
	if(c==8){
		goto print; 
	} 
	r=-1; 
	/*In the nextCol section you have a if statement that states if c is equal to 8 goto the print section and print the board. The reason for this is 
	bc c is only suppose to go from 0 to 7 and if it goes to 8 that means the code is finished and you don't need to do anything but print so thats
	why it heads to print. Also if the if statement doesn't apply the code goes to the top of the board which is -1 bc if it started at 0 it wouldn't
	check 0 as an option. So thats why you start at -1.*/
	nextRow: 
	r++;
	if(r==8){
		goto backtrack;
	} 
	
	for (int i=0; i<=c; i++){
		if (b[r][i] == 1) {
		goto nextRow; 
	}
	} 
	for (int t=1; (r-t)>=0 && (c-t)>=0; t++){
		if (b[r-t][c-t] == 1){
			goto nextRow;
		}
	} 
	for (int w= 1; (r+w)<8 && (c-w)>=0; w++){
		if (b[r+w][c-w] == 1){
		goto nextRow;  
	}
	} 
	b[r][c]=1; 
	/* After you are at -1 you go through all the columns and thats why you need the r++. THe first for loop is there it checks if there is already
	a 1 in that position and if there is it go back to the nextRow section and does r++ which changes the row nucmber and keeps going until it gets one. 
	The other two for statments are there as checks to see if the queen can be in that postion and that there isn't anyone to her upperleft or lowerleft.
	If there is it changes the row number again and goes back to the first for statement and if it says okat it moves on to the next one and if that says 
	ok it moves on to the last and if that says okay it comes out of the for statements and places a 1 at the postion.  */ 
	goto nextCol; 
	backtrack: 
	c--;
	if(c== -1)return 0;
	r=0;
	while(b[r][c]!=1){
		r++;
	} 
	b[r][c]=0; 
	/*backtacking basically is when the code can't place a 1 in a column so it goes back to the previous column and changes the postion of the 1 and if
	it can't move a 1 anywhere else there it does back even further and keeps doing this until it finds a place where the one can be placed. After taht it 
	goes back to the nextRow section.*/
	goto nextRow; 
	print: 
	static int numSolutions =0;
	cout<<"solution #" << ++numSolutions <<":\n";
	for(int a=0; a<=7 ;a++){
		for (int j=0; j<=7; j++){
			cout << b[a][j];
		}
		cout<<endl;
	} 
	goto backtrack;  
	/*in the print there is a nested for loop so that the picture of the board can be printed and it is numbered. After it prints one it goes back to 
	backtrack and creates another chess board until there are 92 solutions printed out.*/
}

