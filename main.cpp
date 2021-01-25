#include <iostream>
#include "Player.h"
#include "MapaCell.h"
#include "GameMap.h"

using namespace std;

int main()
{
    GameMap Map;
    Player Hero;

    Map.DrawIntro();
    Map.Draw();


    while(Map.isGameOver == false){
            cout << "Introduce el comando de movimiento A, W, S y D" << endl;
        Hero.CallInput();

        //Actualizado de informacion heroe a mapa
        if(Map.SetPlayerCell(Hero.x, Hero.y)){

            //Aqui dibujamos el mapa
            Map.Draw();

        }else{
            Hero.ResetToSafePosition();
            //Aqui dibujamos el mapa
            Map.Draw();
        }
    }

    return 0;
}
