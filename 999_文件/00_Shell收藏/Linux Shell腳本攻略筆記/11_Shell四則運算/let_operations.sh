#!/bin/bash
#Filename: let_operations.sh

#四則運算
value01=20
value02=4

#let只令可以直接執行運算操作
let value01++
let value02++
let letresult=value01+value02
printf "letresult=%d\n" $letresult

#使用[]
result01=0
result01=$[ $value01 + $value02 ]
printf "result01 +op=%d\n" $result01

result01=$[ $value01 - $value02 ]
printf "result01 -op=%d\n" $result01

result01=$[ $value01 * $value02 ]
printf "result01 *op=%d\n" $result01

result01=$[ $value01 / $value02 ]
printf "result01 /op=%d\n" $result01

#使用(())
result02=0
result02=$(( $value01 + $value02 ))
printf "result02 +op=%d\n" $result02

result02=$(( $value01 - $value02 ))
printf "result02 -op=%d\n" $result02

result02=$(( $value01 * $value02 ))
printf "result02 *op=%d\n" $result02

result02=$(( $value01 / $value02 ))
printf "result02 /op=%d\n" $result02

#浮點數運算
c=$(echo "5.01-4*2.0"|bc)
printf "c =%f\n" $c
c=$(awk 'BEGIN{print 7.01*5-4.01 }')
printf "c =%f\n" $c
