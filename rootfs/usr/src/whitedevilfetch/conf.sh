#!/bin/bash

# BLYAT TI SAM BIN UDALYAESH KAKOY ./rootfs/bin
# YA BIN NE YDALYAU
# NIKTO EGO NE UDALYAET, ON U MENYA VSEGDA SUSHZEHESTVUET
# A KTO EGO UDALYAET
get_nucversion=$(./rootfs/bin/osinfo -v)
get_hostname=$(cat ./rootfs/etc/hostname)
FILE="./fetch.h"
touch $FILE
echo "#include <stdio.h" | tee -a $FILE
echo "#define get_nucversion \"$get_nucversion\" " | tee -a $FILE
echo "#define get_hostname \"$get_hostname\" " | tee -a $FILE
echo "You can now compile fetch.c."
# huyna
# u tebya fetch.h oshibku bi vydal, '' dlya citat (odnoy bukvi) v C
#  fetch ne meshay delat!!!!!!!
# ya luchze sdelayu
# tak y delayu kak t
