//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_ISYMBOLIZABLE_H
#define PLAYING_CARD_GAME_ISYMBOLIZABLE_H


#include <string_view>

namespace pcg::helper
{
    template<typename CharT,
            typename Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>>
    class ISymbolizable
    {
    public:
        using value_type = std::basic_string<CharT, Traits, Allocator>;
        using view_type = std::basic_string_view<CharT, Traits>;

        [[nodiscard]] virtual view_type getSymbol() const = 0;
        virtual ~ISymbolizable() = default;
    };
}


#endif //PLAYING_CARD_GAME_ISYMBOLIZABLE_H
