#include <iostream>
#include <string>

using namespace std;

string cards[5] = {"a", "b", "c", "d", "e"};
string possible_hands[4][5] = {{"", "b", "", "d", "e"},
                            {"a", "", "c", "", "e"},
                            {"a", "", "c", "d", ""},
                            {"a", "b", "", "d", ""}};

/**
 * Generate a random integer between 0 and max
 * @param max_exclusive
 * @return
 */
int rand_int(int max_exclusive) {
    return rand() % max_exclusive;
}

/**
 * Generate a boss hand
 * A boss hand is three random cards
 * @param boss_hand
 */
void generate_boss(string (&boss_hand)[3]) {
    boss_hand[0] = cards[rand_int(3)];
    boss_hand[1] = cards[rand_int(3)];
    boss_hand[2] = cards[rand_int(3)];
}

/**
 * Lets you play a card and remove the card from the boss's hand
 * True if successful
 * @param card_played
 * @param boss_hand
 * @return
 */
bool attack_boss(string card_played, string (&boss_hand)[3]) {
    for (int i=0; i < 3; i++) { // 3 for len boss_hand
        if (boss_hand[i] == card_played) {
            boss_hand[i] = "";
            return true;
        }
    }
    return false;
}

/**
 * Does the boss have any cards left in their hand
 * @param boss_hand
 * @return
 */
bool boss_alive(string boss_hand[3]) {
    for (int i=0; i < 3; i++) { // 3 for len boss_hand
        if (boss_hand[i] != "") {
            return true;
        }
    }
    return false;
}

/**
 * Print the boss' hand to console
 * @param boss_hand
 */
void print_boss_hand(string boss_hand[3]) {
    for (int i=0; i < 3; i++) {
        if (boss_hand[i] == "") {
            cout << "-";
        } else {
            cout << boss_hand[i];
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));

    string boss_hand[3];
    generate_boss(boss_hand);
    print_boss_hand(boss_hand);

    attack_boss("a", boss_hand);
    attack_boss("a", boss_hand);
    attack_boss("a", boss_hand);
    print_boss_hand(boss_hand);

    return 0;
}