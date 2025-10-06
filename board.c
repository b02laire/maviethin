#include "board.h"
#include <stdio.h>

Bitboard white_pawns, white_rooks, white_knights, white_bishops, white_queen,
         white_king;
Bitboard black_pawns, black_rooks, black_knights, black_bishops, black_queen,
         black_king;
Bitboard white_pieces, black_pieces;

void init_board()
{
    white_pawns = 0xFF00;
    white_rooks = 0x81;
    white_knights = 0x42;
    white_bishops = 0x24;
    white_queen = 0x08;
    white_king = 0x10;

    black_pawns = 0x00FF000000000000;
    black_rooks = 0x8100000000000000;
    black_knights = 0x4200000000000000;
    black_bishops = 0x2400000000000000;
    black_queen = 0x0800000000000000;
    black_king = 0x1000000000000000;

    white_pieces = white_pawns | white_rooks | white_knights | white_bishops |
        white_queen | white_king;
    black_pieces = black_pawns | black_rooks | black_knights | black_bishops |
        black_queen | black_king;

    black_pieces = 0;
}
int get_piece_at_square(const int square){
    // 1ULL is "1" in an unsigned long long int
    const uint64_t mask = 1ULL << square;

    if (white_pawns & mask) return 0;
    if (white_knights & mask) return 1;
    if (white_bishops & mask) return 2;
    if (white_rooks & mask) return 3;
    if (white_queen & mask) return 4;
    if (white_king & mask) return 5;

    if (black_pawns & mask) return 6;
    if (black_knights & mask) return 7;
    if (black_bishops & mask) return 8;
    if (black_rooks & mask) return 9;
    if (black_queen & mask) return 10;
    if (black_king & mask) return 11;

    // empty square
    else return -1;


}
void print_board()
{
    const char *seperator = "+---+---+---+---+---+---+---+---+";
    for (int rank = 7; rank >= 0; rank--)
    {
        printf("%s\n|", seperator);
        for (int file = 0; file < 8; file++)
        {
            const char* symbols[12] = {
                "P", "N", "B", "R", "Q", "K",
                "p", "n", "b", "r", "q", "k"
            };
            int piece = get_piece_at_square(rank * 8 + file);
            char symbol = (piece != -1) ? *symbols[piece] : ' ';
            printf(" %c |", symbol );

        }
        printf(" %u\n", rank+1);
    }
    printf("%s", seperator);
    printf("\n%s\n", "  a   b   c   d   e   f   g   h");
}

int main()
{
    init_board();
    print_board();

    return 0;
}
