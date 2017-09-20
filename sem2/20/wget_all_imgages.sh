#!/bin/sh
Link="https://www.adme.ru/tvorchestvo-hudozhniki/15-kartin-hudozhnika-kotoryj-pereplyunul-realnost-1508515"
Path="/home/kane/Pictures/test/"
wget -P $Path -nd -H -p -A jpg,jpeg,png,gif -e robots=off $Link
