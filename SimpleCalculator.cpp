// Task 2 

#include<iostream>
using namespace std;
int main()
{
    float a,b;
    int choice;
    int x=1;
    while(x)
    {
        cout<<"Welcome to Simple Calculator!!\n";
        cout<<"Please Enter first Number"<<endl;
        cin>>a;
        cout<<"Please Enter second Number"<<endl;
        cin>>b;
        cout<<"\nSelect the choice you want to perform"<<endl;
        cout<<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n\nEnter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Addition of "<<a<<" and "<<b<<" is "<<a+b<<endl<<endl;
            break;
        case 2:
            cout<<"Subtraction of "<<a<<" and "<<b<<" is "<<a-b<<endl<<endl;
            break;
        case 3:
            cout<<"Multiplication of "<<a<<" and "<<b<<" is "<<a*b<<endl<<endl;
            break;
        case 4:
            if(b!=0)
            cout<<"Division of "<<a<<" and "<<b<<" is "<<a/b<<endl<<endl;
            else
            {
                 cout<<"Undefined! Please enter value other than zero"<<endl<<endl;
                 cin>>b;
                 cout<<"Division of "<<a<<" and "<<b<<" is "<<a/b<<endl<<endl;
            }
            break;        
        }
        cout<<"Enter 1 to perform more such operations. \nTo quit, enter 0"<<endl;
        cin>>x;
    }
    return 0;
}