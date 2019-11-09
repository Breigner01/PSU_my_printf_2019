/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays the number given as parameter
*/

void my_putchar(char c);
int swap_numbers(int nb, int nb_1, int count);
int disp_numbers(int nb_1, int count);
int perfect_number(void);

int my_put_nbr(int nb)
{
    int nb_1 = 0;
    int count = 0;

    if (nb < 0){
        my_putchar('-');
        if (nb == -2147483648)
            perfect_number();
        nb *= (-1);
        swap_numbers(nb, nb_1, count);
    }
    if (nb >= 0 && nb < 10)
        my_putchar(nb + 48);
    if (nb >= 10){
        swap_numbers(nb, nb_1, count);
    }
    return (0);
}

int swap_numbers(int nb, int nb_1, int count)
{
    while (nb > 0){
        nb_1 *= 10;
        nb_1 = nb_1 + nb % 10;
        if (nb_1 == 0)
            count++;
        nb = nb - (nb % 10);
        nb /= 10;
    }
    disp_numbers(nb_1, count);
    return (0);
}

int disp_numbers(int nb_1, int count)
{
    while (nb_1 > 0){
        my_putchar((nb_1 % 10) + 48);
        nb_1 = nb_1 - (nb_1 % 10);
        nb_1 /= 10;
    }
    for (int i = 0; i < count; i++)
        my_putchar('0');
    return (0);
}

int perfect_number(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return (0);
}
