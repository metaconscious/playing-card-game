//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_INAMEABLE_H
#define PLAYING_CARD_GAME_INAMEABLE_H


#include <string>
#include <string_view>

namespace game::helper
{
    template<typename CharT, typename Traits = std::char_traits<CharT>>
    class INameable
    {
    public:
        [[nodiscard]] virtual std::basic_string_view<CharT, Traits> getName() const = 0;
        virtual ~INameable() = default;
    };
}


#endif //PLAYING_CARD_GAME_INAMEABLE_H
