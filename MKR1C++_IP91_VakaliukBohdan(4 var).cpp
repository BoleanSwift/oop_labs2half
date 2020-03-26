#include <iostream>
#include <cstdlib>
using namespace std;

struct Node       
{
    int x;     //Значение x будет передаваться в список
    Node* Next, * Prev; 
};

class List   //Создаем тип данных Список
{
    Node* Head, * Tail; //Указатели на адреса начала списка и его конца
public:
    List() :Head(NULL), Tail(NULL) {}; 
    ~List(); //Деструктор
    void Show(); 
    void Add(int x); 
};

List::~List() //Деструктор
{
    while (Head) 
    {
        Tail = Head->Next; 
        delete Head; 
        Head = Tail; //Смена адреса начала на адрес следующего элемента
    }
}

void List::Add(int x)
{
    Node* temp = new Node; 
    temp->Next = NULL;  
    temp->x = x;//Записываем значение в структуру

    if (Head != NULL) 
    {
        temp->Prev = Tail; 
        Tail->Next = temp; 
        Tail = temp; 
    }
    else //Если список пустой
    {
        temp->Prev = NULL; 
        Head = Tail = temp; 
    }
}

void List::Show()
{
    //Выводим список с конца
    Node* temp = Tail;
   
    while (temp != NULL) 
    {
        cout << temp->x << " "; //Выводить значение на экран
        temp = temp->Prev; //Указываем, что нужен адрес предыдущего элемента
    }
    cout << "\n";

    //Выводим список с начала
    temp = Head; //Временно указываем на адрес первого элемента
    while (temp != NULL)
    {
        cout << temp->x << " "; //Выводим каждое считанное значение на экран
        temp = temp->Next; //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}


int main()
{
    int i, n, k;
    List lst;
    cout << "Enter the number of records ";
    cin >> n;
    cout << "Enter numbers" << endl;
    for (i = 0; i < n; i++) {
        cout << i + 1 << " = ";
        cin >> k;
        lst.Add(k);
    }

    lst.Show(); //Отображаем список на экране
    return 0;
}