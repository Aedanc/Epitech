#!/bin/bash
## skip-synthesis.sh for automakefile in /home/fortevg/rendu/automakefile
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Mon Jun 27 09:25:30 2016 Gabriel Forteville
## Last update Wed Jun 29 15:06:34 2016 Gabriel Forteville
##

if [ -z "$1" ]
then
    exit 84
fi

while read data
do
    cpt=0
    for WORD in $data
    do
	if [ $cpt = 2 ]
	then
	   owner=$WORD
	fi
	if [ "$cpt" = 8 ] && [[ "$WORD" =~ ^"$1".* ]]
	then
	       echo -e  "$owner\t\t$WORD"
	fi
	cpt=$((cpt + 1))
    done
done
