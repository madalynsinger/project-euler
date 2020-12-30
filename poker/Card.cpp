#include "Card.h"

#include <iostream>
#include <string>
#include <vector>

using std::istream;
using std::ostream;
using std::string;
using std::vector;

static Suit read_suit(char);
static Value read_value(char);
static ostream& show_suit(ostream&, Suit);
static ostream& show_value(ostream&, Value);

istream& read_card(istream& in, Card& card) {
    string s;
    in >> s;

    card.value = read_value(s[0]);
    card.suit = read_suit(s[1]);

    return in;
}

static Suit read_suit(char ch) {
    switch (ch) {
        case 'C':
            return Clubs;
        case 'D':
            return Diamonds;
        case 'H':
            return Hearts;
        case 'S':
            return Spades;
    }
}

static Value read_value(char ch) {
    if (ch >= '2' && ch <= '9') {
        return static_cast<Value>(ch - '2' + 2);
    } else {
        switch (ch) {
            case 'T':
                return Ten;
            case 'J':
                return Jack;
            case 'Q':
                return Queen;
            case 'K':
                return King;
            case 'A':
                return Ace;
        }
    }
}

ostream& show_card(ostream& out, const Card& card) {
    show_value(out, card.value);
    show_suit(out, card.suit);
    return out;
}

static ostream& show_suit(ostream& out, Suit s) {
    switch (s) {
        case Clubs:
            out << 'C';
            break;
        case Diamonds:
            out << 'D';
            break;
        case Hearts:
            out << 'H';
            break;
        case Spades:
            out << 'S';
            break;
    }

    return out;
}

static ostream& show_value(ostream& out, Value v) {
    if (v < Ten) {
        char ch = v + '2' - 2;
        out << ch;
    } else {
        switch (v) {
            case Ten:
                out << 'T';
                break;
            case Jack:
                out << 'J';
                break;
            case Queen:
                out << 'Q';
                break;
            case King:
                out << 'K';
                break;
            case Ace:
                out << 'A';
                break;
        }
    }

    return out;
}
