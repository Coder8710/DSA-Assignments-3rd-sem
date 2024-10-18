//Assignment 1a & 1b

//Title - Consider a student database of SY COMP class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.  
// a. Design a roll call list, arrange list of students according to roll numbers in ascending order 
// using Insertion Sort 
// b. Arrange list of students alphabetically using shell sort 

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class student
{
    string name,branch;
    int roll;
    static int count;

public:
    void getdata(student s[]);
    void insertion_sort(student s[]);
    void shell_sort(student s[]);
    void display(student s[]);
};

int student::count=0;

void student::getdata(student s[])
{
    cout << "\n" << endl;
    int n;
    cout << "Enter total number of students:";
    cin >> n;
    n = n + count;

    for (int i = count; i < n;i++)
    {
        cout << "" << endl;
        cout << "Enter Details of Student " << count + 1 << endl;
        cout<<"Enter Name of Student:";
        cin >> s[i].name;
        cout << "Enter Roll No.:";
        cin >> s[i].roll;
        cout << "Enter Branch:";
        cin >> s[i].branch;
        cout << "" << endl;
        count++;
    }
}

void student::display(student s[])
{
    int n = count;

    for (int i = 0; i < n;i++)
    {
        cout << "" << endl;
        cout << "Details of Student " << i+1 << endl;
        cout<<"Name of Student:"<<s[i].name<<endl;
        cout << "Roll No.:"<<s[i].roll<<endl;
        cout<<"Branch:"<<s[i].branch<<endl;
        cout << "" << endl;
    }
}

//Insertion sort(Roll Number)
void student::insertion_sort(student s[])
{
    int n = count;
    for (int i = 1; i < n;i++)
    {
        int j = i - 1;
        student val = s[i];

        while(j>=0 && s[j].roll>val.roll)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }

     cout << "\nStudent Database has been sorted according to Roll Number" << endl;
}

//Shell sort(Name)
void student::shell_sort(student s[])
{
    int n = count;
    int gap = n/2;

    while(gap>=1)
    {
        for (int j = gap; j < n;j++)
        {
            for (int i = j - gap; i >= 0;i = i - gap)
            {
                if(s[i+gap].name>s[i].name)
                {
                    break;
                }
                else
                {
                    student temp = s[i];
                    s[i] = s[i + gap];
                    s[i + gap] = temp;
                }
            }
        }

        gap = gap / 2;
    }

    cout << "\nStudent Database has been sorted according to Name" << endl;
}

int main()
{
    student s[50],x;

    char ch;
    int choice;

    do
    {
        cout << "1.Take input\n2.Sort using Insertion sort(Roll Number)\n3.Sort using Shell sort(Name)\n4.Display"<<endl;
        cout << "Select Any:";
        cin >> choice;

        switch (choice)
        {
           case 1:
               x.getdata(s);
               break;
           case 2:
               x.insertion_sort(s);
               break;
           case 3:
               x.shell_sort(s);
               break;
           case 4:
               x.display(s);
               break;
           default:
               cout << "Invalid Choice!" << endl;
               break;
        }

        cout << ""<< endl;

        cout << "Do you want to continue(Enter 'y' for yes or 'n' for no):";
        cin >> ch;

        cout << "\n" << endl;

    } while (ch=='y');
    
    return 0;
}