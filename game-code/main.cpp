#include <iostream>
#include <string>

using namespace std;

const string cards[5] = {"a", "b", "c", "d", "e"};
const string possible_hands[4][5] = {{"", "b", "", "d", "e"},
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
bool attack_boss(const string& card_played, string (&boss_hand)[3]) {
    for (auto & i : boss_hand) {
        if (i == card_played) {
            i = "";
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
        if (!boss_hand[i].empty()) {
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
        if (boss_hand[i].empty()) {
            cout << "-";
        } else {
            cout << boss_hand[i];
        }
    }
    cout << endl;
}

/**
 * Pick hand from possible hand for player
 * @return
 */
 void generate_player(string (&player_hand)[5]) {
    int temp_hand_index = rand_int(4); // pick from 1 of 4 possible hands

    for (int i=0; i < 4; i++) {
        player_hand[i] = possible_hands[temp_hand_index][i];
    }
 }

 void print_player_hand(string player_hand[5]) {
     for (int i=0; i < 5; i++) { // 5 for len player_hand
         if (player_hand[i].empty()) {
             cout << "-";
         } else {
             cout << player_hand[i];
         }
     }
     cout << endl;
 }

/**
* Remove card from hand and return it from the function
* @param card_index
* @param player_hand
* @return
*/
string play_card(int card_index, string (&player_hand)[5]) {
    string c = player_hand[card_index];
    player_hand[card_index] = "";
    return c;
}

/**
 * Get card to play from user and return it using play_card
 * @param player_hand
 * @return
 */
 string get_card(string (&player_hand)[5]) {
     print_player_hand(player_hand);

    int index;
    cin >> index;

     while (player_hand[index] == "") {
         cout << "Invalid input" << endl;
         cin >> index;
     }

     string r = play_card(index, player_hand);
     generate_player(player_hand);
     return r;
 }

 void example() {
     string boss_hand[3]; // create boss hand example
     generate_boss(boss_hand);
     print_boss_hand(boss_hand);

     attack_boss("a", boss_hand); // attack boss example
     attack_boss("a", boss_hand);
     attack_boss("a", boss_hand);
     print_boss_hand(boss_hand);
     cout << boss_alive(boss_hand) << endl;

     string player_hand[5]; // create player hand example
     generate_player(player_hand);
     print_player_hand(player_hand);

     cout << get_card(player_hand); // get card from user hand based on input
 }

 int play_game() {
     int bosses_defeated = 0;
     int boss_goal = 3;
     int hands_played = 0;
     int max_hands = 24;

     string boss_hand[3]; // create boss hand example


     string player_hand[5]; // create player hand example
     generate_player(player_hand);

     while (bosses_defeated < boss_goal) {
         cout << endl << "New boss !" << endl;
         generate_boss(boss_hand);
         print_boss_hand(boss_hand);

         while (boss_alive(boss_hand)) {
             if (hands_played >= max_hands) {
                 cout << "You've run out of cards." << endl;
                 return 0;
             } else {
                 attack_boss(get_card(player_hand), boss_hand);
                 print_boss_hand(boss_hand);
                 hands_played += 1;
             }
         }
         cout << "Boss defeated! You have " << max_hands - hands_played << " moves left." << endl;
         bosses_defeated +=1;
     }

     cout << "You've defeated all the bosses!" << endl;
     return 0;
 }

int main() {
    srand(time(0));

//    example(); // test functions

    play_game();

    return 0;
}