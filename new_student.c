#include <stdio.h>

#define Length 64

int main(int argc, char const *argv[])
{

  char first_name[Length];
  char last_name[Length];
  int age;

  printf("Firstname: ");
  scanf("%s",first_name);

  printf("Lastname: ");
  scanf("%s",last_name);

  printf("Age: ");
  scanf("%d",&age);
  printf("Stored successfully");

  FILE* fd = fopen("students.dat", "r+");
  int id;

  fseek(fd, 0,SEEK_SET);
  fread(&id, sizeof(int), 1, fd);

  fseek(fd, 0, SEEK_END);
  fwrite(&id, sizeof(id), 1, fd);
  fwrite(first_name, sizeof(first_name), 1, fd);
  fwrite(last_name, sizeof(last_name), 1, fd);
  fwrite(&age, sizeof(age), 1, fd);
  fseek(fd, 0, SEEK_SET);
  id++;
  fwrite(&id, sizeof(int), 1, fd);
  fclose(fd);

  return 0;

}
