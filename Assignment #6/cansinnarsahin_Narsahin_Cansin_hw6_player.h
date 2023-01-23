//Cansin Narsahin
//29126

#include "cansinnarsahin_Narsahin_Cansin_hw6_board.h"

#ifndef cansinnarsahin_Narsahin_Cansin_hw6_player_H
#define cansinnarsahin_Narsahin_Cansin_hw6_player_H

template <class Type> class Player
{
    private:

		static int playerNum; 
        Board<Type> & myBoard; //shares borad with reference variable
        int player_id;
        
    public:
        Player(Board<Type> &b);

        bool updateCell(int, int, Type); //if cell is updated and the function returns true
        void updateMyCells(Type);//updates all of the cell of the player calling the function with the parameter value
        bool unclaimOwnership(int, int); //sets id to 0 of cell
        void unclaimOwnerships();//set id to 0 that the player have
};

template <class Type> int Player<Type>::playerNum = 0;

#include "cansinnarsahin_Narsahin_Cansin_hw6_player.cpp"

#endif