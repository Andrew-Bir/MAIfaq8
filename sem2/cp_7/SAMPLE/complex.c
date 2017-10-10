#include <stdio.h>
#include "complex.h" // заголовочный файл для работы с к.ч

typedef struct 
{
    double a,b;
} complex_t;

complex_t add(complex_t x, complex_t y) // ф-ция сложения к.ч.
 {
     complex_t t;
     t.a = x.a + y.a;
     t.b = x.b + y.b; 
     return t;
 }
 
complex_t sub(complex_t x, complex_t y) // ф-ция вычитания к.ч.
 {
     complex_t t;
     t.a = x.a - y.a;
     t.b = x.b - y.b; 
     return t;
 } 
 
 complex_t mul(complex_t x, complex_t y) // ф-ция умножения к.ч.
 {
     complex_t t;
     t.a = x.a * y.a - x.b * y.b;
     t.b = x.a * y.b + x.b * y.a; 
     return t;
 }
 
 complex_t div(complex_t x, complex_t y) // ф-ция деления к.ч.
 {
     complex_t t;
     t.a = (x.a * y.a + x.b * y.b)/(y.a*y.a+y.b*y.b);
     t.b = (x.a * y.b - x.b * y.a)/(y.a*y.a+y.b*y.b); 
     return t;
 }

 
int main()
 {
     double a1,b1,a2,b2;
     printf ("Введите 4 числа: \n");
     while(scanf ("%lf%lf%lf%lf", &a1,&b1,&a2,&b2) == 4) {
     complex_t x = {a1,b1}; // первое к.ч.
     complex_t y = {a2,b2}; // второе к.ч.
     complex_t a = add(x,y); // сумма к.ч.
     complex_t s = sub(x,y); // вычитание к.ч.
     complex_t m = mul(x,y); // умножение к.ч.
     complex_t d = div(x,y); // деление к.ч.
     printf ("a = (%5.2lf, %5.2lfi)\n", a.a, a.b ); // результат суммирования
     printf ("s = (%5.2lf, %5.2lfi)\n", s.a, s.b ); // результат вычитания
     printf ("m = (%5.2lf, %5.2lfi)\n", m.a, m.b ); // результат умножения
     printf ("d = (%5.2lf, %5.2lfi)\n", d.a, d.b ); // результат деления
        return 0;   
     }
     return 0;
 }
Код простой, но может пригодиться какому
