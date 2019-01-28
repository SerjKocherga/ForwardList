#pragma once
template <class T>
class MyForwardList {

public:

	MyForwardList() {

		head = nullptr;
		listSize = 0;
	}

	~MyForwardList() { clear(); }

	void push_back(const T data) {

		if (head == nullptr) { head = new Node<T>(data); }
		else {

			Node<T> *current = this->head;
			while (current->pNext != nullptr) { current = current->pNext; }
			current->pNext = new Node<T>(data);
		}
		listSize++;
	}

	void push_front(const T data) { head = new Node<T>(data, head); listSize++; }

	void insert(const T data, size_t index) {

		if (index == 0) { push_front(data); }
		else if (index == listSize - 1) { push_back(data); }
		else {
			Node<T> *prevorious = this->head;
			for (size_t i = 0; i < index - 1; ++i)
				prevorious = prevorious->pNext;
			prevorious->pNext = new Node<T>(data, prevorious->pNext);
			listSize++;
		}
	}

	void pop_front() {

		Node<T> *temp = head;
		head = head->pNext;
		delete temp;
		listSize--;
	}

	void erase(size_t index) {

		if (index == 0) { pop_front(); }
		else {

			Node<T> *prevorious = this->head;
			for (size_t i = 0; i < index - 1; ++i)
				prevorious = prevorious->pNext;
			Node<T> *toDelete = prevorious->pNext;
			prevorious->pNext = toDelete->pNext;
			delete toDelete;
			listSize--;
		}
	}

	void pop_back() { erase(listSize - 1); }

	size_t GetSize() { return listSize; }

	void clear() { while (listSize) pop_front(); }

	T& operator[](const size_t index) {

		size_t Size(0);
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {

			if (Size == index) { return current->data; break; }
			current = current->pNext;
			Size++;
		}
	}

private:

	template <class T>
	class Node {

	public:

		Node(T data = T(), Node *pNext = nullptr) {

			this->data = data;
			this->pNext = pNext;
		}

		T data;
		Node *pNext;
	};

	Node<T> *head;
	size_t listSize;
};
