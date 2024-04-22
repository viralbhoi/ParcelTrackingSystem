#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void welcome(void);
void authentication(void);
void endScreen(void);
void customerInfo(int i);

int pincode[4]={388120,388001,380001,380213};

struct production {
    char customer_name[22];
    int customer_id;
    struct product{
        int product_id;
        int product_price;
        char product_name[33];
        int quantity;
    }pinfo;
    char payment_method[22];
    char result[34];
    int eta;
}pta[25]={
    {"jethalal Gada", 1000, {12001, 500, "Shampoo", 2}, "COD", "Dispatched", 3},
    {"Champaklal Gada", 1001, {12002, 300, "Conditioner", 1}, "COD", "Pending", 2},
    {"Daya Gada", 1002, {12003, 200, "Soap", 4}, "PREPAID", "Delivered", 1},
    {"Tapu Gada", 1003, {12004, 100, "Toothpaste", 3}, "COD", "Out for Delivery", 2},
    {"Tarak Mehta", 1004, {12005, 150, "Body Lotion", 2}, "COD", "Dispatched", 3},
    {"Anjali Mehta", 1005, {12006, 2000, "Laptop", 1}, "PREPAID", "Delivered", 0},
    {"Chalu Pandey", 1006, {12007, 600, "Towel Set", 2}, "COD", "Pending", 2},
    {"Popatlal Pandey", 1007, {12008, 700, "Pillow", 2}, "EMI", "Processing", 4},
    {"Dr. Hanshraj Hathi", 1008, {12009, 250, "Candle", 5}, "COD", "Dispatched", 3},
    {"Komal Hathi", 1009, {12010, 1200, "Smartphone", 1}, "PREPAID", "Delivered", 0},
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
    {"Bagha Udhaiwala", 1021, {12022, 800, "Television", 1}, "PREPAID", "Delivered", 0},
    {"Bavri", 1022, {12023, 350, "Socks", 3}, "COD", "Dispatched", 3},
    {"Basundi Pandey", 1023, {12024, 200, "Hat", 2}, "COD", "Out for Delivery", 2},
    {"Mohanlal matkaking", 1024, {12025, 100, "Sunglasses", 1}, "PREPAID", "Delivered", 0}
};






int main(){
    // welcome();
    // int k=ETA(pincode);
    // printf("%d",k);
    authentication();
    // endScreen();
    return 0;
}

void welcome(void) {
    printf("\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("!!                                  WELCOME TO PARCEL TRACKING SYSTEM                                 !!\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n\n");
    printf("PRESS ANY KEY TO CONTINUE !!\n");
    getchar(); 
    printf("\e[1;1H\e[2J");
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

void authentication(void) {
    printf("Please Enter Customer id :\t");
    int customerId;
    scanf("%d",&customerId);
    int i;
    for(i=0;i<5;i++){
        if(pta[i].customer_id == customerId){
            customerInfo(i);
        }
    }
    printf("Sorry, Id not found !!\n");

}

void customerInfo(int i){
    printf("Customer Name : %s\n",pta[i].customer_name);
    printf("Customer ID : %d\n", pta[i].customer_id);
    printf("Product Name : %s\n", pta[i].pinfo.product_name);
    printf("Product ID : %d\n", pta[i].pinfo.product_id);
    printf("Quantity : %d\n", pta[i].pinfo.quantity);
    printf("Payment Method : %s\n", pta[i].payment_method);
    printf("Result : %s\n", pta[i].result);
    printf("ETA : %d\n", pta[i].eta);
}
