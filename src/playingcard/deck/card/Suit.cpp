//
// Created by user on 1/25/22.
//

#include "Suit.h"

namespace game::playing_card::deck::card
{
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

    std::ostream& operator<<(std::ostream& os, const Suit& suit)
    {
        os << suit.getName();
        return os;
    }

    namespace suit
    {
        Symbolizable::view_type French::Symbols::clubs()
        {
            static const Symbolizable::value_type s_clubs{ "♣" };
            return s_clubs;
        }

        Symbolizable::view_type French::Symbols::diamonds()
        {
            static const Symbolizable::value_type s_diamonds{ "♦" };
            return s_diamonds;
        }

        Symbolizable::view_type French::Symbols::hearts()
        {
            static const Symbolizable::value_type s_hearts{ "♥" };
            return s_hearts;
        }

        Symbolizable::view_type French::Symbols::spades()
        {
            static const Symbolizable::value_type s_spades{ "♠" };
            return s_spades;
        }

        const French::value_type& French::Suits::clubs()
        {
            static const value_type s_clubs{ Suit::create("Clubs", Symbols::clubs()) };
            return s_clubs;
        }

        const French::value_type& French::Suits::diamonds()
        {
            static const value_type s_diamonds{ Suit::create("Diamonds", Symbols::diamonds()) };
            return s_diamonds;
        }

        const French::value_type& French::Suits::hearts()
        {
            static const value_type s_hearts{ Suit::create("Hearts", Symbols::hearts()) };
            return s_hearts;
        }

        const French::value_type& French::Suits::spades()
        {
            static const value_type s_spades{ Suit::create("Spades", Symbols::spades()) };
            return s_spades;
        }

        const French::container_type& French::suits()
        {
            static const container_type s_suits{ Suits::clubs(), Suits::diamonds(), Suits::hearts(), Suits::spades() };
            return s_suits;
        }

        const French::value_type& French::suitAt(French::size_type index)
        {
            return suits().at(index);
        }

        French::size_type French::size()
        {
            return suits().size();
        }
    }
}
