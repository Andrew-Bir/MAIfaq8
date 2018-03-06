(define dd 12)
(define mm 10)
(define LARGEST-COIN 15)


(define (cc amount largest-coin)
    (cond   ((or (= amount 0) (= largest-coin 1) ) 1)
            ( (not(and (> amount 0) (> largest-coin 0))) 0)
     ((+ (cc amount (next-coin largest-coin)) (cc (- amount largest-coin) largest-coin)))
  )
)



(define (next-coin coin)
  (cond 
            ((= coin 15) 10)
            ((= coin 10) 3)
            ((= coin 3) 2)
            ((= coin 2) 1)
            (else 0)
     )
)
(define (GR-AMOUNT) 
    (remainder (+(* 100 mm) dd) 137)
)

(define (count-change amount)
    (cc amount LARGEST-COIN)

)

    (display " arp variant 10") (newline)
    (display " 1-2-3-10-15") (newline)
    (display "count-change for 100 \t= ")
    (display (count-change 100)) (newline)
    (display "count-change for ")
    (display (GR-AMOUNT))
    (display " \t= ")
    (display (count-change (GR-AMOUNT))) (newline)
    0




