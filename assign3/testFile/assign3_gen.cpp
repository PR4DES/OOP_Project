#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;

struct Hand
{
	enum { HIGH_CARD, PAIR, TWO_PAIRS, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH };

	int rank[5], suit[5];
	long value;

	void operator ()()
	{
		int rank_pot[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, rank_val5[5] = {4, 3, 2, 1, 0};
			
		while(rank_val5[4] == rank_val5[0] - 4)
		{
			random_shuffle(rank_pot, rank_pot + sizeof rank_pot / sizeof *rank_pot);
			memcpy(rank_val5, rank_pot, sizeof rank_val5);
			sort(rank_val5, rank_val5 + 5, greater<int>());
		}
		
		int rank_pot9[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
		int suit_pot[] = {0, 1, 2, 3};
		int suit_pot4[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
		int suit_pot5[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
		int type_pot[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		int type_pot4[] = {0, 1, 2, 3};

		random_shuffle(rank_pot9, rank_pot9 + sizeof rank_pot9 / sizeof *rank_pot9);
		random_shuffle(suit_pot, suit_pot + sizeof suit_pot / sizeof *suit_pot);
		random_shuffle(suit_pot4, suit_pot4 + sizeof suit_pot4 / sizeof *suit_pot4);
		random_shuffle(suit_pot5, suit_pot5 + sizeof suit_pot5 / sizeof *suit_pot5);
		random_shuffle(type_pot, type_pot + sizeof type_pot / sizeof *type_pot);
		random_shuffle(type_pot4, type_pot4 + sizeof type_pot4 / sizeof *type_pot4);
		
		int type = type_pot[0], tb[5];
		type_pot[0] = type == STRAIGHT_FLUSH ? STRAIGHT : type == FLUSH ? type_pot4[0] : type_pot[0];
		
		if(type_pot[0] == HIGH_CARD)
		{
			int rank_val5[] = {rank_pot[0], rank_pot[1], rank_pot[2], rank_pot[3], rank_pot[4]};
			sort(rank_val5, rank_val5 + 5, greater<int>());
			memcpy(rank, rank_val5, sizeof rank_val5);
			memcpy(tb, rank_val5, sizeof rank_val5);
			memcpy(suit, suit_pot4, sizeof suit);
		}
		else if(type_pot[0] == PAIR)
		{
			int rank_val3[] = {rank_pot[0], rank_pot[1], rank_pot[2]};
			sort(rank_val3, rank_val3 + 3, greater<int>());
			memcpy(rank, rank_val3, sizeof rank_val3);
			memcpy(tb + 1, rank_val3, sizeof rank_val3);
			rank[3] = rank[4] = tb[0] = rank_pot[3];
			tb[4] = 0;
			memcpy(suit, suit_pot4, sizeof suit);
		}
		else if(type_pot[0] == TWO_PAIRS)
		{
			int rank_val2[] = {rank_pot[0], rank_pot[1]};
			sort(rank_val2, rank_val2 + 2, greater<int>());
			rank[0] = rank[2] = tb[0] = rank_val2[0];
			rank[1] = rank[3] = tb[1] = rank_val2[1];
			rank[4] = tb[2] = rank_pot[2];
			tb[3] = tb[4] = 0;
			memcpy(suit, suit_pot4, sizeof suit);
		}
		else if(type_pot[0] == THREE_OF_A_KIND)
		{
			rank[0] = rank[3] = rank[4] = tb[0] = rank_pot[0];
			rank[1] = rank_pot[1];
			rank[2] = rank_pot[2];
			tb[1] = tb[2] = tb[3] = tb[4] = 0;
			memcpy(suit, suit_pot4, sizeof suit);
		}
		else if(type_pot[0] == STRAIGHT)
		{
			rank[0] = rank_pot9[0];
			rank[1] = rank[0] + 1;
			rank[2] = rank[0] + 2;
			rank[3] = rank[0] + 3;
			rank[4] = tb[0] = rank[0] + 4;
			tb[1] = tb[2] = tb[3] = tb[4] = 0;
			memcpy(suit, suit_pot4, sizeof suit);
		}
		else if(type_pot[0] == FULL_HOUSE)
		{
			rank[0] = rank[3] = rank[4] = tb[0] = rank_pot[0];
			rank[1] = rank[2] = rank_pot[1];
			tb[1] = tb[2] = tb[3] = tb[4] = 0;
			memcpy(suit, suit_pot5, sizeof suit);
		}
		else if(type_pot[0] == FOUR_OF_A_KIND)
		{
			rank[0] = rank[2] = rank[3] = rank[4] = tb[0] = rank_pot[0];
			rank[1] = rank_pot[1];
			tb[1] = tb[2] = tb[3] = tb[4] = 0;
			memcpy(suit, suit_pot5, sizeof suit);
		}
		
		if(type == FLUSH || type == STRAIGHT_FLUSH)
		{
			int rank_val[] = {rank[0], rank[1], rank[2], rank[3], rank[4]};
			sort(rank_val, rank_val + 5, greater<int>());
			memcpy(tb, rank_val, sizeof rank_val);
			suit[1] = suit[2] = suit[3] = suit[4] = suit[0];
		}
		
		random_shuffle(rank, rank + sizeof rank / sizeof *rank);
		value = ((((type * 15L + tb[0]) * 15 + tb[1]) * 15 + tb[2]) * 15 + tb[3]) * 15 + tb[4];
	}
	
	friend ostream &operator <<(ostream &os, const Hand &rhs)
	{
		static char *r = "  23456789TJQKA", *s = "SHDC";
		
		int n = 5;
		while(n--)
		{
			os.put(r[rhs.rank[n]]);
			os.put(s[rhs.suit[n]]);
			if(n)
			{
				os.put(' ');
			}
		}
		return os;
	}
};

int main(int argc, char **argv)
{
	static char *output[] = {"Black wins.", "White wins.", "Tie."};
	
	int n;
	if(argc != 4 || !(n = atoi(argv[3])))
	{
		cout << "assign3_gen, a test case generator for the third assignment in CSE241.\n";
		cout << "20 March 6NH (2015), Kwulwums Kuthey CPSF <mingosudaisuki@gmail.com>\n\n";
		cout << "usage: " << argv[0] << " [test_case_file] [correct_answer_file] [number_of_lines]\n\n";
		
		return 0;
	}
	
	ofstream fout1(argv[1]), fout2(argv[2]);
	while(n--)
	{
		Hand black, white;
		int fail = 1;
		
		while(fail--)
		{
			black();
			white();
			
			int arr[60] = {0}, i = 5;
			while(i--)
			{
				if(arr[black.suit[i] * 15 + black.rank[i]]++ || arr[white.suit[i] * 15 + white.rank[i]]++)
				{
					fail = 1;
				}
			}
		}
		
		fout1 << black << ' ' << white << endl;
		long result = black.value - white.value;
		fout2 << output[!result + (result <= 0)] << endl;
	}
	
	return 0;
}
