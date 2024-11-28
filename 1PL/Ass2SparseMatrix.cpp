#include <iostream>
using namespace std;
#define MAX 50

using namespace std;
class Sparse
{
public:
	int sp[MAX][3];
	int len;
	int nz;
	Sparse();
	Sparse(int r, int c, int l)
	{
		sp[0][0] = r;
		sp[0][1] = c;
		sp[0][2] = l;
		len = 0;
	}
	void insert(int row, int col, int val);
	void disp();
	Sparse transpose();
	void fast_trans(Sparse sp1);
	Sparse add(Sparse sp2);
	Sparse multi(Sparse sp2);
};
void Sparse ::insert(int row, int col, int val)
{
	if (row >= sp[0][0] || col >= sp[0][1])
	{
		cout << "INVALID";
	}
	else
	{
		sp[len + 1][0] = row;
		sp[len + 1][1] = col;
		sp[len + 1][2] = val;
		len++;
	}
	sp[0][2] = len;
}
void Sparse::disp()
{

	cout << "\nROW\tCOLUMN\tVALUE" << endl;
	for (int i = 0; i <= sp[0][2]; i++)
	{
		cout << " " << sp[i][0] << "\t" << " " << sp[i][1] << "\t" << " " << sp[i][2] << endl;
	}
}
Sparse Sparse::transpose()
{
	Sparse t(sp[0][1], sp[0][0], sp[0][2]);
	t.len = 0;

	for (int i = 0; i < sp[0][1]; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (sp[j][1] == i)
			{
				t.len++;
				t.sp[t.len][0] = sp[j][1];
				t.sp[t.len][1] = sp[j][0];
				t.sp[t.len][2] = sp[j][2];
			}
		}
	}
	return t;
}
void Sparse::fast_trans(Sparse sp1)
{
	int colno;
	int x;
	int *cnt = new int[sp1.sp[0][1]];
	int *loc = new int[sp1.sp[0][1]];
	for (int i = 0; i < sp1.sp[0][1]; i++)
	{
		cnt[i] = 0;
	}
	for (int i = 1; i <= sp1.sp[0][2]; i++)
	{
		colno = sp1.sp[i][1];
		cnt[colno]++;
	}
	loc[0] = 1;
	for (int i = 1; i <= sp1.sp[0][1]; i++)
	{
		loc[i] = loc[i - 1] + cnt[i - 1];
	}
	for (int i = 1; i <= sp1.sp[0][2]; i++)
	{
		colno = sp1.sp[i][1];
		x = loc[colno];
		sp[x][0] = sp1.sp[i][1];
		sp[x][1] = sp1.sp[i][0];
		sp[x][2] = sp1.sp[i][2];
		loc[colno]++;
	}
}
Sparse Sparse::add(Sparse sp2)
{
	Sparse result(sp[0][0], sp[0][1], sp[0][2]);

	if (sp[0][0] != sp2.sp[0][0] && sp[0][1] != sp[0][1])
	{
		cout << "Cannot add";
	}
	else
	{
		int sp1pos = 1;
		int sp2pos = 1;
		while (sp1pos <= len && sp2pos <= len)
		{
			if ((sp[sp1pos][0] > sp2.sp[sp2pos][0]) || (sp[sp1pos][0] == sp2.sp[sp2pos][0] && sp[sp1pos][1] > sp2.sp[sp2pos][1]))
			{
				result.len++;
				result.sp[result.len][0] = sp2.sp[sp2pos][0];
				result.sp[result.len][1] = sp2.sp[sp2pos][1];
				result.sp[result.len][2] = sp2.sp[sp2pos][2];

				sp2pos++;
			}

			else if ((sp[sp1pos][0] < sp2.sp[sp2pos][0]) || (sp[sp1pos][0] == sp2.sp[sp2pos][0] && sp[sp1pos][1] < sp2.sp[sp2pos][1]))
			{
				result.len++;
				result.sp[result.len][0] = sp2.sp[sp2pos][0];
				result.sp[result.len][1] = sp2.sp[sp2pos][1];
				result.sp[result.len][2] = sp2.sp[sp2pos][2];

				sp1pos++;
			}

			else
			{
				result.len++;
				result.sp[result.len][0] = sp2.sp[sp2pos][0];
				result.sp[result.len][1] = sp2.sp[sp2pos][1];
				result.sp[result.len][2] = sp[sp1pos][2] + sp2.sp[sp2pos][2];

				sp1pos++;
				sp2pos++;
			}
		}

		while (sp1pos <= len)
		{
			result.insert(sp[sp1pos][0], sp[sp1pos][1], sp[sp1pos][2]);
			sp1pos++;
		}
		while (sp2pos <= len)
		{
			result.insert(sp2.sp[sp1pos][0], sp2.sp[sp1pos][1], sp2.sp[sp1pos][2]);
			sp2pos++;
		}

		result.sp[0][2] = result.len;
		return result;
	}
}
Sparse Sparse::multi(Sparse sp2)
{
	Sparse result(sp[0][0], sp2.sp[0][1], 0);

	if (sp[0][1] != sp2.sp[0][0])
	{
		cout << "Matrix multiplication not possible!" << endl;
		return result;
	}

	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= sp2.len; j++)
		{
			if (sp[i][1] == sp2.sp[j][0])
			{
				int r = sp[i][0];
				int c = sp2.sp[j][1];
				int v = sp[i][2] * sp2.sp[j][2];

				bool found = false;
				for (int k = 1; k <= result.len; k++)
				{
					if (result.sp[k][0] == r && result.sp[k][1] == c)
					{
						result.sp[k][2] += v;
						found = true;
						break;
					}
				}

				if (!found)
				{
					result.insert(r, c, v);
				}
			}
		}
	}

	result.sp[0][2] = result.len;
	return result;
}
int main()
{

	int n;
	int r, c, l, row, col, val, r1, c1, l1;
	char choice;
	do
	{

		cout << "ENTER THE WICH MATRIX OPRATION YOU WANTED TO PERFORM \n 1  NORMAL TRANSPOSE \n 2 FAST TRANSPOSE \n 3 ADDITION \n 4 MULTIPICATION :  ";
		cin >> n;

		switch (n)
		{

		case 1:
		{

			cout << "ENETR THE NO OF ROWS COLUMN AND NON ZERO VALUES RESP FOR MATRIX : ";
			cin >> r >> c >> l;
			cout << "\n";

			Sparse sp1(r, c, l);

			for (int i = 0; i < l; i++)
			{
				cout << "ENTER THE ROW NO COLUMN NO AND VALUE RESP FOR MATRIX  : ";
				cin >> row >> col >> val;
				sp1.insert(row, col, val);
			}
			cout << "\nYOUR SPARSE MATRIX IS : \n";
			sp1.disp();
			cout << "\n";
			Sparse t = sp1.transpose();
			cout << "\nYOUR SPARSE MATRIX TRANSPOSE IS : \n";
			t.disp();
			break;
		}

		case 2:
		{

			cout << "ENETR THE NO OF ROWS COLUMN AND NON ZERO VALUES RESP FOR MATRIX : ";
			cin >> r >> c >> l;
			cout << "\n";

			Sparse sp1(r, c, l);
			Sparse sp2(c, r, l);
			for (int i = 0; i < l; i++)
			{
				cout << "ENTER THE ROW NO COLUMN NO AND VALUE RESP FOR MATRIX  : ";
				cin >> row >> col >> val;
				sp1.insert(row, col, val);
			}
			cout << "\nYOUR SPARSE MATRIX IS : \n";
			sp1.disp();
			cout << "/n/n";
			sp2.fast_trans(sp1);
			cout << "YOUR TRANSPOSED SPARSE MATRIX IS : ";
			sp2.disp();
			break;
		}

		case 3:
		{
			cout << "ENETR THE NO OF ROWS COLUMN AND NON ZERO VALUES RESP FOR 1ST MATRIX : ";
			cin >> r >> c >> l;
			cout << "\n";

			Sparse sp1(r, c, l);
			for (int i = 0; i < l; i++)
			{
				cout << "ENTER THE ROW NO COLUMN NO AND VALUE RESP FOR FIRST MATRIX  : ";
				cin >> row >> col >> val;
				sp1.insert(row, col, val);
			}
			cout << "\n";
			cout << "ENETR THE NO OF ROWS COLUMN AND NON ZERO VALUES RESP FOR 2ND MATRIX : ";
			cin >> r1 >> c1 >> l1;
			cout << "\n";

			Sparse sp2(r1, c1, l1);

			for (int i = 0; i < l1; i++)
			{
				cout << "ENTER THE ROW NO COLUMN NO AND VALUE RESP FOR SECOND MATRIX  : ";
				cin >> row >> col >> val;
				sp2.insert(row, col, val);
			}
			cout << "\nYOUR FIRST SPARSE MATRIX IS : \n";
			sp1.disp();
			cout << "\n";
			cout << "YOUR SECOND SPARSE MATRIX IS : ";
			sp2.disp();

			cout << "ADDITION OF TWO MATRICES IS : ";
			cout << "\n";
			Sparse r = sp1.add(sp2);
			r.disp();
			break;
		}
		case 4:
		{
			cout << "ENETR THE NO OF ROWS COLUMN AND NON ZERO VALUES RESP FOR 1ST MATRIX : ";
			cin >> r >> c >> l;
			cout << "\n";

			Sparse sp1(r, c, l);
			for (int i = 0; i < l; i++)
			{
				cout << "ENTER THE ROW NO COLUMN NO AND VALUE RESP FOR FIRST MATRIX  : ";
				cin >> row >> col >> val;
				sp1.insert(row, col, val);
			}
			cout << "\n";
			cout << "ENETR THE NO OF ROWS COLUMN AND NON ZERO VALUES RESP FOR 2ND MATRIX : ";
			cin >> r1 >> c1 >> l1;
			cout << "\n";

			Sparse sp3(r1, c1, l1);

			for (int i = 0; i < l1; i++)
			{
				cout << "ENTER THE ROW NO COLUMN NO AND VALUE RESP FOR SECOND MATRIX  : ";
				cin >> row >> col >> val;
				sp3.insert(row, col, val);
			}
			cout << "\nYOUR FIRST SPARSE MATRIX IS : \n";
			sp1.disp();
			cout << "\n";
			cout << "YOUR SECOND SPARSE MATRIX IS : ";
			sp3.disp();
			Sparse sp2(c, r, l);
			sp2.fast_trans(sp3);
			cout << "MULTIPLICATION OF TWO MATRICES IS : ";
			cout << "\n";
			Sparse r = sp1.multi(sp3);
			r.disp();
			break;
		}
		}
		cout << "\n Do you want to continue (y/n): ";
		cin >> choice;

	} while (choice == 'y');

	return 0;
}