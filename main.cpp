#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
  char phone[50];
  char ac[50];
  char password[50];
  float balance;
};

int main()
{
  struct user usr;
  FILE *fp;
  char filename[50], phone[50], pword[50];
  int opt;

  printf("\n What do you want to do?");
  printf("\n\n1. Register an account");
  printf("\n2. Login in an account");

  printf("\n\n Your choise:\t");
  scanf("%d", &opt);

  if (opt == 1)
  {
    system("clear");
    printf("Enter your account nunber:\t");
    scanf("%s", usr.ac);
    printf("\nEnter your phone number:\t");
    scanf("%s", usr.phone);
    printf("\nEnter your new password:\t");
    scanf("%s", usr.password);
    usr.balance = 0;
    strcpy(filename, usr.phone);
    fp = fopen(strcat(filename, ".dat"), "w");
    fwrite(&usr, sizeof(struct user), 1, fp);
    if (fwrite != 0)
    {
      printf("\n\n Account succesfully registered");
    }
    else
    {
      printf("\n\nSomething went wrong please try again");
    }
    fclose(fp);
  }
  if (opt == 2)
  {
    system("clear");
    printf("\nPhone number%:\t");
    scanf("%s", phone);
    printf("Password:\t");
    scanf("%s", pword);
    strcpy(filename, phone);
    fp = fopen(strcat(filename, ".dat"), "r");
    if (fp == NULL)
    {
      printf("\nAccount number not registered");
    }
    else
    {
      fread(&usr, sizeof(struct user), 1, fp);
      fclose(fp);

      if (!strcmp(pword, usr.password))
      {
        printf("\nPassword matched!\n");
      }
      else
      {
        printf("\nInvalid password\n");
      }
    }
  }

  return 0;
}