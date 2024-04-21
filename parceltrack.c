#include<stdio.h>
#include<string.h>

struct Parcel
{
    int itemid;
    int consumerid;
    char paymentmode[50];
    char status[50];
    char dispatch[50];
    char city[50];
    int eta;
};

char app[20]="Approved",COD[20]="COD",pre[20]="Prepaid",EMI[20]="EMI";
int pincode;

int main()
{
    struct Parcel parcel;
    printf("Please enter item id : \n");
    scanf("%d",&parcel.itemid);

    printf("Please enter consumer id : \n");
    scanf("%d",&parcel.consumerid);

    strcpy(parcel.status,app);

    printf("Payment method: \n COD=Cash on delivery \n Prepaid \n EMI \n Type Name Of Payment-Mode You want To Use :");
    scanf("%s",parcel.paymentmode);

    if(strcmp(parcel.paymentmode,COD)==0)
    {
        printf("Cash On Delivery\n");
    }

    else if(strcmp(parcel.paymentmode,pre)==0)
    {
        printf("Prepaid\n");
    }

    else if(strcmp(parcel.paymentmode,EMI)==0)
    {
        printf("EMI\n");
    }
    else
    {
        printf("Please Enter Valid Method From Above.");
    }

    printf("Please Enter Destination City : \n");
    scanf("%s",parcel.city);

    printf("Enter your City's Pincode : \n");
    scanf("%d",&pincode);

    if(pincode==388001)
    {
        parcel.eta=2;
    }

    else if(pincode==380001 && 390001 && 387001)
    {
        parcel.eta=3;
    }
    else if(pincode==395003 && 392001 && 384001 && 382010 && 360001)
    {
        parcel.eta=4;
    }

    else if(pincode==361001 && 3645001 && 361335 && 385505)
    {
        parcel.eta=5;
    }
    else
    {
        printf("Sorry your city is not included in our area.");
        return 0;
    }

    printf("Purchase Detail : \n");

    printf("Item id : %d\n",parcel.itemid);

    printf("Consumer id : %d\n",parcel.consumerid);

    printf("Status : %s\n",parcel.status);

    printf("City To Deliver : %s\n",parcel.city);

    printf("Your Product Will Be Deliverd in Next %d Days.",parcel.eta);

    return 0;

}
