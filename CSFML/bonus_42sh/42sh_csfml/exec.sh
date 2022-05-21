##
## EPITECH PROJECT, 2021
## bonus_42sh
## File description:
## exec.sh
##

rm -rf data/command.txt
((echo "$1" | bash) 2>&1) > command.txt
mv command.txt data
chmod 777 data/command.txt
