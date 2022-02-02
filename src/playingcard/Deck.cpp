//
// Created by user on 2/2/22.
//

#include "Deck.h"

namespace game::playing_card::deck
{

    std::shared_ptr<Deck> Standard52CardDeck::create()
    {
        return std::shared_ptr<Deck>(Deck::create([](Deck::container_type& vec)
        {
            for (Deck::size_type i {0}; i < card::Standard52Card::size(); ++i)
            {
                vec.push_back(card::Standard52Card::cardAt(i));
            }
        }));
    }
}