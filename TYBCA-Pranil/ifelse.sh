#!/bin/bash


read -p "Enter How many Wishes You Want" num
read -p "Enter that girl name " gname

valid=true
count=1
while [ $valid ]
do
echo " $count Love You ♥  $gname"
if [ $count -eq num ];
then
break
fi
((count++))
done
