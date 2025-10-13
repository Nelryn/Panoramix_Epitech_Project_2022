/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-emilie.baunifais
** File description:
** thread
*/

#include "panoramix.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static sem_t semaphore_d;
static sem_t semaphore_v;
static db_t db = {0};

int do_fight(int nb_fight, int id)
{
    nb_fight--;
    db.potions_left--;
    printf("Villager %d: Take that roman scum! Only %d left.\n", id, nb_fight);
    if (nb_fight == 0)
        db.people--;
    return nb_fight;
}

void *battle(void *param)
{
    int nb_fight = db.fights_left;
    int id = *((int  *)param);
    printf("Villager %d: Going into battle!\n", id);
    for (; nb_fight > 0;) {
        pthread_mutex_lock(&mutex);
        printf("Villager %d: I need a drink... ", id);
        printf("I see %d servings left.\n", db.potions_left);
        if (db.potions_left > 0)
            nb_fight = do_fight(nb_fight, id);
        else {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
            sem_post(&semaphore_d);
            sem_wait(&semaphore_v);
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("Villager %d: I'm going to sleep now.\n", id);
    if (db.people <= 0 && db.remaining_refill > 0)
        sem_post(&semaphore_d);
    return param;
}

void *brew(void *param)
{
    printf("Druid: I'm ready... but sleepy...\n");
    while (db.remaining_refill > 0 && db.people > 0) {
        sem_wait(&semaphore_d);
        if (db.people <= 0)
            break;
        db.remaining_refill--;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware ");
        printf("I can only make %d more refills after this one.\n",
        db.remaining_refill);
        db.potions_left = db.all_potions;
        sleep(2);
        sem_post(&semaphore_v);
    }
    if (db.remaining_refill == 0)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return param;
}

void my_manager(int nb_villagers, int pot_size, int nb_fights, int refills)
{
    int id = -1;
    pthread_t threads[nb_villagers + 1];

    db.fights_left = nb_fights;
    db.potions_left = pot_size;
    db.all_potions = pot_size;
    db.remaining_refill = refills;
    db.people = nb_villagers;
    sem_init(&semaphore_d, 0, 0);
    sem_init(&semaphore_v, 0, 0);
    pthread_create(&threads[0], NULL, brew, NULL);
    for (int i = 1; i <= nb_villagers; i++) {
        pthread_create(&threads[i], NULL, battle, &id);
        id++;
    }
    for (int i = 0; i <= nb_villagers; i++)
        pthread_join(threads[i], NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaphore_d);
    sem_destroy(&semaphore_v);
}