#include <iostream>
#include <string>
#include "display_map.cpp"
#include "initialize_map.cpp"
#include "payment.cpp"
#include "vehicle_entry.cpp"
#include "vehicle_exit.cpp"

void initializeMap(std::string map[16][16], bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48], int spotRow[48], int spotColumn[48]);
void showMap(std::string map[16][16]);
void showSummary(bool occupied[48]);
void registerVehicleEntry(std::string map[16][16], bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48], int spotRow[48], int spotColumn[48]);
void registerVehicleExit(std::string map[16][16], bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48], int spotRow[48], int spotColumn[48]);

void run() {
    std::string map[16][16];
    bool occupied[48];
    std::string plateList[48];
    int entryHour[48];
    int entryMinute[48];
    int spotRow[48];
    int spotColumn[48];

    initializeMap(map, occupied, plateList, entryHour, entryMinute, spotRow, spotColumn);

    int option = 0;

    do {
        std::cout << "\n===== PARKING LOT MENU =====\n";
        std::cout << "1. Show parking lot map\n";
        std::cout << "2. Register vehicle entry\n";
        std::cout << "3. Register vehicle exit\n";
        std::cout << "4. Show availability summary\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        while(!(std::cin >> option)) {
            std::cout << "invalid option\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid option: ";
        }

        if (option == 1) {
            showMap(map);
        } else if (option == 2) {
            registerVehicleEntry(map, occupied, plateList, entryHour, entryMinute, spotRow, spotColumn);
        } else if (option == 3) {
            registerVehicleExit(map, occupied, plateList, entryHour, entryMinute, spotRow, spotColumn);
        } else if (option == 4) {
            showSummary(occupied);
        } else if (option == 5) {
            std::cout << "Program finished.\n";
        } else {
            std::cout << "Invalid option.\n";
        }

    } while (option != 5);

}
