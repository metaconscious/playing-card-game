//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_INAMEABLE_H
#define PLAYING_CARD_GAME_INAMEABLE_H


#include <string>
#include <string_view>

namespace pcg::helper
{
    template<typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    class IBasicNameable
    {
    public:
        using value_type = std::basic_string<CharT, Traits, Allocator>;
        using view_type = std::basic_string_view<CharT, Traits>;

        [[nodiscard]] virtual view_type getName() const = 0;
        virtual ~IBasicNameable() = default;
    };

    using INameable = IBasicNameable<char>;
}


#endif //PLAYING_CARD_GAME_INAMEABLE_H
