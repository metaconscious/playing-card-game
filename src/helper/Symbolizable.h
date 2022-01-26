//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_SYMBOLIZABLE_H
#define PLAYING_CARD_GAME_SYMBOLIZABLE_H


#include "ISymbolizable.h"
#include <memory>
#include <string>
#include <utility>

namespace game::helper::impl
{
    template<typename CharT,
            typename Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>>
    class BasicSymbolizable : public ISymbolizable<CharT, Traits>
    {
    public:
        using value_type = typename ISymbolizable<CharT, Traits, Allocator>::value_type ;
        using view_type = typename ISymbolizable<CharT, Traits, Allocator>::view_type ;

    private:
        value_type m_symbol{};

    public:
        explicit BasicSymbolizable(value_type symbol) : m_symbol{ std::move(symbol) }
        {
        }

        explicit BasicSymbolizable(view_type symbol) : m_symbol{ symbol }
        {
        }

        [[nodiscard]] view_type getSymbol() const override
        {
            return m_symbol;
        }

    };

    using Symbolizable = BasicSymbolizable<char>;
}


#endif //PLAYING_CARD_GAME_SYMBOLIZABLE_H
