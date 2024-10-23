//Assignment 9b

// Title -  Implement a checkout system for a supermarket to efficiently manage customer queues during 
//peak hours. The system should support the following operations using a circular queue data 
//structure: 
//a. Customer arrival 
//b. Customer checkout 
//c. Close Checkout Counter 
//d. View customer  

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class customer
{
    string name;
    customer *next;
    public:
    customer(string val);
    friend class queue;
};

customer::customer(string val)
{
    name = val;
    next = NULL;
}

class queue
{
   customer *front,*rear,*head;
   int count;
   public:
   queue();
   void enqueue_customer();  //Add customer to queue
   void dequeue_customer();  //Delete customer from queue
   void view_customers();  //Display customers
   void close_checkout_counter(); //Close checkout counter
};

queue::queue()
{
    front = rear = head = NULL;
    count = 0;
}

void queue::enqueue_customer()
{
    string name;

    if(front==NULL && rear==NULL)
    {
        cout<<"Enter Name of Customer:";
        cin>>name;

        customer *nc = new customer(name);

        front = rear = head = nc;
        rear->next = head;

        cout<<"Customer Added Successfully!"<<endl;

        count++;
    }
    else if(count==5)
    {
        if(rear->next==front)
        {
            cout<<"Queue is Full!"<<endl;
        }
        else
        {
            cout<<"Enter Name of Customer:";
            cin>>name;

             rear = rear->next;
             rear->name = name;

              cout<<"Customer Added Successfully!"<<endl;
        }
    }
    else
    {
        cout<<"Enter Name of Customer:";
        cin>>name;

        customer *nc = new customer(name);

        rear->next = nc;

        rear = nc;

        rear->next = head;

         cout<<"Customer Added Successfully!"<<endl;

        count++;
    }
}

void queue::dequeue_customer()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is already Empty!"<<endl;
    }
    else if(front==rear)
    {
        front = rear = NULL;

        cout<<"Customer Checkout Successfull!"<<endl;
    }
    else
    {
        cout<<"Deleted data:"<<front->name<<endl;
        front = front->next;

        
        cout<<"Customer Checkout Successfull!"<<endl;
    }
}

void queue::view_customers()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is Empty!"<<endl;
    }
    else
    {
        customer *temp = front;

        while(temp!=rear)
        {
            cout<<temp->name<<endl;
            temp = temp->next;
        }

        cout<<temp->name<<endl;
    }
}

void queue::close_checkout_counter()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is already empty!"<<endl;
    }
    else
    {
        front = rear = NULL;
        cout<<"Checkout counter closed!"<<endl;
    }
}
         
int main()
{
    queue q;
    int choose;

    do
    {
        cout<<"\n1.Customer arrival\n2.Customer Checkout\n3.Close Checkout Counter\n4.View Customer\n5.Exit"<<endl;
        cout<<"Select Any:";
        cin>>choose;

        cout<<"\n";

        switch(choose)
        {
            case 1:
              q.enqueue_customer();
              break;
            case 2:
              q.dequeue_customer();
              break;
            case 3:
              q.close_checkout_counter();
              break;
            case 4:
              q.view_customers();
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