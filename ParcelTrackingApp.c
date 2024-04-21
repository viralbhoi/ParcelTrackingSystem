#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void welcome(void);
void endScreen(void);
int ETA(int *a);

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
}pta;

void dataEntry(struct production pta){
    strcpy(pta.customer_name,"Jethalal Gada");
    pta.customer_id=1234567;
    pta.pinfo.product_id=1234;
    pta.pinfo.product_price=25000;
    strcpy(pta.pinfo.product_name,"Mobile");
    pta.pinfo.quantity=2;
    strcpy(pta.payment_method,"EMI");
    strcpy(pta.result,"Approved");
    
}

int main(){
    // welcome();
    int k=ETA(pincode);
    printf("%d",k);
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
//problem !!
int ETA(int *a){
    int target=380001;

    int i=0,j=0;
    for(int i=0;i<3;i++){
       if(*(a+i)==target)
                return (i/2 +1);
    }
    return -1;
}