#include "castle.h"

int my_n,my_m,my_q,my_y;
bool my_need_answer;

void castle_init(int& N, int& M, int& Q, int& Y) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> my_n >> my_m >> my_q >> my_y;

  my_need_answer = false;

  N = my_n;
  M = my_m;
  Q = my_q;
  Y = my_y;
}

void castle_read_map(std::vector<int>& A, std::vector<int>& B) {
  A.resize(my_m);
  B.resize(my_m);
  for (int i = 0;i < my_m;i++) {
    int a,b;
    std::cin >> A[i] >> B[i];
  }
}

void castle_read_event(int& T, int& X, int& Y) {
  if (my_need_answer) {
    std::cout << "You must answer immediately AFTER being asked" << std::endl;
    exit(1);
  }
  std::cin >> T >> X >> Y;
  if (T == 2) my_need_answer = true;
}

void castle_answer(int R) {
  if (my_need_answer) {
    my_need_answer = false;
  } else {
    std::cout << "You answer BEFORE being asked" << std::endl;
    exit(1);
  }
  std::cout << R << "\n";
  //std::cout << R << std::endl;
}

