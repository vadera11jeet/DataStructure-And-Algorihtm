#include<iostream>
using namespace std;

class PetrolPump
{
    public:
    int petrol;
    int distance;
};

int tour(PetrolPump arr[], int n)
{
    int g = 0, c = 0, tank = 0, start =0;
    for(int i = 0; i < n; i++)
    {
        g += arr[i].petrol;
        c += arr[i].distance;
        tank += (arr[i].petrol - arr[i].distance);

        if(tank < 0 )
        {
            tank = 0;
            start = i + 1;
        }
    }

    return g < c ?-1 : start;
}

int main()
{
//    PetrolPump arr[] = {{6, 4}, {5, 6}, {3, 7}, {5, 4}};
    PetrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<tour(arr, n)<<endl;
    return 0;
}
