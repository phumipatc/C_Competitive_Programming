#ifndef castle_h
#define castle_h

#include <iostream>
#include <vector>


void castle_init(int& N, int& M, int& Q, int& Y);
void castle_read_map(std::vector<int>& A, std::vector<int>& B);
void castle_read_event(int& T, int& X, int& Y);
void castle_answer(int R);

#endif
