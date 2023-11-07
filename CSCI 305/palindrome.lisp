

(defun palindromep (x)
     (if (equal(first x)(first(reverse x)))(if(null x)(atom 2)(palindromep(rest(reverse(rest x)))))(atom(cons 1 2))))

(write(palindromep '(a b b a)))
;t
(terpri)
(write(palindromep '(a b c b a)))
;t
(terpri)
(write(palindromep '(a b c)))
;nil
(terpri)
(write(palindromep '(a (d e) b (d e) a)))
;t
(terpri)
(write(palindromep '(a (d e) b (e d) a)))
;nil
(terpri)

