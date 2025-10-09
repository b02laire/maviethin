#ifndef CHESS_H
#define CHESS_H
#include "board.h"

// Move representation
typedef struct {
    int from, to;
    int piece, captured, promoted;
    int flags; // castling, en passant, etc.
} Move;

enum flags
{
    CASTLING,
    EN_PASSANT,
    PROMOTION

};

// Piece movement
int move_piece(Board* board, int from_square, int to_square);
int is_valid_move(Board* board, int from_square, int to_square);
int generate_legal_moves(Board* board, int square, int moves[218]); // max possible moves

// Specific piece movement
int is_valid_pawn_move(Board* board, int from, int to);
int is_valid_rook_move(Board* board, int from, int to);
int is_valid_knight_move(Board* board, int from, int to);
int is_valid_bishop_move(Board* board, int from, int to);
int is_valid_queen_move(Board* board, int from, int to);
int is_valid_king_move(Board* board, int from, int to);

// Game state
int is_in_check(Board* board, int color);
int is_in_checkmate(Board* board, int color);
int is_stalemate(Board* board);
int is_square_attacked(Board* board, int square, int color);

// Move generation
void generate_all_legal_moves(Board* board, MoveList* moves);
void generate_pseudo_legal_moves(Board* board, MoveList* moves);
int perft(Board* board, int depth);

// Castling
int is_valid_castle(Board* board, int color, int king_side);
int perform_castle(Board* board, int color, int king_side);

// En passant
int is_valid_en_passant(Board* board, int from, int to);
int perform_en_passant(Board* board, int from, int to);

// Pawn promotion
int is_pawn_promotion(Board* board, int to_square);
void promote_pawn(Board* board, int square, int piece);

#endif CHESS_H