;Your Name: Ariel Gael Gutierrez
;Course: CSE 240
; Use the template for your programming assignment

;Q1 (6 points)
(define OR-GATE (lambda (a b)
                  (if (or (= a 1)(= b 1)) ; check if the first or second number are 1
                      1
                      0
                      )
                  )
  )

(define AND-GATE (lambda (a b)
                   (if (and (= a 1)(= b 1)) ; check if both the first and second number are 1
                      1
                      0
                      )
                  )
  )

(define XOR-GATE (lambda (a b)
                   (if (or (= a 1)(= b 1)) ; check if the first or the second number are 1
                      (if (= a b)          ; check if both numbers are the same and if they are return false
                          0
                          1
                          )
                      0
                      )
                  )
  )

;Test cases
(AND-GATE 0 0)
(AND-GATE 0 1)
(AND-GATE 1 0)
(AND-GATE 1 1)
;0
;0
;0
;1
(newline)
(OR-GATE 0 0)
(OR-GATE 0 1)
(OR-GATE 1 0)
(OR-GATE 1 1)
;0
;1
;1
;1
(newline)
(XOR-GATE 0 0)
(XOR-GATE 0 1)
(XOR-GATE 1 0)
(XOR-GATE 1 1)
;0
;1
;1
;0

;Q2 
(define bitAdder (lambda (x a b) ;(4 points each)
                   (cons (sum-bits x a b) (carry-out x a b)) ; Format the sum and carry out of binary adder
                   )
  )

(define sum-bits (lambda (x a b) ;(5 points each)
                   (XOR-GATE (XOR-GATE a b) x); Use gates to find the sum of a binary adder
                   )
  )
(define carry-out (lambda (x a b) ;(5 points each)
                    (OR-GATE (AND-GATE (XOR-GATE a b) x) (AND-GATE a b)) ; Use gates to the find the carry out of a binary adder
                    )
  )

;Test cases
(newline)
(bitAdder 0 0 0) 	
(bitAdder 0 0 1) 	
(bitAdder 0 1 0) 	
(bitAdder 0 1 1)	
(bitAdder 1 0 0) 	
(bitAdder 1 0 1)	
(bitAdder 1 1 0) 	
(bitAdder 1 1 1) 
;(0 . 0)
;(1 . 0)
;(1 . 0)
;(0 . 1)
;(1 . 0)
;(0 . 1)
;(0 . 1)
;(1 . 1)


;Q3.1 (4 points)
(define tail (lambda (lst)
               (if (null? (cdr lst))       ; If the next number is null, then we are at the tail
                          (car lst)        ; Return the number at the tail
                          (tail (cdr lst)) ; Recursively scroll through the list
                          )
               )
  )

;Q3.2 (4 points)
(define rmtail (lambda (lst)
                 (if (null? (cdr lst))                                ; If the next number is null, then we are at the tail
                          '()                                         ; Don't add the tail to the new list
                          (append (list(car lst)) (rmtail (cdr lst))) ; Create a new list and scroll through the existing list
                          )
                 )
  )

;Q3.3 (4 points)
; 1) size-n problem:
; Total number of bits to add
; 2) stopping condition:
; When there are no more bits to add
; 3) size-(n-1) problem:
; Total number of bits to add minus 1
; 4) steps to construct size-n problem solution from size-(n-1) solution:
; Add the remaining carry-out to the beginning of the list

;Q3.4 (14 points)
(define X1 '(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0) )	
(define X2 '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) )	
(define X3 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1) )	
(define X4 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0) )
(define X5 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1) )	
(define X6 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1) )

(define n-bit-adder1 (lambda (L1 L2 n)
                       (let ((len1 (length L1)) (len2 (length L2)))
                         (if (> len1 len2)
                             (n-bit-adder1 L2 L1)
                             (if  (< len1 len2)
                                  (n-bit-adder1 (append '(0) L1) L2)
                                  (recursiveAdd L1 L2 0)             ; If the two lists have the same number of elements, start calling the recursive procedure
                                  )
                             )
                         )
                       )
  )

(define recursiveAdd (lambda (L1 L2 c
                       (if (null?  L1)
                                 (list(list c))                                                                   ; Add remaining carry-out to the list
                                 (append (recursiveAdd (rmtail L1) (rmtail L2) (carry-out c (tail L1) (tail L2))) ; Next recursive result gets added to beginning of new list
                                         (list(sum-bits c (tail L1) (tail L2))))                                  ; Add the binary sum to the end of the current list
                                 )
                             )
  )

;Test cases
(newline)
(n-bit-adder1  X1 X2 32)
(n-bit-adder1  X3 X4 32)
(n-bit-adder1  X5 X6 32)
(n-bit-adder1  X2 X3 32)
(n-bit-adder1  X4 X5 32)
(n-bit-adder1  X1 X6 32)
(newline)
(n-bit-adder1  X1 X3 32)
(n-bit-adder1  X1 X4 32)
(n-bit-adder1  X1 X5 32)
(n-bit-adder1  X2 X4 32)
(n-bit-adder1  X2 X5 32)
(n-bit-adder1  X2 X6 32)

;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1)

;((0) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0)
;((0) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1)
;((1) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 1)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 0)
;((1) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0)



