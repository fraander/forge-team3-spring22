#include <iostream>
#include <string>

using namespace std;

const string cards[5] = {"a", "b", "c", "d", "e"};

/**
 * Generate a random integer between 0 and max
 * @param max_exclusive
 * @return
 */
int rand_int(int max_exclusive) {
    return rand() % max_exclusive;
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

void print_hand(int player_hand[5]) {
    for (int i = 0; i < 5; i++) {
        cout << player_hand[i] << " ";
    }
    cout << endl;
}

string remove_card(int (&player_hand)[5]) {
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
    return cards[index];

}

int main() {
    srand(time(0));

    int player_hand[5] = {0, 0, 0, 0, 0}; // Player setup

    draw_card(player_hand, -1); // draw 3 cards to start
    draw_card(player_hand, -1);
    draw_card(player_hand, -1);

    while (true) { // let player keep playing cards
        remove_card(player_hand);
    }

    return 0;
}