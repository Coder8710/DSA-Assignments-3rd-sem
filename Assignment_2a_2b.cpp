//Assignment 2a & 2b

//Title - Consider Employee database of PCCOE (at least 20 records). Database contains different fields of 
// every employee like EMP-ID, EMP-Name and EMP-Salary.  
// a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort 
// b. Arrange list of Employee alphabetically using Merge Sort 

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class employee
{
    string name;
    int id;
    float salary;
    public:
    static int count;
    void getdata(employee e[]);
    void quick_sort(employee e[],int f,int l);
    void merge_sort(employee e[],int t,int r);
    void merge(employee e[],int l,int mid,int r);
    void display(employee e[]);
};

int employee::count=0;

void employee::getdata(employee e[])
{
    cout << "\n" << endl;
    int n;
    cout << "Enter total number of employees:";
    cin >> n;
    n = n + count;

    for (int i = count; i < n;i++)
    {
        cout << "" << endl;
        cout << "Enter Details of Employee " << i + 1 << endl;
        cout<<"Enter Name of Employee:";
        cin >> e[i].name;
        cout << "Enter ID.:";
        cin >> e[i].id;
        cout << "Enter Salary:";
        cin >> e[i].salary;
        cout << "" << endl;
        count++;
    }
}

void employee::display(employee e[])
{
    int n = count;

    for (int i = 0; i < n;i++)
    {
        cout << "" << endl;
        cout << "Details of Employee " << i+1 << endl;
        cout<<"Name of Employee:"<<e[i].name<<endl;
        cout << "ID:"<<e[i].id<<endl;
        cout<<"Salary:"<<e[i].salary<<endl;
        cout << "" << endl;
    }
}

void employee::quick_sort(employee e[],int f,int l)
{
    if(f<l)
    {
        int pivot = f;
        int i = f + 1;
        int j = l;

        while(i<j)
        {
            while(e[i].id<e[pivot].id)
            {
                i++;
            }

            while(e[j].id>e[pivot].id)
            {
                j--;
            }

            if(i<j)
            {
                employee temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
            else
            {
                break;
            }
        }

        employee temp = e[j];
        e[j] = e[pivot];
        e[pivot] = temp;

        quick_sort(e,f,j-1);
        quick_sort(e,j+1,l);
    }

}

void employee::merge_sort(employee e[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    else
    {
       int mid=(l+r)/2;
       merge_sort(e,l,mid);// left subarray
       merge_sort(e,mid+1,r);// right subarray
       merge(e,l,mid,r);
    }
}

void employee::merge(employee e[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    employee L[n1],R[n2];

    for(int i=0;i<n1;i++)
    {
       L[i]=e[l+i];
    }

    for(int j=0;j<n2;j++)
    {
       R[j]=e[mid+1+j];
    }

    int x=0; int y=0; int k=l;

    while(x<n1 && y<n2)
    {
       if(L[x].name<=R[y].name)
       {
            e[k]=L[x];
            x++;
       }
       else
       {
            e[k]=R[y];
            y++;
       }
       
       k++;
    }

    while(x<n1)
    {
       e[k]=L[x];
       x++; k++;
    }

    while(y<n2)
    {
      e[k]=R[y];
      y++,k++;
    }

}

int main()
{
    employee e[50],x;

    char ch;
    int choice;

    do
    {
        cout << "1.Take input\n2.Sort according to Employee ID using Quick Sort\n3.Sort according to Employee Name using Merge Sort\n4.Display"<<endl;
        cout << "Select Any:";
        cin >> choice;

        switch (choice)
        {
           case 1:
                x.getdata(e);
                break;
           case 2:
                x.quick_sort(e,0,x.count-1);
                cout<<"\nEmployee Database has been sorted according to Employee ID"<<endl;
                break;
           case 3:
                x.merge_sort(e,0,x.count-1);
                cout<<"\nEmployee Database has been sorted according to Employee Name"<<endl;
                break;
           case 4:
               x.display(e);
               break;
           default:
               cout<<"Invalid Choice!";
               break;
        }

        cout << ""<< endl;

        cout << "Do you want to continue(Enter 'y' for yes or 'n' for no):";
        cin >> ch;

        cout << "\n" << endl;

    } while (ch=='y');
    
    return 0;
}