#include <stdio.h>

struct Expense {
    float farePerPerson;
    int numPersons;
    float hotelCharge;
    float discPct;
};

struct Booking {
    int id;
    char name[50];
    char dest[50];
    struct Expense exp;
};

int main() {
    int n;
    printf("Enter the number of bookings: ");
    scanf("%d", &n);

    struct Booking b[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details of Booking %d\nEnter Booking ID: ", i + 1);
        scanf("%d", &b[i].id);

        printf("Enter Customer Name: ");
        scanf("%s", b[i].name);

        printf("Enter Destination: ");
        scanf("%s", b[i].dest);

        printf("Enter Travel Fare Per Person: ");
        scanf("%f", &b[i].exp.farePerPerson);

        printf("Enter Number of Persons: ");
        scanf("%d", &b[i].exp.numPersons);

        printf("Enter Hotel Charge: ");
        scanf("%f", &b[i].exp.hotelCharge);

        printf("Enter Discount Percentage: ");
        scanf("%f", &b[i].exp.discPct);
    }

    printf("\n========== Travel Booking Details ==========\n");

    for (int i = 0; i < n; i++) {
        float totalFare = b[i].exp.farePerPerson * b[i].exp.numPersons;
        float preDisc = totalFare + b[i].exp.hotelCharge;
        float discAmt = (b[i].exp.discPct / 100) * preDisc;
        float finalCost = preDisc - discAmt;

        printf("Booking %d\nBooking ID : %d\nCustomer Name : %s\nDestination : %s\n"
               "Total Travel Fare : %.2f\nTotal Cost Before Discount: %.2f\n"
               "Discount Amount : %.2f\nFinal Tour Cost : %.2f\nBooking Category : %s\n\n",
               i + 1, b[i].id, b[i].name, b[i].dest,
               totalFare, preDisc, discAmt, finalCost,
               finalCost > 50000 ? "Premium Booking" : "Regular Booking");
    }

    printf("========== Customers with Discount Amount Greater Than Rs. 5000 ==========\n");

    for (int i = 0; i < n; i++) {
        float discAmt = (b[i].exp.discPct / 100) *
                        (b[i].exp.farePerPerson * b[i].exp.numPersons + b[i].exp.hotelCharge);

        if (discAmt > 5000) {
            printf("Customer Name: %s, Discount Amount: %.2f\n", b[i].name, discAmt);
        }
    }

    return 0;
}
