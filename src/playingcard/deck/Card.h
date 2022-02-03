//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_CARD_H
#define PLAYING_CARD_GAME_CARD_H


#include "helper/Abbreviable.h"
#include "helper/EnableSharedFromThis.h"
#include "helper/Enumerable.h"
#include "helper/Nameable.h"
#include "helper/Symbolizable.h"
#include "card/Rank.h"
#include "card/Suit.h"
#include <memory>
#include <ostream>
#include <vector>

using pcg::helper::impl::Abbreviable;
using pcg::helper::EnableSharedFromThis;
using pcg::helper::impl::Enumerable;
using pcg::helper::impl::Nameable;
using pcg::helper::impl::Symbolizable;

namespace pcg::playing_card::deck
{
    class Card : public Abbreviable, public Enumerable<Card>, public Nameable, public Symbolizable
    {
    public:
        using rank_type = const card::Rank;
        using rank_ptr = std::shared_ptr<rank_type>;
        using suit_type = const card::Suit;
        using suit_ptr = std::shared_ptr<suit_type>;

    private:
        rank_ptr m_rank;
        suit_ptr m_suit;

        Card(Nameable::value_type name, Abbreviable::value_type abbreviable, Symbolizable::value_type symbol);

        Card(Nameable::view_type name, Abbreviable::view_type abbreviable, Symbolizable::view_type symbol);

        Card(const char* name, const char* abbreviable, const char* symbol);

        Card(const rank_ptr& rankPtr, const suit_ptr& suitPtr, const char* symbol);

        Card(const rank_ptr& rankPtr, const suit_ptr& suitPtr, Symbolizable::value_type symbol);

        Card(const rank_ptr& rankPtr, const suit_ptr& suitPtr, Symbolizable::view_type symbol);

        Card(const Card& card) = default;

        Card(Card&& rank) noexcept;

    public:
        friend class EnableSharedFromThis<Card>;

        friend std::ostream& operator<<(std::ostream& os, const Card& card);
    };

    namespace card
    {
        class Standard52Card
        {
        public:
            using element_type = const Card;
            using value_type = std::shared_ptr<element_type>;
            using container_type = std::vector<value_type>;
            using size_type = container_type::size_type;

        private:
            static const container_type& cards();

        public:
            static size_type size();

            class Symbols
            {
            public:
                static Symbolizable::view_type aceOfClubs();

                static Symbolizable::view_type twoOfClubs();

                static Symbolizable::view_type threeOfClubs();

                static Symbolizable::view_type fourOfClubs();

                static Symbolizable::view_type fiveOfClubs();

                static Symbolizable::view_type sixOfClubs();

                static Symbolizable::view_type sevenOfClubs();

                static Symbolizable::view_type eightOfClubs();

                static Symbolizable::view_type nineOfClubs();

                static Symbolizable::view_type tenOfClubs();

                static Symbolizable::view_type jackOfClubs();

                static Symbolizable::view_type queenOfClubs();

                static Symbolizable::view_type kingOfClubs();

                static Symbolizable::view_type aceOfDiamonds();

                static Symbolizable::view_type twoOfDiamonds();

                static Symbolizable::view_type threeOfDiamonds();

                static Symbolizable::view_type fourOfDiamonds();

                static Symbolizable::view_type fiveOfDiamonds();

                static Symbolizable::view_type sixOfDiamonds();

                static Symbolizable::view_type sevenOfDiamonds();

                static Symbolizable::view_type eightOfDiamonds();

                static Symbolizable::view_type nineOfDiamonds();

                static Symbolizable::view_type tenOfDiamonds();

                static Symbolizable::view_type jackOfDiamonds();

                static Symbolizable::view_type queenOfDiamonds();

                static Symbolizable::view_type kingOfDiamonds();

                static Symbolizable::view_type aceOfHearts();

                static Symbolizable::view_type twoOfHearts();

                static Symbolizable::view_type threeOfHearts();

                static Symbolizable::view_type fourOfHearts();

                static Symbolizable::view_type fiveOfHearts();

                static Symbolizable::view_type sixOfHearts();

                static Symbolizable::view_type sevenOfHearts();

                static Symbolizable::view_type eightOfHearts();

                static Symbolizable::view_type nineOfHearts();

                static Symbolizable::view_type tenOfHearts();

                static Symbolizable::view_type jackOfHearts();

                static Symbolizable::view_type queenOfHearts();

                static Symbolizable::view_type kingOfHearts();

                static Symbolizable::view_type aceOfSpades();

                static Symbolizable::view_type twoOfSpades();

                static Symbolizable::view_type threeOfSpades();

                static Symbolizable::view_type fourOfSpades();

                static Symbolizable::view_type fiveOfSpades();

                static Symbolizable::view_type sixOfSpades();

                static Symbolizable::view_type sevenOfSpades();

                static Symbolizable::view_type eightOfSpades();

                static Symbolizable::view_type nineOfSpades();

                static Symbolizable::view_type tenOfSpades();

                static Symbolizable::view_type jackOfSpades();

                static Symbolizable::view_type queenOfSpades();

                static Symbolizable::view_type kingOfSpades();
            };

            class Cards
            {
            public:
                static const value_type& aceOfClubs();

                static const value_type& twoOfClubs();

                static const value_type& threeOfClubs();

                static const value_type& fourOfClubs();

                static const value_type& fiveOfClubs();

                static const value_type& sixOfClubs();

                static const value_type& sevenOfClubs();

                static const value_type& eightOfClubs();

                static const value_type& nineOfClubs();

                static const value_type& tenOfClubs();

                static const value_type& jackOfClubs();

                static const value_type& queenOfClubs();

                static const value_type& kingOfClubs();

                static const value_type& aceOfDiamonds();

                static const value_type& twoOfDiamonds();

                static const value_type& threeOfDiamonds();

                static const value_type& fourOfDiamonds();

                static const value_type& fiveOfDiamonds();

                static const value_type& sixOfDiamonds();

                static const value_type& sevenOfDiamonds();

                static const value_type& eightOfDiamonds();

                static const value_type& nineOfDiamonds();

                static const value_type& tenOfDiamonds();

                static const value_type& jackOfDiamonds();

                static const value_type& queenOfDiamonds();

                static const value_type& kingOfDiamonds();

                static const value_type& aceOfHearts();

                static const value_type& twoOfHearts();

                static const value_type& threeOfHearts();

                static const value_type& fourOfHearts();

                static const value_type& fiveOfHearts();

                static const value_type& sixOfHearts();

                static const value_type& sevenOfHearts();

                static const value_type& eightOfHearts();

                static const value_type& nineOfHearts();

                static const value_type& tenOfHearts();

                static const value_type& jackOfHearts();

                static const value_type& queenOfHearts();

                static const value_type& kingOfHearts();

                static const value_type& aceOfSpades();

                static const value_type& twoOfSpades();

                static const value_type& threeOfSpades();

                static const value_type& fourOfSpades();

                static const value_type& fiveOfSpades();

                static const value_type& sixOfSpades();

                static const value_type& sevenOfSpades();

                static const value_type& eightOfSpades();

                static const value_type& nineOfSpades();

                static const value_type& tenOfSpades();

                static const value_type& jackOfSpades();

                static const value_type& queenOfSpades();

                static const value_type& kingOfSpades();
            };

            static const value_type& cardAt(size_type index);
        };

        class Misc
        {
        public:
            using element_type = const Card;
            using value_type = std::shared_ptr<element_type>;

            class Symbols
            {
            public:
                static Symbolizable::view_type cardBack();

                static Symbolizable::view_type knightOfClubs();

                static Symbolizable::view_type knightOfDiamonds();

                static Symbolizable::view_type knightOfHearts();

                static Symbolizable::view_type knightOfSpades();

                static Symbolizable::view_type whiteJoker();

                static Symbolizable::view_type blackJoker();
            };

            class Cards
            {
            public:
                static const value_type& cardBack();

                static const value_type& knightOfClubs();

                static const value_type& knightOfDiamonds();

                static const value_type& knightOfHearts();

                static const value_type& knightOfSpades();

                static const value_type& blackJoker();

                static const value_type& whiteJoker();
            };
        };
    }
}


#endif //PLAYING_CARD_GAME_CARD_H
