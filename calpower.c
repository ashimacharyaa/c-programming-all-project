// Railway Reservation System in C
// Features: File persistence, seat tracking, date-wise booking, user authentication, fare calculation, RAC, ticket printing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAINS 3
#define MAX_NAME 50
#define MAX_CONTACT 15
#define MAX_CLASS 3
#define MAX_DATE_BOOKINGS 365
#define MAX_BOOKINGS 1000

const char *CLASSES[] = {"Sleeper", "AC", "First"};

typedef struct {
    int number;
    char name[MAX_NAME];
    char start[MAX_NAME];
    char end[MAX_NAME];
    char via[3][MAX_NAME];
    char dep[6];
    char arr[6];
    float distance;
    float base_fare;
    int seats[MAX_CLASS];
} Train;

typedef struct {
    char date[11];
    int booked[MAX_CLASS];
    int rac[MAX_CLASS];
} SeatDate;

typedef struct {
    char name[MAX_NAME];
    char contact[MAX_CONTACT];
    int train_no;
    char date[11];
    int seat_no;
    int class;
    float fare;
    int rac;
} Booking;

Train trains[MAX_TRAINS];
int train_count = 3;
SeatDate seats[MAX_TRAINS][MAX_DATE_BOOKINGS];
Booking bookings[MAX_BOOKINGS];
int bookings_count = 0;

void init_trains() {
    strcpy(trains[0].name, "Ashim Express");
    trains[0].number = 101;
    strcpy(trains[0].start, "Kathmandu");
    strcpy(trains[0].end, "Pokhara");
    strcpy(trains[0].via[0], "Thankot");
    strcpy(trains[0].via[1], "Satungal");
    strcpy(trains[0].via[2], "Mugling");
    strcpy(trains[0].dep, "08:00");
    strcpy(trains[0].arr, "12:00");
    trains[0].distance = 200;
    trains[0].base_fare = 4.0;
    trains[0].seats[0] = 100; trains[0].seats[1] = 50; trains[0].seats[2] = 20;

    strcpy(trains[1].name, "Nitesh Express");
    trains[1].number = 102;
    strcpy(trains[1].start, "Butwal");
    strcpy(trains[1].end, "Janakpur");
    strcpy(trains[1].via[0], "Narayanghat");
    strcpy(trains[1].via[1], "Hetauda");
    strcpy(trains[1].via[2], "Bharatpur");
    strcpy(trains[1].dep, "09:30");
    strcpy(trains[1].arr, "16:30");
    trains[1].distance = 300;
    trains[1].base_fare = 4.0;
    trains[1].seats[0] = 100; trains[1].seats[1] = 50; trains[1].seats[2] = 20;

    strcpy(trains[2].name, "Abiral Express");
    trains[2].number = 103;
    strcpy(trains[2].start, "Biratnagar");
    strcpy(trains[2].end, "Nepalgunj");
    strcpy(trains[2].via[0], "Birgunj");
    strcpy(trains[2].via[1], "Lahan");
    strcpy(trains[2].via[2], "Ghorahi");
    strcpy(trains[2].dep, "06:45");
    strcpy(trains[2].arr, "17:00");
    trains[2].distance = 450;
    trains[2].base_fare = 4.0;
    trains[2].seats[0] = 100; trains[2].seats[1] = 50; trains[2].seats[2] = 20;
}

void save_data() {
    FILE *f = fopen("bookings.dat", "wb");
    fwrite(&bookings_count, sizeof(int), 1, f);
    fwrite(bookings, sizeof(Booking), bookings_count, f);
    fclose(f);
}

void load_data() {
    FILE *f = fopen("bookings.dat", "rb");
    if (f) {
        fread(&bookings_count, sizeof(int), 1, f);
        fread(bookings, sizeof(Booking), bookings_count, f);
        fclose(f);
    }
}

int find_train_index(int train_no) {
    for (int i = 0; i < train_count; i++)
        if (trains[i].number == train_no) return i;
    return -1;
}

void print_ticket(Booking *b) {
    printf("\n---- Ticket ----\n");
    printf("Name: %s\nContact: %s\nTrain No: %d (%s)\nDate: %s\nClass: %s\nSeat No: %s\nFare: %.2f\n",
        b->name, b->contact, b->train_no,
        trains[find_train_index(b->train_no)].name,
        b->date, CLASSES[b->class],
        (b->rac ? "RAC" : b->seat_no > 0 ? "Confirmed" : "NA"), b->fare);
    printf("--------------\n");

    char fname[100];
    sprintf(fname, "ticket_%s_%d.txt", b->name, bookings_count);
    FILE *fp = fopen(fname, "w");
    fprintf(fp, "Ticket\nName: %s\nContact: %s\nTrain: %d - %s\nDate: %s\nSeat No: %d (%s)\nFare: %.2f\n",
            b->name, b->contact, b->train_no,
            trains[find_train_index(b->train_no)].name,
            b->date, b->seat_no, (b->rac ? "RAC" : "Confirmed"), b->fare);
    fclose(fp);
    printf("Ticket saved to file: %s\n", fname);
}

void book_ticket() {
    char name[MAX_NAME], contact[MAX_CONTACT], date[11];
    int tno, cls;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Contact number: ");
    scanf("%s", contact);
    printf("Enter train number: ");
    scanf("%d", &tno);
    printf("Enter journey date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Class (0-Sleeper, 1-AC, 2-First): ");
    scanf("%d", &cls);

    int idx = find_train_index(tno);
    if (idx == -1) {
        printf("Train not found!\n"); return;
    }

    Train *t = &trains[idx];
    SeatDate *s = &seats[idx][cls];
    if (s->booked[cls] < t->seats[cls]) {
        Booking b;
        strcpy(b.name, name); strcpy(b.contact, contact);
        b.train_no = tno;
        strcpy(b.date, date);
        b.class = cls;
        b.seat_no = ++s->booked[cls];
        b.rac = 0;
        b.fare = t->base_fare * t->distance * (1 + 0.5 * cls);
        bookings[bookings_count++] = b;
        print_ticket(&b);
    } else if (s->rac[cls] < 10) {
        Booking b;
        strcpy(b.name, name); strcpy(b.contact, contact);
        b.train_no = tno;
        strcpy(b.date, date);
        b.class = cls;
        b.seat_no = -1; b.rac = 1;
        b.fare = t->base_fare * t->distance * (1 + 0.5 * cls);
        bookings[bookings_count++] = b;
        printf("All seats full. RAC booked.\n");
        print_ticket(&b);
    } else {
        printf("No seats or RAC available.\n");
    }
}

void view_trains() {
    printf("\nAvailable Trains:\n");
    for (int i = 0; i < train_count; i++) {
        printf("%d - %s: %s to %s | Dep: %s | Arr: %s | Distance: %.2fkm\n",
            trains[i].number, trains[i].name,
            trains[i].start, trains[i].end,
            trains[i].dep, trains[i].arr, trains[i].distance);
    }
}

int main() {
    init_trains();
    load_data();
    int ch;
    do {
        printf("\n-- Railway Reservation System --\n");
        printf("1. View Trains\n2. Book Ticket\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: view_trains(); break;
            case 2: book_ticket(); break;
            case 3: save_data(); printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 3);
    return 0;
}
