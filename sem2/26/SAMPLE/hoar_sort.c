 //Описание функции сортировки Хоара
 void Hoar_Sort (int k, int *x) {
     Quick_Sort (0, k-1, x);
 }
 
 void Quick_Sort(int left, int right, int *x){
     int i, j, m, h;
     i = left;
     j = right;
     m = x[(i+j+1)/2];
     do {
         while (x[i] < m) i++;
         while (x[j] > m) j--;
         if (i <= j) {
             Exchange(i,j,x);
             i++;
             j--;
         }
     } while(i <= j);
     if (left < j) 
         Quick_Sort (left, j, x);
     if (i < right) 
         Quick_Sort (i, right, x);
 }
 
 //процедура обмена двух элементов
 void Exchange (int i, int j, int *x){
     int tmp;
     tmp = x[i];
     x[i] = x[j];
     x[j] = tmp;
 }
 
 
 using System;
using System.Collections.Generic;
using System.Linq;
  
static public class Qsort
    {
        public static IEnumerable<T> QuickSort<T>(this IEnumerable<T> list) where T : IComparable<T>
        {
            if (!list.Any())
            {
                return Enumerable.Empty<T>();
            }
            var pivot = list.First();
            var smaller = list.Skip(1).Where(item => item.CompareTo(pivot) <= 0).QuickSort();
            var larger = list.Skip(1).Where(item => item.CompareTo(pivot) > 0).QuickSort();
  
            return smaller.Concat(new[] { pivot }).Concat(larger);
        }
    }
