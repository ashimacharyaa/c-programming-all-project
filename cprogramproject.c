#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 10
#define ADMIN_USER "admin"
#define ADMIN_PASS "1234"

typedef struct {
    int seatNumber;
    char name[50];
    int isBooked;
} Seat;

Seat seats[TOTAL_SEATS];

void initializeSeats() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].name, "None");
    }
}

void displaySeats() {
    printf("\nSeat Status:\n");
    printf("Seat\tStatus\t\tName\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("%d\t%s\t\t%s\n", seats[i].seatNumber, 
               seats[i].isBooked ? "Booked" : "Available", 
               seats[i].name);
    }
}

void bookSeat() {
    int seatNum;
    char name[50];

    printf("Enter seat number to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (seats[seatNum - 1].isBooked) {
        printf("Seat already booked.\n");
    } else {
        printf("Enter passenger name: ");
        scanf(" %[^\n]", name);
        seats[seatNum - 1].isBooked = 1;
        strcpy(seats[seatNum - 1].name, name);
        printf("Seat %d successfully booked for %s.\n", seatNum, name);
    }
}

void cancelBooking() {
    int seatNum;
    printf("Enter seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (seats[seatNum - 1].isBooked) {
        seats[seatNum - 1].isBooked = 0;
        strcpy(seats[seatNum - 1].name, "None");
        printf("Seat %d booking cancelled.\n", seatNum);
    } else {
        printf("Seat %d is already available.\n", seatNum);
    }
}

void adminPanel() {
    char user[20], pass[20];
    printf("\n=== Admin Login ===\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, ADMIN_USER) == 0 && strcmp(pass, ADMIN_PASS) == 0) {
        int choice;
        do {
            printf("\n=== Admin Panel ===\n");
            printf("1. View All Booked Seats\n");
            printf("2. Reset All Bookings\n");
            printf("3. Exit Admin Panel\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nBooked Seats:\n");
                    for (int i = 0; i < TOTAL_SEATS; i++) {
                        if (seats[i].isBooked) {
                            printf("Seat %d - %s\n", seats[i].seatNumber, seats[i].name);
                        }
                    }
                    break;
                case 2:
                    initializeSeats();
                    printf("All bookings have been reset.\n");
                    break;
                case 3:
                    printf("Exiting admin panel.\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while (choice != 3);
    } else {
        printf("Incorrect username or password.\n");
    }
}

int main() {
    int choice;
    initializeSeats();

    do {
        printf("\n====== Railway Reservation System ======\n");
        printf("1. View Seat Status\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Admin Panel\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                adminPanel();
                break;
            case 5:
                printf("Thank you for using the reservation system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
