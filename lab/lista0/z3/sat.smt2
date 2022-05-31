(declare-const x Int)
(declare-const y Int)
(assert (= x (+ y 1)))
(assert (= y (* x 2)))
(check-sat)
(get-model)

