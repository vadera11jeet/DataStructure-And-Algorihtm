#include<iostream>
using namespace std;

void towerOfHanoi(int source, int destination, int helper, int rings)
{
    if(rings == 1)
    {
        cout<<source<< " to " << destination<<endl;
        return ;
    }
    towerOfHanoi(source, helper, destination, rings - 1);
    cout<<source<< " to " << destination<<endl;
    towerOfHanoi(helper, destination, source, rings - 1);

}

int main()
{
    towerOfHanoi(1, 3, 2 ,3);
    return 0;
}
