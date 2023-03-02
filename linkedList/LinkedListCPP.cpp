#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	int data;
	Node<T>* next;

	Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList
{
	Node<T>* first; // Первый элемент
	Node<T>** last; // Адрес на последний элемент
public:
	LinkedList() : first(nullptr), last(nullptr) {}

	void PushBack(int value)
	{
		Node<T>* new_node = new Node<T>(value);

		if (first == nullptr)
		{
			first = new_node;
			last = &first->next;
		}
		else
		{
			*last = new_node; // Получить досутп к next
			last = &new_node->next; // Перемещаю ласт на новый элемент
		}
	}

	void Show()
	{
		auto cur_node = first;

		while (cur_node != nullptr)
		{
			cout << cur_node->data << " -> ";
			cur_node = cur_node->next;
		}

		cout << "null" << endl;
	}
};

int main()
{
	LinkedList<int> llist;
	llist.PushBack(1);
	llist.PushBack(2);
	llist.PushBack(3);
	llist.PushBack(4);

	llist.Show();
}