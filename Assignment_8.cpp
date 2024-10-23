//Assignment 8

// Title - Write a program to convert infix expression to postfix, infix expression to prefix and evaluation 
//of postfix and prefix expression. 

//PRN No. - 123B1B181

//Name - Om Sanjay Lokhande

//Class & Div - S.Y.B.Tech & C Division

#include<iostream>
using namespace std;

class prefix_postfix
{
    char stack[100];
    int stack2[100];
    string postfix;
    int top;
    public:
    void push(char ch);
    void push2(int a);
    void pop();
    int pop2();
    void infix_to_prefix();
    void infix_to_postfix();
    void prefix_evaluation();
    void postfix_evaluation();
    bool is_operand(char ch);
    bool stack_is_empty();
    int precedence(char ch);
};

void prefix_postfix::push(char ch)
{
    top++;
    stack[top] = ch;
}

void prefix_postfix::pop()
{
    postfix = postfix + stack[top];
    top--;
}

int prefix_postfix::pop2()
{
    int val = stack2[top];
    top--;
    return val;
}

void prefix_postfix::push2(int a)
{
    top++;
    stack2[top] = a;
}

void prefix_postfix::infix_to_prefix()
{
    top = -1;
    string infix;
    postfix = "";

    cout<<"Enter Infix Expression:";
    cin>>infix;

    //Reversing Infix Expression
    for(int i = 0;i<(infix.length())/2;i++)
    {
         char temp = infix[i];
         infix[i] = infix[infix.length()-1-i];
         infix[infix.length()-1-i] = temp;
    }

    for(int i=0;i<(infix.length());i++)
    {
        if(infix[i]=='(')
        {
            infix[i] = ')';
        }
        else if(infix[i]==')')
        {
            infix[i] = '(';
        }
    }

    for(int i=0;i<(infix.length());i++)
    {
         if(is_operand(infix[i]))
         {
              postfix = postfix + infix[i];
         }
         else if(infix[i] == '(')
         {
             push(infix[i]);
         }
         else if(infix[i] == ')')
         {
            while(stack[top]!='(')
            {
                pop();
            }

            top--;
         }
         else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
         {
            while(!stack_is_empty() && precedence(stack[top])>=precedence(infix[i]) && stack[top]!='(')
            {
                if(infix[i]=='^' && stack[top]=='^')
                {
                    break;
                }
                else
                {
                   pop();
                }
            }

            push(infix[i]);
         }
         else
         {
            cout<<"Wrong infix Expression"<<endl;
            exit(0);
         }
    }

    while(!stack_is_empty())
    {
        pop();
    }

    //Reversing Postfix Expression
    for(int i = 0;i<(postfix.length())/2;i++)
    {
         char temp = postfix[i];
         postfix[i] = postfix[postfix.length()-1-i];
         postfix[postfix.length()-1-i] = temp;
    }

    cout<<"Prefix:"<<postfix<<endl;
}        

void prefix_postfix::infix_to_postfix()
{
    top = -1;
    string infix;
    postfix = "";

    cout<<"Enter Infix Expression:";
    cin>>infix;

    for(int i=0;i<(infix.length());i++)
    {
         if(is_operand(infix[i]))
         {
              postfix = postfix + infix[i];
         }
         else if(infix[i] == '(')
         {
             push(infix[i]);
         }
         else if(infix[i] == ')')
         {
            while(stack[top]!='(')
            {
                pop();
            }

            top--;
         }
         else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
         {
            while(!stack_is_empty() && precedence(stack[top])>=precedence(infix[i]) && stack[top]!='(')
            {
                if(infix[i]=='^' && stack[top]=='^')
                {
                    break;
                }
                else
                {
                   pop();
                }
            }

            push(infix[i]);
         }
         else
         {
            cout<<"Wrong infix Expression"<<endl;
            exit(0);
         }
    }

    while(!stack_is_empty())
    {
        pop();
    }

    cout<<"Postfix:"<<postfix<<endl;
}     

void prefix_postfix::prefix_evaluation()
{
    int a,b;
    string prefix;
    top = -1;
    cout<<"Enter prefix Expression:";
    cin>>prefix;

    //Reversing Prefix Expression
    for(int i = 0;i<(prefix.length())/2;i++)
    {
         char temp = prefix[i];
         prefix[i] = prefix[prefix.length()-1-i];
         prefix[prefix.length()-1-i] = temp;
    }

    for(int i = 0;i<(prefix.length());i++)
    {
        if(prefix[i]>='0' && prefix[i]<='9')
        {
            push2(prefix[i] - '0');
        }
        else if(prefix[i]=='+')
        {
            a = pop2();
            b = pop2();
            push2(a+b);
        }
        else if(prefix[i]=='-')
        {
            a = pop2();
            b = pop2();
            push2(a-b);
        }
        else if(prefix[i]=='*')
        {
            a = pop2();
            b = pop2();
            push2(a*b);
        }
        else if(prefix[i]=='/')
        {
            a = pop2();
            b = pop2();
            push2(a/b);
        }
        else
        {
            cout<<"Wrong Prefix Expression!"<<endl;
            exit(0);
        }
    }

    cout<<"Answer:"<<stack2[top]<<endl;
}

void prefix_postfix::postfix_evaluation()
{
    int a,b;
    string p;
    top = -1;
    cout<<"Enter postfix Expression:";
    cin>>p;

    for(int i = 0;i<(p.length());i++)
    {
        if(p[i]>='0' && p[i]<='9')
        {
            push2(p[i] - '0');
        }
        else if(p[i]=='+')
        {
            a = pop2();
            b = pop2();
            push2(b+a);
        }
        else if(p[i]=='-')
        {
            a = pop2();
            b = pop2();
            push2(b-a);
        }
        else if(p[i]=='*')
        {
            a = pop2();
            b = pop2();
            push2(b*a);
        }
        else if(p[i]=='/')
        {
            a = pop2();
            b = pop2();
            push2(b/a);
        }
        else
        {
            cout<<"Wrong Postfix Expression!"<<endl;
            exit(0);
        }
    }

    cout<<"Answer:"<<stack2[top]<<endl;
}

bool prefix_postfix::is_operand(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return true;
    }
    else if(ch>='A' && ch<='Z')
    {
        return true;
    }
    else if(ch>='0' && ch<='9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool prefix_postfix::stack_is_empty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int prefix_postfix::precedence(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='^')
    {
        return 3;
    }
    else 
    {
        return 0;
    }
}

int main()
{
    string infix;
    int choose;

    prefix_postfix p;

    do
    {
         cout<<"\n1.Infix to Prefix\n2.Infix to Postfix\n3.Prefix Evaluation\n4.Postfix Evaluation\n5.Exit"<<endl;
         cout<<"Select Any:";
         cin>>choose;

         switch(choose)
         {
            case 1:
              p.infix_to_prefix();
              break;
            case 2:
              p.infix_to_postfix();
              break;
            case 3:
              p.prefix_evaluation();
              break;
            case 4:
              p.postfix_evaluation();
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