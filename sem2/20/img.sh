#!/bin/sh
Link="http://www.adme.ru/vdohnovenie-919705/sumasshedshie-starye-otkrytki-549605"
Path="/mnt/data/Media/Pictures/Other/"

Res=1
Try=0

while [ $Res != 0 ]; do
  Try=$(($Try+1))
  echo "Попытка: "$Try
  /mnt/data/Personal/C/usbreset/resetmodem.sh

  #wget -t 0 -c -T 15 --retry-connrefused=on -P $Path $Link
  wget -O - $Link | grep -o 'http://.*\.jpg' | xargs wget -t 0 -c -T 15 --retry-connrefused=on -P $Path
  Res=$?
  echo "Res="$Res

  sleep 5
done

#poweroff
#pm-suspend

