/*
 Сортировка и поиск
 Составить программу на Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в 
 таблице.

 Программа должна вводить значения элементов неупорядоченной таблицы и проверять работу процедуры сортировки 
 в трех случаях:
 1. элементы таблицы с самого начала упорядочены
 2. элементы таблицы расставлены в обратном порядке
 3. элементы таблицы не упорядочены

 В качестве текста для записей таблицы взять — 7) изображение ASCII-графики
 Варианты сортировок — 4) Шейкер-сортировка
 Структура таблицы — 6)
 Тип ключа — Вещественный
 Хранение данных и ключей — Отдельно

 Входные данные
 В первой строке файла находится число M, указывающее количество записей в таблице.
 На следующих M строках расположены пары ключ-значение, разделенные знаком табуляции.
 Далее до конца файла находятся ключи, которые нужно искать в таблице.
------------------------- 
 gcc -Wall -pedantic -ansi -std=c99 -O2 -g cocktail_sort.c -o prog -lm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLEN 100

typedef struct {
    float key;
} key_t;

typedef struct {
    char data[MAXLEN];
} data_t;

int menu();

void printTable(key_t *k, data_t *v, int size);
void binarysearch(key_t*, data_t*, int, float);
void cocktail_sort(key_t*, data_t*, int);
void reverse(key_t*, data_t*, int);
void exchange(key_t*, data_t*, int, int);
void mix(key_t*, data_t*, int);
int wild(int, int);
int is_sorted(key_t*, int);
int match(float, float);

int main(int argc, char *argv[]) {

    FILE *pfile = NULL;
    char *fname;
    size_t cnt = 0;
    float a;
    int action;

    if (argc == 2) {
        fname = argv[1];
    } else {
        printf("Invalid number of parameters\n");
        exit(1);
    }
    //Open the file for reading
    if(!(pfile = fopen(fname, "r"))) {
        printf("Error opening %s for reading. Program terminated.\n", fname);
        exit(1);
    } else printf("File %s open for reading...\n", fname);
    
    if (fscanf(pfile, "%zu", &cnt)!=1) {
        printf("Error! Invalid input format! No number of rows specified. Program terminated.\n");
        exit(1);
    }
    printf("\n%3lu rows:\n\n",cnt);

    key_t keys[cnt];
    data_t str[cnt];

    int i = 0;
    while (i < cnt) {
        if (fscanf(pfile, "%f", &keys[i].key)!=1) {
            printf("Error! Invalid input format key. Program terminated.\n");
            exit(1);
        }
        if (fscanf(pfile, "%100s", str[i].data)!=1) {
            printf("Error! Invalid input format str! Program terminated.\n");
            exit(1);
        }
        i++;
    }
// print то что считали из файла
    printTable(keys, str, cnt);
    printf("\n");

//     binarysearch
    printf("binary search result:\n\n");
    while (fscanf(pfile, "%f", &a)==1) {
        printf("%.2f\t",a);
        binarysearch(keys, str, cnt, a);
    }
    printf("\n");
    fclose(pfile); // Close the file

    do {
        action = menu();
        switch (action) {
            case 1: 
                printTable(keys, str, cnt);
                break;
            case 2:
                if (!is_sorted(keys, cnt)) {
                    cocktail_sort(keys, str, cnt);
                }
                printTable(keys, str, cnt);
                float s_key;
                printf("Enter key: ");
                scanf("%f", &s_key);
                printf("\nBinary search result:\n\n");
                printf("%.2f\t",s_key);
                binarysearch(keys, str, cnt, s_key);
                printf("\n");
                break;
            case 3:
                printTable(keys, str, cnt);
                printf("\nCocktail sort result:\n\n");
                cocktail_sort(keys, str, cnt);
                printTable(keys, str, cnt);
                break;
            case 4:
                printTable(keys, str, cnt);
                printf("\nMix table result:\n\n");
                mix(keys, str, cnt);
                printTable(keys, str, cnt);
                break;
            case 5:
                printTable(keys, str, cnt);
                printf("\nReverse table result:\n\n");
                reverse(keys, str, cnt);
                printTable(keys, str, cnt);
                break;
            case 6: break;
            default:
                printf("Invalide menu action!\n");
                break;
        }
    } while (action != 6);
    return 0;
}
// выводит меню
int menu() {
    int action;
    printf("Program menu:\n");
    printf("1) - Print\n");
    printf("2) - Binary search\n");
    printf("3) - Cocktail_sort\n");
    printf("4) - Mix table\n");
    printf("5) - Reverse\n");
    printf("6) - Exit\n");
    printf("\nSelect action: ");
    scanf("%d",&action);
    return action;
}

// print table
void printTable(key_t *k, data_t *v, int size){
    printf("+-----+--------+------------------------------------------------------------------+\n");
    printf("|  #  |  key   |  Data                                                            |\n");
    printf("+-----+--------+------------------------------------------------------------------+\n\n");
    for (int i = 0; i < size; i++) {
        printf("| %2d  |  %.2f  | %-*s \n",i, k[i].key, (int)((MAXLEN-strlen(v[i].data))/2+strlen(v[i].data)), v[i].data);
    }
    printf("\n+-----+--------+------------------------------------------------------------------+\n");
}

// бинарный поиск по ключу таблицы
void binarysearch(key_t *k, data_t *v, int size, float key) {
    if (!size) printf("Error size!");
    int test = 0;
    int low, high, middle;
    low = 0;
    high = size - 1;
    while (low <= high) {
        middle = (low + high)/2;
        if (key < k[middle].key) {
             high = middle - 1;
        } else if (key > k[middle].key) {
            low = middle + 1;
        } else {
            test = 1;
            break;
        }
    }
    if (test) {
        printf("row: %-3d\t", middle);
        printf("key: %-.2f\t",k[middle].key);
        printf("data: %-*s\n",(int)((MAXLEN-strlen(v[middle].data))/2+strlen(v[middle].data)),v[middle].data);
    } else printf("Not found\n");
}

// Шейкерная сортировка
void cocktail_sort(key_t *k, data_t *v, int size) {
    int flag = 1;  // флаг наличия перемещений
    int left = 0;
    int right = size - 1; // левая и правая границы сортируемой области массива
  // Выполнение цикла пока левая граница не сомкнётся с правой или пока в массиве имеются перемещения
    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i<right; i++) {
            //двигаемся слева направо
            if (k[i].key > k[i+1].key) {
                // если следующий элемент меньше текущего, меняем их местами
                exchange(k, v, i+1, i);
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i>left; i--) {
            //двигаемся справа налево
            if (k[i-1].key > k[i].key) {
                // если предыдущий элемент больше текущего, меняем их местами
                exchange(k, v, i, i-1);
                flag = 1;      // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}

// меняет местами k[a] k[b] и v[a] b v[b]
void exchange(key_t *k, data_t *v, int a, int b) {
    key_t tmpkey_t;
    data_t tmpdata_t;

    tmpkey_t = k[a];
    k[a] = k[b];
    k[b] = tmpkey_t;

    tmpdata_t = v[a];
    v[a] = v[b];
    v[b] = tmpdata_t;
}

// Перемешивание строк таблицы в псевдослучайном порядке
void mix(key_t *k, data_t *v, int size) {
    int i, j;
    srand((size_t)time(0));
    for (int z = 0; z < size; z++) {
        i = wild(0, size-1);
        j = wild(0, size-1);
        exchange(k, v, i, j);
    }
}
// возвращает "очень" случайное число от 0 до size для mix
int wild(int a, int b) {
    return a + rand() % (b - a + 1);
}

// расставляет элементы таблицы в обратном порядке
void reverse(key_t *k, data_t *v, int size) {
    int i, j;
    for (i = 0, j = size-1; i < j; i++, j--) {
        exchange(k, v, i, j);
    }
}

// проверяет отсортирована ли таблица по возрастанию
int is_sorted(key_t *k, int size){ 
    for (int i = 0; i < size; i++) {
        if (!match(k[i].key, k[i + 1].key)) {
            return 0;
        }
    }
    return 1;
}
// сравнивает значения ключей для is_sorted
int match(float k1, float k2) {
    return k2 >= k1;
}

