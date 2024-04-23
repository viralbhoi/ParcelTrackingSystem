#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function prototypes :

void welcome(void);
void authentication(void);
void endScreen(void);
void customerInfo(int i);
float dcharge(int k);
void bill(int i);
void newcustomer(int c);
void newcustomerInfo(int c);
void newbill(int c);
int eta (int);



//declaring a structer which consist of product & customer information. alse give some inputs.

struct production
{
    char customer_name[22];
    int customer_id;
    struct product
    {
        int product_id;
        int product_price;
        char product_name[33];
        int quantity;
    } pinfo;
    char payment_method[22];
    char result[34];
    int eta;
} pta[100] = {
    {"jethalal Gada", 1000, {12001, 500, "Shampoo", 2}, "COD", "Dispatched", 3},
    {"Champaklal Gada", 1001, {12002, 300, "Conditioner", 1}, "COD", "Pending", 2},
    {"Daya Gada", 1002, {12003, 200, "Soap", 4}, "PREPAID", "Delivered", 1},
    {"Tapu Gada", 1003, {12004, 100, "Toothpaste", 3}, "COD", "Out for Delivery", 2},
    {"Tarak Mehta", 1004, {12005, 150, "Body Lotion", 2}, "COD", "Dispatched", 3},
    {"Anjali Mehta", 1005, {12006, 199999, "Laptop", 1}, "PREPAID", "Delivered", 0},
    {"Chalu Pandey", 1006, {12007, 600, "Towel Set", 2}, "COD", "Pending", 2},
    {"Popatlal Pandey", 1007, {12008, 700, "Pillow", 2}, "EMI", "Processing", 4},
    {"Dr. Hanshraj Hathi", 1008, {12009, 250, "Candle", 5}, "COD", "Dispatched", 3},
    {"Komal Hathi", 1009, {12010, 12000, "Smartphone", 1}, "PREPAID", "Delivered", 0},
    {"Atmaram Tukaram Bhide", 1010, {12011, 80, "Hand Soap", 6}, "COD", "Pending", 2},
    {"Madhvi Bhide", 1011, {12012, 4000, "Gaming Console", 1}, "PREPAID", "Delivered", 0},
    {"Abdul", 1012, {12013, 180, "Shower Gel", 3}, "COD", "Dispatched", 3},
    {"Gulabkumar Hathi", 1013, {12014, 150, "Hairbrush", 2}, "COD", "Out for Delivery", 2},
    {"Krishnan Ayyar", 1014, {12015, 90, "Nail Cutter", 4}, "PREPAID", "Delivered", 0},
    {"Babita Ayyar", 1015, {12016, 350, "Perfume", 1}, "COD", "Pending", 2},
    {"Mr. Roshansingh sodhi", 1016, {12017, 200, "Shaving Cream", 3}, "COD", "Dispatched", 3},
    {"Mrs. Roshansingh Sodhi", 1017, {12018, 600, "Backpack", 1}, "PREPAID", "Delivered", 0},
    {"Gurucharan Singh Sodhi", 1018, {12019, 250, "Earphones", 2}, "COD", "Pending", 2},
    {"Sonalika Bhide", 1019, {12020, 1500, "Camera", 1}, "PREPAID", "Delivered", 0},
    {"Natarvarlal Udhaiwala", 1020, {12021, 120, "Tissues", 5}, "COD", "Out for Delivery", 2},
    {"Bagha Udhaiwala", 1021, {12022, 8000, "Television", 1}, "PREPAID", "Delivered", 0},
    {"Bavri", 1022, {12023, 350, "Socks", 3}, "COD", "Dispatched", 3},
    {"Basundi Pandey", 1023, {12024, 200, "Hat", 2}, "COD", "Out for Delivery", 2},
    {"Mohanlal matkaking", 1024, {12025, 100, "Sunglasses", 1}, "PREPAID", "Delivered", 0}};

int main()
{
    welcome();
    authentication();
    endScreen();

    return 0;
}

//this function is called at starting of program and this act as welcome screen of executable file.

void welcome(void)
{
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                  WELCOME TO PARCEL TRACKING SYSTEM                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("\n\n\n\n\n\n\n");

    printf("PRESS ANY KEY TO CONTINUE !!\n");
    getche();
    printf("\e[1;1H\e[2J");
}


//this act as end screen and this called at last of program. after this we exit from program
void endScreen()
{
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                      THANKS FOR USING THIS SYSTEM                                  !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("\n\n\n\n\n\n\n");

    printf("PRESS ANY KEY TO EXIT !!\n");
    getche();
}

// from this we are doing some caluculatoin / operation for diplaying output.
void authentication(void)
{
    int customerId, i, c, flag1, flag2;
    printf("If you are new customer then press 1 or press 0\n");
    scanf("%d", &flag1);

    if (flag1 == 1)
    {
        printf("If you want registration then press 1 or if you want to exit then press 0\n");
        scanf("%d", &flag2);
        if (flag2 == 1)
        {
            newcustomer(c);
        }
        else if (flag2 == 0)
        {
            printf("Exiting !!\n");
            printf("Press Any Key to continue !!!\n");
            getche();
            printf("\e[1;1H\e[2J");
        }else{
            printf("Not Allowed !!\n");
            printf("Press Any Key to continue !!!\n");
            getche();
            printf("\e[1;1H\e[2J");
        return;
        }
    }
    else if (flag1 == 0)
    {
        printf("Please Enter Customer id :\t");
        scanf("%d", &customerId);

        if (customerId > 999 && customerId < 1025)
        {

            for (i = 0; i < 25; i++)
            {

                if (pta[i].customer_id == customerId)
                {
                    customerInfo(i);
                }
            }
        }else
        {
            printf("please Enter Your Valid customer id.\n\n");
        }
    }else{
        printf("Not Allowed !!\n");
        printf("Press Any Key to continue !!!\n");
        getche();
        printf("\e[1;1H\e[2J");
        return;
    }
}

// we are displaying customer information by this function.

void customerInfo(int i)
{
    printf("Customer Name : %s\n", pta[i].customer_name);
    printf("Customer ID   : %d\n", pta[i].customer_id);
    printf("Product Name  : %s\n", pta[i].pinfo.product_name);
    printf("Result        : %s\n", pta[i].result);
    printf("ETA           : %d\n", pta[i].eta);
    printf("\n\n\n");
    printf("Press Any Key to continue !!!\n");
    getche();
    printf("\e[1;1H\e[2J");
    bill(i);
}

//for printing bill like structer on screen we are using bill() funtion.

void bill(int i)
{
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                        YOUR BILL :                                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("Customer name     : %s\n", pta[i].customer_name);
    printf("Customer id       : %d\n", pta[i].customer_id);
    printf("Product id        : %d\n", pta[i].pinfo.product_id);
    printf("product name      : %s\n", pta[i].pinfo.product_name);
    printf("Product Price     : %d\n", pta[i].pinfo.product_price);
    printf("Product quantity  : %d\n", pta[i].pinfo.quantity);

    int pPrice = pta[i].pinfo.quantity * pta[i].pinfo.product_price;
    printf("Total ProductPrice   : %d\n", pPrice);

    float dCharge = dcharge(pta[i].pinfo.quantity * pta[i].pinfo.product_price);
    printf("Delivery Charges : %.2f\n ", dCharge);
    
    float gTotal = pPrice + dCharge;
    printf("\n\n\n");
    printf("Grand Total is : %.2f\n", gTotal);
   
    printf("Press any key to continue !!\n");
    getche();
    printf("\e[1;1H\e[2J");
    return;
}

//this function calculates delivery charges from value of order.

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
        if (20 > k * 0.05)
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


//here we are taking  new user and saving the input in data.txt file

void newcustomer(int c)
{
    FILE *fptr = fopen("data.txt","a");
    c = 25;
    pta[c].customer_id = 1025;
    pta[c].pinfo.product_id = 12026;

    printf("Enter your Name: ");
    scanf("%s", pta[c].customer_name);

    printf("Enter product name : ");
    scanf("%s", pta[c].pinfo.product_name);

    printf("Enter price of product : ");
    scanf("%d", &pta[c].pinfo.product_price);

    printf("How many items do you want : ");
    scanf("%d", &pta[c].pinfo.quantity);

    printf("Which Payment method do you prefer : ");
    scanf("%s", pta[c].payment_method);

    strcpy(pta[c].result, "Approved");
    int pin;
    printf("Enter pin : ");
    scanf("%d",&pin);
    pta[c].eta=eta(pin);

    fprintf(fptr,"\n%s %d %d %d %s %d %s %s %d\n",pta[c].customer_name,  pta[c].customer_id,pta[c].pinfo.product_id,pta[c].pinfo.product_price,pta[c].pinfo.product_name,pta[c].pinfo.quantity,pta[c].payment_method,pta[c].result,pta[c].eta);
    pta[c].customer_id++;
    pta[c].pinfo.product_id++;
    fclose(fptr);

    
    printf("Press any key to continue !!\n");
    getche();
    printf("\e[1;1H\e[2J");

    newcustomerInfo(c);
}

// this function will display informatoin about new customers.

void newcustomerInfo(int c)
{
    printf("Customer Name : %s\n", pta[c].customer_name);
    printf("Customer ID   : %d\n", pta[c].customer_id);
    printf("Product Name  : %s\n", pta[c].pinfo.product_name);
    printf("Result        : %s\n", pta[c].result);
    printf("ETA           : %d\n", pta[c].eta);
    printf("\n\n\n");

    printf("Press Any Key to continue !!!\n");
    getche();
    printf("\e[1;1H\e[2J");
    newbill(c);
}

void newbill(int c)
{
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                        YOUR BILL :                                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("Customer name    : %s\n", pta[c].customer_name);
    printf("Customer id      : %d\n", pta[c].customer_id);
    printf("Product id       : %d\n", pta[c].pinfo.product_id);
    printf("product name     : %s\n", pta[c].pinfo.product_name);
    printf("Product Price    : %d\n", pta[c].pinfo.product_price);
    printf("Product quantity : %d\n", pta[c].pinfo.quantity);

    int pPrice = pta[c].pinfo.quantity * pta[c].pinfo.product_price;
    printf("Total ProductPrice   : %d\n", pPrice);

    float dCharge = dcharge(pta[c].pinfo.quantity * pta[c].pinfo.product_price);
    printf("Delivery Charges : %.2f\n ", dCharge);

    float gTotal = pPrice + dCharge;
    printf("\n\n\n");
    printf("Grand Total is : %.2f\n", gTotal);

    printf("Press any key to continue !!\n");
    getche();
    printf("\e[1;1H\e[2J");

    return;
}

int eta (int k){
    if(k==388001 || k==388120 || k==388320){
        return 1;
    }else if (k==395003 || k==392001 || k==384001 || k==382010 || k==360001){
        return 2;
    }else if(k==361001 || k==3645001 || k==361335 || k==385505){
        return 3;
    }else{
        return 5;
    }
}
