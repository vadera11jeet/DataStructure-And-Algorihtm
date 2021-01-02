#include<iostream>
#include<vector>
using namespace std;


void insert_(vector<int> &v, int temp)
{
    if(v.size()== 0 || v[v.size()-1] <= temp)
    {
        v.push_back(temp);
        return;
    }

    int value = v[v.size()-1];
    v.pop_back();
    insert_(v, temp);
    v.push_back(value);
}


void sort_(vector<int> &v)
{
    if(v.size() == 1)
        return;
    int temp = v[v.size() - 1];
    v.pop_back();
    sort_(v);
    insert_(v, temp);
}

int main()
{
    vector<int> v;

    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    sort_(v);

    for(int i=0; i<5; i++)
        cout<< v[i]<< "  ";

    return 0;
}
