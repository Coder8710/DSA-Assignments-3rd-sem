//Assignment 3

// Title - Consider the playlist in a music player. Implement a playlist feature in music player application 
// using singly linked list. Each song in the playlist is represented as a node in the linked list. Each 
// node contains information about the song (such as title or artist or duration, etc.).  
// The playlist should allow users to:  
// a. Add songs 
// b. Remove songs 
// c. Display the entire playlist 
// d. Play specific songs 

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class song  //Node
{
    public:
    string title,artist;
    int duration;
    song *next;
    song(string t,string a,int d);
};

song::song(string t,string a,int d)
{
    title = t;
    artist = a;
    duration = d;
    next = NULL;
}

class playlist  //Linked List
{
   song *head;
   song *tail;
   int songs;
   public:
   playlist();
   void add_song();
   void display_playlist();
   void play_song();
   void delete_song();
};

playlist::playlist()
{
   head = NULL;
   songs = 0;
}

void playlist::add_song()
{
   string title,artist;
   int duration;

   cout<<"Enter Details of Song"<<endl;
   cout<<"Enter Song Title:";
   cin>>title;
   cout<<"Enter Song Artist:";
   cin>>artist;
   cout<<"Enter Song Duration(In Seconds):";
   cin>>duration;

   song *ns = new song(title,artist,duration);

   if(head==NULL)
   {
      head= ns;
      tail = ns;
   }
   else
   {
      ns->next = head;
      head = ns;
   }
}

void playlist::display_playlist()
{
    if(head==NULL)
    {
        cout<<"Your Playlist is empty!\n"<<endl;
    }
    else
    {
        song *temp = head;
        int count = 1;

        while(temp->next!=NULL)
        {
            cout<<"Song "<<count<<endl;
            cout<<"Song Title:"<<temp->title<<endl;
            cout<<"Song Artist:"<<temp->artist<<endl;
            cout<<"Song Duration:"<<temp->duration<<" seconds"<<endl;
            cout<<""<<endl;
            temp = temp->next;
            count++;
        }

        cout<<"Song "<<count<<endl;
        cout<<"Song Title:"<<temp->title<<endl;
        cout<<"Song Artist:"<<temp->artist<<endl;
        cout<<"Song Duration:"<<temp->duration<<" seconds"<<endl;
        cout<<""<<endl;

    }
}

void playlist::play_song()
{
    string title;
    song *temp = head;

  if(head!=NULL)
  {
    cout<<"Enter Song Title to Play:";
    cin>>title;

    while(temp->next!=NULL)
    {
       if(temp->title==title)
       {
          cout<<"Playing Song "<<title<<"\n"<<endl;
          return;
       }
       else
       {
          temp = temp->next;
       }
    }

    if(temp->title==title)
    {
        cout<<"Playing Song "<<title<<"\n"<<endl;
        return;
    }
    else
    {
        cout<<"Song not found in your Playlist!"<<endl;
    }
  }
  else
  {
    cout<<"Your Playlist is empty!\n"<<endl;
  }
}

void playlist::delete_song()
{
    if(head==NULL)
    {
       cout<<"Your Playlist is empty!\n"<<endl;
    }
    else
    {
       string title;
       cout<<"Enter Song Title:";
       cin>>title;

       if(head->title==title)  //Deleting Start Node
       {
          song *temp = head;
          head = head->next;
          temp->next = NULL;

          cout<<"Song Deleted Successfully!\n"<<endl;

       }
       else if(tail->title==title)  //Deleting End Node
       {
          song *temp = head;

          while(temp->next!=tail)
          {
            temp = temp->next;
          }

          temp->next = NULL;

          cout<<"Song Deleted Successfully!\n"<<endl;

       }  //Deleting node in between
       else
       {

          song *temp1 = head;
          song *temp2 = head;

          while(temp1->title!=title)
          {
             temp1 = temp1->next;
          }

          while(temp2->next!=temp1)
          {
             temp2 = temp2->next;
          }

          temp1 = temp1->next;
          temp2->next = temp1;
       
          cout<<"Song Deleted Successfully!\n"<<endl;

       }
    }
}
         
int main()
{
    playlist p;

    int choose;

    do
    {
       cout<<"1.Add Song\n2.Display Entire Playlist\n3.Play Song\n4.Delete Song\n5.Exit"<<endl;
       cout<<"Select Any:";
       cin>>choose;

       cout<<""<<endl;

       switch (choose)
       {
          case 1:
            p.add_song();
            cout<<""<<endl;
            break;
          case 2:
            p.display_playlist();
            break;
          case 3:
            p.play_song();
            break;
          case 4:
            p.delete_song();
            break;
          case 5:
            break;
          default:
            cout<<"Invalid Choice!"<<endl;
            break;
       }

    } while (choose!=5);
            
    return 0;
}