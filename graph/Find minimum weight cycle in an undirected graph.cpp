#include<bits/stdc++.h>
using namespace std;


class queueEntery
{
public:
    int v;
    int dist;

    queueEntery(int v=0, int dist=0)
    {
        this->v = v;
        this->dist = dist;
    }


};


int snackAndLadder(int board[], int n)
{
    vector<bool> visited(n, false);

    queue<queueEntery> q;

    visited[0] = true;

    queueEntery s = queueEntery(0, 0);
    q.push(s);



    while(!q.empty())
    {
        queueEntery temp = q.front();
        q.pop();
        int v = temp.v;

        if(v == n-1)
            return temp.dist;

        for(int i = v + 1; i <= v+6 && i < n; i++)
        {
            if(!visited[i])
            {
                queueEntery a;
                a.dist = temp.dist + 1;
                visited[i] = true;

                if(board[i] != -1)
                    a.v = board[i];
                else
                    a.v = i;

                q.push(a);

            }
        }

    }

    return -1;
}


int main()
{

    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout<< snackAndLadder(moves, N);

    return 0;
}
