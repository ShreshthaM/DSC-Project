#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct details
{
    int roomid;
    char name1[30];
    long mobile;
    char id[20];
    int ppl;
    char name2[30];
    char name3[30];
    int roomtype;
    int iduration;
    int duration;
    int eduration;
    int eroomtype;
    int bill;
    int resbill;
    int tbill;
    struct details *next;
};
int i=0;
void addroom();
void roomdet();
void checkout();
int restr();
void update();
struct details *head= NULL;
void main()
{
    int c1,ubill=0;
do{
printf(" WELCOME TO LE MAGENTA \n 1) ROOM DETAILS \n 2) CHECK IN \n 3) CHECK OUT \n 4) UPDATE INFORMATION \n 5) RESTAURANT \n 6) EXIT \n");
scanf("%d", &c1);
    switch(c1)
    {
        case 1: roomdet(); break;
        case 2: addroom(); break;
        case 3: checkout(); break;
        case 4: update();
                
                break;
        case 5: ubill=restr(); break;
        case 6: exit(0);
        default: printf("WRONG INPUT \n");
    }
}while(c1!=6);
}
void roomdet()
{
printf(" 1) DELUXE ROOM: Rs 650 per person per night. \n SINGLE OR DOUBLY OCCUPIED \n AMENITIES \n BREAKFAST INCLUDED \n AC \n TV \n FREE WIFI \n QUEEN SIZED BED \n");
printf(" 2) SUPER DELUXE ROOM: Rs 950 per person per night. \n SINGLE OR DOUBLY OCCUPIED \n AMENITIES \n BREAKFAST INCLUDED \n AC \n TV \n FREE WIFI \n KING SIZED BED \n EVENING SPA \n");
printf(" 3) DELUXE SUITE: Rs 1150 per person per night. \n DOUBLY OCCUPIED \n AMENITIES \n BREAKFAST AND SNACKS INCLUDED \n AC \n TV \n FREE WIFI \n 2 KING SIZED BEDS \n ALL DAY SPA & FREE ACCESS TO CLUB HOUSE \n");
}

void addroom()
{
    int s1=0;
    long mobi;
    int extra;
    struct details *temp;
    temp=(struct details*)malloc(sizeof(struct details));
printf("KINDLY ENTER YOUR DETAILS \n");
printf("FULL NAME \n");
scanf("%s", &temp->name1);
do{
printf("MOBILE NUMBER \n");
scanf("%ld", &mobi);
if(mobi<9999999999 && mobi>7000000000)
{ temp->mobile=mobi; s1=1; }
else
printf("enter a valid mobile number \n");
}while(s1!=1);
printf("ID NUMBER \n");
scanf("%s", &temp->id);
printf("HOW MANY MORE COMPANIONS ALONG \n");
scanf("%d",&extra);
    temp->ppl=extra;
    if(extra==0)
    {
    temp->name2[0] = '\0';
    temp->name3[0] = '\0';
    }
    else if(extra==1)
    {
printf("NAME OF THE COMPANION \n");
scanf("%s",temp->name2);
    temp->name3[0]='\0';
    }
    else if(extra==2)
    {
printf("RS 200 will be charged for an additional bed \n");
printf("NAME OF THE 1ST COMPANION \n");
scanf("%s",temp->name2);
printf("NAME OF THE 2ND COMPANION \n");
scanf("%s",temp->name3);
}
if(extra<=2)
{
    int totalbill;
    int time;
printf("Duration of stay \n");
scanf("%d",&time);
printf("\n %d",time);
    temp->iduration=time;
printf("WHICH ROOM WOULD YOU LIKE TO BOOK \n");
roomdet();
scanf("%d",&temp->roomtype);
    if(temp->roomtype==1)
    {
        if(temp->ppl==0)
totalbill=650*time;
        else if(temp->ppl==1)
totalbill=650*2*time;
        else
totalbill=650*3*time + 200;
    }
    else if(temp->roomtype==2)
    {
        if(temp->ppl==0)
totalbill=950*time;
        else if(temp->ppl==1)
totalbill=950*2*time;
        else
totalbill=950*3*time + 200;
    }
    else if(temp->roomtype==3)
    {
        if(temp->ppl==0)
totalbill=1150*time;
        else if(temp->ppl==1)
totalbill=1150*2*time;
        else
totalbill=1150*3*time + 200;
    }
    temp->bill=totalbill;

    temp->roomid=i;
    ++i;
    temp->next=head;
    head=temp;
    temp->roomid=i;
printf("YOUR ROOM ID IS %d",temp->roomid);
printf("\n HAVE A WONDERFUL STAY");
}


     else if(extra>2)

            printf("PLEASE GO FOR MORE ROOMS SINCE ONE ROOM IS LIMITED TO 3 PEOPLE ONLY \n");
            
        
    

    
}
void checkout()
{
    int idout;
    int tbill = 0;
    struct details *temp;
    
    temp=head;
    
printf("Enter your Room ID \n");
scanf("%d",&idout);
  
    while(temp->roomid!=idout)
        temp=temp->next;
    printf("BOOKING UNDER THE NAME OF %s \n", temp->name1);
        if(temp->name2[0] != '\0')
        printf("COMPANION 1 %s \n", temp->name2);
        if(temp->name3[0] != '\0')
        printf("COMPANION  2 %s \n", temp->name3);
        printf("MOBILE NUMBER %ld \n", temp->mobile);
        printf("ID NUMBER %s \n", temp->id);
         printf("INITIAL DURATION OF STAY %d \n", temp->iduration);
            printf("ROOMTYPE SELECTED %d \n", temp->roomtype);
        if(temp->roomtype==1)
        printf("COST PER PERSON PER NIGHT IS ? 650 \n");
        if(temp->roomtype==2)
        printf("COST PER PERSON PER NIGHT IS ? 950 \n ");
        if(temp->roomtype==3)
        printf("COST PER PERSON PER NIGHT IS ? 1150 \n");
        
        if(temp->eduration!=0)
           
        printf("EXTENDED DURATION %d \n", temp->eduration);
        if(temp->eroomtype!=0)
        {
         printf("ROOMTYPE SELECTED %d \n", temp->eroomtype);
        if(temp->eroomtype==1)
        printf("COST PER PERSON PER NIGHT IS ? 650 \n");
        if(temp->eroomtype==2)
        printf("COST PER PERSON PER NIGHT IS ? 950 \n ");
        if(temp->eroomtype==3)
        printf("COST PER PERSON PER NIGHT IS ? 1150 \n");
        }
        printf("TOTAL DUARTION OF THE STAY %d \n", temp->iduration + temp->eduration);
       
        
printf("BILL OF HOTEL IS  %d \n", temp->bill);
printf("BILL OF RESTAURANT IS  %d \n", temp->resbill);
tbill=  temp->bill +  temp->resbill;
temp->tbill =tbill;
printf("TOTAL BILL IS  %d \n", temp->tbill);
free(temp);


            

    }
    



void update()
{
    printf("ONE CAN CHANGE THEIR DURATION OF STAY AND ROOM BOOKED UNDER UPDATE \n");
    int idup=0,t,s;
    struct details *temp;
    temp=head;
    
    printf("please enter your room id \n");
    scanf("%d",&idup);
    
    int roomprice;
    int rchoice;
    
         printf("please enter the number of days you want to extend \n");
            scanf("%d",&t);
            temp->eduration = t;
            printf("do you want to change the room? \n");
            printf("press 1 for yes and 0 for no \n");
            scanf("%d",&s);
            if(s==1)
            {
            printf("which room would you like to book \n");
            roomdet();
            scanf("%d",&rchoice);
            temp->eroomtype=rchoice;
         while(temp->roomid!=idup)
        temp=temp->next;
     temp->eduration = t;
        temp->duration=t + temp->iduration;
        if(temp->eroomtype==1) roomprice=650;
        else if(temp->eroomtype==2) roomprice=950;
        else roomprice=1150;
        
        temp->bill+=(roomprice)*t*(temp->ppl +1);
            }
            else if(s==0)
            {
                while(temp->roomid!=idup)
        temp=temp->next;
         temp->eduration = t;
        temp->duration =t+ temp->iduration;
        if(temp->roomtype==1) roomprice=650;
        else if(temp->roomtype==2) roomprice=950;
        else roomprice=1150;
        
        temp->bill+=(roomprice)*t*(temp->ppl +1);
                
            }
        
        
        
       
        
}

int restr()
{ 
int rbill=0;
int p[60]={100,120,140,100,80,90,100,135,100,120,100, 140,160,150,100, 110,150,120,120,100,
120,140,150,100,140,160,180,150,120,140,200,240,250,280,270,290,300,340,300,270,270,280,400,400,380,
400,380,360,370,400,150,100,120,160,200,210,200,230,230,250};
int  num, i, k, idr;
printf("Here is the menu \n");
printf("\n \t \t \t STARTERS");
printf("\n \t \t ITEM NAME \t   PRICE");
printf("\n \t 1. Clear veg soup      Rs.100"); 
printf("\n \t 2. Chicken soup        Rs.120");
printf("\n \t 3. Veg spring roll     Rs.140");
printf("\n \t 4. Chilly paneer       Rs.100");
printf("\n \t 5. Mushroom chilly      Rs.80");
printf("\n \t 6. Gobi manchurian      Rs.90");
printf("\n \t 7. Baby corn chilly    Rs.100");
printf("\n \t 8. Tandoori chicken    Rs.135");
printf("\n \t 9. Fish tikka          Rs.100");
printf("\n \t 10. Chicken cutlets    Rs.120");
printf("\n \t 11. Chicken popcorn    Rs.100");
printf("\n \t 12. Prawn fry          Rs.140");
printf("\n \t 13. Veg platter        Rs.160");
printf("\n \t 14. Non veg platter    Rs.150");
printf("\n \t 15. Fish tawa fry      Rs.100");
printf("\n \t 16. Prawns tawa fry    Rs.110");
printf("\n \t 17. Chicken chilly     Rs.150");
printf("\n \t 18. Chicken 65         Rs.120");
printf("\n \t 19. Chicken pepper     Rs.120");
printf("\n \t 20. Chicken malai      Rs.100");
printf("\n \t \t \t DESSERTS");
printf("\n \t \t ITEM NAME \t       PRICE");
printf("\n \t 21. Chocolate cake     Rs.120");
printf("\n \t 22. Donut              Rs.140");
printf("\n \t 23. Tiramisu           Rs.150");
printf("\n \t 24. Redvelvet cake     Rs.100");
printf("\n \t 25. Walnut tart        Rs.140");
printf("\n \t 26. Cheesecake         Rs.160");
printf("\n \t 27. Icecream           Rs.180");
printf("\n \t 28. Gulab jamun        Rs.150");
printf("\n \t 29. Jalebi             Rs.120");
printf("\n \t 30. Rasgulla           Rs.140");

printf("\n \t \t \t MAIN COURSE");
printf("\n \t \t ITEM NAME \t       PRICE ");
printf("\n \t 31. Pasta Arabiata                 Rs.200");
printf("\n \t 32. Creamy Alfredo Pasta     Rs.240");
printf("\n \t 33. Fried rice                        Rs.250");
printf("\n \t 34. Pesto pasta                     Rs.280");
printf("\n \t 35. Tandoori Paneer Steak    Rs.270");
printf("\n \t 36. Veg Lassagne                  Rs.290");
printf("\n \t 37. Thai Basil Chicken           Rs.300");
printf("\n \t 38. Hakka Noodles                Rs.340");
printf("\n \t 39. Chicken biryani               Rs.300");
printf("\n \t 40. TavaPulav                       Rs.270");
printf("\n \t 41. Kashmiri Pulav                  Rs.270");
printf("\n \t 42. Wedge Max Burger         Rs.280");
printf("\n \t 43. Peri Peri Paneer               Rs.400");
printf("\n \t 44. Cheese Burger                 Rs.400");
printf("\n \t 45. Veg Platter                      Rs.380");
printf("\n \t 46. Non Veg Platter               Rs.400");
printf("\n \t 47. Hot Pot Chicken               Rs.380");
printf("\n \t 48. Fish & Chips                     Rs.360");
printf("\n \t 49. Thai curry & rice              Rs.370");
printf("\n \t 50. Ramen noodles                 Rs.400");
printf("\n \t \t \t BEVERAGES");
printf("\n \t \t ITEM NAME \t       PRICE ");
printf("\n \t 51. Iced Latte                       Rs.150");
printf("\n \t 52. Brownie Points                 Rs.100");
printf("\n \t 53. Oreo shake                     Rs.120");
printf("\n \t 54. Irish cold coffee             Rs.160");
printf("\n \t 55. Choco Mocha                   Rs.200");
printf("\n \t 56 Very Berry Blast              Rs.210");
printf("\n \t 57. Santa Maria                     Rs.200");
printf("\n \t 58. Ferraro Rocher               Rs.230");
printf("\n \t 59. Lychee                            Rs.230");
printf("\n \t 60. Raspberry Fixxo              Rs.250");
do
{
printf("\n Please type the corresponding serial number to place your order \n");
scanf("%d",&i);
printf("\n Enter the number of plates you would like to order \n");
scanf("%d",&num);
rbill += p[i-1] *num;

printf("\n Do you want to continue ordering\n ");
printf("\n press 1. Yes and 0. No\n ");
scanf("%d",&k);

} while(k!=0);

printf("\n PLEASE enter your room ID \n");
scanf("%d",&idr);
struct details *tempr;
tempr=head;
while(tempr->roomid!=idr)
tempr=tempr->next;
tempr->resbill=rbill;
printf("\n The price of your order is = %d \n",rbill);

return(rbill);
}





