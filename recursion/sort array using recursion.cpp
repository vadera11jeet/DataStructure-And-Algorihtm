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

    v.push_back(50);
    v.push_back(46);
    v.push_back(333);
    v.push_back(28);
    v.push_back(0);

    sort_(v);

    for(int i=0; i<5; i++)
        cout<< v[i]<< "  ";

    return 0;
}
