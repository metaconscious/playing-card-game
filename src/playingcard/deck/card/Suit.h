//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_SUIT_H
#define PLAYING_CARD_GAME_SUIT_H


#include "helper/EnableSharedFromThis.h"
#include "helper/Enumerable.h"
#include "helper/Nameable.h"
#include "helper/Symbolizable.h"
#include <ostream>
#include <memory>
#include <vector>


using game::helper::EnableSharedFromThis;
using game::helper::impl::Enumerable;
using game::helper::impl::Nameable;
using game::helper::impl::Symbolizable;

namespace game::playing_card::deck::card
{
    class Suit : public Enumerable<Suit>, public Nameable, public Symbolizable
    {
    private:
        Suit(const char* nameRaw, const char* symbolRaw);

        Suit(Nameable::value_type name, Symbolizable::value_type symbol);

        Suit(Nameable::view_type nameView, Symbolizable::view_type symbolView);

    public:
        friend class EnableSharedFromThis<Suit>;

        friend std::ostream& operator<<(std::ostream& os, const Suit& suit);
    };

    namespace suit
    {
        class French
        {
        public:
            using element_type = const Suit;
            using value_type = std::shared_ptr<element_type>;
            using container_type = std::vector<value_type>;
            using size_type = container_type::size_type;

            class Symbols
            {
            public:
                static Symbolizable::view_type clubs();

                static Symbolizable::view_type diamonds();

                static Symbolizable::view_type hearts();

                static Symbolizable::view_type spades();
            };

            class Suits
            {
            public:
                static const value_type& clubs();

                static const value_type& diamonds();

                static const value_type& hearts();

                static const value_type& spades();

            };

            static const value_type& suitAt(size_type index);

        };
    }
}


#endif //PLAYING_CARD_GAME_SUIT_H
