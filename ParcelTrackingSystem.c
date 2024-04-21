
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function prototypes
void welcome(void);
void authentication(void);
void productDetail(void);
void eta(void);
void endScreen(void);

// Struct to hold customer information
struct Customer {
    char id[15];
    char name[50];
    char status[10];
    char destiCity;
    char currCity;
    float price;
    char payment[10];
};

int main() {
    welcome();
    printf("Entered to main\n");
    authentication();
    endScreen();
    return 0;
}

void welcome(void) {
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                  WELCOME TO PARCEL TRACKING SYSTEM                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n\n");
    printf("PRESS ANY KEY TO CONTINUE !!\n");
    getchar(); // Use getchar() instead of getch() for portability
    printf("\e[1;1H\e[2J");
}

void authentication() {
    struct Customer customer = {"123456789", "Champaklal Gada", "Approved", 'E', 'A', 12345.00, "COD"};
    char id[15];
    printf("Please enter your product id : ");
    fgets(id, sizeof(id), stdin); // Use fgets() for safer input
    id[strcspn(id, "\n")] = '\0'; // Remove newline character
    if(strcmp(id, customer.id) == 0) {
        productDetail();
    } else {
        printf("Invalid product ID!\n");
        printf("PRESS ANY KEY TO CONTINUE !!\n");
        getchar(); // Use getchar() instead of getch() for portability
        printf("\e[1;1H\e[2J");
    }
}

void productDetail() {
    struct Customer customer = {"123456789", "Champaklal Gada", "Approved", 'E', 'A', 12345.00, "COD"};
    printf("Information about the Purchase/parcel : \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\nCustomer Name : %s", customer.name);
    printf("\nProduct Name  : %s", customer.id);
    printf("\nPrice         : %.2f", customer.price);
    printf("\nStatus        : %s", customer.status);
    if(strcmp(customer.status, "Approved") == 0) {
        printf("\nInformation about Delivery : \n");
        eta();
    } else if(strcmp(customer.status, "Pending") == 0) {
        printf("Please wait till order approve !\n");
    } else {
        printf("Apologies, but your order is rejected !\n");
    }
    printf("\n\n\n");
    printf("PRESS ANY KEY TO CONTINUE !!\n");
    getchar(); // Use getchar() instead of getch() for portability
    printf("\e[1;1H\e[2J");
}

void eta() {
    struct Customer customer = {"123456789", "Champaklal Gada", "Approved", 'E', 'A', 12345.00, "COD"};
    int res = customer.destiCity - customer.currCity;

    if(res == 0) {
        printf("Your Parcel is arriving Today.\n");
    } else if(res == 1) {
        printf("Your Parcel is arriving Tomorrow.\n");
    } else {
        printf("Your Parcel is arriving in %d Days.\n", res);
    }
}

void endScreen() {
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                      THANKS FOR USING THIS SYSTEM                                  !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n\n");
    printf("PRESS ANY KEY TO EXIT !!\n");
    getchar();
}
