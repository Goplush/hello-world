#include<bits\stdc++.h>
using namespace std;

struct Node
{
	int* line;
	Node* next;
};
class YHTri {
private:
	int Line;
	int MaxL;
	Node* head;
	Node* Last;
public:
	YHTri(int n);
	YHTri():YHTri(0){}
	void generate();

};
YHTri::YHTri(int n) :MaxL(n), Line(1), head(new Node)
{
	head->next = NULL;
	Last = head;
}
void YHTri ::generate()
{
	for (; Line <= MaxL; Line++)
	{
		Last->next = new Node;
		Last->next->line = new int[Line + 2];
		if (Line == 1)
		{
			for (int i = 0; i < Line + 2; i++) {
				switch (i)
				{
				case 0:
					*((Last->next->line) + i) = 0;
					break;
				case 1:
					*((Last->next->line) + i) = 1;
					break;
				case 2:
					*((Last->next->line) + i) = 0;
					break;
				default:
					break;
				}
			}
		}
		else
		{
			*(Last->next->line) = 0;
			*((Last->next->line) + Line + 1) = 0;
			for (int i = 1; i <= Line; i++)
			{
				*((Last->next->line) + i) = *((Last->line) + i - 1) + *((Last->line) + i);
			}
		}
		Last = Last->next;
		for (int i = 0; i < Line + 2; i++)
		{
			if(*((Last->line) + i)==0)
			{ }
			else
			{
				cout << *((Last->line) + i)<<"  ";
			}
		}
		cout << endl;
	}
	

}
