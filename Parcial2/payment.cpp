int calculateParkedMinutes(int startHour, int startMinute, int endHour, int endMinute) {
    int startTotal = startHour * 60 + startMinute;
    int endTotal = endHour * 60 + endMinute;

    if (endTotal < startTotal) {
        endTotal = endTotal + 24 * 60;
    }

    return endTotal - startTotal;
}

int calculatePayment(int totalMinutes) {
    int pricePerHour = 3000;
    int chargedHours = totalMinutes / 60;

    if (totalMinutes % 60 != 0) {
        chargedHours++;
    }

    if (chargedHours == 0) {
        chargedHours = 1;
    }

    return chargedHours * pricePerHour;
}
