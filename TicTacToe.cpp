// Task 4 DEC batch A24

#include<iostream>
using namespace std;
string brd[9]={ " "," "," "," "," "," "," "," "," "};
int ply=1;
int pos=0;


void intro()
{
    cout<<"\n\nLets begin\n"<<endl;
    cout<<"\n\nPlayer 1 - X\nPlayer 2 - O"<<endl;
    cout<<"\n\n";
    cout<<"     |     |     "<<endl;
    cout<<"  1  |  2  |  3  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  4  |  5  |  6  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  7  |  8  |  9  "<<endl;
    cout<<"     |     |     "<<endl<<endl;

}

bool Winner1()
{
    bool winr=0;
    if (brd[0]==brd[1] && brd[1]==brd[2] && brd[0]=="X" && brd[0]!=" ")
    {
        winr=1;
    }
    else if(brd[3]==brd[4] && brd[4]==brd[5] && brd[3]=="X" && brd[3]!=" ")
    {
        winr=1;
    }
    else if(brd[6]==brd[7] && brd[7]==brd[8] && brd[6]=="X" && brd[6]!=" ")
    {
        winr=1;
    }
    

    else if(brd[0]==brd[3] && brd[3]==brd[6] && brd[0]=="X" && brd[0]!=" ")
    {
        winr=1;
    }
    else if(brd[1]==brd[4] && brd[4]==brd[7] && brd[1]=="X" && brd[1]!=" ")
    {
        winr=1;
    }
    else if(brd[2]==brd[5] && brd[5]==brd[8] && brd[2]=="X" && brd[2]!=" ")
    {
        winr=1;
    }
    
    
    else if(brd[0]==brd[4] && brd[4]==brd[8] && brd[0]=="X" && brd[0]!=" ")
    {
        winr=1;
    }
     else if(brd[2]==brd[4] && brd[4]==brd[6] && brd[2]=="X" && brd[2]!=" ")
    {
        winr=1;
    }
    return winr;
}

bool Winner2()
{
    bool winr=0;
    if (brd[0]==brd[1] && brd[1]==brd[2] && brd[0]=="O" && brd[0]!=" ")
    {
        winr=1;
    }
    else if(brd[3]==brd[4] && brd[4]==brd[5] && brd[3]=="O" && brd[3]!=" ")
    {
        winr=1;
    }
    else if(brd[6]==brd[7] && brd[7]==brd[8] && brd[6]=="O" && brd[6]!=" ")
    {
        winr=1;
    }
    

    else if(brd[0]==brd[3] && brd[3]==brd[6] && brd[0]=="O" && brd[0]!=" ")
    {
        winr=1;
    }
    else if(brd[1]==brd[4] && brd[4]==brd[7] && brd[1]=="O" && brd[1]!=" ")
    {
        winr=1;
    }
    else if(brd[2]==brd[5] && brd[5]==brd[8] && brd[2]=="O" && brd[2]!=" ")
    {
        winr=1;
    }
    
    
    else if(brd[0]==brd[4] && brd[4]==brd[8] && brd[0]=="O" && brd[0]!=" ")
    {
        winr=1;
    }
     else if(brd[2]==brd[4] && brd[4]==brd[6] && brd[2]=="O" && brd[2]!=" ")
    {
        winr=1;
    }
    return winr;
}




bool isFilled()
{
    bool fill=1;
    for(int i=0;i<9;i++)
    {
        if(brd[i]==" ")
        {
            fill=0;
        }
    }
    return fill;
}

void draw()
{
    cout<<"\n\n";
    cout<<"     |     |     "<<endl;
    cout<<"  "<<brd[0]<<"  |  "<<brd[1]<<"  |  "<<brd[2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<brd[3]<<"  |  "<<brd[4]<<"  |  "<<brd[5]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<brd[6]<<"  |  "<<brd[7]<<"  |  "<<brd[8]<<"  "<<endl;
    cout<<"     |     |     "<<endl<<endl;
}

void setPos()
{
    cout<<"Player "<<ply<<" Enter 1-9 - ";
    while(!(cin>>pos))
    {
        cout<<"Please enter valid position\n";
        cin.clear();
        cin.ignore();
    }
    while(brd[pos-1]!=" ")
    {
        cout<<"The position is filled\n";
        cout<<"Player "<<ply<<"'s turn : "<<endl;
        cin>>pos;
        cout<<endl;
    }

}

void update()
{
    if(ply%2==1)
    {
        brd[pos-1]="X";
    }
    else
    {
        brd[pos-1]="O";
    }
}

void switchPlayer()      
{

    if(ply==1)
    {
        ply++;
    }
    else
    {
        ply--;
    }
}

void turn()
{
    while(!Winner1() &&!Winner2() && !isFilled())
    {
        setPos();
        update();
        switchPlayer();
        draw();
    }
}

void endGme()
{
    if(Winner1())
    {
        cout<<"Player 1 is winner!!"<<endl;
    }
    else if(Winner2())
    {
        cout<<"Player 2 is winner!!"<<endl;
    }
    else if(isFilled())
    {
        cout<<"There is a tie!!"<<endl;
    }
}
int main()
{
    intro();
    turn();
    endGme();
    
    return 0;
}