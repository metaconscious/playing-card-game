//
// Created by user on 1/25/22.
//

#include "Card.h"

#include <utility>

namespace pcg::playing_card::deck
{
    Card::Card(const rank_ptr& rankPtr, const suit_ptr& suitPtr, Symbolizable::value_type symbol)
            : Abbreviable{
            Symbolizable::value_type{ suitPtr->getSymbol() } + Symbolizable::value_type{ rankPtr->getSymbol() }},
              Nameable{
                      Nameable::value_type{ rankPtr->getName() } + " of " + Nameable::value_type{ suitPtr->getName() }},
              Symbolizable{ std::move(symbol) }
    {

    }

    Card::Card(const Card::rank_ptr& rankPtr, const Card::suit_ptr& suitPtr, Symbolizable::view_type symbol)
            : Abbreviable{
            Symbolizable::value_type{ suitPtr->getSymbol() } + Symbolizable::value_type{ rankPtr->getSymbol() }},
              Nameable{
                      Nameable::value_type{ rankPtr->getName() } + " of " + Nameable::value_type{ suitPtr->getName() }},
              Symbolizable{ symbol }
    {

    }

    Card::Card(const Card::rank_ptr& rankPtr, const Card::suit_ptr& suitPtr, const char* symbol)
            : Card(rankPtr, suitPtr, Symbolizable::view_type{ symbol })
    {

    }

    Card::Card(Card&& card) noexcept
            : Abbreviable{ std::move(card) }, Enumerable<Card>{ std::move(card) },
              Nameable{ std::move(card) }, Symbolizable{ std::move(card) },
              m_rank{ std::move(card.m_rank) }, m_suit{ std::move(card.m_suit) }
    {

    }

    std::ostream& operator<<(std::ostream& os, const Card& card)
    {
        os << card.getName();
        return os;
    }

    Card::Card(const char* name, const char* abbreviable, const char* symbol)
            : Card{ Abbreviable::view_type{ abbreviable },
                    Nameable::view_type{ name },
                    Symbolizable::view_type{ symbol }}
    {

    }

    Card::Card(Nameable::value_type name, Abbreviable::value_type abbreviable, Symbolizable::value_type symbol)
            : Abbreviable{ std::move(abbreviable) },
              Nameable{ std::move(name) },
              Symbolizable{ std::move(symbol) }
    {

    }

    Card::Card(Nameable::view_type name, Abbreviable::view_type abbreviable, Symbolizable::view_type symbol)
            : Abbreviable{ abbreviable },
              Nameable{ name },
              Symbolizable{ symbol }
    {

    }

    namespace card
    {
        Symbolizable::view_type Standard52Card::Symbols::aceOfClubs()
        {
            static const Symbolizable::value_type s_aceOfClubs{ "🂡" };
            return s_aceOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::twoOfClubs()
        {
            static const Symbolizable::value_type s_twoOfClubs{ "🂢" };
            return s_twoOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::threeOfClubs()
        {
            static const Symbolizable::value_type s_threeOfClubs{ "🃓" };
            return s_threeOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::fourOfClubs()
        {
            static const Symbolizable::value_type s_fourOfClubs{ "🃔" };
            return s_fourOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::fiveOfClubs()
        {
            static const Symbolizable::value_type s_fiveOfClubs{ "🃕" };
            return s_fiveOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::sixOfClubs()
        {
            static const Symbolizable::value_type s_sixOfClubs{ "🃖" };
            return s_sixOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::sevenOfClubs()
        {
            static const Symbolizable::value_type s_sevenOfClubs{ "🃗" };
            return s_sevenOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::eightOfClubs()
        {
            static const Symbolizable::value_type s_eightOfClubs{ "🃘" };
            return s_eightOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::nineOfClubs()
        {
            static const Symbolizable::value_type s_nineOfClubs{ "🃙" };
            return s_nineOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::tenOfClubs()
        {
            static const Symbolizable::value_type s_tenOfClubs{ "🃚" };
            return s_tenOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::jackOfClubs()
        {
            static const Symbolizable::value_type s_jackOfClubs{ "🃛" };
            return s_jackOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::queenOfClubs()
        {
            static const Symbolizable::value_type s_queenOfClubs{ "🃝" };
            return s_queenOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::kingOfClubs()
        {
            static const Symbolizable::value_type s_kingOfClubs{ "🃞" };
            return s_kingOfClubs;
        }

        Symbolizable::view_type Standard52Card::Symbols::aceOfDiamonds()
        {
            static const Symbolizable::value_type s_aceOfDiamonds{ "🃁" };
            return s_aceOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::twoOfDiamonds()
        {
            static const Symbolizable::value_type s_twoOfDiamonds{ "🃂" };
            return s_twoOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::threeOfDiamonds()
        {
            static const Symbolizable::value_type s_threeOfDiamonds{ "🃃" };
            return s_threeOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::fourOfDiamonds()
        {
            static const Symbolizable::value_type s_fourOfDiamonds{ "🃄" };
            return s_fourOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::fiveOfDiamonds()
        {
            static const Symbolizable::value_type s_fiveOfDiamonds{ "🃅" };
            return s_fiveOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::sixOfDiamonds()
        {
            static const Symbolizable::value_type s_sixOfDiamonds{ "🃆" };
            return s_sixOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::sevenOfDiamonds()
        {
            static const Symbolizable::value_type s_sevenOfDiamonds{ "🃇" };
            return s_sevenOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::eightOfDiamonds()
        {
            static const Symbolizable::value_type s_eightOfDiamonds{ "🃈" };
            return s_eightOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::nineOfDiamonds()
        {
            static const Symbolizable::value_type s_nineOfDiamonds{ "🃉" };
            return s_nineOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::tenOfDiamonds()
        {
            static const Symbolizable::value_type s_tenOfDiamonds{ "🃊" };
            return s_tenOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::jackOfDiamonds()
        {
            static const Symbolizable::value_type s_jackOfDiamonds{ "🃋" };
            return s_jackOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::queenOfDiamonds()
        {
            static const Symbolizable::value_type s_queenOfDiamonds{ "🃍" };
            return s_queenOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::kingOfDiamonds()
        {
            static const Symbolizable::value_type s_kingOfDiamonds{ "🃎" };
            return s_kingOfDiamonds;
        }

        Symbolizable::view_type Standard52Card::Symbols::aceOfHearts()
        {
            static const Symbolizable::value_type s_aceOfHearts{ "🂱" };
            return s_aceOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::twoOfHearts()
        {
            static const Symbolizable::value_type s_twoOfHearts{ "🂲" };
            return s_twoOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::threeOfHearts()
        {
            static const Symbolizable::value_type s_threeOfHearts{ "🂳" };
            return s_threeOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::fourOfHearts()
        {
            static const Symbolizable::value_type s_fourOfHearts{ "🂴" };
            return s_fourOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::fiveOfHearts()
        {
            static const Symbolizable::value_type s_fiveOfHearts{ "🂵" };
            return s_fiveOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::sixOfHearts()
        {
            static const Symbolizable::value_type s_sixOfHearts{ "🂶" };
            return s_sixOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::sevenOfHearts()
        {
            static const Symbolizable::value_type s_sevenOfHearts{ "🂷" };
            return s_sevenOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::eightOfHearts()
        {
            static const Symbolizable::value_type s_eightOfHearts{ "🂸" };
            return s_eightOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::nineOfHearts()
        {
            static const Symbolizable::value_type s_nineOfHearts{ "🂹" };
            return s_nineOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::tenOfHearts()
        {
            static const Symbolizable::value_type s_tenOfHearts{ "🂺" };
            return s_tenOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::jackOfHearts()
        {
            static const Symbolizable::value_type s_jackOfHearts{ "🂻" };
            return s_jackOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::queenOfHearts()
        {
            static const Symbolizable::value_type s_queenOfHearts{ "🂽" };
            return s_queenOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::kingOfHearts()
        {
            static const Symbolizable::value_type s_kingOfHearts{ "🂾" };
            return s_kingOfHearts;
        }

        Symbolizable::view_type Standard52Card::Symbols::aceOfSpades()
        {
            static const Symbolizable::value_type s_aceOfSpades{ "🂡" };
            return s_aceOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::twoOfSpades()
        {
            static const Symbolizable::value_type s_twoOfSpades{ "🂢" };
            return s_twoOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::threeOfSpades()
        {
            static const Symbolizable::value_type s_threeOfSpades{ "🂣" };
            return s_threeOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::fourOfSpades()
        {
            static const Symbolizable::value_type s_fourOfSpades{ "🂤" };
            return s_fourOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::fiveOfSpades()
        {
            static const Symbolizable::value_type s_fiveOfSpades{ "🂥" };
            return s_fiveOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::sixOfSpades()
        {
            static const Symbolizable::value_type s_sixOfSpades{ "🂦" };
            return s_sixOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::sevenOfSpades()
        {
            static const Symbolizable::value_type s_sevenOfSpades{ "🂧" };
            return s_sevenOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::eightOfSpades()
        {
            static const Symbolizable::value_type s_eightOfSpades{ "🂨" };
            return s_eightOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::nineOfSpades()
        {
            static const Symbolizable::value_type s_nineOfSpades{ "🂩" };
            return s_nineOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::tenOfSpades()
        {
            static const Symbolizable::value_type s_tenOfSpades{ "🂪" };
            return s_tenOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::jackOfSpades()
        {
            static const Symbolizable::value_type s_jackOfSpades{ "🂫" };
            return s_jackOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::queenOfSpades()
        {
            static const Symbolizable::value_type s_queenOfSpades{ "🂭" };
            return s_queenOfSpades;
        }

        Symbolizable::view_type Standard52Card::Symbols::kingOfSpades()
        {
            static const Symbolizable::value_type s_kingOfSpades{ "🂮" };
            return s_kingOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::aceOfClubs()
        {
            static const value_type s_aceOfClubs{
                    Card::create(rank::French::Ranks::ace(), suit::French::Suits::clubs(), Symbols::aceOfClubs()) };
            return s_aceOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::twoOfClubs()
        {
            static const value_type s_twoOfClubs{
                    Card::create(rank::French::Ranks::two(), suit::French::Suits::clubs(), Symbols::twoOfClubs()) };
            return s_twoOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::threeOfClubs()
        {
            static const value_type s_threeOfClubs{
                    Card::create(rank::French::Ranks::three(), suit::French::Suits::clubs(), Symbols::threeOfClubs()) };
            return s_threeOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fourOfClubs()
        {
            static const value_type s_fourOfClubs{
                    Card::create(rank::French::Ranks::four(), suit::French::Suits::clubs(), Symbols::fourOfClubs()) };
            return s_fourOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fiveOfClubs()
        {
            static const value_type s_fiveOfClubs{
                    Card::create(rank::French::Ranks::five(), suit::French::Suits::clubs(), Symbols::fiveOfClubs()) };
            return s_fiveOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sixOfClubs()
        {
            static const value_type s_sixOfClubs{
                    Card::create(rank::French::Ranks::six(), suit::French::Suits::clubs(), Symbols::sixOfClubs()) };
            return s_sixOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sevenOfClubs()
        {
            static const value_type s_sevenOfClubs{
                    Card::create(rank::French::Ranks::seven(), suit::French::Suits::clubs(), Symbols::sevenOfClubs()) };
            return s_sevenOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::eightOfClubs()
        {
            static const value_type s_eightOfClubs{
                    Card::create(rank::French::Ranks::eight(), suit::French::Suits::clubs(), Symbols::eightOfClubs()) };
            return s_eightOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::nineOfClubs()
        {
            static const value_type s_nineOfClubs{
                    Card::create(rank::French::Ranks::nine(), suit::French::Suits::clubs(), Symbols::nineOfClubs()) };
            return s_nineOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::tenOfClubs()
        {
            static const value_type s_tenOfClubs{
                    Card::create(rank::French::Ranks::ten(), suit::French::Suits::clubs(), Symbols::tenOfClubs()) };
            return s_tenOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::jackOfClubs()
        {
            static const value_type s_jackOfClubs{
                    Card::create(rank::French::Ranks::jack(), suit::French::Suits::clubs(), Symbols::jackOfClubs()) };
            return s_jackOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::queenOfClubs()
        {
            static const value_type s_queenOfClubs{
                    Card::create(rank::French::Ranks::queen(), suit::French::Suits::clubs(), Symbols::queenOfClubs()) };
            return s_queenOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::kingOfClubs()
        {
            static const value_type s_kingOfClubs{
                    Card::create(rank::French::Ranks::king(), suit::French::Suits::clubs(), Symbols::kingOfClubs()) };
            return s_kingOfClubs;
        }

        const Standard52Card::value_type& Standard52Card::Cards::aceOfDiamonds()
        {
            static const value_type s_aceOfDiamonds{
                    Card::create(rank::French::Ranks::ace(), suit::French::Suits::diamonds(),
                            Symbols::aceOfDiamonds()) };
            return s_aceOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::twoOfDiamonds()
        {
            static const value_type s_twoOfDiamonds{
                    Card::create(rank::French::Ranks::two(), suit::French::Suits::diamonds(),
                            Symbols::twoOfDiamonds()) };
            return s_twoOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::threeOfDiamonds()
        {
            static const value_type s_threeOfDiamonds{
                    Card::create(rank::French::Ranks::three(), suit::French::Suits::diamonds(),
                            Symbols::threeOfDiamonds()) };
            return s_threeOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fourOfDiamonds()
        {
            static const value_type s_fourOfDiamonds{
                    Card::create(rank::French::Ranks::four(), suit::French::Suits::diamonds(),
                            Symbols::fourOfDiamonds()) };
            return s_fourOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fiveOfDiamonds()
        {
            static const value_type s_fiveOfDiamonds{
                    Card::create(rank::French::Ranks::five(), suit::French::Suits::diamonds(),
                            Symbols::fiveOfDiamonds()) };
            return s_fiveOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sixOfDiamonds()
        {
            static const value_type s_sixOfDiamonds{
                    Card::create(rank::French::Ranks::six(), suit::French::Suits::diamonds(),
                            Symbols::sixOfDiamonds()) };
            return s_sixOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sevenOfDiamonds()
        {
            static const value_type s_sevenOfDiamonds{
                    Card::create(rank::French::Ranks::seven(), suit::French::Suits::diamonds(),
                            Symbols::sevenOfDiamonds()) };
            return s_sevenOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::eightOfDiamonds()
        {
            static const value_type s_eightOfDiamonds{
                    Card::create(rank::French::Ranks::eight(), suit::French::Suits::diamonds(),
                            Symbols::eightOfDiamonds()) };
            return s_eightOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::nineOfDiamonds()
        {
            static const value_type s_nineOfDiamonds{
                    Card::create(rank::French::Ranks::nine(), suit::French::Suits::diamonds(),
                            Symbols::nineOfDiamonds()) };
            return s_nineOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::tenOfDiamonds()
        {
            static const value_type s_tenOfDiamonds{
                    Card::create(rank::French::Ranks::ten(), suit::French::Suits::diamonds(),
                            Symbols::tenOfDiamonds()) };
            return s_tenOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::jackOfDiamonds()
        {
            static const value_type s_jackOfDiamonds{
                    Card::create(rank::French::Ranks::jack(), suit::French::Suits::diamonds(),
                            Symbols::jackOfDiamonds()) };
            return s_jackOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::queenOfDiamonds()
        {
            static const value_type s_queenOfDiamonds{
                    Card::create(rank::French::Ranks::queen(), suit::French::Suits::diamonds(),
                            Symbols::queenOfDiamonds()) };
            return s_queenOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::kingOfDiamonds()
        {
            static const value_type s_kingOfDiamonds{
                    Card::create(rank::French::Ranks::king(), suit::French::Suits::diamonds(),
                            Symbols::kingOfDiamonds()) };
            return s_kingOfDiamonds;
        }

        const Standard52Card::value_type& Standard52Card::Cards::aceOfHearts()
        {
            static const value_type s_aceOfHearts{
                    Card::create(rank::French::Ranks::ace(), suit::French::Suits::hearts(), Symbols::aceOfHearts()) };
            return s_aceOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::twoOfHearts()
        {
            static const value_type s_twoOfHearts{
                    Card::create(rank::French::Ranks::two(), suit::French::Suits::hearts(), Symbols::twoOfHearts()) };
            return s_twoOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::threeOfHearts()
        {
            static const value_type s_threeOfHearts{
                    Card::create(rank::French::Ranks::three(), suit::French::Suits::hearts(),
                            Symbols::threeOfHearts()) };
            return s_threeOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fourOfHearts()
        {
            static const value_type s_fourOfHearts{
                    Card::create(rank::French::Ranks::four(), suit::French::Suits::hearts(), Symbols::fourOfHearts()) };
            return s_fourOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fiveOfHearts()
        {
            static const value_type s_fiveOfHearts{
                    Card::create(rank::French::Ranks::five(), suit::French::Suits::hearts(), Symbols::fiveOfHearts()) };
            return s_fiveOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sixOfHearts()
        {
            static const value_type s_sixOfHearts{
                    Card::create(rank::French::Ranks::six(), suit::French::Suits::hearts(), Symbols::sixOfHearts()) };
            return s_sixOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sevenOfHearts()
        {
            static const value_type s_sevenOfHearts{
                    Card::create(rank::French::Ranks::seven(), suit::French::Suits::hearts(),
                            Symbols::sevenOfHearts()) };
            return s_sevenOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::eightOfHearts()
        {
            static const value_type s_eightOfHearts{
                    Card::create(rank::French::Ranks::eight(), suit::French::Suits::hearts(),
                            Symbols::eightOfHearts()) };
            return s_eightOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::nineOfHearts()
        {
            static const value_type s_nineOfHearts{
                    Card::create(rank::French::Ranks::nine(), suit::French::Suits::hearts(), Symbols::nineOfHearts()) };
            return s_nineOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::tenOfHearts()
        {
            static const value_type s_tenOfHearts{
                    Card::create(rank::French::Ranks::ten(), suit::French::Suits::hearts(), Symbols::tenOfHearts()) };
            return s_tenOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::jackOfHearts()
        {
            static const value_type s_jackOfHearts{
                    Card::create(rank::French::Ranks::jack(), suit::French::Suits::hearts(), Symbols::jackOfHearts()) };
            return s_jackOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::queenOfHearts()
        {
            static const value_type s_queenOfHearts{
                    Card::create(rank::French::Ranks::queen(), suit::French::Suits::hearts(),
                            Symbols::queenOfHearts()) };
            return s_queenOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::kingOfHearts()
        {
            static const value_type s_kingOfHearts{
                    Card::create(rank::French::Ranks::king(), suit::French::Suits::hearts(), Symbols::kingOfHearts()) };
            return s_kingOfHearts;
        }

        const Standard52Card::value_type& Standard52Card::Cards::aceOfSpades()
        {
            static const value_type s_aceOfSpades{
                    Card::create(rank::French::Ranks::ace(), suit::French::Suits::spades(), Symbols::aceOfSpades()) };
            return s_aceOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::twoOfSpades()
        {
            static const value_type s_twoOfSpades{
                    Card::create(rank::French::Ranks::two(), suit::French::Suits::spades(), Symbols::twoOfSpades()) };
            return s_twoOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::threeOfSpades()
        {
            static const value_type s_threeOfSpades{
                    Card::create(rank::French::Ranks::three(), suit::French::Suits::spades(),
                            Symbols::threeOfSpades()) };
            return s_threeOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fourOfSpades()
        {
            static const value_type s_fourOfSpades{
                    Card::create(rank::French::Ranks::four(), suit::French::Suits::spades(), Symbols::fourOfSpades()) };
            return s_fourOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::fiveOfSpades()
        {
            static const value_type s_fiveOfSpades{
                    Card::create(rank::French::Ranks::five(), suit::French::Suits::spades(), Symbols::fiveOfSpades()) };
            return s_fiveOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sixOfSpades()
        {
            static const value_type s_sixOfSpades{
                    Card::create(rank::French::Ranks::six(), suit::French::Suits::spades(), Symbols::sixOfSpades()) };
            return s_sixOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::sevenOfSpades()
        {
            static const value_type s_sevenOfSpades{
                    Card::create(rank::French::Ranks::seven(), suit::French::Suits::spades(),
                            Symbols::sevenOfSpades()) };
            return s_sevenOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::eightOfSpades()
        {
            static const value_type s_eightOfSpades{
                    Card::create(rank::French::Ranks::eight(), suit::French::Suits::spades(),
                            Symbols::eightOfSpades()) };
            return s_eightOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::nineOfSpades()
        {
            static const value_type s_nineOfSpades{
                    Card::create(rank::French::Ranks::nine(), suit::French::Suits::spades(), Symbols::nineOfSpades()) };
            return s_nineOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::tenOfSpades()
        {
            static const value_type s_tenOfSpades{
                    Card::create(rank::French::Ranks::ten(), suit::French::Suits::spades(), Symbols::tenOfSpades()) };
            return s_tenOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::jackOfSpades()
        {
            static const value_type s_jackOfSpades{
                    Card::create(rank::French::Ranks::jack(), suit::French::Suits::spades(), Symbols::jackOfSpades()) };
            return s_jackOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::queenOfSpades()
        {
            static const value_type s_queenOfSpades{
                    Card::create(rank::French::Ranks::queen(), suit::French::Suits::spades(),
                            Symbols::queenOfSpades()) };
            return s_queenOfSpades;
        }

        const Standard52Card::value_type& Standard52Card::Cards::kingOfSpades()
        {
            static const value_type s_kingOfSpades{
                    Card::create(rank::French::Ranks::king(), suit::French::Suits::spades(), Symbols::kingOfSpades()) };
            return s_kingOfSpades;
        }

        const Standard52Card::container_type& Standard52Card::cards()
        {
            static const container_type s_cards
                    {
                            Cards::aceOfClubs(),
                            Cards::twoOfClubs(),
                            Cards::threeOfClubs(),
                            Cards::fourOfClubs(),
                            Cards::fiveOfClubs(),
                            Cards::sixOfClubs(),
                            Cards::sevenOfClubs(),
                            Cards::eightOfClubs(),
                            Cards::nineOfClubs(),
                            Cards::tenOfClubs(),
                            Cards::jackOfClubs(),
                            Cards::queenOfClubs(),
                            Cards::kingOfClubs(),
                            Cards::aceOfDiamonds(),
                            Cards::twoOfDiamonds(),
                            Cards::threeOfDiamonds(),
                            Cards::fourOfDiamonds(),
                            Cards::fiveOfDiamonds(),
                            Cards::sixOfDiamonds(),
                            Cards::sevenOfDiamonds(),
                            Cards::eightOfDiamonds(),
                            Cards::nineOfDiamonds(),
                            Cards::tenOfDiamonds(),
                            Cards::jackOfDiamonds(),
                            Cards::queenOfDiamonds(),
                            Cards::kingOfDiamonds(),
                            Cards::aceOfHearts(),
                            Cards::twoOfHearts(),
                            Cards::threeOfHearts(),
                            Cards::fourOfHearts(),
                            Cards::fiveOfHearts(),
                            Cards::sixOfHearts(),
                            Cards::sevenOfHearts(),
                            Cards::eightOfHearts(),
                            Cards::nineOfHearts(),
                            Cards::tenOfHearts(),
                            Cards::jackOfHearts(),
                            Cards::queenOfHearts(),
                            Cards::kingOfHearts(),
                            Cards::aceOfSpades(),
                            Cards::twoOfSpades(),
                            Cards::threeOfSpades(),
                            Cards::fourOfSpades(),
                            Cards::fiveOfSpades(),
                            Cards::sixOfSpades(),
                            Cards::sevenOfSpades(),
                            Cards::eightOfSpades(),
                            Cards::nineOfSpades(),
                            Cards::tenOfSpades(),
                            Cards::jackOfSpades(),
                            Cards::queenOfSpades(),
                            Cards::kingOfSpades()
                    };
            return s_cards;
        }

        Standard52Card::size_type Standard52Card::size()
        {
            return cards().size();
        }

        const Standard52Card::value_type& Standard52Card::cardAt(Standard52Card::size_type index)
        {
            return cards().at(index);
        }

        Symbolizable::view_type Misc::Symbols::cardBack()
        {
            static const Symbolizable::value_type s_cardBack{ "🂠" };
            return s_cardBack;
        }

        Symbolizable::view_type Misc::Symbols::knightOfClubs()
        {
            static const Symbolizable::value_type s_knightOfClubs{ "🃜" };
            return s_knightOfClubs;
        }

        Symbolizable::view_type Misc::Symbols::knightOfDiamonds()
        {
            static const Symbolizable::value_type s_knightOfDiamonds{ "🃌" };
            return s_knightOfDiamonds;
        }

        Symbolizable::view_type Misc::Symbols::knightOfHearts()
        {
            static const Symbolizable::value_type s_knightOfHearts{ "🂼" };
            return s_knightOfHearts;
        }

        Symbolizable::view_type Misc::Symbols::knightOfSpades()
        {
            static const Symbolizable::value_type s_knightOfSpades{ "🂬" };
            return s_knightOfSpades;
        }

        Symbolizable::view_type Misc::Symbols::whiteJoker()
        {
            static const Symbolizable::value_type s_whiteJoker{ "🃟" };
            return s_whiteJoker;
        }

        Symbolizable::view_type Misc::Symbols::blackJoker()
        {
            static const Symbolizable::value_type s_blackJoker{ "🃏" };
            return s_blackJoker;
        }

        const Misc::value_type& Misc::Cards::cardBack()
        {
            static const value_type s_cardBack{ Card::create("Card Back", "back", Symbols::cardBack()) };
            return s_cardBack;
        }

        const Misc::value_type& Misc::Cards::knightOfClubs()
        {
            static const value_type s_knightOfClubs
                    {
                            Card::create
                                    (
                                            rank::Tarot::Ranks::knight(),
                                            suit::French::Suits::clubs(),
                                            Symbols::knightOfClubs()
                                    )
                    };
            return s_knightOfClubs;
        }

        const Misc::value_type& Misc::Cards::knightOfDiamonds()
        {
            static const value_type s_knightOfDiamonds
                    {
                            Card::create
                                    (
                                            rank::Tarot::Ranks::knight(),
                                            suit::French::Suits::diamonds(),
                                            Symbols::knightOfDiamonds()
                                    )
                    };
            return s_knightOfDiamonds;
        }

        const Misc::value_type& Misc::Cards::knightOfHearts()
        {
            static const value_type s_knightOfHearts
                    {
                            Card::create
                                    (
                                            rank::Tarot::Ranks::knight(),
                                            suit::French::Suits::hearts(),
                                            Symbols::knightOfHearts()
                                    )
                    };
            return s_knightOfHearts;
        }

        const Misc::value_type& Misc::Cards::knightOfSpades()
        {
            static const value_type s_knightOfSpades
                    {
                            Card::create
                                    (
                                            rank::Tarot::Ranks::knight(),
                                            suit::French::Suits::spades(),
                                            Symbols::knightOfSpades()
                                    )
                    };
            return s_knightOfSpades;
        }

        const Misc::value_type& Misc::Cards::blackJoker()
        {
            static const value_type s_blackJoker{ Card::create("Black Joker", "bJ", Symbols::blackJoker()) };
            return s_blackJoker;
        }

        const Misc::value_type& Misc::Cards::whiteJoker()
        {
            static const value_type s_whiteJoker{ Card::create("White Joker", "wJ", Symbols::whiteJoker()) };
            return s_whiteJoker;
        }
    }
}

