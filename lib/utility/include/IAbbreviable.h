//
// Created by user on 1/26/22.
//

#ifndef PLAYING_CARD_GAME_IABBREVIABLE_H
#define PLAYING_CARD_GAME_IABBREVIABLE_H


#include <memory>
#include <string_view>

namespace pcg::helper
{
    template<typename CharT,
            typename Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>>
    class IBasicAbbreviable
    {
    public:
        using value_type = std::basic_string<CharT, Traits, Allocator>;
        using view_type = std::basic_string_view<CharT, Traits>;

        [[nodiscard]] virtual view_type getAbbreviation() const = 0;
        virtual ~IBasicAbbreviable() = default;
    };
}


#endif //PLAYING_CARD_GAME_IABBREVIABLE_H
