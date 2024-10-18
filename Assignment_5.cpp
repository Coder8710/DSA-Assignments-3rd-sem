//Assignment 5

// Title - Implement a navigation system for a delivery service using a circular linked list to represent 
// routes. The navigation system should support the following functionalities: 
// a. Add route 
// b. Remove route 
// c. Display route

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class route
{
   public:
   string path;
   route *next;
   route *previous;
   route(string p);
};

route::route(string p)
{
    next = NULL;
    previous = NULL;
    path = p;
}

class navigation_system
{
    route *head;
    route *tail;
    public:
    navigation_system();
    void add_route();
    void add_route_start(string p);
    void add_route_end(string p);
    void add_route_between(string p);
    void remove_route();
    void remove_route_start();
    void remove_route_end();
    void remove_route_between(string p);
    void display_route();
    void display_route_ascending();
    void display_route_descending();
};

navigation_system::navigation_system()
{
    head = NULL;
    tail = NULL;
}

void navigation_system::add_route()
{
    cout<<""<<endl;

    string p;
    cout<<"Enter Route to add:";
    cin>>p;

  if(head==NULL)
  {
      route *nr = new route(p);
      head = nr;
      tail = nr;
      head->next = head;
      head->previous = head;

      cout<<"Route Added Successfully!"<<endl;
  }
  else
  {
    int choose;
    cout<<"1.Add at Start\n2.Add at End\n3.Add in between"<<endl;
    cout<<"Select Any:";
    cin>>choose;

    switch(choose)
    {
        case 1:
           add_route_start(p);
           break;
        case 2:
            add_route_end(p);
            break;
        case 3:
            add_route_between(p);
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
            break;
    }
  }
}

void navigation_system::add_route_start(string p)
{
    cout<<""<<endl;
    route *nr = new route(p);

    nr->next = head;
    head->previous = nr;
    head = head->previous;
    head->previous = tail;
    tail->next = head;

    cout<<"Route Added Successfully!\n"<<endl;
}

void navigation_system::add_route_end(string p)
{
    cout<<""<<endl;
    route *nr = new route(p);

    tail->next = nr;
    nr->previous = tail;
    tail = tail->next;
    head->previous = tail;
    tail->next = head;

    cout<<"Route Added Successfully!\n"<<endl;
}

void navigation_system::add_route_between(string p)
{
    cout<<""<<endl;

   if(head==tail)
   {
      cout<<"Need Atleast two routes in Navigation Sytem to add in between!\n"<<endl;
   }
   else
   {
    int pos;
    cout<<"Enter Position at which route to be added:";
    cin>>pos;

    route *temp = head;

    int i = 2;

    while(i<pos)
    {
        temp = temp->next;
        i++;
    }

    route *temp2 = temp->next;

    route *nr = new route(p);

    temp->next = nr;
    nr->previous = temp;
    nr->next = temp2;
    temp2->previous = nr;

    cout<<"Route Added Successfully!\n"<<endl;
   }
}

void navigation_system::remove_route()
{
     cout<<""<<endl;

  if(head==NULL)
  {
     cout<<"Routes Not Found! Navigation System is Empty!\n"<<endl;
  }
  else
  {
    string p;
    cout<<"Enter Route to Remove:";
    cin>>p;

    if(p==head->path)
    {
        remove_route_start();
    }
    else if(p==tail->path)
    {
        remove_route_end();
    }
    else
    {
        remove_route_between(p);
    }
  }
}

void navigation_system::remove_route_start()
{
     route *temp = head;

     head = head->next;
     temp->next = NULL;
     temp->path = "NULL";
     temp->previous = NULL;

     head->previous = tail;
     tail->next = head;

     cout<<"Route Removed Successfully!\n"<<endl;
}

void navigation_system::remove_route_end()
{
    route *temp = tail;

    tail = tail->previous;

    temp->previous = NULL;
    temp->path = "NULL";
    temp->next = NULL;

    tail->next = head;
    head->previous = tail;

    cout<<"Route Removed Successfully!\n"<<endl;

}

void navigation_system::remove_route_between(string p)
{
    route *temp = head;

    while(temp->next!=head)
    {
        if(temp->path==p)
        {
            route *temp1 = temp->previous;
            route *temp2 = temp->next;

            temp->next = NULL;
            temp->path = "NULL";
            temp->previous = NULL;

            temp1->next = temp2;
            temp2->previous = temp1;

            cout<<"Route Deleted Successfully!\n"<<endl;

            return;
        }
        else
        {
            temp = temp->next;
        }
    }

    cout<<"Route Not Found!\n"<<endl;
}

void navigation_system::display_route()
{
     cout<<""<<endl;

    if(head==NULL)
    {
        cout<<"Routes Not Found! Navigation System is Empty!\n"<<endl;
    }
    else
    {
        cout<<""<<endl;
        int choose;
        cout<<"1.Display in Ascending Order\n2.Display in Descending Order"<<endl;
        cout<<"Select Any:";
        cin>>choose;

        switch(choose)
        {
            case 1:
               display_route_ascending();
               break;
            case 2:
               display_route_descending();
               break;
            default:
               cout<<"Invalid Choice!"<<endl;
               break;
        }
    }
}

void navigation_system::display_route_ascending()
{
     cout<<""<<endl;

    route *temp = head;

    while(temp->next!=head)
    {
        cout<<temp->path<<"----->";
        temp = temp->next;
    }

    cout<<temp->path;

    cout<<""<<endl;
}

void navigation_system::display_route_descending()
{
     cout<<""<<endl;

    route *temp = tail;

    while(temp->previous!=tail)
    {
        cout<<temp->path<<"----->";
        temp = temp->previous;
    }

    cout<<temp->path;

    cout<<""<<endl;
}
         
int main()
{
    navigation_system n;

    int choose;

    do
    {
        cout<<""<<endl;
        cout<<"1.Add Route\n2.Remove Route\n3.Display Route\n4.Exit"<<endl;
        cout<<"Select Any:";
        cin>>choose;

        switch(choose)
        {
            case 1:
              n.add_route();
              break;
            case 2:
              n.remove_route();
              break;
            case 3:
              n.display_route();
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