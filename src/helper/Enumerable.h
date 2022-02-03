//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_ENUMERABLE_H
#define PLAYING_CARD_GAME_ENUMERABLE_H


#include "EnableSharedFromThis.h"
#include "IEnumerable.h"
#include <compare>
#include <cstddef>

namespace game::helper::impl
{
    template <typename Target>
    class Enumerable : public EnableSharedFromThis<Target>, public IEnumerable<Target>
    {
    public:
        using value_type = typename IEnumerable<Target>::value_type;

    private:
        static inline value_type s_size{ 0 };

    public:
        static value_type size()
        {
            return s_size;
        }

    private:
        value_type m_value{};

    public:
        Enumerable() : m_value{ s_size++ } {}

        [[nodiscard]] value_type getValue() const override
        {
            return m_value;
        }

    };
}


#endif //PLAYING_CARD_GAME_ENUMERABLE_H
