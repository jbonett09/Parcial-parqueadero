#include <iostream>
#include <string>

int findFreeSpace(bool occupied[48]) {
    for (int i = 0; i < 48; i++) {
        if (!occupied[i]) {
            return i;
        }
    }

    return -1;
}

bool plateAlreadyInside(std::string plateList[48], bool occupied[48], std::string plate) {
    for (int i = 0; i < 48; i++) {
        if (occupied[i] && plateList[i] == plate) {
            return true;
        }
    }

    return false;
}

void askEntryTime(int *hour, int *minute) {
    std::cout << "Enter entry hour (0-23): ";
    while(!(std::cin >> *hour)) {
        std::cout << "invalid number\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter entry hour (0-23): ";
    }

    std::cout << "Enter entry minute (0-59): ";
    while(!(std::cin >> *minute)) {
        std::cout << "invalid number\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter entry minute (0-59): ";
    }
}

void registerVehicleEntry(std::string map[16][16], bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48], int spotRow[48], int spotColumn[48]) {
    int freeIndex = findFreeSpace(occupied);

    if (freeIndex == -1) {
        std::cout << "The parking lot is full.\n";
        return;
    }

    std::string plate;
    int hour;
    int minute;

    std::cout << "Enter vehicle plate: ";
    std::cin >> plate;

    if (plateAlreadyInside(plateList, occupied, plate)) {
        std::cout << "This plate is already inside the parking lot.\n";
        return;
    }

    askEntryTime(&hour, &minute);

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        std::cout << "Invalid time.\n";
        return;
    }

    occupied[freeIndex] = true;
    plateList[freeIndex] = plate;
    entryHour[freeIndex] = hour;
    entryMinute[freeIndex] = minute;

    map[spotRow[freeIndex]][spotColumn[freeIndex]] = plate;

    std::cout << "Vehicle registered correctly.\n";
    std::cout << "Assigned space number: " << freeIndex + 1 << "\n";
}
