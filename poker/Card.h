#ifndef GUARD_card_h
#define GUARD_card_h

#include <iostream>

enum Value {
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

enum Suit { Clubs, Diamonds, Hearts, Spades };

struct Card {
    Value value;
    Suit suit;
};

std::istream& read_card(std::istream&, Card&);
std::ostream& show_card(std::ostream&, const Card&);

#endif