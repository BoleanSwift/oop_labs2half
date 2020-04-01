#include <iostream>
#include <fstream>
#include <string>
#define HSIZE 9999999
#define VOC_PATH "dict_processed.txt"


using namespace std;

class nash_spisok
{
	class Node
	{
	public:
		Node* next;
		string word;
		string data;
		Node(string word, string data, Node* next = nullptr)
		{
			this->word = word;
			this->data = data;
			this->next = next;
		}

	};
	int lsize;
	Node* head;
public:
	nash_spisok();
	~nash_spisok();
	int razmer_spiska();
	void nazad(string word, string data);
	void perehod();
	string naxozhdenie_slova(const string find);
	void ochistka_spiska();
	unsigned long getHash(string a);
	void chtenie_slovarya(nash_spisok* Voc, string path);
};

nash_spisok::nash_spisok()
{

	lsize = 0;
	head = nullptr;

}

nash_spisok::~nash_spisok()
{
	ochistka_spiska();
}

int nash_spisok::razmer_spiska()
{
	return lsize;
}

void nash_spisok::nazad(string word, string data)
{


	if (head == nullptr)
	{
		head = new Node(word, data);
	}
	else
	{
		Node* curnum = head;
		while (curnum->next != nullptr)
		{
			curnum = curnum->next;
		}
		curnum->next = new Node(word, data);
	}
	lsize++;

}

void nash_spisok::perehod()
{
	if (lsize == 0) { cout << "Размер списка = 0."; 
	}
	else
	{
		Node* current = head;
		head = head->next;
		delete current;
		lsize--;
	}
}

string nash_spisok::naxozhdenie_slova(const string find)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->word == find)
		{
			return current->data;
		}
		current = current->next;
	}
	return "Слово неверного формата, попробуйте еще раз.";
}

void nash_spisok::ochistka_spiska()
{
	while (lsize)
	{
		perehod();
		lsize--;
	}
}

unsigned long getHash(string a)
{
	unsigned long hash = 5381;
	int c;

	for (int i = 0; i < a.length(); i++)
	{
		c = a[i];
		hash = ((hash << 5) + hash) + c;
	}
	return hash % HSIZE;
}

void chtenie_slovarya(nash_spisok* Voc, string path)
{
	ifstream voc;
	voc.open(path);
	if (!voc.is_open())
	{
		cout << "Невозможно открыть файл";
	}
	else
	{
		cout << "Загрузка.";
		while (!voc.eof())
		{
			string word, data;
			char ch;
			while (voc.get(ch) && ch != ';')
			{
				word += ch;
			}
			voc.get(ch);
			do
			{
				voc.get(ch);
				data += ch;

			} while (ch != '\n' && !voc.eof());
			Voc[getHash(word)].nazad(word, data);
		}
		voc.close();
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	nash_spisok* Voc = new nash_spisok[HSIZE];
	chtenie_slovarya(Voc, VOC_PATH);
	string input;
	cout << "Что бы выйти, напишите \"exit\"\n";
	do
	{
		cout << "Введите слово: ";
		cin >> input;
		cout << Voc[getHash(input)].naxozhdenie_slova(input);

	} while (input != "exit");
	delete[] Voc;
	return 0;
}