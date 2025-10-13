/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-emilie.baunifais
** File description:
** panoramix
*/

#pragma once

#define USAGE   "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights>\
 <nb_refills>\n"

#include <pthread.h>
#include <semaphore.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct database_s {
    int fights_left;
    int potions_left;
    int all_potions;
    int remaining_refill;
    int people;
} db_t;


int check_errors(int ac, char **av);
void my_manager(int nb_villagers, int pot_size, int nb_fights, int refills);