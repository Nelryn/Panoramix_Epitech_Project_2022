/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-emilie.baunifais
** File description:
** main
*/

#include "panoramix.h"

int main(int ac, char **av)
{
    if (check_errors(ac, av) == 84)
        return 84;
    my_manager(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]));
    return 0;
}
