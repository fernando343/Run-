#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;
}

void GameMap::Draw()
{

    for (int i = 0; i < 30; i++)
    {
        for (int p = 0; p < 100; p++)
        {
            cout << cells[i][p].id;
        }

        cout << endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if (cells[PlayerY][PlayerX].isBlocked() == false)
    {
        if (cells[PlayerY][PlayerX].id == '$')
        {
            DrawVictory();
            isGameOver = true;
        }
        else if (cells[PlayerY][PlayerX].id == '5')
        {
            DrawOver();
            isGameOver = true;
        }
        else
        {

            if (PlayerCell != NULL)
            {
                PlayerCell->id = 0;
            }
            PlayerCell = &cells[PlayerY][PlayerX];
            PlayerCell->id = 20;

            return true;
        }
    }
    else
    {

        return false;
    }

    //cout << "las cordenadas del jugador estan en: " << PlayerX << ", " << PlayerY;
}

void GameMap::DrawIntro()
{

    string line;
    int row = 0;
    ifstream Myfile("intro.txt");

    if (Myfile.is_open())
    {
        while (getline(Myfile, line))
        {
            cout << line << endl;
        }

        cin >> line;
    }
    else
    {
        cout << "Intro file could not be loaded" << endl;
    }
}

void GameMap::DrawVictory()
{

    string line;
    int row = 0;
    ifstream Myfile("victoria.txt");

    if (Myfile.is_open())
    {
        while (getline(Myfile, line))
        {
            cout << line << endl;
        }

        cin >> line;
    }
    else
    {
        cout << "Intro file could not be loaded" << endl;
    }
}

void GameMap::DrawOver()
{

    string line;
    int row = 0;
    ifstream Myfile("over.txt");

    if (Myfile.is_open())
    {
        while (getline(Myfile, line))
        {
            cout << line << endl;
        }

        cin >> line;
    }
    else
    {
        cout << "GameOver file could not be loaded" << endl;
    }
}

void GameMap::LoadMapFromFile()
{

    /*ofstream FileCreated("Map.txt");
    if(FileCreated.is_open()){

    }else{
    cout << "Map file could not be loaded" << endl ;
    }*/

    string line;
    int row = 0;
    ifstream Myfile("Map.txt");

    if (Myfile.is_open())
    {
        while (getline(Myfile, line))
        {
            for (int p = 0; p < line.length(); p++)
            {

                if (line[p] == '0')
                {
                    cells[row][p].id = 0;
                }
                else
                {
                    cells[row][p].id = line[p];
                }
            }
            row++;
        }
    }
    else
    {
        cout << "Map file could not be loaded" << endl;
    }
}
