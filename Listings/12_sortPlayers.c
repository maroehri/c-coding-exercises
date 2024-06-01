#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 64

typedef struct {
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    int age;
} Player;

Player* createPlayer(const char firstName[], const char lastName[], int age) {
    Player* player = malloc(sizeof(Player));
    if (player == NULL) {
        fprintf(stderr, "Fehler: Speicherallokation fehlgeschlagen\n");
        return NULL;
    }

    snprintf(player->firstName, NAME_LENGTH, "%s", firstName);
    snprintf(player->lastName, NAME_LENGTH, "%s", lastName);
    player->age = age;

    return player;
}

void printPlayer(Player* player) {
    printf("%s %s, %d Jahre\n", player->firstName, player->lastName, player->age);
}

int comparePlayerByLastName(const void* pa, const void* pb) {
    const Player* A = *(const Player**)pa;
    const Player* B = *(const Player**)pb;

    return strcmp(A->lastName, B->lastName);
}

void freeTeam(Player** team, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        free(team[i]);
    }
    free(team);
}

int main(void) {
    const int NUM_PLAYERS = 5;
    Player** team = malloc(NUM_PLAYERS * sizeof(Player*));

    team[0] = createPlayer("Thomas", "Müller", 34);
    team[1] = createPlayer("Florian", "Wirtz", 21);
    team[2] = createPlayer("İlkay", "Gündoğan", 33);
    team[3] = createPlayer("Jamal", "Musiala", 21);
    team[4] = createPlayer("Manuel", "Neuer", 38);

    printf("Vor der Sortierung:\n");
    for (int i = 0; i < NUM_PLAYERS; i++)
        printPlayer(team[i]);

    qsort(team, NUM_PLAYERS, sizeof(Player*), comparePlayerByLastName);

    printf("\nNach der Sortierung:\n");
    for (int i = 0; i < NUM_PLAYERS; i++)
        printPlayer(team[i]);

    freeTeam(team, NUM_PLAYERS);

    return 0;
}
