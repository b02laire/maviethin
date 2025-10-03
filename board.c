#include "board.h"
#include <stdio.h>

Bitboard white_pawns, white_rooks, white_knights, white_bishops, white_queen, white_king;
Bitboard black_pawns, black_rooks, black_knights, black_bishops, black_queen, black_king;
Bitboard white_pieces, black_pieces;

void init_board(){
    white_pawns=0xFF00;
    white_rooks=0x81;
    white_knights=0x42;
    white_bishops=0x24;
    white_queen=0x08;
    white_king=0x10;

    black_pawns=0x00FF000000000000;
    black_rooks=0x8100000000000000;
    black_knights=0x4200000000000000;
    black_bishops=0x2400000000000000;
    black_queen=0x0800000000000000;
    black_king=0x1000000000000000;

    white_pieces=white_pawns | white_rooks | white_knights | white_bishops | white_queen | white_king;
    black_pieces=black_pawns | black_rooks | black_knights | black_bishops | black_queen | black_king;

    black_pieces=0;
}

void print_board(Bitboard black_pieces, Bitboard white_pieces)
{
    Bitboard all_pieces = black_pieces | white_pieces;
    printf("%lu", all_pieces);
}
int main(){

init_board();
print_board(black_pieces, white_pieces);

return 0;}