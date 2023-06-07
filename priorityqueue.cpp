/*
Consider a scenario for Hospital to cater services to different kinds of patients as Serious
(top priority), b) non-serious (medium priority), c) General Checkup (Least priority).
Implement the priority queue to cater services to the patients.    
*/

#include<iostream>
#include<string.h>
using namespace std;

#define N 20
#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

string name[N];
int priority[N];
int f=-1,r=-1;

void  enqueue(string n,int p)
{
    int i;
    if(f==0 && r==(N-1))
    {
        cout<<"Queue is full";
        return;
    }
    else
    {
        if(f==-1)
        {
            f=r=0;
            name[r]=n;
            priority[r]=p;
        }
        else if(r==(N-1))
        {
            for(i=f;i<r;i++)
            {
                name[i-1]=name[i];
                priority[i-f]=priority[i];
                r=r-f;
                f=0;
                for(i=r;i>=f;i--)
                {
                    if(p>priority[i])
                    {
                        name[i+1]=name[i];
                        priority[i+1]=priority[i];
                    }
                    else
                        break;
                        name[i+1]=n;
                        priority[i+1]=p;
                        r++;
                }
            }
        }
        else
        {
            for(i=r;i>=f;i--)
                {
                    if(p>priority[i])
                    {
                        name[i+1]=name[i];
                        priority[i+1]=priority[i];
                    }
                    else
                        break;
                }
                name[i+1]=n;
                priority[i+1]=p;
                r++;
        }
    }
}

void dequeue()
{
    if(f==-1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        cout<<"Deleted Element: "<<name[f]<<endl;
        cout<<"Priority: "<<priority[f]<<endl;
        if(f==r)
            f=r=-1;
        else
            f++;
    }

}
void print()
{
    int i;
    if(f==-1)
    {
        cout<<"Queue is empty.";
        return;
    }
    for(int i = f; i <= r; i++)
    {
        cout<<"Patient: \n"<<name[i];
        switch(priority[i])
        {
            case 1:cout<<"::Priority-'checkup"<<endl;
            break;
            case 5:cout<<"::Priority-'nonserious"<<endl;
            break;
            case 10:cout<<"::Priority-'serious"<<endl;
            break;
            default:
            cout<<"Priority invalid"<<endl;
            break;
        }
    }
}

int main()
{
    string name;
    int opt=0,p;
    while(opt!=4)
    {
        cout<<"\n------Priority Queue--------\n";
    cout<<"\n1.Insert\n2.Display\n3.Delete\n4.Exit";
    cin>>opt;
    switch(opt)
    {
        case 1:
        cout<<"Enter the patients name: ";
        cin>>name;
        cout<<"Enter the patients kind: (1.Checkup 2.Nonserious 3.Serious) ";
        cin>>p;
        switch(p)
        {
            case 1:enqueue(name,CHECKUP);
            break;
            case 2:enqueue(name,NONSERIOUS);
            break;
            case 3:enqueue(name,SERIOUS);
            break;
            default:
            cout<<"Invalid.";
            break;
        }
        break;
        case 2:
        print();
        break;
        case 3:
        dequeue();
        break;
        case 4: 
        cout<<"Exit";
        break;
        default:
        cout<<"Enter valid.";
        break;
    }
    }
    return 0;
}
