#include "game.hpp"
#include <cstdio>
#include <conio.h>
#include <windows.h>

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
    int c;
    putOne(a);
    do
    {
        system("cls");
        show();
        printf("«Î ‰»Î∑ΩœÚ\n");
        while(true){
            if(kbhit()){
                getch();
                c = getch();
                break;
            }
        }
        switch(c){
        case 75:
            nextStep(a,'a');
            break;
        case 72:
            nextStep(a,'w');
            break;
        case 80:
            nextStep(a,'s');
            break;
        case 77:
            nextStep(a,'d');
            break;
        default:
            break;
        }
    }
    while(true);
}

void Game::show()
{
    const char split[27] = "-------------------------\n";
    for (int i = 0; i < 4; i++)
    {
        printf(split);
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
                printf("|     ");
            else
                printf("|%5d", a[i][j]);
        }
        printf("|\n");
    }
    printf(split);
    return;
}
