#include <stdio.h>
#include <string.h>
#include <math.h>

// student structure
//struct Student...

struct Student {
        char first[50];
        char last[50];
        int age;
        int id;
};


void printStudent(struct Student* student)
{

	printf("---- student ----\n");
        printf("Student: %s %s\n", student->first, student->last);
        printf("Age: %d\n", student->age);
        printf("ID: %d\n", student->id);

}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
//loop that calls all students information

for(int i = 0; i < num; i++){
	printStudent(&students[i]);
}
}


int main()
{

  // an array of students
  //xxxstudents;
 struct Student students[10];

  int numStudents = 0;
  int i = numStudents;
  char input[256];
while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
//create structure for new student



	printf("First name: ");
	fgets(input, 50, stdin);
	sscanf(input, "%s", students[i].first);

        printf("Last name: ");
        fgets(input, 50, stdin);
        sscanf(input, "%s", students[i].last);

        printf("Enter age: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &students[i].age);

        printf("Enter id:");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &students[i].id);


      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
