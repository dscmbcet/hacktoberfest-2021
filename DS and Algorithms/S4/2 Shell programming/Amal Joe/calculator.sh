#!/bin/bash

# if operands are provided as arguments, use that or else read it from the user
if [ $# -ge 2 ]
then
    a=$1
    b=$2
else
    echo "Enter first number:"
    read a
    echo "Enter second number:"
    read b
fi
# possible values of flag = start | restart | stop
flag="start"
# prompt the user untill he enters a correct option
while [ $flag != "stop" ]
do
    # if operator is provided as argument, use that and make sure its a valid operator
    if [ $# -ge 3 -a $flag != "restart" ]
    then
        o=$3
    else
        echo "Enter your option (a- add, s- subtract, m -multiply, d- division):"
        read o
    fi
    flag="stop"
    # menu driven program to find sum, difference, product, quotient and remainder
    case $o in
        a) echo "Sum after addition: " `expr $a + $b`;;
        s) echo "Difference after subtraction: " `expr $a - $b`;;
        m) echo "Product after multiplication: " `expr $a \* $b`;;
        d) echo "Quotient after division: " `expr $a / $b` "     Remainder: " `expr $a % $b`;;
        *) echo "Invalid option, try again!!"
        # if option is invalid, loop again
        flag="restart";;
    esac
done