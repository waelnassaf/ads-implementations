#include <iostream>
#include <string>

using namespace std;

class Suspect{
public:
	string name;
	Suspect(string cname):name(cname){}
	Suspect() {}
};

class Lawyer {
public:
	string name;
	Lawyer(string cname) :name(cname) {}
	Lawyer(){}
};

class Case {
public:
	Suspect* suspects;
	Lawyer* lawyers;
	int nLawyers;
	int nSuspects;
	//....
	Case(int nLawyers, int nSuspects) {
		this->lawyers = new Lawyer[nLawyers];
		this->suspects = new Suspect[nSuspects];
		this->nLawyers = nLawyers;
		this->nSuspects = nSuspects;
	}
	Case() {
		this->lawyers = new Lawyer[1];
		this->suspects = new Suspect[1];
		this->nLawyers = 1;
		this->nSuspects = 1;
	}
};

class Court {
public:
	Case* cases;
	int nCases;
	Court() {
		nCases = 1;
		cases = new Case[1];
	}
	Court(int n):nCases(n) {
		cases = new Case[nCases];
	}

	Lawyer* GetLawyers(int& size) {
		int counter = 0;
		Lawyer* lawyers;
		for (int i = 0; i < nCases; i++)
		{
			counter += cases[i].nLawyers;
		}
		lawyers = new Lawyer[counter];
		int c2 = 0;
		for (int i = 0; i < nCases; i++)
		{
			for (int j = 0; j < cases[i].nLawyers; j++)
			{
				lawyers[c2++] = cases[i].lawyers[j];
			}
		}
		size = counter;
		return lawyers;
	}
};


void main()
{
	Court c(2);
	c.cases->lawyers[0] = Lawyer("omar");
	c.cases[1].lawyers = new Lawyer("ahmad");
	int n = 0;
	Lawyer* lawyers = c.GetLawyers(n);
	cout << "n. of lawyers = "<<n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "lawyer[" << i << "]= " << lawyers[i].name<<endl;
	}

	int i;
	for (i = 0 ; i < 3; i++) {
		cout << "A" << endl;
	}

	system("pause");
}
