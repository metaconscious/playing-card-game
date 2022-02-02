//
// Created by user on 1/25/22.
//
#include "playingcard/deck/card/Suit.h"
#include "playingcard/deck/card/Rank.h"
#include "playingcard/deck/Card.h"
#include "playingcard/Deck.h"
#include <iostream>

using game::playing_card::deck::card::Suit;
using FrenchSuit = game::playing_card::deck::card::suit::French;
using Suits = game::playing_card::deck::card::suit::French::Suits;
using game::playing_card::deck::card::Rank;
using FrenchRank = game::playing_card::deck::card::rank::French;
using Ranks = game::playing_card::deck::card::rank::French::Ranks;
using game::playing_card::deck::Card;
using game::playing_card::deck::card::Standard52Card;
using game::playing_card::deck::card::Misc;
using game::playing_card::Deck;
using game::playing_card::deck::Standard52CardDeck;

int main()
{
    //std::shared_ptr<const Suit> suit{ Suit::create("name", "symbol") };
    //std::cout << *suit << ' ' << suit->getValue() << '\n';

    FrenchSuit::value_type s0{ Suits::clubs() };
    std::cout << *s0 << ": " << s0->getSymbol() << ' ' << s0->getValue() << '\n';

    std::cout << *FrenchSuit::suitAt(3) << '\n';

    //std::shared_ptr<const Rank> rank{ Rank::create("name", "symbol") };
    //std::cout << *rank << ' ' << rank->getValue() << '\n';

    FrenchRank::value_type r0{ Ranks::ace() };
    std::cout << *r0 << ": " << r0->getSymbol() << ' ' << s0->getValue() << '\n';

    std::cout << *FrenchRank::rankAt(12) << '\n';

    Standard52Card::value_type c0{ Standard52Card::Cards::kingOfClubs() };
    std::cout << *c0 << ": " << c0->getSymbol() << ' ' << c0->getValue() << ' ' << c0->getAbbreviation() << '\n';

    std::cout << *Standard52Card::cardAt(37) << '\n';

    auto deck{ Deck::create([](Deck::container_type& v)
    { v.push_back(Standard52Card::Cards::kingOfClubs()); }) };

    std::cout << *deck << '\n';

    auto s52c{ Standard52CardDeck::create() };
    std::cout << *static_cast<std::shared_ptr<VectorWrapper<std::shared_ptr<const Card>>>>(s52c) << '\n';

    return 0;
}