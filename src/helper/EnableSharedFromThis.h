//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_ENABLE_SHARED_FROM_THIS_H
#define PLAYING_CARD_GAME_ENABLE_SHARED_FROM_THIS_H


#include <memory>
#include <utility>

namespace game::helper
{
    template<typename Tp>
    class EnableSharedFromThis : public std::enable_shared_from_this<Tp>
    {
    public:
        template<typename ...Args>
        static std::shared_ptr<Tp> create(Args ...args)
        {
            return std::shared_ptr<Tp>{ new Tp{ std::forward<Args>(args)... } };
        }

        std::shared_ptr<Tp> copy()
        {
            return this->shared_from_this();
        }

        std::shared_ptr<const Tp> copy() const
        {
            return this->shared_from_this();
        }

        virtual ~EnableSharedFromThis() = default;
    };
}


#endif //PLAYING_CARD_GAME_ENABLE_SHARED_FROM_THIS_H
