#include <iostream>
#include <iomanip>
#include <string>

std::string shortCell(std::string value) {
    if (value == "wall") {
        return "##";
    } else if (value == "road") {
        return "..";
    } else if (value == "parking") {
        return "PP";
    } else if (value == "empty") {
        return "  ";
    } else if (value == "ENTRY") {
        return "IN";
    } else if (value == "EXIT") {
        return "OU";
    }

    if (value.length() >= 3) {
        return value.substr(0, 3);
    }

    if (value.length() == 2) {
        return value;
    }

    return value + " ";
}

void showMap(std::string map[16][16]) {
    std::cout << "\nPARKING LOT MAP\n";
    std::cout << "## = wall | .. = road | PP = free parking | IN = entry | OU = exit\n";
    std::cout << "A plate means that the space is occupied.\n\n";

    for (int row = 0; row < 16; row++) {
        for (int column = 0; column < 16; column++) {
            std::cout << std::setw(4) << shortCell(map[row][column]);
        }
        std::cout << "\n";
    }
}

void showSummary(bool occupied[48]) {
    int busy = 0;
    int freeSpaces = 0;

    for (int i = 0; i < 48; i++) {
        if (occupied[i]) {
            busy++;
        } else {
            freeSpaces++;
        }
    }

    std::cout << "\nAVAILABILITY\n";
    std::cout << "Occupied spaces: " << busy << "\n";
    std::cout << "Free spaces: " << freeSpaces << "\n";
    std::cout << "Total spaces: 48\n";
}
