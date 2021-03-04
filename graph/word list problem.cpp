#include<bits/stdc++.h>
using namespace std;

// here we are using BFS to find target word
// we insert starting word in queue count level or depth it is like count level in tree
// we add all word in set and we create word manually for each position and compare with target and check in set if this word exist in set if it is then push
// in queue and remove from set
// if we find target word we will return level + 1 value;



int wordList(vector<string> &wordlist, string start, string target)
{
    unordered_set<string> myset;
    bool isPresent = false;
// checking the word is exist in word list or not
    for(auto x : wordlist)
    {
        if(target.compare(x) == 0)
            isPresent = true;
        myset.insert(x);
    }

    if(!isPresent)
        return 0;

//  starting bfs
    queue<string> q;
    q.push(start);
    int depth = 0;

    while(!q.empty())
    {
        depth += 1;
        int size_ = q.size();

        while(size_--)
        {
            string curr = q.front();
            q.pop();

            for(int i = 0; i< curr.length(); i++)
            {
                string temp = curr;
                for(char c = 'a'; c<= 'z'; c++)
                {
                    temp[i] = c;
                    if(temp.compare(curr) == 0)
                        continue;
                    if(temp == target)
                        return depth + 1;
                    if(myset.find(temp) != myset.end())
                    {
                        q.push(temp);
                        myset.erase(temp);
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
   vector<string> vec = {"hot","dot","dog","lot","log","cog"};

   cout<<wordList(vec, "hit", "cog");

    return 0;
}
