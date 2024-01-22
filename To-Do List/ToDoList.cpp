// Task 4 DEC batch A24

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist
{
    int id;
    string task;
};
int ID;

void banner()
{
    cout<<"_______________________________"<<endl;
    cout<<"         My To-Do List         "<<endl;
    cout<<"_______________________________"<<endl;

}

void addTask()
{
    system("cls");
    banner();
    todolist todo;
    cout<<"Enter new task\n";
    cin.get();
    getline(cin,todo.task);
    char sve;
    cout<<"Do you want to save?\n(y/n)"<<endl;
    cin>>sve;
    if(sve=='y')
    {
        ID++;
        ofstream fout;
        fout.open("todo.txt",ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;

        system("cls");
        cout<<"Added successfully!!"<<endl;
        return ;
        
    }
    system("cls");
}


void showTask()
{
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"Task : "<<endl;
    while (!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task!="")
        {
            cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
        }
        else
        {
            cout<<"\tEmpty!"<<endl;
        }
    }
    fin.close();
    char exit;
    cout<<"Do You want to exit?\n(y/n) : ";
    cin>>exit;
    if(exit!='y')
    {
        showTask();
    }
    system("cls");
} 

int searchTask()
{
    system("cls");
    banner();
    int id;
    cout<<"Enter task id : ";
    cin>>id;
    todolist todo;
    ifstream fin("todo.txt");
    while (!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id==id)
        {
            system("cls");
            cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
            return id;
        }
    }
    system("cls");
    cout<<"Not Found\n";
    return 0;
}

void deleteTask()
{
  system("cls");
  int id=searchTask();  
  if(id!=0)
  {
    char del;
    cout<<"\nDelete?\n(y/n) :  ";
    cin>>del;
    if(del=='y')
    {
        todolist todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream fin;
        fin.open("todo.txt");
        int index=1;
        while (!fin.eof())
        {
            fin>>todo.id;
            fin.ignore();
            getline(fin,todo.task);
            if(todo.id!=id)
            {
                tempFile<<"\n"<<index;
                tempFile<<"\n"<<todo.task;
                index++;
                ID--;
            }
        }
        fin.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt","todo.txt");
        system("cls");
        cout<<"Task is deleted successfully!!"<<endl;
    }
    else
    {
        system("cls");
        cout<<"Not Deleted!!"<<endl;
    }
  }
}

void updateTask()
{
    system("cls");
    int id = searchTask();
    if (id != 0)
    {
        todolist todo;
        ifstream fin("todo.txt");
        ofstream tempFile;
        tempFile.open("temp.txt");
        int index = 1;

        while (!fin.eof())
        {
            fin >> todo.id;
            fin.ignore();
            getline(fin, todo.task);

            if (todo.id == id)
            {
                cout << "Enter the updated task description:\n";
                cin.ignore(); 
                getline(cin, todo.task);
            }

            tempFile << "\n" << index;
            tempFile << "\n" << todo.task;
            index++;
        }

        fin.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        system("cls");
        cout << "Task updated successfully!!" << endl;
    }
    else
    {
        system("cls");
        cout << "Not Updated!!" << endl;
    }
}


int main()
{
    while(1)
    {
        banner();
        cout<<" \n1. Add task";
        cout<<" \n2. Show task";
        cout<<" \n3. Search task";
        cout<<" \n4. Delete task";
        cout<<" \n5. Update task";
        cout<<" \n6. Exit ";

        int ch;
        cout<<"\nEnter your choice :  ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            addTask();
            break;
        case 2:
            showTask();
            break;
        case 3:
            searchTask();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            updateTask();
            break;    
        }

    }
    return 0;
}
