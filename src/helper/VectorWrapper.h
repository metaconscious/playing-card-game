//
// Created by user on 2/2/22.
//

#ifndef PLAYING_CARD_GAME_VECTOR_WRAPPER_H
#define PLAYING_CARD_GAME_VECTOR_WRAPPER_H


#include "playingcard/deck/Card.h"
#include <algorithm>
#include <concepts>
#include <functional>
#include <random>
#include <vector>
#include <ostream>

using pcg::playing_card::deck::Card;

namespace pcg::helper::impl
{
    template<typename Value>
    requires std::totally_ordered<Value>
    class VectorWrapper
    {
    public:
        using value_type = Value;
        using container_type = std::vector<value_type>;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = typename container_type::size_type;
        using difference_type = typename container_type::difference_type;
        using iterator = typename container_type::iterator;
        using const_iterator = typename container_type::const_iterator;
        using reverse_iterator = typename container_type::reverse_iterator;
        using const_reverse_iterator = typename container_type::const_reverse_iterator;

    protected:
        container_type m_vector;

    public:
        // element access
        [[nodiscard]] constexpr reference at(size_type index)
        {
            return m_vector.at(index);
        }

        [[nodiscard]] constexpr const_reference at(size_type index) const
        {
            return m_vector.at(index);
        }

        [[nodiscard]] constexpr reference operator[](size_type index)
        {
            return m_vector[index];
        }

        [[nodiscard]] constexpr const_reference operator[](size_type index) const
        {
            return m_vector[index];
        }

        [[nodiscard]] constexpr reference front()
        {
            return m_vector.front();
        }

        [[nodiscard]] constexpr const_reference front() const
        {
            return m_vector.front();
        }

        [[nodiscard]] constexpr reference back()
        {
            return m_vector.back();
        }

        [[nodiscard]] constexpr const_reference back() const
        {
            return m_vector.back();
        }

        // iterators
        [[nodiscard]] constexpr iterator begin()
        {
            return m_vector.begin();
        }

        [[nodiscard]] constexpr const_iterator cbegin()
        {
            return m_vector.cbegin();
        }

        [[nodiscard]] constexpr iterator end()
        {
            return m_vector.end();
        }

        [[nodiscard]] constexpr const_iterator cend()
        {
            return m_vector.cend();
        }

        [[nodiscard]] constexpr reverse_iterator rbegin()
        {
            return m_vector.rbegin();
        }

        [[nodiscard]] constexpr const_reverse_iterator crbegin()
        {
            return m_vector.crbegin();
        }

        [[nodiscard]] constexpr reverse_iterator rend()
        {
            return m_vector.rend();
        }

        [[nodiscard]] constexpr const_reverse_iterator crend()
        {
            return m_vector.crend();
        }

        // capacity
        [[nodiscard]] constexpr bool empty() const noexcept
        {
            return m_vector.empty();
        }

        [[nodiscard]] constexpr size_type size() const noexcept
        {
            return m_vector.size();
        }

        [[nodiscard]] constexpr size_type max_size() const noexcept
        {
            return m_vector.max_size();
        }

        constexpr void reserve(size_type newCapacity)
        {
            m_vector.reserve(newCapacity);
        }

        [[nodiscard]] constexpr size_type capacity() const noexcept
        {
            return m_vector.capacity();
        }

        constexpr void shrink_to_fit()
        {
            m_vector.shrink_to_fit();
        }

        // modifiers
        constexpr void clear() noexcept
        {
            m_vector.clear();
        }

        constexpr iterator insert(const_iterator position, const value_type& value)
        {
            return m_vector.insert(position, value);
        }

        constexpr iterator insert(const_iterator position, value_type&& value)
        {
            return m_vector.insert(position, value);
        }

        constexpr iterator insert(const_iterator position, size_type count, const value_type& value)
        {
            return m_vector.insert(position, count, value);
        }

        template<class InputIt>
        constexpr iterator insert(const_iterator position, InputIt first, InputIt last)
        {
            return m_vector.insert(position, first, last);
        }

        constexpr iterator insert(const_iterator position, std::initializer_list<Value> initializerList)
        {
            return m_vector.insert(position, initializerList);
        }

        template<typename ...Args>
        constexpr iterator emplace(const_iterator position, Args&& ...args)
        {
            return m_vector.emplace(position, &args...);
        }

        constexpr iterator erase(const_iterator position)
        {
            return m_vector.erase(position);
        }

        constexpr iterator erase(const_iterator first, const_iterator last)
        {
            return m_vector.erase(first, last);
        }

        constexpr void push_back(const value_type& value)
        {
            m_vector.push_back(value);
        }

        constexpr void push_back(value_type&& value)
        {
            m_vector.push_back(value);
        }

        template<typename ... Args>
        constexpr reference emplace_back(Args&& ...args)
        {
            return m_vector.template emplace_back(&args...);
        }

        constexpr void pop_back()
        {
            m_vector.pop_back();
        }

        constexpr void resize(size_type count)
        {
            m_vector.resize(count);
        }

        constexpr void resize(size_type count, const value_type& value)
        {
            m_vector.resize(count, value);
        }

        constexpr void swap(container_type& other) noexcept
        {
            m_vector.swap(other);
        }

        // member functions
        constexpr container_type& get()
        {
            return m_vector;
        }

        constexpr const container_type& get() const
        {
            return m_vector;
        }

        template<typename Compare>
        void sort(Compare compare)
        {
            std::ranges::sort(m_vector, compare);
        }

        void sort()
        {
            sort(std::greater<Value>());
        }

        void descending_sort()
        {
            sort(std::less<Value>());
        }

        template<typename UniformRandomBitGenerator>
        requires std::uniform_random_bit_generator<UniformRandomBitGenerator>
        void shuffle(UniformRandomBitGenerator gen)
        {
            std::ranges::shuffle(m_vector, gen);
        }

        void shuffle()
        {
            static std::random_device r{};
            static std::seed_seq seed{ r(), r(), r(), r(), r(), r() };
            static std::mt19937 mersenneTwister{ seed };
            shuffle(mersenneTwister);
        }

        template<typename Compare>
        constexpr bool find(const Value& value, Compare compare) const
        {
            return std::ranges::binary_search(m_vector, value, compare);
        }

        constexpr bool find(const Value& value) const
        {
            return std::ranges::binary_search(m_vector, value);
        }

        constexpr void forEach(std::function<void(const Value&)> execute) const
        {
            for (const auto& value: m_vector)
            {
                execute(value);
            }
        }

        // non-member functions
        friend std::ostream& operator<<(std::ostream& os, const VectorWrapper& wrapper)
        {
            for (auto&& constCardSharedPtr: wrapper.m_vector)
            {
                os << constCardSharedPtr->getSymbol() << ' ';
            }
            return os;
        }

    };
}


#endif //PLAYING_CARD_GAME_VECTOR_WRAPPER_H
