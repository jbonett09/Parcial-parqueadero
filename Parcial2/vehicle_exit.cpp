#include <iostream>
#include <string>

int calculateParkedMinutes(int startHour, int startMinute, int endHour, int endMinute);
int calculatePayment(int totalMinutes);

int findVehicleByPlate(std::string plateList[48], bool occupied[48], std::string plate) {
    for (int i = 0; i < 48; i++) {
        if (occupied[i] && plateList[i] == plate) {
            return i;
        }
    }

    return -1;
}

void askExitTime(int *hour, int *minute) {
    std::cout << "Enter exit hour (0-23): ";
    while(!(std::cin >> *hour)) {
        std::cout << "invalid number\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter exit hour (0-23): ";
    }

    std::cout << "Enter exit minute (0-59): ";
    while(!(std::cin >> *minute)) {
        std::cout << "invalid number\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter exit minute (0-59): ";
    }
}

void registerVehicleExit(std::string map[16][16], bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48], int spotRow[48], int spotColumn[48]) {
    std::string plate;
    int exitHour;
    int exitMinute;

    std::cout << "Enter vehicle plate: ";
    std::cin >> plate;

    int vehicleIndex = findVehicleByPlate(plateList, occupied, plate);

    if (vehicleIndex == -1) {
        std::cout << "Vehicle not found.\n";
        return;
    }

    askExitTime(&exitHour, &exitMinute);

    if (exitHour < 0 || exitHour > 23 || exitMinute < 0 || exitMinute > 59) {
        std::cout << "Invalid time.\n";
        return;
    }

    int totalMinutes = calculateParkedMinutes(entryHour[vehicleIndex], entryMinute[vehicleIndex], exitHour, exitMinute);
    int totalPayment = calculatePayment(totalMinutes);

    std::cout << "Parked minutes: " << totalMinutes << "\n";
    std::cout << "Total to pay: " << totalPayment << "\n";

    occupied[vehicleIndex] = false;
    plateList[vehicleIndex] = "";
    entryHour[vehicleIndex] = -1;
    entryMinute[vehicleIndex] = -1;

    map[spotRow[vehicleIndex]][spotColumn[vehicleIndex]] = "parking";

    std::cout << "Vehicle exit registered correctly.\n";
}
