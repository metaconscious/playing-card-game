//
// Created by user on 1/26/22.
//

#ifndef PLAYING_CARD_GAME_ABBREVIABLE_H
#define PLAYING_CARD_GAME_ABBREVIABLE_H


#include "IAbbreviable.h"
#include <memory>
#include <string>

namespace pcg::helper::impl
{
    template<typename CharT,
            typename Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>>
    class BasicAbbreviable : public IBasicAbbreviable<CharT, Traits, Allocator>
    {
    public:
        using value_type = typename IBasicAbbreviable<CharT, Traits, Allocator>::value_type;
        using view_type = typename IBasicAbbreviable<CharT, Traits, Allocator>::view_type;

    private:
        value_type m_abbreviation;

    public:
        explicit BasicAbbreviable(value_type abbreviation) : m_abbreviation{ std::move(abbreviation) }
        {
        }

        explicit BasicAbbreviable(view_type abbreviation) : m_abbreviation{ abbreviation }
        {
        }

        view_type getAbbreviation() const override
        {
            return m_abbreviation;
        }

    };

    using Abbreviable = BasicAbbreviable<char>;
}


#endif //PLAYING_CARD_GAME_ABBREVIABLE_H
