#ifndef GUARD_hand_h
#define GUARD_hand_h

#include <iostream>
#include <vector>

#include "Card.h"

typedef std::vector<Card> Hand;

bool compare(const Hand&, const Hand&);
std::istream& read_hand(std::istream&, Hand&);
std::ostream& show_hand(std::ostream&, const Hand&);

#endif
