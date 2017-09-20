#!/usr/bin/bash

# Удлинение имен файлов до указанной длины заданным знаком
text="Syntax filename symbol number";
if [ -z "$1" ]; then
    echo "Need file to rename";
    echo $text;
    exit 1;
fi

if [ -z "$2" ]; then
	echo "Need argument";
	echo $text;
	exit 2;
fi

if [ -z "$3" ]; then
	echo "Need new name files length argument";
	echo $text;
	exit 3;
fi

if [[ $3 =~ ^[0-9]+$ ]]; then
	files_length="$3"
else
	echo "Amount of added symbols has to be a number";
	exit 4;
fi

extention="${1##*.}"

old_name=${1%.*}

len=${#old_name}

char=$2

new_name=${old_name}
for (( i=0; i<${files_length} - ${len}; ++i )); do
	new_name="${new_name}${char}"
done
if [ "${extention}" != "${old_name}" ] 
then
new_name="${new_name}"."${extention}"
fi
mv  "$1" "${new_name}"
