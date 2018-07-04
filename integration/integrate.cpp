#include <iostream>
using namespace std;

typedef double (*FUNC)(double); 


double integrate(FUNC f, double a, double b) {
    double ans=0.0;
    
	for(double x = a;x <= b;x = (x+.0001)){
        ans=ans+(f(x)*.0001);
 }
  
 return ans;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
} 
/*Once we compile this code the main will print out the messages and along side them the integral answer for that line. In order to get the integral we need to create a function that does it so 
thats why I created a function called integral. In the parameters you need to supply the kind of line it is and then you need to x points. In this case the x points are the same for all 3 integrals
which is one and five. Not only do we want to create a integral function but we also need to create functions for the type of line we put inside the integral. Because if you put in line 
it will give you an error since line was never defined. So thats why I made a function called line that took in a double and returns a double. Also created two other fucntions called square and cube which took in
doubles also and returned them as well. The reason i choice doubles is because with doubles you get a more accurate number. Now before i explain the integral function i should talk about the global variable we 
declared which is a typedef. What typedef means is that it is an alias for something else. In this case we created a typed def that is a function and takes in a double and returns a double as well as its ans. Also 
in the newer version of c++ we don't need the pointer next to FUNC. Now in the integral function you are inputing the functions and also 1 and 5. Then you create a local variable to that function that can store the ans 
so once you are done and find the number you can just return that variable. Inside of the integrate function i created a for loop because you need to run through the code alot of time to get the ans for the integral 
and i made x equal to a bc a is the smaller number and plus thats where you begin your creating the boxes to check the integral. Then i set x to be less than and equal to b becasue you want to go up to but not over the 
second number. I made it so that x went up by .0001 so that we could get the most accurate number possible. Then inside the for loop i made the number x go into the function so whatever function we are doing at that
time it would go into that functions function that we create. For example for the line fucntion it would plug in the x inside the line function and return you the x. Then after the function returns you some number 
you multiply it by .0001 and add it to ans which stores all the previous values that you go from runing through that for loop. And once the x reaches the value of b it returns the ans and that is what is sent to 
the main and than printed onto the screen.*/
