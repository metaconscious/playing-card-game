//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_IENUMERABLE_H
#define PLAYING_CARD_GAME_IENUMERABLE_H

#include <cstddef>

namespace game::helper
{
    template<typename Target>
    class IEnumerable
    {
    public:
        using target_type = Target;
        using value_type = std::size_t;

        [[nodiscard]] virtual value_type getValue() const = 0;
        virtual ~IEnumerable() = default;
    };
}

#endif //PLAYING_CARD_GAME_IENUMERABLE_H
