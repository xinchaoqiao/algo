#include <iostream>
using namespace std;
double total;
int main(){
    scanf("%lf",&total);
    if(total <= 150){
        double price = 0.4463;
        printf("%.1lf",price * total);
    }
    else if(total >150 && total <= 400){
        double price1 = 0.4463;
        double price2 = 0.4663;
        int extra = total - 150;
        double cost = price1 * 150 + extra * price2;
        printf("%.1lf",cost);
    }
    else{
        double price1 = 0.4463, price2 = 0.4663,price3 = 0.5663;
        int extra1 = 400 - 150;
        int extra2 = total - 400;
        double cost = price1 * 150 + extra1 * price2 + extra2 * price3;
        printf("%.1lf",cost);
    }
    return 0;
}