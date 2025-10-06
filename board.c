#include "board.h"
#include <stdio.h>

void init_board(Board *board)
{
    board->white_pawns = 0xFF00;
    board->white_rooks = 0x81;
    board->white_knights = 0x42;
    board->white_bishops = 0x24;
    board->white_queen = 0x08;
    board->white_king = 0x10;

    board->black_pawns = 0x00FF000000000000;
    board->black_rooks = 0x8100000000000000;
    board->black_knights = 0x4200000000000000;
    board->black_bishops = 0x2400000000000000;
    board->black_queen = 0x0800000000000000;
    board->black_king = 0x1000000000000000;
}
int get_piece_at_square(Board *board, const int square){
    // 1ULL is "1" in an unsigned long long int
    const uint64_t mask = 1ULL << square;

    if (board->white_pawns & mask) return 0;
    if (board->white_knights & mask) return 1;
    if (board->white_bishops & mask) return 2;
    if (board->white_rooks & mask) return 3;
    if (board->white_queen & mask) return 4;
    if (board->white_king & mask) return 5;

    if (board->black_pawns & mask) return 6;
    if (board->black_knights & mask) return 7;
    if (board->black_bishops & mask) return 8;
    if (board->black_rooks & mask) return 9;
    if (board->black_queen & mask) return 10;
    if (board->black_king & mask) return 11;

    // empty square
    else return -1;


}
void print_board(Board board)
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
            int piece = get_piece_at_square(&board, rank * 8 + file);
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
    Board board;
    init_board(&board);
    print_board(board);

    return 0;
}
