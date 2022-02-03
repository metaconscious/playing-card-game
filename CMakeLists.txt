cmake_minimum_required(VERSION 3.21)
project(playing_card_game VERSION 0.37.15 LANGUAGES CXX)
add_subdirectory(tests)

set(CMAKE_CXX_STANDARD 20)

# -Weffc++ not in use
# since "error: base class ‘class std::enable_shared_from_this<_Ty>’ has accessible non-virtual destructor"
# would be thrown by compiler
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wsign-conversion -Werror -pedantic-errors")

include_directories(src)


add_executable(playing_card_game
        src/helper/Enumerable.h
        src/helper/IEnumerable.h
        src/playingcard/deck/card/Rank.cpp
        src/playingcard/deck/card/Rank.h
        src/playingcard/deck/card/Suit.cpp
        src/playingcard/deck/card/Suit.h
        src/playingcard/deck/Card.cpp
        src/playingcard/deck/Card.h
        src/main.cpp src/helper/INameable.h src/helper/Nameable.h src/helper/Symbolizable.h src/helper/ISymbolizable.h src/helper/EnableSharedFromThis.h src/helper/IAbbreviable.h src/helper/Abbreviable.h src/playingcard/Deck.h src/helper/VectorWrapper.h src/playingcard/Deck.cpp)
