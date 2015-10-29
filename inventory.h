//stores player items
//contains all items in the game

#include<stdio.h>
#include<stdlib.h>

#ifndef INVENTORY_H
#define INVENTORY_H


struct Item 
{
    int id;
    char* name;
    int pickup;
    int useable;
    int size;
    int uses;
};
typedef struct Item Item;

//inventory() contains the user's personal inventory
void inventory()
{
};


//items need to know/have:
//  id              - able to be referenced in code
//  name            - in-game name for player to see
//  pick-up-able?   - can the item be picked up
//  useable         - can the item be used
//  weight/size     - how heavy/large is it (inventory space)
//  uses            - can it be used up like matches or is it infinite uses?

void makeItems() 
{
    //Item* button1[] = {1,"button1",0,1,0,0};
    //Item* itemList[] = { 
};


void itemList()
{
    // for(int k = 0; k < sizeof(Item); k++)
    // {
    //     Item* (itemList[k]) = malloc(sizeof(Item));
    //     itemList[k] -> id = (itemList[k])[0];
    //     itemList[k] -> name = (itemList[k])[1];
    //     itemList[k] -> pickup = (itemList[k])[2];
    //     itemList[k] -> useable = (itemList[k])[3];
    //     itemList[k] -> size = (itemList[k])[4];
    //     itemList[k] -> uses = (itemList[k])[5];
    // }
    Item* button1 = malloc(sizeof(Item));
    button1 -> id = 1;
    button1 -> name = "button1";
    button1 -> pickup = 0;
    button1 -> useable = 1;
    button1 -> size = 0;
    button1 -> uses = 0;
};
#endif