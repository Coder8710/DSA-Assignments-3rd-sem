//linear queue using linked list
#include<iostream>
using namespace std;

class party
{
   string name;
   party *next;
   public:
   friend class waitlist;
   party(string name);
};

party::party(string name)
{
    this->name = name;
    next = NULL;
}

class waitlist
{
    party *front,*rear;
    int parties,count;
    public:
    waitlist();
    void enqueue_party();
    void seat_party();  //dequeue operation
    void display_waitlist();
};

waitlist::waitlist()
{
    front = NULL;
    rear = NULL;
    parties = 0;
    count = 1;
}

void waitlist::enqueue_party()
{
    string name;

    if(front==NULL && rear==NULL)
    {
        cout<<"Enter name of party:";
        cin>>name;

        party *np = new party(name);
        front = np;
        rear = np;

        parties++;

        cout<<"Party added to Waitlist!"<<endl;
    }
    else if(parties==5)
    {
        cout<<"Waitlist is Full!"<<endl;
    }
    else
    {
        cout<<"Enter name of party:";
        cin>>name;

        party *np = new party(name);
        rear->next = np;
        rear = np;

        parties++;

        cout<<"Party added to Waitlist!"<<endl;
    }
}

void waitlist::seat_party()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Waitlist is already empty!"<<endl;
    }
    else if(front==rear)
    {
        string name = front->name;
        cout<<"Seated Party:"<<name<<endl;

        count++;

        front=rear=NULL;
    }
    else
    {
        string name = front->name;
        cout<<"Seated Party:"<<name<<endl;

        count++;

        front = front->next;
    }
}

void waitlist::display_waitlist()
{
    if(front==NULL &&rear==NULL)
    {
        cout<<"Waitlist is Empty!"<<endl;
    }
    else
    {
    party *temp = front;

    int i = count;

    while(temp!=rear)
    {
        cout<<i<<"."<<temp->name<<endl;
        temp = temp->next;
        i++;
    }

    cout<<i<<"."<<temp->name<<endl;
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