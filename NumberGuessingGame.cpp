#include <cstdlib> 
#include <ctime>
#include <iostream> 
using namespace std; 

int main() 
{ 
	cout<<"Hey user let's play Number Guessing Game "<<endl;
	cout<<"Please enter 1 to start"<<endl;
	int x;
	cin>>x;
	while(x)
	{
	cout<<"Please enter the lower bound value"<<endl;
	int min,max;
	cin>>min;
	cout<<"Please enter the upper bound value"<<endl;
	cin>>max;
	
	srand(time(0));
	int value=(rand() % (max - min)) + min ;
	cout<<"The random value is generated"<<endl;
	int guess;
	int cnt = 0;
	do
	{
		cout<<"Enter your guess value"<<endl;
		cin>>guess;
		if(guess == value)
		{
			cnt++;
			cout<<"Wohoo!! That's a right guess"<<endl<<"Number of attempts "<<cnt<<endl;
		}
		else if(guess<value)
		{
			cnt++;
			cout<<"That's too small. Try larger than this."<<endl;
		}
		else if(guess>value)
		{
			cnt++;
			cout<<"That's too large. Try smaller than this."<<endl;
		}
	} while (value!=guess);
	cout<<"Please enter 1 to play again or enter 0 to quit"<<endl;
	cin>>x;
	}
	
	return 0; 
} 
