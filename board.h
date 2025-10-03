#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

typedef uint64_t Bitboard;

extern Bitboard white_pawns, white_rooks, white_knights,
 white_bishops, white_queen, white_king;
extern Bitboard black_pawns, black_rooks, black_knights,
 black_bishops, black_queen, black_king;

extern Bitboard white_pieces;
extern Bitboard black_pieces;

void init_board();
void print_board();

#endif //BOARD_H