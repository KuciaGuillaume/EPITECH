#include<unistd.h>

void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_evil_str(char *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);

int main(void)
{
    
    int a = 111 ;
    int b = 222 ;
    
    char tab[4];
    tab[0] = 'a';
    tab[1] = 'b';
    tab[2] = 'c';
    tab[3] = 'd';

    int numtab[4];
    numtab[0] = 11;
    numtab[1] = 22;
    numtab[2] = 33;
    numtab[3] = 44;

    int taille = 4;
    
    my_swap(&a, &b);
    my_putstr(tab);
    my_strlen(tab);
    my_evil_str(tab);
    my_getnbr(tab);
    my_sort_int_array(numtab, taille);
}
