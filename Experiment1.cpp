/*
Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers 
*/

#include<iostream>
#include<string.h>
using namespace std;
struct data
{  char name[30];
   long teleno;
};
int n,sum,x,c,i,j;   
char na[30]; 
long no;
data d[10];
class hash_table
{  
    
   public:
   hash_table()
   {  for(i=0;i<10;i++)
      {  d[i].teleno=0;   }
   }  
   void insert();
   void search();
   void display();
};
void hash_table::insert()
{
  cout<<"\n enter no. of clients : ";
  cin>>n;    //d[x].name
  for(j=0;j<n;j++)
  {   cout<<"\n enter name of client : ";
      cin>>na;
      cout<<"\n enter telephone no. of client : ";
      cin>>no;
      sum=0;
      for(i=0;i<strlen(na);i++)
      {   sum=sum+na[i]; 
      }
      x=(sum/strlen(na))%10;
      cout<<"X : "<<x;
      c=x;
           while(1)
           {
          
               if(d[x].teleno==0)
               {   strcpy(d[x].name,na);
                   d[x].teleno=no;
                   break;
               }
                x=(x+1)%10;
              if(c==x)
              {  cout<<"\n hash table is full";
                  break;
              }   
           }

   }
}
void hash_table::search()
{  cout<<"\n enter name to be searched : ";
   cin>>na;
  
    sum=0;
      for(i=0;i<strlen(na);i++)
      {   sum=sum+(int)na[i]; 
      }
      x=(sum/strlen(na))%10;
      c=x;
   while(1)
           {
          
               if(!strcmp(d[x].name,na))
               {   cout<<"\n data found : TELEPHONE NO: "<<d[x].teleno;
                   break;
               }
                x=(x+1)%10;
              if(c==x)
              {  cout<<"\n data not found";
                  break;
              }   
           }
}          
void hash_table::display()
{
        for(int i=0;i<10;i++){
        cout<<endl<<d[i].name<<" "<<d[i].teleno;
        }


}
int main()
{
  hash_table h;
  h.insert();
 // h.display();
   h.search();
//   h.display();
  return 0;
}     