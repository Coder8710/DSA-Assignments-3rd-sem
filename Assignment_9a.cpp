//Linear queue using array
#include<iostream>
using namespace std;

class waitlist
{
   string parties[10];
   int front=-1,rear=-1;
   public:
   void enqueue_party();
   void seat_party();  //dequeue operation
   void display_waitlist();
};

void waitlist::enqueue_party()
{
    string name;

    if(front==-1 &&rear==-1)
    {
        cout<<"Enter name of party:";
        cin>>name;

        front++;
        rear++;
        parties[rear] = name;

        cout<<"Party added to Waitlist!"<<endl;
    }
    else if(rear==9)
    {
        cout<<"Waitlist is Full!"<<endl;
    }
    else
    {
        cout<<"Enter name of party:";
        cin>>name;

        rear++;
        parties[rear] = name;

        cout<<"Party added to Waitlist!"<<endl;
    }
}

void waitlist::seat_party()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Waitlist is already Empty!"<<endl;
    }
    else if(front==rear)
    {
        string name = parties[front];
        cout<<"Seated Party:"<<name<<endl; 
        front=rear=-1;
    }
    else
    {
        string name = parties[front];
        front++;
        cout<<"Seated Party:"<<name<<endl; 
    }
}

void waitlist::display_waitlist()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Waitlist is Empty!"<<endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<i+1<<"."<<parties[i]<<endl;
        }
    }
}
         
int main()
{
    waitlist w; 

    int choose;

  do
  {
     cout<<"\n1.Add Party to Waitlist\n2.Seat Party\n3.Display Waitlist\n4.Exit"<<endl;
     cout<<"Select Any:";
     cin>>choose;

     cout<<"\n";

    switch(choose)
    {
        case 1:
          w.enqueue_party();
          break;
        case 2:
          w.seat_party();
          break;
        case 3:
          w.display_waitlist();
          break;
        case 4:
          break;
        default:
          cout<<"Invalid Choice!"<<endl;
          break;
    }

    }while(choose!=4);
         
    return 0;
}