#include <cstdio>
#include <ctime>
#include <random>
#include "run.hpp"

void putOne(int a[4][4])
{
    int new_x, new_y, news;
    do
    {
        news = rand() % 16;
        new_x = news / 4;
        new_y = news % 4;
    }
    while (a[new_x][new_y] != 0);
    a[new_x][new_y] = 2;
    return;
}

bool nextStep(int a[4][4], char c)
{
    int deal[4][4];
    int counts = 0;
    if (c=='a')
    {
        while(isMoved(a)) counts++;
    }
    else if(c=='s')
    {
        rot(a, deal);
        while(isMoved(deal)) counts++;
        rot(deal, a);
        rot(a, deal);
        rot(deal, a);
    }
    else if(c=='d')
    {
        rot(a, deal);
        rot(deal, a);
        while(isMoved(a)) counts++;
        rot(a, deal);
        rot(deal, a);
    }
    else if(c=='w')
    {
        rot(a, deal);
        rot(deal, a);
        rot(a, deal);
        while(isMoved(deal)) counts++;
        rot(deal, a);
    }
    if(counts==0)return false;
    int num = 0;
    for(int i = 0; i<4; i++)
        for(int j=0; j<4; j++)
            if(a[i][j])
                num++;
    if(num<16)
    {
        putOne(a);
        return true;
    }
    return false;
}

bool isMoved(int a[4][4])
{
    bool moved = false;
    for(int i=0;i<4;i++){
        for(int j=1;j<4;j++){
            if(a[i][j]==0)continue;
            if(a[i][j-1]!=0 && a[i][j-1]!= a[i][j])continue;
            if(a[i][j-1]==0)a[i][j-1] = a[i][j];
            else if(a[i][j-1]==a[i][j])a[i][j-1] = 2*a[i][j];
            a[i][j] = 0;
            moved = true;
        }
    }
    return moved;
}

void rot(int a[4][4], int b[4][4]){
    for(int i = 0;i<4;i++)
        for(int j =0;j<4;j++)
            b[j][3-i] = a[i][j];
}
