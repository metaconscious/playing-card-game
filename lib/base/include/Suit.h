//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_SUIT_H
#define PLAYING_CARD_GAME_SUIT_H


#include "EnableSharedFromThis.h"
#include "Enumerable.h"
#include "Nameable.h"
#include "Symbolizable.h"
#include <ostream>
#include <memory>
#include <vector>


using pcg::helper::EnableSharedFromThis;
using pcg::helper::impl::Enumerable;
using pcg::helper::impl::Nameable;
using pcg::helper::impl::Symbolizable;

namespace pcg::playing_card::deck::card
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

        private:
            static const container_type& suits();

        public:
            static const value_type& suitAt(size_type index);

            static size_type size();
        };
    }
}


#endif //PLAYING_CARD_GAME_SUIT_H
