person.h:

#ifndef __person_h__
#define __person_h__

typedef struct {
  char name[50];
  int age;
} person;

#endif
persons_dump.c:

#include 
#include 
#include 

#include "person.h"

void usage()
{
  printf("Usage: program filename\n"); 
}

int readperson(person *p)
{
  return scanf("%\t%d\n", p->name, &p->age) == 2;
}

int main(int argc, char* argv[])
{
  if (argc != 2) {
    usage();
    return 1;
  }
  person p;
  FILE *out = fopen(argv[1], "w");
  if (!out) {
    perror("Can't open file");
    return 2;
  } 
  while (readperson(&p))
    fwrite(&p, sizeof(p), 1, out);
  return 0;
}
young_persons.c:

#include 
#include 

#include "person.h"

/*
Программа загружает данные из бинарного файла
и выводит имена и фамилии людей,
возраст которых меньше среднего.
*/

void usage()
{
  printf("Usage: program filename\n");
}

int main(int argc, char* argv[])
{
  if (argc != 2) {
    usage();
    return 1;
  }
  person p;
  FILE *in = fopen(argv[1], "r");
  if (!in) {
    perror("Can't open file");
    return 2;
  }
  int age_sum = 0;
  int n = 0;
  while (fread(&p, sizeof(p), 1, in) == 1) {
    age_sum += p.age;
    ++n;
  }
  fseek(in, 0, SEEK_SET);
  if (n == 0) {
    printf("No people, average age is not defined\n");
    return 3;
  }
  double avg = (double)age_sum / n;
  while (fread(&p, sizeof(p), 1, in) == 1)
    if (p.age < avg)
      printf("%s\n", p.name);
  return 0;
}
