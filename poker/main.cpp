#include "Hand.h"

using namespace std;

int main() {
    int wins = 0;
    int i = 0;
    while (cin) {
        Hand hand1, hand2;
        if (read_hand(cin, hand1)) {
            read_hand(cin, hand2);
            if (!compare(hand1, hand2)) {
                ++wins;
            }
        }
    }

    cout << "Player 1 won " << wins << " hands." << endl;
    return 0;
}
