/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** DAY04 Task05
*/

#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);

int my_getnbr(char const *str)
{
	long int chiffre = 0;
	int cpt = 0;
	int a = 1;
	int ch = 0;

	if (chiffre < 2147483647 && chiffre > -2147483647) {

	while (str[cpt] != '\0') {

		if(str[cpt] == '-') {
			a = a *(-1);
		}

		if (str[cpt] < 48 || str[cpt] > 57) 
		{
        if ((str[cpt] != 45 && str[cpt] != 43) || ch != 0)
	    {
        break;
		}
		  
		} else if (str[cpt] != 45 && str[cpt] != 43) {

			chiffre = chiffre *10 + (str[cpt] - '0');
			ch = ch + 1;
		} 
		cpt++;
    }

	chiffre = chiffre * a;
    return chiffre;

    } else {

	return 0;
	
    }
}
