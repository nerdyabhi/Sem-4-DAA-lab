#include<stdio.h>
struct arr{
    int weight;
    int profit;
    float ratio;
};
int main(int argc, char const *argv[])
{
    printf("\nEnter the capacity of the arr : ");
    int cap;  // weight of the arr
    scanf("%d",&cap); 
    printf("\nEnter the no. of the objects to be put in the arr : ");
    int n ;
    scanf("%d", &n);
    struct arr object[n];

    // enter the data of each obj of arr
    for(int i = 0; i< n; i++){
        printf("\nEnter the weight and profit of %d bag : \t", i+1);
        scanf("%d %d", &object[i].weight,&object[i].profit);
        object[i].ratio = (float)object[i].profit/(float)object[i].weight;
    }

    // printinng the arr datas:
    printf("\nSo the arr is : \n");
    printf("\nProfit:\t");
    for(int i = 0 ; i< n;i++){
        printf(" %d \t", object[i].profit);
    }
    printf("\nWeight:\t");
    for(int i = 0 ; i< n;i++){
        printf(" %d \t", object[i].weight);
    }

    // sorting the object on the basis of the profit:  (using B. Sort but actually we have to use Merge Sort)
    // sorting in descending order of ratios
    for(int i = 0; i<n-1;i++){
        for(int j = 0; j<n-i-1;j++){
            if(object[j].ratio < object[j+1].ratio ){

                // swap the objects . no need to swap its attributes alg alg
                struct arr temp = object[j];
                object[j] = object[j+1];
                object[j+1] = temp;
            
            }
        }
    }

    // printinng the arr datas:  after sorting
    printf("\n\nSo the sorted arr is : \n");
    printf("\nBags:  \t");
    printf("\nProfit:\t");
    for(int i = 0 ; i< n;i++){
        printf(" %d \t", object[i].profit);
    }
    printf("\nWeight:\ t");
    for(int i = 0 ; i< n;i++){
        printf(" %d \t", object[i].weight);
    }

    // greedy algo :

    float prof=0;
    float rProf=0.0;
    int remW = cap;
    int i = 0;
    for(i = 0 ; i<n;i++){
        if(object[i].weight>remW) break;

        prof+=object[i].profit;
        remW-= object[i].weight;
        
       
    }
     printf("\n%.2f", prof);
     printf("\n%d", remW);
    if(i<n){

            // rProf = object[i].ratio*object[i].profit;  // wrong h .hmlog ko remainning weight k ratio lena hga
            rProf= object[i].profit * (float)remW/object[i].weight;
            prof+= rProf;  

        }

    printf("\n\n the profit is %.2f", prof);

    return 0;
}