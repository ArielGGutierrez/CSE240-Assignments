; Q1 (5 points)
; Evaluates expressions in the asignment
(+ (* 8 4) (- 3 1))
(+ (* (+ 2 8) (- 10 2 5)) 15)
(* 9 (- (+ 5 (/ 32 8)) (* 3 (+ 7 9))) )
(* 3 (+ 9 (* (- (+ 2 (/ 36 4)) (* 2 5)) (- 10 2))))
(- (/ (- (* (* (* (+ 4 6) (+ 6 4)) 2) 2) 10) 2) (+ (/ (* 3 (+ (* 4 5) (* 6 4))) 2) (* 4 5)))

; Q2 (5 points)
(define Multiply
  (lambda (num1 num2)
    (* num1 num2) ; Multiplies both number inputs
  )
)

(Multiply 10 40)

; Q3 (5 points)
(define Exponent
  (lambda (x n)
    (if (= n 0) ; if the exponent is 0, return 1, otherwise keep multiplying
        1
        (* x (Exponent x (- n 1)))
    )
  )
)

(Exponent 2 5)

; Q4: Please enter test values 2 and 5. It should return 32. (5 points)
(display "Enter 2 5 as test case. It returns 32")
(newline)
(define (ReadForExponent)
  (Exponent (read) (read)) ; Read user input to use
)

(ReadForExponent)

; Q5 (5 points)
(define MultiplyExponents
  (lambda (x n y o)
    (Multiply (Exponent x n) (Exponent y o)) ; Use Multiply and Exponent to multiply exponents
  )
)

(MultiplyExponents 2 5 3 4)

;Q6 (5 points)
(define (MultiplyLet x y)
  (let((deez x)
       (nutz y))
    (* deez nutz) ; Multiply local Names for x and y
  )
)


(MultiplyLet 60 40)

; Q7 (10 points)
(define (Letexpression)
  (let((two 2) ; Assign Names to 2, 3, 4, 5, 6 and 10
       (three 3)
       (four 4)
       (five 5)
       (six 6)
       (ten 10))
    (- (/ (- (* (* (* (+ four six) (+ six four)) two) two) ten) two) (+ (/ (* three (+ (* four five) (* six four))) two) (* four five))) ; Use Names instead of number
  )
)


(Letexpression)

; Q8: Enter values 1 2 3 4 5 6 7 8, and it should return 20. (10 points)
(display "Enter 1 2 3 4 5 6 7 8 and e, and it returns 20.")
(newline)
(define accumulator	; recursive
  (lambda (evensum next)
    (if (number? next) ; If the next input is a number
        (if(= (remainder next 2) 0)              ; Check if the number is even
           (accumulator (+ evensum next) (read)) ; (true)  Add the number and read another
           (accumulator evensum (read))          ; (false) Read another number
        )
        evensum ; Return the sum
    )
  )
)
   
  
(accumulator 0 0) 