//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_RANK_H
#define PLAYING_CARD_GAME_RANK_H


#include "helper/EnableSharedFromThis.h"
#include "helper/Enumerable.h"
#include "helper/Nameable.h"
#include "helper/Symbolizable.h"
#include <ostream>
#include <vector>

using game::helper::EnableSharedFromThis;
using game::helper::impl::Enumerable;
using game::helper::impl::Nameable;
using game::helper::impl::Symbolizable;

namespace game::playing_card::deck::card
{
    class Rank : public Enumerable<Rank>, public Nameable, public Symbolizable
    {
    private:
        Rank(const char* name, const char* symbol);

        Rank(Nameable::value_type name, Symbolizable::value_type symbol);

        Rank(Nameable::view_type name, Symbolizable::view_type symbol);

    public:
        friend class EnableSharedFromThis<Rank>;

        friend std::ostream& operator<<(std::ostream& os, const Rank& rank);
    };

    namespace rank
    {
        class French
        {
        public:
            using element_type = const Rank;
            using value_type = std::shared_ptr<element_type>;
            using container_type = std::vector<value_type>;
            using size_type = container_type::size_type;

            class Symbols
            {
            public:
                static Symbolizable::view_type ace();

                static Symbolizable::view_type two();

                static Symbolizable::view_type three();

                static Symbolizable::view_type four();

                static Symbolizable::view_type five();

                static Symbolizable::view_type six();

                static Symbolizable::view_type seven();

                static Symbolizable::view_type eight();

                static Symbolizable::view_type nine();

                static Symbolizable::view_type ten();

                static Symbolizable::view_type jack();

                static Symbolizable::view_type queen();

                static Symbolizable::view_type king();
            };

            class Ranks
            {
            public:
                static const value_type& ace();

                static const value_type& two();

                static const value_type& three();

                static const value_type& four();

                static const value_type& five();

                static const value_type& six();

                static const value_type& seven();

                static const value_type& eight();

                static const value_type& nine();

                static const value_type& ten();

                static const value_type& jack();

                static const value_type& queen();

                static const value_type& king();
            };

            static const value_type& rankAt(size_type index);
        };

        class Tarot
        {
        public:
            using element_type = const Rank;
            using value_type = std::shared_ptr<element_type>;

            class Symbols
            {
            public:
                static Symbolizable::view_type knight();
            };

            class Ranks
            {
            public:
                static const value_type& knight();
            };
        };
    }
}


#endif //PLAYING_CARD_GAME_RANK_H
