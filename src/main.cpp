//
// Created by user on 1/25/22.
//
#include "playingcard/deck/card/Suit.h"
#include "playingcard/deck/card/Rank.h"
#include "playingcard/deck/Card.h"
#include "playingcard/Deck.h"
#include <iostream>

using pcg::playing_card::deck::card::Suit;
using FrenchSuit = pcg::playing_card::deck::card::suit::French;
using Suits = pcg::playing_card::deck::card::suit::French::Suits;
using pcg::playing_card::deck::card::Rank;
using FrenchRank = pcg::playing_card::deck::card::rank::French;
using Ranks = pcg::playing_card::deck::card::rank::French::Ranks;
using pcg::playing_card::deck::Card;
using pcg::playing_card::deck::card::Standard52Card;
using pcg::playing_card::deck::card::Misc;
using pcg::playing_card::Deck;
using pcg::playing_card::deck::Standard52CardDeck;

int main()
{
    //std::shared_ptr<const Suit> suit{ Suit::create("name", "symbol") };
    //std::cout << *suit << ' ' << suit->getValue() << '\n';

    std::cout << *FrenchSuit::suitAt(3) << '\n';

    FrenchSuit::value_type s0{ Suits::clubs() };
    std::cout << *s0 << ": " << s0->getSymbol() << ' ' << s0->getValue() << '\n';

    std::cout << std::boolalpha << (FrenchSuit::suitAt(0) < FrenchSuit::suitAt(1)) << '\n';

    //std::shared_ptr<const Rank> rank{ Rank::create("name", "symbol") };
    //std::cout << *rank << ' ' << rank->getValue() << '\n';

    std::cout << *FrenchRank::rankAt(12) << '\n';


    FrenchRank::value_type r0{ Ranks::ace() };
    std::cout << *r0 << ": " << r0->getSymbol() << ' ' << s0->getValue() << '\n';

    //std::cout << std::boolalpha << (FrenchSuit::suitAt(1) < FrenchRank::rankAt(2)) << '\n';

    std::cout << *Standard52Card::cardAt(37) << '\n';

    Standard52Card::value_type c0{ Standard52Card::Cards::kingOfClubs() };
    std::cout << *c0 << ": " << c0->getSymbol() << ' ' << c0->getValue() << ' ' << c0->getAbbreviation() << '\n';


    auto deck{ Deck::create([](Deck::container_type& v)
    { v.push_back(Standard52Card::Cards::kingOfClubs()); }) };

    std::cout << *deck << '\n';

    auto s52c{ Standard52CardDeck::create() };
    std::cout << *s52c << '\n';

    s52c->shuffle();
    std::cout << *s52c << '\n';

    s52c->descending_sort();
    std::cout << *s52c << '\n';

    std::cout << "Ace of Spades is in it: " << std::boolalpha << s52c->find(Standard52Card::Cards::aceOfSpades())
              << '\n';

    s52c->forEach([](const auto& value){ std::cout << value->getAbbreviation() << ' '; });

    return 0;
}