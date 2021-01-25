#include "MapaCell.h"


MapaCell::MapaCell()
{
    id = 0;
}

bool MapaCell::isBlocked(){

    if(id == '1'){
        return true;
    }else{
        return false;
    }
}

