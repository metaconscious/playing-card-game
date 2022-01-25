//
// Created by user on 1/25/22.
//

#include "Suit.h"

using game::playing_card::deck::card::Suit;

Suit::Suit(Nameable::value_type name, Symbolizable::value_type symbol)
        : Nameable{ std::move(name) }, Symbolizable{ std::move(symbol) }
{

}

Suit::Suit(Nameable::view_type nameView, Symbolizable::view_type symbolView)
        : Nameable{ nameView }, Symbolizable{ symbolView }
{

}

Suit::Suit(const char* nameRaw, const char* symbolRaw)
        : Suit{ Nameable::view_type{ nameRaw }, Symbolizable::view_type{ symbolRaw }}
{

}

namespace game::playing_card::deck::card
{
    std::ostream& operator<<(std::ostream& os, const Suit& suit)
    {
        os << suit.getName();
        return os;
    }

    namespace suit
    {
        const Symbolizable::value_type& FrenchSuit::Symbol::clubs()
        {
            static const Symbolizable::value_type s_clubs{ "♣" };
            return s_clubs;
        }

        const Symbolizable::value_type& FrenchSuit::Symbol::diamonds()
        {
            static const Symbolizable::value_type s_diamonds{ "♦" };
            return s_diamonds;
        }

        const Symbolizable::value_type& FrenchSuit::Symbol::hearts()
        {
            static const Symbolizable::value_type s_hearts{ "♥" };
            return s_hearts;
        }

        const Symbolizable::value_type& FrenchSuit::Symbol::spades()
        {
            static const Symbolizable::value_type s_spades{ "♠" };
            return s_spades;
        }

        const FrenchSuit::value_type& FrenchSuit::clubs()
        {
            static const value_type s_clubs{ Suit::create("Clubs", Symbol::clubs()) };
            return s_clubs;
        }

        const FrenchSuit::value_type& FrenchSuit::diamonds()
        {
            static const value_type s_diamonds{ Suit::create("Diamonds", Symbol::diamonds()) };
            return s_diamonds;
        }

        const FrenchSuit::value_type& FrenchSuit::hearts()
        {
            static const value_type s_hearts{ Suit::create("Hearts", Symbol::hearts()) };
            return s_hearts;
        }

        const FrenchSuit::value_type& FrenchSuit::spades()
        {
            static const value_type s_spades{ Suit::create("Spades", Symbol::spades()) };
            return s_spades;
        }

        const FrenchSuit::value_type& FrenchSuit::suitAt(FrenchSuit::size_type index)
        {
            static const container_type s_suits{ clubs(), diamonds(), hearts(), spades() };
            return s_suits.at(index);
        }
    }
}
