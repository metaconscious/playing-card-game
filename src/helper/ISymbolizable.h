//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_ISYMBOLIZABLE_H
#define PLAYING_CARD_GAME_ISYMBOLIZABLE_H


#include <string_view>

namespace game::helper
{
    template<typename CharT, typename Traits = std::char_traits<CharT>>
    class ISymbolizable
    {
    public:
        [[nodiscard]] virtual std::basic_string_view<CharT, Traits> getSymbol() const = 0;
        virtual ~ISymbolizable() = default;
    };
}


#endif //PLAYING_CARD_GAME_ISYMBOLIZABLE_H
