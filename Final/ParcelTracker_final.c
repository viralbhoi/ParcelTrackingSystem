/*
BIRLA VISHVAKARMA MAHAVIDYALAYA.
BRANCH   --- COMPUTER ENGINEERING
SUBJECT  --- PROGRAMMING FOR PROBLEM SOLVING
PROF     --- MAYUR VEGAD SIR

---GROUP MEMBERS---

ABHISHHEK CHAUHAN --- 23CP028
VIRAL BHOI        --- 23CP029
YUG PATEL         --- 23CP039

PROJECT TITLE: PARCEL TRACKING SYSTEM

ABOUT :
    THIS PROJECT IS FOR TRACKING YOUR PARCEL ITEM FROM YOUR CUSTOMER ID. 
    IT DISPLAYS BILL FROM YOUR DATA.
    IT ALLOWS ADMIN MODE, WHICH CAN ACCSSES THROUGH PASSWORD.
    ADMIN CAN INPUT NEW USERS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define PASSWORD 12345
#define MAX_CUSTOMERS 50

// Function prototypes:
void welcome(void);
void endScreen(void);
float dcharge(int k);
void bill(int i);
int eta(int k);
void read(void);
void mode(void);
void user(void);
void admin(void);
void displayAfterInput(void);
void next(void);
void input(void);

// Declaring a structure which consists of product & customer information.
struct detail
{
    char customer_name[22];
    int customer_id;
    int product_id;
    int product_price;
    char product_name[33];
    int quantity;
    char payment_method[22];
    char result[34];
    int pincode;
};

struct detail d[MAX_CUSTOMERS];

// Global variables
int currcID = 1000, currpID = 12001;

int main()
{
    welcome();
    read();
    mode();
    endScreen();
    return 0;
}

// Display welcome screen
void welcome(void)
{
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                  WELCOME TO PARCEL TRACKING SYSTEM                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("\n\n\n\n\n\n\n");

    printf("PRESS ANY KEY TO CONTINUE !!\n");
    getchar();
    system("clear || cls");
}

// Display end screen
void endScreen(void)
{
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                      THANKS FOR USING THIS SYSTEM                                  !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("\n\n\n\n\n\n\n");

    printf("PRESS ANY KEY TO EXIT !!\n");
    getchar();
}

// Read customer data from file
void read(void)
{
    FILE *ptr = fopen("data.txt", "r");
    int i = 0;
    while (i < MAX_CUSTOMERS && fscanf(ptr, "%s %d %d %d %s %d %s %s %d",d[i].customer_name, &d[i].customer_id, &d[i].product_id,&d[i].product_price, d[i].product_name, &d[i].quantity,d[i].payment_method, d[i].result, &d[i].pincode) == 9)
    {
        i++;
    }
    fclose(ptr);
    currcID += i;
    currpID += i;
    FILE *q = fopen("id.txt", "w");
    fprintf(q, "%d %d", currcID, currpID);
    fclose(q);
}

// Choose mode (User or Admin)
void mode(void)
{
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                      CHOOSE THE MODE                                               !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n\n\n");
    int try = 1;
retry:
    printf("Which mode do you want to use? USER -> 1, ADMIN -> 2\n\n");
    printf("Enter option: (1 or 2) ");
    int opt;
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        user();
        break;
    case 2:
        admin();
        break;
    default:
        printf("Invalid Option. Do you want to retry? (y/n) ");
        char o;
        scanf(" %c", &o);
        if ((o == 'y' || o == 'Y') && try < 3)
        {
            try++;
            goto retry;
        }
        else if (try == 3)
        {
            printf("You have tried three times, so you are exiting the program.\n\n");
            next();
        }
        break;
    }
}
// User mode
void user(void)
{
    printf("You Have Entered the Program as User!!!\n\n");
    printf("For Tracking, Enter Customer ID: ");
    int c_id;
    scanf("%d", &c_id);

    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (c_id == d[i].customer_id)
        {
            printf("ID Matched!\n");
            printf("\n\nDisplaying information of customer!!\n\n");

            printf("Customer Name: %s\n", d[i].customer_name);
            printf("Product ID: %d\n", d[i].product_id);
            printf("Product Name: %s\n", d[i].product_name);
            printf("Product Price: %d\n", d[i].product_price);
            printf("Quantity: %d\n", d[i].quantity);
            printf("Status: %s\n", d[i].result);
            printf("Payment Method: %s\n", d[i].payment_method);
            for (int j = 0; d[i].payment_method[j]; j++)
            {
                d[i].payment_method[j] = tolower(d[i].payment_method[j]);
            }
            if (eta(d[i].pincode) != -1 && !strcmp(d[i].payment_method, "approved"))
            {
                printf("ETA: %d\n", eta(d[i].pincode));
            }
            printf("\n\nGenerating Bill!!!\n\n");
            next();
            bill(i);
            return;
        }
    }
    printf("\n\nID Not Found!!!\n\n");
    printf("Press any key to continue !!\n");
    getchar();
    system("clear || cls");
    return;
}

// Generate bill
void bill(int i)
{
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                        YOUR BILL :                                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("Customer name : %s\n", d[i].customer_name);
    printf("Customer id   : %d\n", d[i].customer_id);
    printf("Product id    : %d\n", d[i].product_id);
    printf("product name   : %s\n", d[i].product_name);
    printf("Product Price   : %d\n", d[i].product_price);
    printf("Product quantity   : %d\n", d[i].quantity);

    int pPrice = d[i].quantity * d[i].product_price;
    printf("Total ProductPrice   : %d\n", pPrice);

    float dCharge = dcharge(pPrice);
    printf("Delivery Charges : %.2f\n ", dCharge);

    float gTotal = pPrice + dCharge;
    printf("\n\n\n");
    printf("Grand Total is : %.2f\n", gTotal);

    next();
}

// Admin mode
void admin(void)
{
    printf("You Have Entered the Program as ADMIN!!!\n\n");
    int pass, try = 1;
retry_pass:
    printf("Enter your 5 digit password :  ");
    scanf("%d", &pass);
    if (pass != PASSWORD)
    {
        if (try > 3)
        {
            printf("You have given wrong password for 3 times !!\n\n");
            printf("Exiting !!\n");
            next();
            return;
        }
        try++;
        printf("Wrong Password !! Retry !\n");
        goto retry_pass;
    }
    else
    {
        printf("Correct Password !!\n\n");
        next();
        input();
    }
}

// Take input from admin
void input(void)
{
    printf("Customer name : ");
    scanf("%s", d[currcID - 1000].customer_name);

    d[currcID - 1000].customer_id = currcID;
    d[currcID - 1000].product_id = currpID;

    printf("product price : ");
    scanf("%d", &d[currcID - 1000].product_price);

    printf("product name : ");
    scanf("%s", d[currcID - 1000].product_name);

    printf("quantity : ");
    scanf("%d", &d[currcID - 1000].quantity);

    printf("payment method : ");
    scanf("%s", d[currcID - 1000].payment_method);

    printf("pincode : ");
    scanf("%d", &d[currcID - 1000].pincode);

    FILE *p = fopen("data.txt", "a");
    fprintf(p, "%s %d %d %d %s %d %s %s %d\n", d[currcID - 1000].customer_name, d[currcID - 1000].customer_id, d[currcID - 1000].product_id, d[currcID - 1000].product_price, d[currcID - 1000].product_name, d[currcID - 1000].quantity, d[currcID - 1000].payment_method, d[currcID - 1000].result, d[currcID - 1000].pincode);
    fclose(p);

    currcID++;
    currpID++;

    FILE *w = fopen("id.txt", "w");
    fprintf(w, "%d %d", currcID, currpID);
    fclose(w);
    next();
    displayAfterInput();
}

// Display customer information after input
void displayAfterInput(void)
{
    printf("\n\nDisplaying information of customer !!\n\n");

    printf("Customer Name : %s\n", d[currcID - 1001].customer_name);
    printf("Product ID : %d\n", d[currcID - 1001].product_id);
    printf("Product Name : %s\n", d[currcID - 1001].product_name);
    printf("Product Price : %d\n", d[currcID - 1001].product_price);
    printf("Quantity : %d\n", d[currcID - 1001].quantity);
    printf("Payment Method : %s\n", d[currcID - 1001].payment_method);
    for (int i = 0; d[currcID - 1001].payment_method[i]; i++)
    {
        d[currcID - 1001].payment_method[i] = tolower(d[currcID - 1001].payment_method[i]);
    }
    if (eta(d[currcID - 1001].pincode) != -1 && !strcmp(d[currcID - 1001].result, "approved"))
    {
        printf("ETA : %d\n", eta(d[currcID - 1001].pincode));
    }
    printf("\n\nGenerating Bill !!!\n\n");
    next();
    bill(currcID - 1001);
}

// Calculate ETA based on pincode
int eta(int k)
{
    if (k == 388001 || k == 388120 || k == 388320)
    {
        return 1;
    }
    else if (k == 395003 || k == 392001 || k == 384001 || k == 382010 || k == 360001)
    {
        return 2;
    }
    else if (k == 361001 || k == 3645001 || k == 361335 || k == 385505)
    {
        return 3;
    }
    else
    {
        return 5;
    }
}

// Calculate delivery charges based on the value of the order
float dcharge(int k)
{
    if (k <= 500)
    {
        if (50 > k * 0.10)
        {
            return 50;
        }
        else
        {
            return (k * 0.10);
        }
    }
    else if (k > 500 && k <= 1000)
    {
        if (20 > k * 0.10)
        {
            return 20;
        }
        else
        {
            return (k * 0.05);
        }
    }
    else
    {
        return 0;
    }
}

// Display message and wait for any key press
void next(void)
{
    printf("Press any key to continue !!\n");
    getchar();
    system("clear || cls");
}
