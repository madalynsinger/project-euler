#include "Hand.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <vector>

using std::all_of;
using std::back_inserter;
using std::domain_error;
using std::istream;
using std::lexicographical_compare;
using std::ostream;
using std::pair;
using std::transform;
using std::vector;

enum HandKind {
    HighCard,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
};

struct Ranking {
    HandKind kind;
    vector<Value> high;
};

static Ranking rank_hand(const Hand&);

bool compare(const Hand& hand1, const Hand& hand2) {
    Ranking rank1 = rank_hand(hand1);
    Ranking rank2 = rank_hand(hand2);
    HandKind k1 = rank1.kind, k2 = rank2.kind;
    vector<Value> h1 = rank1.high, h2 = rank2.high;

    if (k1 < k2) {
        return true;
    } else if (k1 > k2) {
        return false;
    } else {
        return lexicographical_compare(h1.begin(), h1.end(), h2.begin(),
                                       h2.end());
    }
}

Ranking rank_hand(const Hand& hand) {
    //std::cout << "Ranking..." << std::endl;
    if (hand.size() != 5) {
        throw domain_error("hand must have five cards");
    }
    // TODO exception if duplicate cards

    Ranking rank;
    rank.kind = HighCard;

    vector<Value> values;
    transform(hand.begin(), hand.end(), back_inserter(values),
              [](Card c) { return c.value; });
    sort(values.rbegin(), values.rend());

    bool is_straight = true;
    Value v = values[0];
    for (int i = 1; i != 5 && is_straight; ++i) {
        if (values[i] != v - 1) {
            is_straight = false;
        } else {
            v = values[i];
        }
    }

    const Suit s1 = hand[0].suit;
    const bool is_flush = all_of(hand.begin() + 1, hand.end(),
                                 [s1](Card c) { return c.suit == s1; });

    if (is_flush && is_straight) {
        if (values[0] == Ace) {
            rank.kind = RoyalFlush;
        } else {
            rank.kind = StraightFlush;
            rank.high.push_back(values[0]);
        }
    } else if (is_flush) {
        rank.kind = Flush;
        rank.high = values;
    } else if (is_straight) {
        rank.kind = Straight;
        rank.high.push_back(values[0]);
    } else {
        typedef pair<int, Value> group_t;

        vector<group_t> groups;
        Value cur_val = values[0], v;
        int count = 1;
        for (int i = 1; i != 5; ++i) {
            v = values[i];
            if (v == cur_val) {
                ++count;
            } else {
                groups.push_back(group_t(count, cur_val));
                cur_val = v;
                count = 1;
            }
        }
        groups.push_back(group_t(count, cur_val));
        sort(groups.rbegin(), groups.rend());

        HandKind& k = rank.kind;
        int cnt1 = groups[0].first;
        int cnt2 = groups[1].first;  // TODO exception if only one group

        if (cnt1 == 4) {
            k = FourOfAKind;
        } else if (cnt1 == 3) {
            if (cnt2 == 2) {
                k = FullHouse;
            } else {
                k = ThreeOfAKind;
            }
        } else if (cnt1 == 2) {
            if (cnt2 == 2) {
                k = TwoPair;
            } else {
                k = OnePair;
            }
        } else {
            k = HighCard;
        }

        transform(groups.begin(), groups.end(), back_inserter(rank.high),
                  [](group_t g) { return g.second; });
    }

    return rank;
}

istream& read_hand(istream& in, Hand& hand) {
    hand.clear();
    for (int i = 0; i != 5; ++i) {
        Card card;
        read_card(in, card);
        hand.push_back(card);
    }
    return in;
}

std::ostream& show_hand(std::ostream& out, const Hand& hand) {
    for (const Card card : hand) {
        show_card(out, card) << " ";
    }
    return out;
}
