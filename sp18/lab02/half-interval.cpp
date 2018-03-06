//  half-interval.cpp 2018
/*
(define(fun z)
  (set! z (- z (/ 11 12)(/ e)))
  (- (expt(- (exp (- z)) 4) 3) 10)
)

*/
#include "mlisp.h"

const double tolerance(0.00001);



double fun();
bool close__enough__Q();
double average();
double __arp__try();
double half__interval__method();
double root();




double fun(double z)
{
	z = z - double(11) / 12 - 1 / e;
	z = expt((expt(e, (-z)) - 4), 3) - 10;
	return z;
}

/*
(define (close-enough? x y)
  (<(abs (- x y))tolerance))
(define (average x y)(/(+ x y)2.))

*/


bool close__enough_Q(double x, double y)
{
    return abs(x - y) < tolerance;
}

double average(double x, double y)

{
	return (x + y) / 2;
}




/*
(define(try neg-point pos-point)
 (let(
       (midpoint (average neg-point pos-point))
       (test-value 0)
     )
     (display "+")
     (cond((close-enough? neg-point pos-point) midpoint)
        (#t (set! test-value (fun midpoint))
            (cond((> test-value 0)(try neg-point midpoint))
                 ((< test-value 0)(try midpoint pos-point))
                 (else midpoint))
         )
     )
 )
)
*/


double __arp__try(double neg__point, double pos__point)
{
    double midpoint(average(neg__point, pos__point));
	double test__value(0);
	display("+");
	//test__value = fun(midpoint);
	return(close__enough_Q(neg__point, pos__point) ? midpoint 
		:true ?
			test__value = fun(midpoint),
			test__value > 0 ?  	__arp__try(neg__point, midpoint):
		    test__value < 0 ?   	__arp__try(midpoint, pos__point):
			midpoint : false //сложнааа
		);

}



/*
;  half-interval.ss 2018
(define (half-interval-metod a b)
  (let((a-value (fun a))
       (b-value (fun b))
      )
     (cond((and(< a-value 0)(> b-value 0))
                 (try a b))
         ((and(> a-value 0)(< b-value 0))
                 (try b a))
         (else(+ b 1))
     )
  )
)
*/


double half__interval__method(double a, double b)
{
	double a__value(fun(a));
	double b__value(fun(b));
    return(  a__value < 0 && b__value > 0 ? __arp__try(a,b) 
     : a__value > 0 && b__value < 0 ? __arp__try(b,a)
     :b + 1
    );
	
}



/*
(define (root a b)
 (display"interval=\t[")
 (display a)
 (display" , ")
 (display b)
 (display"]\n")
 (let((temp (half-interval-metod a b)))
      (newline)
      (display"discrepancy=\t")
      (display(fun temp))(newline)
      (display"root=\t\t")
      (display(if(=(- temp b 1)0)"[bad]" "[good]"))
      temp 
 )
)
*/

double root(double a, double b)
{
	display("interval=\t[");
	display(a);
	display(" , ");
	display(b);
	display("]\n");
	double temp(half__interval__method(a, b));
	newline();
	display("discrepancy=\t");
	display(fun(temp)); newline();
	display("root=\t\t");
    display( (temp - b - 1) == 0 ? "[bad]" : "[good]"); //тут
    newline();
    display(temp);
	return temp;
}


int main(){
" arp variant 11";
std::cin.get();
root (double(-1), double(0));

}
