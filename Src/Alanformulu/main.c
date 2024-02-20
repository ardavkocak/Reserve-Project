#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int main()
{

    //int arr[5][2] = {{5,5},{13,12},{8,17},{1,10},{5,5}}; //69
    //int arr[5][2]={{20,20},{30,20},{20,40},{10,40},{20,20}}; //200
    int arr[4][2]={{40,22},{50,32},{30,32},{40,22}};
    int result1=0 , result2=0;
    float area;


    for(int i=0;i<kenarSayisi[0]-1;i++)
    {
        result1 = (arr[i][0] * arr[i+1][1])+ result1;
    }
    //result1= (arr[3][0]* arr[0][1])+ result1;

    printf("%d\n", result1);

    for(int i=0;i<3;i++)
    {
        result2 = (arr [i][1] * arr[i+1][0])+ result2;
    }
    //result2= (arr[3][1]* arr[0][0])+ result2;

    printf("%d\n", result2);

    area=0.5 * (abs(result1-result2));

    printf("alan degeri %f",area);

   /*
    void makeIt(){
    int arr[4][2] = {{5,5},{13,12},{8,17},{1,10}};
    int result1=0, result2=0;
    float area;

    for(int i=0;i<3;i++){
        result1 = (arr[i][0] * arr[i+1][1])+ result1;
    }
    result1= (arr[3][0]* arr[0][1])+ result1;

    printf("%d\n", result1);

    for(int i=0;i<3;i++){
        result2 = (arr[i][1] * arr[i+1][0])+ result2;
    }
    result2= (arr[3][1]* arr[0][0])+ result2;

    printf("%d\n", result2);

    area=0.5 * (abs(result1-result2));

    printf("alan degeri %f",area);
}
    */


    return 0;

}
