#include<stdio.h>
struct employee
   {
      char name[50],designation;
      int id;
      float salary;
   };
  
int main()
{
   int i,n,index=0;
   scanf("%d",&n);
   struct employee s[n];
      for(i=0;i<n;i++)
         {
            getchar();
             scanf("%s",s[i].name);
               getchar();
             scanf("%s",&s[i].designation);
             scanf("%d",&s[i].id);
             scanf("%f",&s[i].salary);
            
         }
         for(i=0;i<n;i++)
         {
          if(s[i].salary>80000)
          {
            index=i;
          }
           printf("%s",s[index].name);
         printf("%c",s[index].designation);
         printf("%d",s[index].id);
         printf("%f",s[index].salary);
          
         }
         
  }
  