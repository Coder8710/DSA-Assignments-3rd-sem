//Assignment 7

// Title - Implement a browser history management system using a stack data structure to track the user's 
// browsing history. The system should support the following functionalities: 
// a. Add visited page 
// b. Navigate back 
// c. View current page 
// d. Check if history is empty or not 
// Assume no upper bound on number of pages visited

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class Browser
{
    string websites1[50];
    string websites2[50];
    int top1;
    int top2;
    public:
    Browser();
    void add_page();
    void navigate_back();
    void view_current_page();
    void show_history();
};

Browser::Browser()
{
    top1 = -1;
    top2 = -1;
}

void Browser::add_page()
{
    string website;

    cout<<"Enter Website Name:";
    cin>>website;

    while(top2>=0)
    {
        top1++;
        websites1[top1] = websites2[top2];
        top2--;
    }

    top1++;

    websites1[top1] = website;

    cout<<"Website Added Successfully!\n"<<endl;
}

void Browser::navigate_back()
{
    if(top1==-1)
    {
        cout<<"Browser History is empty!\n"<<endl;
    }
    else if(top1==0)
    {
        cout<<"Cannot Navigate Back!\n"<<endl;
    }
    else
    {
        top2++;
        websites2[top2] = websites1[top1];
        top1--;
        cout<<"Navigated Back Successfully!"<<endl;
        cout<<"Current Website:"<<websites1[top1]<<endl;

        cout<<""<<endl;
    }
}

void Browser::show_history()
{
    int i = 1;

    if(top1==-1)
    {
        cout<<"History is Empty!"<<endl;
    }
    else
    {
        int temp2 = 0;

        while(temp2<=top2)
        {
            cout<<i<<"."<<websites2[temp2]<<endl;
            i++;
            temp2++;
        }

        int temp1 = top1;

        while(temp1!=-1)
        {
            cout<<i<<"."<<websites1[temp1]<<endl;
            i++;
            temp1--;
        }
    }

    cout<<""<<endl;
}

void Browser::view_current_page()
{
    cout<<"Current Website:"<<websites1[top1]<<endl;

    cout<<""<<endl;
}
         
int main()
{
    Browser b;

    int choose;

    do
    {
        cout<<"1.Add Page\n2.Navigate Back\n3.View Current Page\n4.Show History\n5.Exit"<<endl;
        cout<<"Select Any:";
        cin>>choose;

        cout<<"\n"<<endl;

        switch(choose)
        {
            case 1:
              b.add_page();
              break;
            case 2:
              b.navigate_back();
              break;
            case 3:
              b.view_current_page();
              break;
            case 4:
              b.show_history();
              break;
            case 5:
              break;
            default:
              cout<<"Invalid Choice!"<<endl;
              break;
        }

    }while(choose!=5);
         
         
    return 0;
}