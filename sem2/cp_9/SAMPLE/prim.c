// http://www.cyberforum.ru/c-beginners/thread1984687.html


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

void printTable(const key_t *k, const data_t *v, const int size);
void binarysearch(const key_t*, const data_t*, const int, const float);
void sort(key_t *k, data_t *v, const int size);
void scramble(key_t *k, data_t *v, const int size);
void reverse(key_t *k, data_t *v, const int size);

void getRow(FILE *stream, char *str, const int size);
void swapRows(key_t *k, data_t *v, const int a, const int b);
int comparator(const key_t k1, const key_t k2);
int isEqualkey_ts(const key_t k1, const key_t k2);
int randomAB(const int a, const int b);
int isSorted(const key_t *k, const int size);

int main(int argc, char *argv[]) {

    FILE *pfile = NULL;
    char *fname;
    size_t cnt = 0;
    float a;

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

    //int action;
    //char ch;
    key_t keys[cnt];
    data_t str[cnt];
    
    //key_t_t key_t;
 
    int i = 0;
    
    while (i < cnt) {
        if (fscanf(pfile, "%f", &keys[i].key)!=1) {
            printf("Error! Invalid input format! No number of rows specified. Program terminated.\n");
            exit(1);
        }
        //fscanf(file, "%100s", &ch);
        //getRow(file, values[i].data, sizeof(values[i].data));
        if (fscanf(pfile, "%100s", str[i].data)!=1) {
            printf("Error! Invalid input format! No number of rows specified. Program terminated.\n");
            exit(1);
        }
        i++;
    }
// print то что считали из файла
    printTable(keys, str, cnt);
    printf("\n");

//     binarysearch
    while (fscanf(pfile, "%f", &a)==1) {
        printf("%.2f:\t",a);
        binarysearch(keys, str, cnt, a);
    }
    printf("\n");
    fclose(pfile); // Close the file

    
    /*cnt = i;
    
    do
    {
        printf("Меню\n");
        printf("1) Печать\n");
        printf("2) Двоичный поиск\n");
        printf("3) Сортировка\n");
        printf("4) Перемешивание\n");
        printf("5) Реверс\n");
        printf("6) Выход\n");
        printf("Выберите действие\n");
        scanf("%d", &action);
        
        switch (action)
        {
            case 1:
            {
                printTable(key_ts, values, cnt);
                
                break;
            }
            
            case 2:
            {
                if (!isSorted(key_ts, cnt))
                    printf("Ошибка. Таблица не отсортирована\n");
                else
                {
                    printf("Введите ключ: ");
                    scanf("%s", &key_t.key);
                    
                    i = binSearch(key_ts, values, cnt, key);
                    
                    if (i > -1)
                        printf("Найдена строка: %s\n", values[i].data_t);
                    else
                        printf("Строка с таким ключом не найдена\n");
                }
                
                break;
            }
            
            case 3:
            {
                sort(key_ts, values, cnt);
                
                break;
            }
            
            case 4:
            {
                scramble(key_ts, values, cnt);
                
                break;
            }
            
            case 5:
            {
                reverse(key_ts, values, cnt);
                
                break;
            }
            
            case 6: break;
            
            default:
            {
                printf("Ошибка. Такого пункта меню не существует\n");
                
                break;
            }
        }
    }
    while (action != 6);*/
    
    return 0;
}

void printTable(const key_t *k, const data_t *v, const int size)
{
    int i;
    
    printf("+--------+------------------------------------------------------------------+\n");
    printf("|  Ключ  |  Значение                                                        |\n");
    printf("+--------+------------------------------------------------------------------+\n");
    
    for (i = 0; i < size; i++)
        printf("|  %.2f  | %-*s \n", k[i].key, (int)((MAXLEN-strlen(v[i].data))/2+strlen(v[i].data)), v[i].data);
    
    printf("+--------+------------------------------------------------------------------+\n");
}

void binarysearch(const key_t *k, const data_t *v, const int size, const float key) {
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

void sort(key_t *k, data_t *v, const int size)
{
    /*int i,j,min;//,t;
    int count[size];
    //key_t b1[size];
    //data_t b2[size];
    for (i = 0; i < size; i++)
        count[i] = 0;
    
    for (i=0;i<size-1;i++)
    {
        min=i;      
        for (j=i+1; j<size; j++)
            if (k[j].key<k[min].key)   
                min=j;
            swapRows(k,v,min,i);
    }*/
}


void scramble(key_t *k, data_t *v, const int size)
{
    int i, j, z;
    
    srand((unsigned int)time(0));
    
    for (z = 0; z < size; z++)
    {
        i = randomAB(0, size - 1);
        j = randomAB(0, size - 1);
        
        swapRows(k, v, i, j);
    }
}

void reverse(key_t *k, data_t *v, const int size)
{
    int i, j;
    
    for (i = 0, j = size - 1; i < j; i++, j--)
        swapRows(k, v, i, j);
}

void getRow(FILE *stream, char *str, const int size)
{
    int cnt = 0, ch;
    
    while ((ch = getc(stream)) != '\n' && cnt < size - 1)
        str[cnt++] = ch;
    
    str[cnt] = '\0';
}

void swapRows(key_t *k, data_t *v, const int a, const int b)
{
    key_t tmpkey_t;
    data_t tmpdata_t;
    
    tmpkey_t = k[a];
    k[a] = k[b];
    k[b] = tmpkey_t;
    
    tmpdata_t = v[a];
    v[a] = v[b];
    v[b] = tmpdata_t;
}

int comparator(const key_t k1, const key_t k2)
{
    return k2.key >= k1.key;
}

int isEqualkey_ts(const key_t k1, const key_t k2)
{
    return k1.key == k2.key;
}

int randomAB(const int a, const int b)
{
    return a + rand() % (b - a + 1);
}

int isSorted(const key_t *k, const int size)
{
    int i;
    
    for (i = 0; i < size - 1; i++)
        if (!comparator(k[i], k[i + 1]))
            return 0;
        
        return 1;
}

