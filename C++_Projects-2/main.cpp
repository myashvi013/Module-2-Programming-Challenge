/*
 * Carnival: main.cpp
 * Master: Yashvi Mehta
 * Show: Stage manager to check every feature works
 */

#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> playList;

    std::cout << " --- Welcome to the Linked List Carnival! --- \n\n";

    std::cout << " Show 1: Making numbers with a magic loop...\n";
    for (int step = 7; step <= 35; step += 7) {
        playList.addItem(step);
    }
    std::cout << "Current Track: " << playList << " (Count: " << playList.getSize() << ")\n\n";

    std::cout << " Show 2: Searching for hidden treasures...\n";
    std::cout << "Looking for 21: " << (playList.find(21) ? "Allocated! " : "Missing! ") << "\n";
    std::cout << "Looking for 99: " << (playList.find(99) ? "Allocated! " : "Missing! ") << "\n\n";

    std::cout << "🪄 Show 3: Magic tricks (Removals)...\n";
    std::cout << "Removing head (7)... ";
    playList.remove(7);
    std::cout << "List: " << playList << "\n";

    std::cout << "Removing middle (21)... ";
    playList.remove(21);
    std::cout << "List: " << playList << "\n";

    std::cout << "Removing tail (35)... ";
    playList.remove(35);
    std::cout << "List: " << playList << "\n\n";

    std::cout << " Show 4: Trying to remove an imaginary number (√-404)... ";
    bool ghostResult = playList.remove(404);
    std::cout << (ghostResult ? "Success?" : "Nothing happened!") << "\n";
    std::cout << "List: " << playList << " (Count: " << playList.getSize() << ")\n\n";

    std::cout << " Show 5: Emptying the list completely (Bye, Bye!)...\n";
    playList.remove(14);
    playList.remove(28);
    std::cout << "Final List: " << playList << " (Count: " << playList.getSize() << ")\n\n";

    std::cout << " Show trial successfull! (All test complete)\n";

    return 0;
}