#!/bin/bash

# -----------------------------------------------------------

# echo Hello World!

# -----------------------------------------------------------

# echo $@
# echo $1
# echo $2
# echo $3
# echo $4
# echo $5
# echo $6
# echo $7
# echo $8
# echo $9

# for arg in $@
# do
#     echo $arg
# done

# -----------------------------------------------------------

# x=Hello
# y=World!
# echo $x $y
# echo
# z=~
# echo $z
# w=$( find $z -name *.txt -print | wc -l )
# echo $w

# -----------------------------------------------------------

# let a=5+4
# echo $a # 9
# let a++
# echo $a # 10
# let a=$a+1
# echo $a # 11
# let a=4*5
# echo $a # 20
# let a=$1+30
# echo $a # arg1 + 30

# -----------------------------------------------------------

# expr 5 + 4
# expr 5 \* $1
# expr 11 % 2 
# let a=$( expr 5 + 4 )
# let b=$( expr 10 - 3 )
# echo $a + $b # no
# echo expr $a + $b # no
# echo $( expr $a + $b ) # 12

# -----------------------------------------------------------

# a='Hello World'
# echo ${#a} # 11
# b=4953
# echo ${#b} # 4

# -----------------------------------------------------------

# echo test starting
# if [ $1 -gt 100 ]
# then
#   echo large number
# else
#   echo small number
# fi

# -----------------------------------------------------------

# if [ $1 -ge 18 ]
# then
#   echo You do not need my permission to go to the party.
# elif [ $1 -ge 15 ]
# then
#   echo You may go to the party but be back before midnight.
# else
#   echo You may not go to the party.
# fi

# -----------------------------------------------------------

# if [ -r $1 ] && [ -s $1 ]
# then
#   echo $1 is readable and not empty
# else
#   echo $1 is not usable
# fi

# -----------------------------------------------------------

# if [ $USER == 'bob' ] || [ $USER == 'andy' ]
# then
#     echo either bob or andy
# else
#     echo $USER is neither bob nor andy
# fi

# -----------------------------------------------------------

# case $1 in
# start)
#   echo starting
#   ;;
# stop)
#   echo stoping
#   ;;
# restart)
#   echo restarting
#   ;;
# *)
#   echo don\'t know
#   ;;
# esac

# -----------------------------------------------------------

# counter=1
# while [ $counter -le $1 ]
# do
#   echo $counter
#   let counter++
# done

# -----------------------------------------------------------

# counter=1
# until [ $counter -gt $1 ]
# do
#   echo $counter
#   ((counter++))
# done

# -----------------------------------------------------------

# names='Stan Kyle Cartman'
# for name in $names
# do
#   echo $name
# done

# -----------------------------------------------------------

# for value in {1..5}
# do
#   echo $value
# done

# -----------------------------------------------------------

# for value in {1,3,7,19,51}
# do
#   echo $value
# done

# -----------------------------------------------------------

# for file in ./*.txt
# do
#   wc -l $file
# done

# -----------------------------------------------------------

# files=$( find . -name *.txt -print )
# for file in $files
# do
#   wc -l $file
# done

# -----------------------------------------------------------

# total=0
# for file in $@
# do
#     lines=$(wc -l < $file | sed 's/^[\t ]*//' | cut -d ' ' -f 1)
#     total=$(( $total + $lines ))
# done

# -----------------------------------------------------------

# if [ $# -lt 2 ]
# then
#   echo usage: myscript binary file1 file2 ... filen
#   exit 1
# fi
# if [ ! -x $1 ]
# then
#   echo error: file is not executable
#   exit 1
# fi
# binary=$1
# shift
# for file in $@
# do
#     echo running $file test
#     ./$binary < $file
# done

# -----------------------------------------------------------

# #kill all processes with $1 in the description
# processes=$( ps -A | grep $1 | cut -f 1 )
# for process in $processes
# do
#     kill -9 $process 2> /dev/null
# done

# -----------------------------------------------------------

# trash=$HOME/.trash
# if [ ! -d $trash ]
# then
#    mkdir $trash
# fi
#
# for arg in $@
# do
#    if [ $arg == '-clean' ]
#    then
#        rm -rf $trash/*
#    else
#        mv $arg $trash
#    fi
# done

# -----------------------------------------------------------
