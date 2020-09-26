#include <stdio.h>
#include <math.h>
#include <assert.h>

//Function to calcualte next multiple of two given values
int findNextMultiple(int number1, int number2){
	//TODO
	int next_multiple = number1+number2-number1%number2;
	return next_multiple;
}

//Function to convert Fahrenheit to Celsuius
float convertFtoC(float fahrenheit){
	//TODO
	float C = (fahrenheit-32)/1.8;
	return C;
}

//Function to calculate fibonacci series for first 20 numbers
int fibonacci(){
	//TODO
	int f0=0;
	int fc=0;
	int f1=1;
	for(int i=2;i<20;i++){
	fc=f0+f1;
	f0=f1;
	f1=fc;
	}
	return fc;
}

//Function to cast a long to an int
int castToInt(long num){
	//TODO
	int cast=(int) num;
	return cast;
}

//Function to cast a long to an double
double castToDouble(long num){
	//TODO
	double cast = (double)num;
	return cast;
}

//Function to cast a long to an char
char castToChar(long num){
	//TODO
	char cast = (char)num;
}

//The main driver
int main(){

	//TODO Write code to print "Hello World"
	printf("%s","Hello World");

	//TODO For given value of x calculate value of expression
	printf("\n\t=============================\n");
	printf("\t=           PART A          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Expression Conversion Tests===========\n");
	//Write code to evaluate the following expression: 3x^3 - 5x^2 + 6 for x = 2.5.

	float result = 3*pow(2.5,3)-5*pow(2.5,2)+6; //TODO write your expression here

	assert(result == 21.625);

	//Write code to evaluate the following expression: (4 × 10^8 + 2 × 10^-7) / (7 × 10^-6 + 2 × 10^8)

	result = (4*pow(10,8)+2*pow(10,-7))/(7*pow(10,-6)+2*pow(10,8));//TODO write your expression here

	assert(result == 2.0);

	printf("\n\t\t....Converting Expressions Tests Passed\n");

	printf("\n\t=========Starting Next Multiple Tests===========\n");
	//For given numbers find next multiple
	int number1 = 365, number2 = 7;
	assert(371 == findNextMultiple(number1,number2));

	number1 = 12258; number2 = 28;
	assert(12264 == findNextMultiple(number1,number2));

	number1 = 996; number2 = 4;
	assert(1000 == findNextMultiple(number1,number2));

	printf("\n\t\t....Next Multiple Tests Passed\n");

	printf("\n\t=========Starting Fahrenheit to Celsius Tests===========\n");

	//Convert Fahrenheit value to Celsius value
	float fahrenheit = 95;
	float celsius = convertFtoC(fahrenheit);
	assert(35.0 == celsius);

	fahrenheit = 32;
	celsius = convertFtoC(fahrenheit);
	assert(0.0 == celsius);

	fahrenheit = -40;
	celsius = convertFtoC(fahrenheit);
	assert(-40.0 == celsius);
	printf("\n\t\t....Fahrenheit to Celsius Tests Passed\n");

	printf("\n\t=============================\n");
	printf("\t=           PART B          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Casting Tests===========\n");
	//Testing our Casting and how its loses values for wrong casting
	long int large_num = 9223372036854775617;
	int large_num_as_int = castToInt(large_num);
	assert(-191 == large_num_as_int);
	double large_num_as_double = castToDouble(large_num);
	assert(9223372036854775808.0 == large_num_as_double);
	char large_num_as_char = castToChar(large_num);
	assert('A' == large_num_as_char);

	printf("\n\t\t....Casting Tests Passed\n");

	printf("\n\t=============================\n");
	printf("\t=           PART C          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Fibonacci Tests===========\n");
	//finding fibonacci series for first 20 numbers
	assert(4181 == fibonacci());

	printf("\n\t\t....Fibonacci Tests Passed\n");

	printf("\n\t=========ALL TESTS PASSED===========\n");

	return 0;
}
