#include <stdio.h>
#include <math.h>
#include <string.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

  float product;
  float total;

float areaOfCircle(float radius){
  float area = radius * radius * M_PI;
  return area;

}


int main(int argc, char* argv[]){


// first check to see if two args (3 including program name) were entered 
  if (argc != 3)
  {
    printf("%s : expected 2 args, please enter two integers\n", argv[0]);

	int input[256], start[256], end[256];

	printf("input lower: \n");
	fgets(input, 256, stdin);
	sscanf(input, "%d", start);

        printf("input higher: \n");
        fgets(input, 256, stdin);
        sscanf(input, "%d", end);


  }
  // at this point we know we have two args, let's check that they are ints
  float start;
  // ssscanf scans a string for a format - in this case an integer (%d) and returns
  // the number of items found
  float found = sscanf(argv[1], "%f", &start);
  if (found != 1)
  {
    printf("first arg is not an integer, enter two ints\n");
    return 1;
  }

  float end;
  found = sscanf(argv[2], "%f", &end);
  if (found != 1)
  {
    printf("second arg is not an integer, enter two ints\n");
    return 1;
  }

  if (start > end)
  {
    printf("Only positive integers accepted");
  }




  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2

  int reps = 3;




  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  printf("calculating area of circle starting at %f, and ending at %f\n", start, end);

  // add your code below to call areaOfCircle function with values between
  // start and end
  float area;

for (float i = start; i <= end; i++){
 float area = areaOfCircle(i);

printf("area of circle with radius of %f is %f\n", i, area);

}}
