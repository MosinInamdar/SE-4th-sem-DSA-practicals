/*
Experiment 13 : Represent a given grapg using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
                Use the map of the area around the college as a graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
Adjecency List
*/

#include<iostream>
using namespace std;

#define MAX 10
#define TRUE 1
#define FALSE 0

class ADL
{
    private:
        struct node 
        {
            int vertex;
            struct node *next;
        };
        node *head[MAX];
        int visited[MAX];

    public:
        ADL();
        void create();
        void dfs(int);
};

ADL::ADL()
{
    int v1;
    for(v1=0;v1<MAX;v1++)
        visited[v1]=FALSE;
    for(v1=0; v1<MAX;v1++)
        head[v1]=NULL;
}

void ADL::create()
{
    int v1,v2;
    char ans;
    node *first,*N;
    cout<<"Enter the vertices no. beginning with 0 : ";
    do
    {
        cout<<"\nEnter the Edge of a graph: \n";
        cin>>v1>>v2;
        if(v1>=MAX || v2>=MAX)
        {
            cout<<"Invalid Vertex Value!!\n";
        }
        else{
            //creating link v1 to v2
            N=new node;
            if(N==NULL)
            {
                cout<<"Insufficient Memory!!\n";
            }
            N->vertex = v2 ;
            N->next=NULL;
            first = head[v1];
            if(first == NULL)
                head[v1]=N;
                else{
                    while(first->next != NULL)
                        first = first->next;
                    first->next = N;
                }

                //creating link from v1 to v2

                N = new node;

                if(N==NULL)
                    cout<<"Insufficient Memory!!\n";
                N->vertex =v1;
                N->next=NULL;
                first = head[v2];
                if(first == NULL)
                    head[v2]=N;
                else{
                    while(first->next != NULL)
                        first= first->next;
                    first->next = N;
                }
                
        }
        cout << "\n Want to add more edges?(y/n) : ";
        cin>>ans;
    }while(ans == 'y');
}

//dfs function
void ADL::dfs(int v1)
{
    node *first;
    cout << endl
         << v1;
    visited[v1] = TRUE;
    first = head[v1];
    while (first != NULL)
        if (visited[first->vertex] == FALSE)
            dfs(first->vertex);
        else
            first = first->next;
}

int main()
{
    int v1;
    ADL g;
    
    g.create();
    cout << endl << "Enter the vertex from where you want to traverse : ";
    cin >> v1;
    if (v1 >= MAX)
        cout << "Invalid Vertex!!\n";
    else
    {
        cout << "The Dfs of the graph : ";
        g.dfs(v1);
    }
    
    return 0;
}
