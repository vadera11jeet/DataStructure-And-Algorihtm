#include<iostream>
#include<string>
using namespace std;

void reverseString(string s, int size_)
{
    if(size_ < 0)
        return;
    cout<<s[size_];
    reverseString(s, size_-1);

}

int main()
{
    string s = "jeet";

    reverseString(s, s.size()-1);
    return 0;
}
