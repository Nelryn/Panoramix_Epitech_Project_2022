/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-emilie.baunifais
** File description:
** errors
*/

#include "panoramix.h"

int check_numbers(int i, char **av)
{
    for (int ind = 0; av[i][ind] != '\0'; ind++) {
        if (isdigit(av[i][ind]) == 0) {
            fprintf(stderr, USAGE);
            return 84;
        }
    }
    return 0;
}

int check_errors(int ac, char **av)
{
    if (ac != 5) {
        fprintf(stderr, USAGE);
        return 84;
    }
    for (int i = 1; i != ac; i++) {
        if (check_numbers(i, av) == 84)
            return 84;
        if (atoi(av[i]) <= 0) {
            fprintf(stderr, USAGE);
            return 84;
        }
    }
    return 0;
}