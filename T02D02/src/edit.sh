#! /bin/bash

ARGS=3

if [ $# -ne "$ARGS" ]
then
  echo "Usage: filename old-pattern new-pattern"
  exit
fi

old_pattern=$2
new_pattern=$3

if [ -f "$1" ]
then
  file_name=$1
else
  echo "File \"$1\" does not exist."
  exit
fi


sed -i "" "s/$old_pattern/$new_pattern/g" $file_name


echo "$1 - $(wc -c $file_name | awk '{print $1}') - $(date +'%Y-%m-%d %H:%M')  - $(shasum -a 256 $file_name | cut -d " " -f 1) - sha256" >> files.log

exit
