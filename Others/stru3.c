include<stdio.h>
#include<string.h>

struct student {
	int roll_no;
	char name[30];
	char department[20];
	char course[20];
	int year;
	};
	void pyear(struct student s[])
	{
		int y,i;
		printf("\nEnter the particular year :");
		scanf("%d",&y);
		printf("Name of the students who joined in the year %d are :\n",y);
		for(i =0;i<2;i++){
		if(s[i].year==y)
		puts(s[i].name);
		}	
	}
	void data(struct student s[])
	{
		int r,i;
		printf("\nEnter the roll no. of the student :");
		scanf("%d",&r);
		for(i =0;i<2;i++){
		if(s[i].roll_no==r)
		{
			printf("Name of the student = ");
			puts(s[i].name);
			printf("Department of the student = ");
			puts(s[i].department);
			printf("Course of the student = ");
			puts(s[i].course);
			printf("Year of joining = %d\n",s[i].year);
			}
			}
			}
	
	int main(){
		struct student s[2];
		int i;
		for(i =0;i<2;i++){
		printf("\nEnter the details for student %d :\n",i+1);
		printf("Enter the roll_no :");
		scanf("%d",&s[i].roll_no);
		
		printf("Enter the name :");
		scanf(" %[^\n]s",s[i].name);
		printf("Enter the department :");
		scanf(" %[^\n]s",s[i].department);
		printf("Enter the course :");
		scanf(" %[^\n]s",s[i].course);
		printf("Enter the year of joining :");
		scanf("%d",&s[i].year);
		}
		pyear(s);
		data(s);
		}

