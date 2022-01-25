//
// Created by user on 1/25/22.
//

#ifndef PLAYING_CARD_GAME_NAMEABLE_H
#define PLAYING_CARD_GAME_NAMEABLE_H


#include "INameable.h"
#include <string>
#include <memory>

namespace game::helper::impl
{
    template<typename CharT,
            typename Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>>
    class BasicNameable : public INameable<CharT, Traits>
    {
    public:
        using value_type = std::basic_string<CharT, Traits, Allocator>;
        using view_type = std::basic_string_view<CharT, Traits>;

    private:
        value_type m_name{};

    public:
        explicit BasicNameable(std::basic_string<CharT, Traits, Allocator> name) : m_name{ std::move(name) }
        {
        }

        explicit BasicNameable(std::basic_string_view<CharT, Traits> name) : m_name{ name }
        {
        }

        std::basic_string_view<CharT, Traits> getName() const override
        {
            return m_name;
        }

    };

    using Nameable = BasicNameable<char>;

}


#endif //PLAYING_CARD_GAME_NAMEABLE_H
