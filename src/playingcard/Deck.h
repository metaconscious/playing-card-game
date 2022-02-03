//
// Created by user on 2/2/22.
//

#ifndef PLAYING_CARD_GAME_DECK_H
#define PLAYING_CARD_GAME_DECK_H


#include "helper/VectorWrapper.h"
#include "deck/Card.h"
#include <functional>
#include <memory>
#include <ostream>

using game::helper::impl::VectorWrapper;

namespace game::playing_card
{
    template<typename Element, typename Value = std::shared_ptr<Element>>
    class BasicDeck : public EnableSharedFromThis<BasicDeck<Element>>, public VectorWrapper<Value>
    {
    public:
        using element_type = Element;
        using value_type = Value;
        using container_type = typename VectorWrapper<Value>::container_type;
        using size_type = typename VectorWrapper<Value>::size_type;

    protected:
        explicit BasicDeck(std::function<void(container_type& vector)> initializer)
        {
            initializer(this->VectorWrapper<Value>::m_vector);
        }

    public:
        friend class EnableSharedFromThis<BasicDeck<Element>>;

        friend std::ostream& operator<<(std::ostream& os, const BasicDeck& deck)
        {
            os << static_cast<const VectorWrapper<Value>&>(deck);
            return os;
        }

    };

    using Deck = BasicDeck<const deck::Card>;

    namespace deck
    {
        class Standard52CardDeck
        {
        public:
            static std::shared_ptr<Deck> create();
        };
    }
}


#endif //PLAYING_CARD_GAME_DECK_H
