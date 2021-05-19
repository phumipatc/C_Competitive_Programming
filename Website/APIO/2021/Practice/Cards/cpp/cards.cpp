/*
	Task	: cards
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 May 2021 [09:10]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}

#include "cards.h"

void init_magician(int N, int K) {
}

void init_assistant(int N, int K) {
}

std::vector<int> choose_cards(std::vector<int> cards) {
  return std::vector<int>((int) cards.size() - 1);
}

int find_discarded_card(std::vector<int> cards) {
  return 1;
}

int main() {
  int N, K, Q;
  assert(scanf("%d %d %d", &N, &K, &Q) == 3);
  
  init_assistant(N, K);
  init_magician(N, K);

  for (int i = 0; i < Q; ++i) {
    std::vector<int> cards(K);
    for (int j = 0; j < K; ++j) {
      assert(scanf("%d", &cards[j]) == 1);
    }

    std::vector<int> chosen_cards = choose_cards(cards);

    if (static_cast<int>(chosen_cards.size()) != K - 1) {
      printf("Wrong Answer: invalid number of chosen cards\n");
      continue;
    }
    std::vector<bool> cards_chosen(K, false);
    bool wrong_chosen_cards = false;
    for (int card : chosen_cards) {
      int card_idx = std::lower_bound(cards.begin(), cards.end(), card) -
                     cards.begin();
      if (card_idx >= K || cards[card_idx] != card) {
        printf("Wrong Answer: invalid chosen card number\n");
        wrong_chosen_cards = true;
        break;
      }
      if (cards_chosen[card_idx]) {
        printf("Wrong Answer: duplicated chosen cards\n");
        wrong_chosen_cards = true;
        break;
      }
      cards_chosen[card_idx] = true;
    }

    if (!wrong_chosen_cards) {
      int discarded_card = find_discarded_card(chosen_cards);
      int card_idx = std::lower_bound(cards.begin(), cards.end(),
                                      discarded_card) - cards.begin();
      if (card_idx >= K || cards[card_idx] != discarded_card ||
          cards_chosen[card_idx]) {
        printf("Wrong Answer: wrong discarded card\n");
        continue;
      }

      printf("Accepted: chosen_cards = [");
      for (int j = 0; j < K - 1; ++j) {
        printf("%d", chosen_cards[j]);
        if (j == K - 2) {
          printf("]; ");
        } else {
          printf(", ");
        }
      }
      printf("discarded_card = %d\n", discarded_card);
    }
  }
  return 0;
}
