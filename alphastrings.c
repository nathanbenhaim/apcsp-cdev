#include <stdio.h>
#include <string.h>



int main()
{

  char AString[] = "abcdefghijklmnopqrstuvwxyz";
  char BString[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
  char CString[52];

  if (strcmp(AString, BString) == 0)
	printf("AString and BString are identical\n");
	else
	printf("The strings arent identical\n");

  for(int i = 0 ; i < 26; i++){

  AString[i] = AString[i] - 32;


}
  if (strcmp(AString, BString) == 0)
        printf("After loop: the string are identical\n");
        else
        printf("After loop: the string are different\n");

  strcat(CString, AString);
  strcat(CString, BString);


  printf("All Caps String: %s\n", AString);
  printf("All Undercase String: %s\n", BString);
  printf("Combined String: %s\n", CString);
}
