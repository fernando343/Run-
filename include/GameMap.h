#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapaCell.h"


class GameMap
{
    public:
        GameMap();

        MapaCell* PlayerCell;
        MapaCell cells[25][100];

        void DrawIntro();
        void DrawVictory();
        void DrawOver();
        void Draw();
        bool SetPlayerCell(int PlayerX, int PlayerY);

        bool isGameOver;

    protected:
        void LoadMapFromFile();
    private:
};

#endif // GAMEMAP_H
