//saves/loads game

#include<stdio.h>

void fileCheck()
{
    //checks what save files exist
    //returns them with numbers (for selection)
    //i.e. 1. game1, 2. game2, 3. game3
    //use load(3) to load game3
}


void save(Character* player)
{
    FILE* fp = fopen("./saveFile.txt","w+");
    fprintf(fp, "%s,%i,%i", player->name,player->room,player->hp);
    fclose(fp);
    //saves game to file
};


void load(FILE* fp)
{
    fp = fopen("./saveFile.txt","r");
    fclose(fp);
    //loads game file
};
