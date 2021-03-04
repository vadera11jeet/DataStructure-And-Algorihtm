#include<bits/stdc++.h>
using namespace std;


class KnightDetails
{
public:
    int knight_x;
    int knight_y;
    int steps;

    KnightDetails(int knight_x, int knight_y, int steps = 0)
    {
        this->knight_x = knight_x;
        this->knight_y = knight_y;
        this->steps = steps;
    }

};

bool checkValidPosition(int x, int y, int n)
{
    if(x < 0 || x >=n || y < 0 || y >=n)
        return false;

    return true;
}

int stepsByKnight(int boardSize, int knight_x, int knight_y, int destination_x, int destination_y)
{
    bool visited[boardSize][boardSize] = {false} ;

    queue<KnightDetails> q;

    q.push(KnightDetails(knight_x, knight_y, 0));

    while(!q.empty())
    {
        KnightDetails  temp = q.front();
        q.pop();

        if(temp.knight_x == destination_x && temp.knight_y == destination_y)
        {
            return temp.steps;

        }
        else
        {
            if(checkValidPosition(temp.knight_x+2, temp.knight_y+1, boardSize) && !visited[temp.knight_x+2][temp.knight_y+1])
            {
                q.push(KnightDetails(temp.knight_x+2, temp.knight_y+1, temp.steps+1));
                visited[temp.knight_x+2][temp.knight_y+1] = true;
            }

            if(checkValidPosition(temp.knight_x+2, temp.knight_y-1, boardSize) && !visited[temp.knight_x+2][temp.knight_y-1] )
            {
                q.push(KnightDetails(temp.knight_x+2, temp.knight_y-1, temp.steps+1));
                visited[temp.knight_x+2][temp.knight_y-1] = true;
            }

            if(checkValidPosition(temp.knight_x-2, temp.knight_y+1, boardSize) && !visited[temp.knight_x-2][temp.knight_y+1])
            {
                visited[temp.knight_x-2][temp.knight_y+1] = true;
                q.push(KnightDetails(temp.knight_x-2, temp.knight_y+1, temp.steps+1));
            }

            if(checkValidPosition(temp.knight_x-2, temp.knight_y-1, boardSize) && !visited[temp.knight_x-2][temp.knight_y-1])
            {
                visited[temp.knight_x-2][temp.knight_y-1] = true;
                q.push(KnightDetails(temp.knight_x-2, temp.knight_y-1, temp.steps+1));
            }

            if(checkValidPosition(temp.knight_x+1, temp.knight_y+2, boardSize) && ! visited[temp.knight_x+1][temp.knight_y+2])
            {
                q.push(KnightDetails(temp.knight_x+1, temp.knight_y+2, temp.steps+1));
                visited[temp.knight_x+1][temp.knight_y+2] = true;
            }

            if(checkValidPosition(temp.knight_x-1, temp.knight_y+2, boardSize) && !visited[temp.knight_x-1][temp.knight_y+2])
            {
                visited[temp.knight_x-1][temp.knight_y+2] = true;
                q.push(KnightDetails(temp.knight_x-1, temp.knight_y+2, temp.steps+1));
            }

            if(checkValidPosition(temp.knight_x+1, temp.knight_y-2, boardSize) && !visited[temp.knight_x+1][temp.knight_y-2])
            {
                visited[temp.knight_x+1][temp.knight_y-2] = true;
                q.push(KnightDetails(temp.knight_x+1, temp.knight_y-2, temp.steps+1));
            }

            if(checkValidPosition(temp.knight_x-1, temp.knight_y-2, boardSize) && !visited[temp.knight_x-1][temp.knight_y-2])
            {
                visited[temp.knight_x-1][temp.knight_y-2] = true;
                q.push(KnightDetails(temp.knight_x-1, temp.knight_y-2, temp.steps+1));
            }

        }

    }
    return -1;
}


int main()
{
    cout<<stepsByKnight(6, 3, 4, 0, 0)<<endl;
    cout<<stepsByKnight(6, 1, 3, 5, 3);
    cout<<endl;
    cout<<stepsByKnight(30, 0, 0, 29, 29);
    cout<<endl<<stepsByKnight(7,1-1,1-1,7-1,5-1);
    return 0;
}
