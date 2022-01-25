//
// Created by user on 1/25/22.
//
#include "playingcard/deck/card/Suit.h"
#include <iostream>

using game::playing_card::deck::card::Suit;
using game::playing_card::deck::card::suit::FrenchSuit;

int main()
{
    std::shared_ptr<const Suit> suit{ Suit::create("name", "symbol") };
    std::cout << *suit << '\n';

    FrenchSuit::value_type s0{ FrenchSuit::clubs() };
    std::cout << *s0 << ": " << s0->getSymbol() << ' ' << s0->getValue() << '\n';

    return 0;
}