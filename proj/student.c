//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

//(Need to dynamically create a student on the heap)
  Student* st = (Student*)malloc(sizeof(Student));
  st->firstName = (char*)malloc(strlen(fname)+1);
  st->lastName = (char*)malloc(strlen(lname)+1);
  strcpy(st->firstName, fname);
  strcpy(st->lastName, lname);
  st->age = age;
  st->id = id;
  students[numStudents] = st;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting the pointer
  // values to 0 and adjusting the numStudents to 0
  for (int i = 0; i < numStudents; i++)
  {

        deleteStudent(students[i]);
        students[i]=0;

  }
  numStudents=0;
}

char* FILE_NAME = "studentdata.txt";
void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234
  //       james dean 21 2345
  //       katy jones 18 4532


FILE* fp;
  char buff[256];

  fp = fopen(FILE_NAME, "w");
  if (fp)
 {
    for (int i = 0; i < numStudents; i++)
  {
      // copy the data into a string first, might be useful if you
      // want to do something to the string before saving it to the file...
      sprintf(buff, "%s %s %d %ld\n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
        printf("%s\n", buff);
        if(key != 0)
        caesarEncrypt(buff, key);

        fprintf(fp, "%s\n", buff);
        }
    fclose(fp);
  }
}



void loadStudents(int key)
{
  if (numStudents > 0){
    deleteStudents();
  }

  FILE* fp;
  fp = fopen("studentdata.txt", "r");
  if (fp)
  {

    while(1){
      char b1[256]; char b2[256]; char b3[256]; char b4[256]; 
      int match = fscanf(fp, "%s %s %s %s", b1, b2, b3, b4);
      if(match == 4){
        if (key != 0){
          caesarDecrypt(b1, key);
          caesarDecrypt(b2, key);
          caesarDecrypt(b3, key);
          caesarDecrypt(b4, key);
        }
        int age;
        long id;
        sscanf(b3, "%d", &age);
        sscanf(b4, "%ld", &id);
        createStudent(b1, b2, age, id);
      }
      else
        break;
    }
     printf("loaded %d students", numStudents);
     fclose(fp);
  }
}

void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++)
 {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
 }
}

