#include<stdio.h>
#include<string.h>
struct Car
{
    int carID,rate;
    char model[30];
};
int main()
{
  int n,i,days,c;
  printf("Enter no. of cars : ");
  scanf("%d",&n);
  struct Car s[n];
  for(i = 0; i<n; i++)
  {
    printf("Enter details for car with car ID %d:",i+1);
    s[i].carID = i+1;
    printf("\n");
    printf(" Enter model name of the car : ");
    scanf(" %s",s[i].model);
    printf(" Rental rate of the car per day : ");
    scanf("%d",&s[i].rate);
  }
  printf("Enter no. of days for which the car is to be rented : ");
  scanf("%d",&days);
  printf("\n");
  for(i = 0; i<n; i++){
  printf(" Total rental of %s car with car ID %d for %d days = %d",s[i].model,i+1,days,s[i].rate*days);
  printf("\n");
  }
  printf("Enter the car id to be booked or press 0 if u dont to continue");
  scanf("%d",&c);
  for(i = 0; i<n; i++){3
    if(c==0)
        return 0;
    if(c==s[i].carID)
        printf("Total amount is %d and car model %s is booked",s[i].rate*days,s[i].m);
  }
  printf("\n"); 
  return 0;
}
