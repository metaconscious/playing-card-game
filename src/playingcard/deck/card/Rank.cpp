//
// Created by user on 1/25/22.
//

#include "Rank.h"

namespace pcg::playing_card::deck::card
{
    Rank::Rank(Nameable::value_type name, Symbolizable::value_type symbol)
            : Nameable{ std::move(name) }, Symbolizable{ std::move(symbol) }
    {

    }

    Rank::Rank(Nameable::view_type name, Symbolizable::view_type symbol)
            : Nameable{ name }, Symbolizable{ symbol }
    {

    }

    Rank::Rank(const char* name, const char* symbol)
            : Rank{ Nameable::view_type{ name }, Symbolizable::view_type{ symbol }}
    {

    }

    std::ostream& operator<<(std::ostream& os, const pcg::playing_card::deck::card::Rank& rank)
    {
        os << rank.getName();
        return os;
    }

    namespace rank
    {
        Symbolizable::view_type French::Symbols::ace()
        {
            static const Symbolizable::value_type s_ace{ "A" };
            return s_ace;
        }

        Symbolizable::view_type French::Symbols::two()
        {
            static const Symbolizable::value_type s_two{ "2" };
            return s_two;
        }

        Symbolizable::view_type French::Symbols::three()
        {
            static const Symbolizable::value_type s_three{ "3" };
            return s_three;
        }

        Symbolizable::view_type French::Symbols::four()
        {
            static const Symbolizable::value_type s_four{ "4" };
            return s_four;
        }

        Symbolizable::view_type French::Symbols::five()
        {
            static const Symbolizable::value_type s_five{ "5" };
            return s_five;
        }

        Symbolizable::view_type French::Symbols::six()
        {
            static const Symbolizable::value_type s_six{ "6" };
            return s_six;
        }

        Symbolizable::view_type French::Symbols::seven()
        {
            static const Symbolizable::value_type s_seven{ "7" };
            return s_seven;
        }

        Symbolizable::view_type French::Symbols::eight()
        {
            static const Symbolizable::value_type s_eight{ "8" };
            return s_eight;
        }

        Symbolizable::view_type French::Symbols::nine()
        {
            static const Symbolizable::value_type s_nine{ "9" };
            return s_nine;
        }

        Symbolizable::view_type French::Symbols::ten()
        {
            static const Symbolizable::value_type s_ten{ "10" };
            return s_ten;
        }

        Symbolizable::view_type French::Symbols::jack()
        {
            static const Symbolizable::value_type s_jack{ "J" };
            return s_jack;
        }

        Symbolizable::view_type French::Symbols::queen()
        {
            static const Symbolizable::value_type s_queen{ "Q" };
            return s_queen;
        }

        Symbolizable::view_type French::Symbols::king()
        {
            static const Symbolizable::value_type s_king{ "K" };
            return s_king;
        }

        const French::value_type& French::Ranks::ace()
        {
            static const value_type s_ace{ Rank::create("Ace", Symbols::ace()) };
            return s_ace;
        }

        const French::value_type& French::Ranks::two()
        {
            static const value_type s_two{ Rank::create("Two", Symbols::two()) };
            return s_two;
        }

        const French::value_type& French::Ranks::three()
        {
            static const value_type s_ace{ Rank::create("Three", Symbols::three()) };
            return s_ace;
        }

        const French::value_type& French::Ranks::four()
        {
            static const value_type s_four{ Rank::create("Four", Symbols::four()) };
            return s_four;
        }

        const French::value_type& French::Ranks::five()
        {
            static const value_type s_five{ Rank::create("Five", Symbols::five()) };
            return s_five;
        }

        const French::value_type& French::Ranks::six()
        {
            static const value_type s_six{ Rank::create("Six", Symbols::six()) };
            return s_six;
        }

        const French::value_type& French::Ranks::seven()
        {
            static const value_type s_seven{ Rank::create("Seven", Symbols::seven()) };
            return s_seven;
        }

        const French::value_type& French::Ranks::eight()
        {
            static const value_type s_eight{ Rank::create("Eight", Symbols::eight()) };
            return s_eight;
        }

        const French::value_type& French::Ranks::nine()
        {
            static const value_type s_nine{ Rank::create("Nine", Symbols::nine()) };
            return s_nine;
        }

        const French::value_type& French::Ranks::ten()
        {
            static const value_type s_ten{ Rank::create("Ten", Symbols::ten()) };
            return s_ten;
        }

        const French::value_type& French::Ranks::jack()
        {
            static const value_type s_jack{ Rank::create("Jack", Symbols::jack()) };
            return s_jack;
        }

        const French::value_type& French::Ranks::queen()
        {
            static const value_type s_queen{ Rank::create("Queen", Symbols::queen()) };
            return s_queen;
        }

        const French::value_type& French::Ranks::king()
        {
            static const value_type s_king{ Rank::create("King", Symbols::king()) };
            return s_king;
        }

        const French::container_type& French::ranks()
        {
            static const container_type s_ranks
                    {
                            Ranks::ace(), Ranks::two(), Ranks::three(), Ranks::four(),
                            Ranks::five(), Ranks::six(), Ranks::seven(), Ranks::eight(),
                            Ranks::nine(), Ranks::ten(), Ranks::jack(), Ranks::queen(), Ranks::king()
                    };
            return s_ranks;
        }

        French::size_type French::size()
        {
            return ranks().size();
        }

        const French::value_type& French::rankAt(French::size_type index)
        {
            return ranks().at(index);
        }

        Symbolizable::view_type Tarot::Symbols::knight()
        {
            static const Symbolizable::value_type s_knight{ "C" };
            return s_knight;
        }

        const Tarot::value_type& Tarot::Ranks::knight()
        {
            static const value_type s_knight{ Rank::create("Knight", Symbols::knight()) };
            return s_knight;
        }
    }
}

