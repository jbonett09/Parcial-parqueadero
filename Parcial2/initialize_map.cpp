#include <string>

void fillBorders(std::string map[16][16]) {
    for (int row = 0; row < 16; row++) {
        map[row][0] = "wall";
        map[row][15] = "wall";
    }

    for (int column = 0; column < 16; column++) {
        map[0][column] = "wall";
        map[15][column] = "wall";
    }
}

void fillRoadArea(std::string map[16][16]) {
    for (int row = 1; row < 15; row++) {
        for (int column = 1; column < 15; column++) {
            map[row][column] = "road";
        }
    }
}

void placeParkingSpaces(std::string map[16][16], int spotRow[48], int spotColumn[48]) {
    int parkingRows[6] = {2, 3, 5, 6, 8, 9};
    int parkingColumns[8] = {1, 2, 4, 5, 7, 8, 10, 11};
    int index = 0;

    for (int rowIndex = 0; rowIndex < 6; rowIndex++) {
        for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
            int row = parkingRows[rowIndex];
            int column = parkingColumns[columnIndex];

            map[row][column] = "parking";
            spotRow[index] = row;
            spotColumn[index] = column;
            index++;
        }
    }
}

void placeVerticalRoads(std::string map[16][16]) {
    int roadColumns[4] = {3, 6, 9, 12};

    for (int i = 0; i < 4; i++) {
        int column = roadColumns[i];
        for (int row = 1; row < 15; row++) {
            map[row][column] = "road";
        }
    }
}

void placeHorizontalRoads(std::string map[16][16]) {
    int roadRows[6] = {1, 4, 7, 10, 12, 13};

    for (int i = 0; i < 6; i++) {
        int row = roadRows[i];
        for (int column = 1; column < 15; column++) {
            map[row][column] = "road";
        }
    }
}

void placeEntryAndExit(std::string map[16][16]) {
    map[0][2] = "ENTRY";
    map[0][3] = "ENTRY";
    map[0][12] = "EXIT";
    map[0][13] = "EXIT";

    map[1][2] = "road";
    map[1][3] = "road";
    map[1][12] = "road";
    map[1][13] = "road";
}

void initializeVehicleData(bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48]) {
    for (int i = 0; i < 48; i++) {
        occupied[i] = false;
        plateList[i] = "";
        entryHour[i] = -1;
        entryMinute[i] = -1;
    }
}

void initializeMap(std::string map[16][16], bool occupied[48], std::string plateList[48], int entryHour[48], int entryMinute[48], int spotRow[48], int spotColumn[48]) {
    for (int row = 0; row < 16; row++) {
        for (int column = 0; column < 16; column++) {
            map[row][column] = "empty";
        }
    }

    fillBorders(map);
    fillRoadArea(map);
    placeParkingSpaces(map, spotRow, spotColumn);
    placeVerticalRoads(map);
    placeHorizontalRoads(map);
    placeEntryAndExit(map);
    initializeVehicleData(occupied, plateList, entryHour, entryMinute);
}
