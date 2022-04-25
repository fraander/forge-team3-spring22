#include <iostream>
#include <string>

using namespace std;

string cards[5] = {"a", "b", "c", "d", "e"};
string possible_hands[4][5] = {{"", "b", "", "d", "e"},
                            {"a", "", "c", "", "e"},
                            {"a", "", "c", "d", ""},
                            {"a", "b", "", "d", ""}};

string boss_hand[3];

int main() {
    srand (time(0));
    return 0;
}

int rand_int(int max_exclusive) {
    return rand() % max_exclusive;
}

void generate_boss(string (&boss_hand)[3]) {
    boss_hand[0] = cards[rand_int(3)];
    boss_hand[1] = cards[rand_int(3)];;
    boss_hand[2] = cards[rand_int(3)];;
}
