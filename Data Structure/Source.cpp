#include<iostream>
#include<vector>
using namespace std;

enum type
{
	maxHeap,
	minHeap
};
class Node {
public:
	Node* link;
	int info;
	Node() {
		link = nullptr;
		info = 0;
	}
};
class singleUnorderLinkedList {
public:
	Node* head;
	Node* tail;
	int count;
	singleUnorderLinkedList() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	void insert(int info) {
		Node* newnode = new Node();
		newnode->info = info;
		Node* current = head;
		if (head == nullptr) {
			head = newnode;
			tail = newnode;
			count++;
		}
		else {
			while (current->link != nullptr) {
				current = current->link;
			}
			current->link = newnode;
			tail = newnode;
			count++;
		}
	}
	bool is_empty() {
		if (head == nullptr) {
			return true;
		}
		else
			return false;
	}
	void delete_item(int item) {
		Node* current = head;
		Node* tailcurrent = head;
		bool found = false;
		if (head == nullptr) {
			cout << "there is no item in list";
		}
		else if (head->info == item) {
			head = head->link;
			delete current;
			count--;
		}
		else {
			while (!found && current != nullptr) {
				if (current->info == item) {
					found = true;
				}
				else {
					tailcurrent = current;
					current = current->link;
				}

			}
			if (found) {
				tailcurrent->link = current->link;
				if (current == tail) {
					tail = tailcurrent;
				}
				delete current;
			}
			else {
				cout << "your item is not in list";
			}

		}
	}
	int length() {
		return count;
	}
	int get_tail() {
		return tail->info;
	}
	int get_head() {
		return head->info;
	}
	void PrintList() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->info << " ";
			current = current->link;
		}
	}
};
class singleOrderLinkedList {
public:
	Node* head;
	int info;
	singleOrderLinkedList() {
		head = nullptr;
		info = 0;
	}
	bool is_empty() {
		if (head == nullptr) {
			return true;
		}
		else
			return false;
	}
	void insert(int item) {
		Node* newnode = new Node();
		newnode->info = item;
		Node* current = head;
		Node* tailcurrent = head;
		bool found = false;
		if (head == nullptr) {
			head = newnode;
		}
		else {
			while (current != nullptr && !found) {
				if (current->info >= item) {
					found = true;
				}
				else {
					tailcurrent = current;
					current = current->link;
				}
			}
			if (current == head) {
				head = newnode;
				head->link = current;
			}
			else {
				tailcurrent->link = newnode;
				newnode->link = current;
			}
		}
	}
	void PrintList() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->info << " ";
			current = current->link;
		}
	}
};
template<class t>
class stackAB {
public:
	int top;
	t arr[25];
	stackAB() {
		top = -1;
	}
	void push(t item) {
		if (top == 24) {
			cout << "stack is full";
			return;
		}
		arr[top + 1] = item;
		top++;
	}
	void pop() {
		if (top < 0) {
			cout << "the stack is empty";
		}
		else {
			arr[top] == 0;
			top--;
		}
	}
	t peek() {
		return arr[top];
	}
	bool is_full() {
		if (top == 24) {
			return true;
		}
		else
			return false;
	}
	bool is_empty() {
		if (top == -1) {
			return true;
		}
		else
			return false;
	}
};
class stackLLB {
public:
	singleUnorderLinkedList stack;
	void push(int item) {
		stack.insert(item);
	}
	int peek() {
		return stack.get_tail();
	}
	void pop() {
		stack.delete_item(stack.get_tail());
	}
	bool is_empty() {
		return stack.is_empty();
	}
};
class queueAB {
public:
	int count;
	int front;
	int last;
	int arr[5];
	queueAB() {
		count = 0;
		front = 0;
		last = 4;
	}
	bool is_full() {
		if (count == 5) {
			return true;
		}
		else
			return false;
	}
	bool is_empty() {
		if (count == 0) {
			return true;
		}
		else
			return false;
	}
	int get_front() {
		return arr[front];
	}
	int get_last() {
		return arr[last];
	}
	int length() {
		return count;
	}
	void enqueue(int item) {
		if (count == 5) {
			cout << "queue is full";
		}
		else {
			arr[(last + 1) % 5] = item;
			last = (last + 1) % 5;
			count++;
		}
	}
	void dequeue() {
		if (count != 0) {
			arr[front] = 0;
			front = (front + 1) % 5;
			count--;
		}
	}
};
class queueLLB {
public:
	singleUnorderLinkedList queue;
	void enqueue(int item) {
		queue.insert(item);
	}
	void dequeue() {
		queue.delete_item(queue.get_head());
	}
	int length() {
		return queue.length();
	}
	bool is_empty() {
		return queue.is_empty();
	}
	int get_front() {
		return queue.get_head();
	}
	int get_last() {
		return queue.get_tail();
	}
};
class heap {
public:
	int list[100];
	int size;
	type kind;
	heap(type kind) {
		this->kind = kind;
		size = 0;
	}
	void intial(int size) {
		int element;
		for (int i = 0;i < size;i++) {
			cin >> list[i];
			this->size++;
		}
	}
	void insert(int newElement) {
		if (kind == maxHeap) {
			list[size + 1] == newElement;
			build_max_heap();
			this->size++;
		}
		else {
			list[size + 1];
			build_min_heap();
		}
	}
	void max_heap(int index, int size) {
		if (size == 0) {
			cout << "the tree is empty";
		}
		else {
			int highest = index;
			int left = (2 * index) + 1;
			int right = (2 * index) + 2;
			if (left < size && list[highest] < list[left]) {
				highest = left;
			}
			if (right < size && list[highest] < list[right]) {
				highest = right;
			}
			if (highest != index) {
				swap(list[highest], list[index]);
				max_heap(highest, size);
			}
		}
	}
	void build_max_heap() {
		for (int i = size / 2;i >= 0;i--) {
			max_heap(i, size);
		}
	}
	void print_heap() {
		for (int i = 0;i < size;i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
	void min_heap(int index, int size) {
		int least = index;
		int left = (2 * index) + 1;
		int right = (2 * index) + 2;
		if (left < size && list[left] < list[least]) {
			least = left;
		}
		if (right < size && list[right] < list[least]) {
			least = right;
		}
		if (least != index) {
			swap(list[least], list[index]);
			min_heap(least, size);
		}
	}
	void build_min_heap() {
		for (int i = size / 2;i >= 0;i--) {
			min_heap(i, size);
		}
	}
	void asc_heap_sort() {
		build_max_heap();
		for (int i = 1;i < size;i++) {
			swap(list[0], list[size - i]);
			max_heap(0, size - i);
		}
	}
	void dec_heap_sort() {
		build_min_heap();
		for (int i = 1;i < size;i++) {
			swap(list[0], list[size - i]);
			min_heap(0, size - i);
		}
	}
};
int main() {
	vector<int>arr;
	heap tree = heap(maxHeap);
	tree.intial(5);
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << " ";
	}
}