#! /bin/bash

ARGS=1

if [ $# -ne "$ARGS" ]
then
  echo "Usage: filename"
  exit
fi

if [ -f "$1" ]
then
  file_name=$1
else
  echo "File \"$1\" does not exist."
  exit
fi

lines=()
while IFS= read -r line
do
  lines+=("$line");
done < $file_name

unique=()
unique=($(echo "$(echo "${lines[@]}" | awk '{print $1}')" | tr ' ' '\n' | sort -u | tr '\n' ' '))

sorted=()
IFS=$'\n' sorted=($(sort <<<"${lines[*]}"))
unset IFS

count=0
for (( i = 1; i < ${#sorted[@]}; i++ ));
do
  param1=$(echo ${sorted[i]} | awk '{print $1}')
  param2=$(echo ${sorted[i-1]} | awk '{print $1}')
  if [ $param1 = $param2 ]
  then
    param3=$(echo ${sorted[i]} | awk '{print $8}')
    param4=$(echo ${sorted[i-1]} | awk '{print $8}')
    if [ $param3 != $param4 ]
    then
      count=$((count + 1))
    fi
  fi
done

echo "$(( $(wc -l $file_name | awk '{print $1}') - 1 )) $(echo "${#unique[@]}") $count =="
