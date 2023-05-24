#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

template<typename T>
struct Node
{
	int data;
	Node<T>* next;
	Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class ListIterator {
public:
    ListIterator(Node<T>* node) : current(node) {}
    bool operator==(const ListIterator& other) const {
        return current == other.current;
    }
    
    bool operator!=(const ListIterator& other) const {
        return !(*this == other);
    }
    
    T& operator*() const {
        return current->data;
    }
    
    ListIterator& operator++() {
        current = current->next;
        return *this;
    }
    
    ListIterator operator++(int) {
        ListIterator old = *this;
        ++(*this);
        return old;
    }
    
private:
    Node<T>* current;
};

template<typename T>
class LinkedList
{
    size_t size;
	Node<T>* first; // Первый элемент
	Node<T>** last; // Адрес на последний элемент
	
public:
	LinkedList() : first(nullptr), last(nullptr), size(0) {}

	void PushBack(T value)
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
		
		size++;
	}
	
	void PushFront(T value) {
		Node<T>* new_node = new Node<T>(value);
        new_node->next = first;
        first = new_node;
        size++;
	}
	
	void Insert(size_t idx, T value) {
        Node<T>* new_node = new Node<T>(value);
        if (idx == 0) {
            new_node->next = first;
            first = new_node;
        } 
        
        else {
            Node<T>* current_node = first;
            for (int i = 0; i < idx - 1; i++) {
                if (current_node == nullptr) {
                    std::cerr << "Error: position out of range" << std::endl;
                    return;
                }
                
                current_node = current_node->next;
            }
            
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
        
        size++;
	}
	
	void Pop_Back() {
        if (first == nullptr) {
            std::cerr << "Error: list is empty" << std::endl;
            return;
        }
        
        if (first->next == nullptr) {
            delete first;
            first = nullptr;
            return;
        }
        
        Node<T>* current_node = first;
        while (current_node->next->next != nullptr) {
            current_node = current_node->next;
        }
        
        delete current_node->next;
        current_node->next = nullptr;
        size--;
    }
    
    void Pop_Front() {
        if (first == nullptr) {
            std::cerr << "Error: list is empty" << std::endl;
            return;
        }
        
        Node<T>* temp = first;
        first = first->next;
        delete temp;
        size--;
	}
	
	void Remove_At(size_t index){
        if (first == nullptr) {
            std::cerr << "Error: list is empty" << std::endl;
            return;
        }
        
        if (index == 0) {
            Pop_Front();
            return;
        }
        
        Node<T>* current_node = first;
        Node<T>* previous_node = nullptr;
        for (int i = 0; i < index; i++) {
            if (current_node == nullptr) {
                std::cerr << "Error: index out of range" << std::endl;
                return;
            }
            
            previous_node = current_node;
            current_node = current_node->next;
        }
        
        previous_node->next = current_node->next;
        delete current_node;
        size--;
	}

	T& operator[](size_t index) {
        Node<T>* current_node = first;
        for (size_t i = 0; i < index; i++)
            current_node = current_node->next;

        return current_node->data;
    }
    const T& operator[](size_t index) const {
        Node<T>* current_node = first;
        for (size_t i = 0; i < index; i++) 
            current_node = current_node->next;
        
        return current_node->data;
    }

	size_t Size() const { return size; }

	bool empty() const
	{
        if  (first == nullptr)
            return true;
            
        return false;
	}

	void clear() { first = nullptr; }

	T front() const{ return first->data; }

	T back() const {
        Node<T>* current_node = first;
        while (current_node->next != nullptr)
            current_node = current_node->next;
            
        return current_node->data;
	}
	
	ListIterator<T> begin() const { return ListIterator<T>(first); }
    
    ListIterator<T> end() const {
        return ListIterator<T>(nullptr);
    }

	void Show() {
		auto cur_node = first;
		while (cur_node != nullptr)
		{
			cout << cur_node->data << " -> ";
			cur_node = cur_node->next;
		}

		cout << "null" << endl;
	}
};

void print_lst(const LinkedList <char> &l) {
    for(int i = 0; i < l.Size(); i++)
        cout << l[i];
}

int main()
{
    LinkedList<char> lst; // ваш список
    std::cout << std::boolalpha << lst.empty() << std::endl;

    for (int i = 0; i < 5; i++)
        lst.PushBack(char('a' + i));

    print_lst(lst);

    for (int i = 0; i < 5; i++)
        lst.Insert(0, char('z' - i));

    print_lst(lst);

    for (size_t i = 0; i != lst.Size(); i++)
        lst[i] = char('a' + i);

    print_lst(lst);
    
    lst.Pop_Back();
    lst.Pop_Front();
    
    print_lst(lst);

    lst.Remove_At(5);
    lst.Insert(3, 'o');
    
    print_lst(lst);

    lst.clear();

    lst.PushBack('q');
    lst.PushBack('w');
    
    std::cout << lst.Size() << ' ' << std::boolalpha << lst.empty() << std::endl;
}
