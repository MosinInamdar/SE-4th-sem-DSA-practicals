/*
Experiment 5 : C++ Program To read details of a book consists of chapters, chapters consist of sections and sections      
               consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.
*/

#include<iostream>
#include<string.h>
using namespace std;

struct node 
{
    string label;
    int ch_count;
    struct node * child[10];
}*root;

class GT
{
    public:
    void create_tree();
    void display(node *);
    GT()
    {
        root=NULL;
    }
};

void GT::create_tree()
{
    int tbooks,tchapters,i,j,k;
    root=new node;
    cout<<"\n Enter the name of the book : ";
    cin.get();
    getline(cin,root->label);
    cout<<"\n Enter Number of Chapters : ";
    cin>>tchapters;
    root->ch_count = tchapters;
    for(i=0;i<tchapters;i++)
    {
        root->child[i]=new node;
        cout<<"\n Enter the Name of the chapter : ";
        cin.get();
        getline(cin,root->child[i]->label);
        cout<<"\n Enter the sections of the chapter : ";
        cin>>root->child[i]->ch_count;
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"\n Enter the name of the sections :";
            cin.get();
            getline(cin,root->child[i]->child[j]->label);
        }
    }
}

void GT::display(node *r1)
{
    int i,j,k,tchapters;
    while(r1!=NULL)
    {
        cout<<"\n--------BOOK HIERARCHY--------";
        cout<<"\n TITLE : "<<r1->label;
        tchapters=r1->ch_count;
        for(i=0;i<tchapters;i++)
        {
            cout<<"\nChapters"<<i+1;
            cout<<" : "<<r1->child[i]->label;
            cout<<"\nSections : ";
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<"\n"<<r1->child[i]->child[j]->label;
            }
        }
    }
    cout<<endl;
}

int main()
{
    int choice;
    GT gt;
    while(1)
    {
        cout<<"----------------------";
        cout<<"\nBook Tree Creation"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            gt.create_tree();
            break;
            case 2:
            gt.display(root);
            break;
            case 3: 
            cout<<"Thanks for using this program!!!";
            exit(1);
            default:
            cout<<"Wrong choice!!!"<<endl;
        }
    }
    return 0;
}