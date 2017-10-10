#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUF_LEN 64
#define SEP "----------------------------------------------------------------------"
 
typedef struct MOVE {
    char title[BUF_LEN];
    char director[BUF_LEN];
    int year;
    double cost;
    double income;
} move_t;
 
/* возвращает индекс в массиве или size, если не найдено */
size_t searchByTitle(const char *title, const move_t *arr, size_t size){
    size_t i;
    for ( i = 0; i < size && strcmp(title, arr[i].title); ++i )
        ;
    return i;
}
 
size_t searchByCostRange(double low, double high, const move_t *arr, size_t size){
    size_t i;
    for ( i = 0; i < size && ( arr[i].cost < low || arr[i].cost > high ); ++i )
        ;
    return i;
}
 
/* функция для сортировки */
int cmpByIncome(const void *a, const void *b){
    double delta = (*(move_t*)a).income - (*(move_t*)b).income;
    if ( delta < 0.0 )
        return -1;
    else if ( delta > 0.0 )
        return 1;
    else
        return 0;
}
 
void prnArray(const move_t *arr, size_t size){
    size_t i;
    printf("\n%s\nTITLE               DIRECTOR            YEAR  COST  INCOME\n%s\n", SEP, SEP);
    for ( i = 0; i < size; ++i )
        printf("%-20s%-20s%-6d%-6.1f%-8.1f\n", arr[i].title, arr[i].director, arr[i].year, arr[i].cost, arr[i].income);
    printf("%s\n", SEP);
}
 
int menuMsg(){
    int ret;
    printf("\nChoice one:\n1 - Show all\n2 - Find by title\n3 - Find by cost range\n4 - Sort by income\n0 - exit\n> ");
    if ( scanf("%d%*c", &ret) != 1 )
        return -1;
    return ret;
}
 
#define SIZE 7
int main(void){
    move_t arr[SIZE] = {
        {"Avatar", "James Kemeron", 2010, 600.0, 7000000.0},
        {"Titanik", "James Kemeron", 1997, 500.0, 5500000.0},
        {"Edje of Darkness", "Martin Campbell", 2010, 200.0, 1200000.0},
        {"Peacoc", "Mikl Lander", 2010, 350.0, 800000.0},
        {"Casino Royale", "Martin Campbell", 2006, 700.0, 5000000.0},
        {"Halloween", "Rom Zombi", 2007, 125.0, 1000000.0},
        {"The Others", "Alejandro Amenabar", 2001, 660.0, 1250000.0}
    };
    int menu, found;
    char buf[BUF_LEN], *p;
    double lr, hr;
    
    while ( 1 ){
        menu = menuMsg();
        switch ( menu ){
            case 1 :
                prnArray(arr, SIZE);
                break;
            case 2 : 
                printf("Title: ");
                if ( !fgets(buf, BUF_LEN, stdin) )
                    exit(1);
                if ( p = strrchr(buf, '\n') )
                    *p = '\0';
                if ( !*buf )
                    break;
                if ( ( found = searchByTitle(buf, arr, SIZE) ) == SIZE )
                    printf("***Not found!\n");
                else
                    prnArray(&arr[found], 1);
                break;
            case 3 :
                printf("Low range: ");
                if ( scanf("%lf", &lr) != 1 )
                    exit(1);
                printf("High range: ");
                if ( scanf("%lf%*c", &hr) != 1 )
                    exit(1);
                found = searchByCostRange(lr, hr, arr, SIZE);
                while ( found < SIZE ){
                    prnArray(&arr[found], 1);
                    if ( ++found == SIZE )
                        break;
                    found += searchByCostRange(lr, hr, arr + found, SIZE - found);
                }
                break;
            case 4 :
                qsort(arr, SIZE, sizeof(move_t), cmpByIncome);
                prnArray(arr, SIZE);
                break;
            case 0 :
                exit(0);
            default :
                printf("Wrong menu index!\n");
        }
    }
    exit(0);
}
