//Assignment 4

// Title - Implement a simple text editor application using a doubly linked list to manage the text buffer. 
// Text editor should support the following functionalities:  
// a. Insert text 
// b. Delete text 
// c. Display text 
// d. Search text 
// e. Print text in reverse 

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class text
{
   public:
   string t;
   text *next;
   text *previous;
   text(string t);
};

text::text(string text_t)
{
    t = text_t;
    next = NULL;
    previous = NULL;
}

class text_editor
{
    text *head;
    text *tail;
    public:
    text_editor();
    void insert_text();
    void insert_text_start(string t);
    void insert_text_end(string t);
    void delete_text();
    void delete_text_start();
    void delete_text_end();
    void delete_text_between(string t);
    void display_text();
    void print_text_reverse();
    void search_text();
};

void text_editor::search_text()
{
    if(head==NULL)
    {
        cout<<"Text Editor is Empty!"<<endl;
    }
    else
    {
        string t;
        cout<<"Enter text to Search:";
        cin>>t;

        text *temp = head;
        int pos = 1;

        while(temp!=NULL)
        {
           if(temp->t==t)
           {
              cout<<t<<" found at position "<<pos<<endl;
              return;
           }
           else
           {
              temp = temp->next;
              pos++;
           }
        }

        cout<<"Text not found!"<<endl;
    }
    
}

void text_editor::display_text()
{
    if(head==NULL)
    {
        cout<<"Text Editor is Empty!"<<endl;
    }
    else
    {
        text *temp = head;

        while(temp!=NULL)
        {
           cout<<temp->t<<" ";
           temp = temp->next;
        }
    }
}

void text_editor::print_text_reverse()
{
  if(head==NULL)
  {
     cout<<"Text Editor is Empty!"<<endl;
  }
  else
  {
    text *temp = tail;

    while(temp!=NULL)
    {
        cout<<temp->t<<" ";
        temp = temp->previous;
    }
  }
}

void text_editor::delete_text()
{
  if(head==NULL)
  {
     cout<<"Text Editor is Empty!"<<endl;
  }
  else
  {
    text *temp1 = head;
    text *temp2 = tail;
    string t;
    cout<<"Enter text to delete:";
    cin>>t;

    if(temp1->t==t)
    {
        delete_text_start();
    }
    else if(temp2->t==t)
    {
        delete_text_end();
    }
    else
    {
        delete_text_between(t);
    }
  }
}

void text_editor::delete_text_start()
{
    text *temp = head;

    if(temp->next==NULL)
    {
        head = head->next;
        temp->t = "NULL";
    }
    else
    {
       head = head->next;
       head->previous = NULL;
       temp->next = NULL;
       temp->t = "NULL";
    }

    cout<<"Text Deleted Successfully!"<<endl;
}

void text_editor::delete_text_end()
{
    text *temp = tail;
    tail = tail->previous;
    tail->next = NULL;
    temp->previous = NULL;
    temp->t = "NULL";

    
    cout<<"Text Deleted Successfully!"<<endl;
}

void text_editor::delete_text_between(string t)
{
    text *temp = head;

    while(temp!=NULL)
    {
        if(temp->t==t)
        {
            text *temp1 = temp->previous;
            text *temp2 = temp->next;

            temp1->next = temp2;
            temp2->previous = temp1;
            temp->previous = NULL;
            temp->next = NULL;
            temp->t = "NULL";

            cout<<"Text Deleted Successfully!"<<endl;

            return;
        }
        else
        {
            temp = temp->next;
        }
    }

    cout<<"Text not Found!"<<endl;
}

void text_editor::insert_text()
{
    string t;
    cout<<"Enter text to insert:";
    cin>>t;

    if(head==NULL)
    {
        text *nt = new text(t);
        head = nt;
        tail =nt;

        cout<<"Text Added Successfully!"<<endl;
    }
    else
    {
        int choose;
        cout<<"1.Insert at start\n2.Insert at end"<<endl;
        cout<<"Select Any:";
        cin>>choose;

        switch(choose)
        {
            case 1:
              insert_text_start(t);
              break;
            case 2:
              insert_text_end(t);
              break;
            default:
              cout<<"Invalid Choice!"<<endl;
        }
    }
}

void text_editor::insert_text_start(string t)
{
    text *nt = new text(t);
    head->previous = nt;
    nt->next = head;
    head = nt;

    cout<<"Text Added Successfully!"<<endl;
}

void text_editor::insert_text_end(string t)
{
    text *nt = new text(t);
    tail->next = nt;
    nt->previous = tail;
    tail = nt;

    cout<<"Text Added Successfully!"<<endl;
}

text_editor::text_editor()
{
    head = NULL;
    tail = NULL;
}

int main()
{
    text_editor t;

    int choose;

    do
    {
        cout<<"\n"<<endl;
        cout<<"1.Insert text\n2.Delete text\n3.Display text\n4.Search text\n5.Print text in Reverse\n6.Exit"<<endl;
        cout<<"Select Any:";
        cin>>choose;

        cout<<"\n"<<endl;

        switch(choose)
        {
            case 1:
              t.insert_text();
              break;
            case 2:
              t.delete_text();
              break;
            case 3:
              t.display_text();
              break;
            case 4:
              t.search_text();
              break;
            case 5:
              t.print_text_reverse();
              break;
            case 6:
              break;
            default:
              cout<<"Invalid Choice!"<<endl;
              break;
          
        }

    }while(choose!=6);
         
         
    return 0;
}