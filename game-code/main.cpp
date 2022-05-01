#include <iostream>
#include <string>

using namespace std;

/**
 * Generate a random integer between 0 and max
 * @param max_exclusive
 * @return
 */
int rand_int(int max_exclusive) {
    return rand() % max_exclusive;
}

void generate_boss(int (&boss_hand)[5]) {
    for (int i = 0; i < 4; i++) {
        int new_c = rand_int(5);
        boss_hand[new_c] += 1;
    }
}

void attack_boss(int (&boss_hand)[5], int attack_index) {
    if (boss_hand[attack_index] > 0) {
        boss_hand[attack_index] -= 1;
    }
}

bool boss_alive(int boss_hand[5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += boss_hand[i];
    }
    return sum > 0;
}

void draw_card(int (&player_hand)[5], int most_recent) {
    while (true) {
        int new_c = rand_int(5);

        if (player_hand[new_c] < 2 && new_c != most_recent) {
            player_hand[new_c] += 1;
            return;
        }
    }
}

void print_hand(int hand[5]) {
    for (int i = 0; i < 5; i++) {
        cout << hand[i] << " ";
    }
    cout << endl;
}

int remove_card(int (&player_hand)[5]) {
    cout << "YOU:  ";
    print_hand(player_hand);

    int index = -1;

    while (player_hand[index] == 0 || index < 0 || index > 5) {
        cin >> index;

        if (player_hand[index] == 0 || index < 0 || index > 5) {
            cout << "Invalid input." << endl;
        }
    }

    player_hand[index] -= 1;
    draw_card(player_hand, index);
    return index;

}

int main() {
    srand(time(0));

    int num_bosses = 5;
    int deck_size = 40;
    int cards_played = 0;

    int player_hand[5] = {0, 0, 0, 0, 0}; // player setup
    draw_card(player_hand, -1); // draw 3 cards to start
    draw_card(player_hand, -1);
    draw_card(player_hand, -1);

    cout << "TIME TO TAKE ON THE DUNGEON!" << endl;

    for (int bosses_defeated = 0; bosses_defeated < num_bosses; bosses_defeated++) {
        int boss_hand[5] = {0, 0, 0, 0, 0}; // boss setup
        generate_boss(boss_hand); // draw cards for boss

        while (boss_alive(boss_hand)) {
            cout << "CARDS: " << cards_played << "/" << deck_size << endl;
            cout << "BOSSES: " << bosses_defeated << "/" << num_bosses << endl;

            if (deck_size - cards_played == 0) {
                cout << "You're out of cards. You lose." << endl;
            }

            cout << "BOSS: ";
            print_hand(boss_hand);

            attack_boss(boss_hand, remove_card(player_hand));

            cards_played += 1;
        }
    }

    return 0;
}