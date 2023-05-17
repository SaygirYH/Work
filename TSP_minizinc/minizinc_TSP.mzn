int: V;
int: E_n;
array[1..E_n, 1..2] of 1..V: E;
array[1..E_n] of int: c;
array[1..E_n] of var 0..1: x;
array[1..E_n] of var int: y;
var int: total = sum(i in 1..E_n) (c[i] * x[i]);
solve :: int_search(
   [x[i] | i in 1..E_n] ++
   [y[i] | i in 1..E_n] ++
   [total],
   first_fail,
   indomain_max,
   complete
   )
   minimize total;

constraint
   forall(i in 1..V) (
        sum(k in 1..E_n where E[k,1] = i) (x[k]) = 1
   )
   /\
   forall(j in 1..V) (
        sum(k in 1..E_n where E[k,2] = j) (x[k]) = 1
   )
   /\
   forall(k in 1..E_n) (
      y[k] >= 0
      /\
      y[k] <= (V-1) * x[k]
   )
   /\
   forall(i in 1..V) (
      (
      sum(k in 1..E_n where E[k,2] = i) (y[k]) + (if i = 1 then V else 0 endif)
      )
      = 
      (
      sum(k in 1..E_n where E[k,1] = i) (y[k]) + 1
      )
   )
;

output [
   "total: " ++ show(total / 10) ++ "\n"
];