#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

class Object {
public:
	double data1;
	double data2;
	Object* next;
	Object* prev;

	Object() {
		next = nullptr;
		prev = nullptr;
	}
};

template <class T>
class List {
//private:
public:
	Object* head;
	Object* tail;
	int size;

//public:
	List() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	};

	void addToEnd(T);				//a)
	void addToStart(T);				//b)
	void print(int);				//e)
	void edit(int, T);				//f)
	void search(T);					//g) to fix
	void deleteLast();				//c)
	void deleteFirst();				//d)
	bool searchAndDelete(T);		//h)
	~List();						//j)
	void add(int, T);				//i)
	void info();					//k)
	
};

template <class T>
void List<T>::addToEnd(T objectData) {
	Object* newObject = new Object();
	Object* objectPrt;

	newObject->data1 = objectData.data1;
	newObject->data2 = objectData.data2;
	size++;

	if (!head) {
		head = newObject;
		tail = newObject;
	}
	else
	{
		objectPrt = tail;
		newObject->prev = objectPrt;
		objectPrt->next = newObject;
		tail = newObject;
	};
}

template <class T>
void List<T>::addToStart(T objectData) {
	Object* newObject = new Object();
	Object* objectPtr;
;
	newObject->data1 = objectData.data1;
	newObject->data2 = objectData.data2;
	size++;

	if (!head) {
		head = newObject;
		tail = newObject;
	}
	else
	{
		objectPtr = head;
		newObject->next = objectPtr;
		objectPtr->prev = newObject;
		head = newObject;
	}
}

template <class T>
void List<T>::print(int index) {
	Object* objectPtr = head;
	int i = 0;

	while (i <= index) {
		if (objectPtr == nullptr) {
			cout << "Out of range!" << endl;
			break;
		}
		else if (i != index) {
			objectPtr = objectPtr->next;
		}
		else {
			cout << objectPtr->data1 << " " << objectPtr->data2 << endl;
		}
		i++;
	};
}

template <class T>
void List<T>::edit(int index, T newData) {
	Object* objectPtr = head;

	int i = 0;

	while (i <= index) {
		if (objectPtr == nullptr) {
			cout << "Out of range!" << endl;
			break;
		}
		else if (i != index) {
			objectPtr = objectPtr->next;
		}
		else {
			objectPtr->data1 = newData.data1;
			objectPtr->data2 = newData.data2;
		}
		i++;
	};
}

template <class T>
void List<T>::search(T data) {
	Object* objectPtr = head;
	bool finished = false;

	while (finished != true) {
		if (objectPtr == nullptr) {
			cout << "NULL" << endl;
			finished = true;
			//return NULL;			//////////////////////////////////////////////////////////////
		}
		else if (objectPtr->data1 == data.data1 || objectPtr->data2 == data.data2) {
			cout << objectPtr->data1 << " " << objectPtr->data2;
			finished = true;
			//return *objectPtr;
		}
		else
		{
			objectPtr = objectPtr->next;
		}
	}
}

template <class T>
void List<T>::deleteLast() {
	Object* objectToDelete = tail;
	Object* objectPtr;
	
	if (objectToDelete == nullptr) {
		cout << "Empty list!" << endl;
	}
	else if (objectToDelete->next == nullptr && objectToDelete->prev == nullptr) {
		head = nullptr;
		tail = nullptr;
		delete objectToDelete;
		size--;
	}
	else {
		objectPtr = objectToDelete->prev;
		objectPtr->next = nullptr;
		tail = objectPtr;
		delete objectToDelete;
		size--;
	}
}

template <class T>
void List<T>::deleteFirst() {
	Object* objectToDelete = head;
	Object* objectPtr;

	if (objectToDelete == nullptr) {
		cout << "Empty list!" << endl;
	}
	else if (objectToDelete->next == nullptr && objectToDelete->prev == nullptr) {
		head = nullptr;
		tail = nullptr;
		delete objectToDelete;
		size--;
	}
	else {
		objectPtr = objectToDelete->next;
		objectPtr->prev = nullptr;
		head = objectPtr;
		delete objectToDelete;
		size--;
	}
}

template <class T>
bool List<T>::searchAndDelete(T data) {
	Object* objectToDelete = head;
	Object* objectPtr;
	bool finished = false;

	while (finished != true) {
		if (objectToDelete == nullptr) {
			cout << "ERROR" << endl;
			finished = true;
			return false;	
		}
		else if (objectToDelete->data1 == data.data1 || objectToDelete->data2 == data.data2) {
			if (objectToDelete->prev == nullptr && objectToDelete->next == nullptr) {
				head = nullptr;
				tail = nullptr;
				delete objectToDelete;
				size--;
			}
			else if (objectToDelete->prev == nullptr) {
				objectPtr = objectToDelete->next;
				objectPtr->prev = nullptr;
				head = objectPtr;
				delete objectToDelete;
				size--;
			}
			else if (objectToDelete->next == nullptr) {
				objectPtr = objectToDelete->prev;
				objectPtr->next = nullptr;
				tail = objectPtr;
				delete objectToDelete;
				size--;
			}
			else
			{
				objectPtr = objectToDelete->prev;
				objectPtr->next = objectToDelete->next;
				objectPtr->next->prev = objectToDelete->prev;
				delete objectToDelete;
				size--;
			}
			finished = true;
			return true;
		}
		else
		{
			objectToDelete = objectToDelete->next;
		}
	}
}

template <class T>
List<T>::~List() {
	Object* objectToDelete = head;
	Object* objectPtr;

	if (objectToDelete == nullptr) {
		cout << "Empty list!" << endl;
	}
	else
	{
		while (objectToDelete != nullptr)
		{
			objectPtr = objectToDelete->next;
			delete objectToDelete;
			objectToDelete = objectPtr;
			size--;
		}
		head = nullptr;
		tail = nullptr;
	}
}

template <class T>
void List<T>::add(int index, T objectData) {
	Object* newObject = new Object();
	Object* objectPtr;

	int i = 0;

	newObject->data1 = objectData.data1;
	newObject->data2 = objectData.data2;
	size++;

	if (!head) {
		head = newObject;
		tail = newObject;
		cout << "Empty list! Add on position " << i << endl;;
	}
	else {
		objectPtr = head;
		while (i <= index) {
			if (i == index) {
				if (objectPtr->prev == nullptr) {
					newObject->next = objectPtr;
					objectPtr->prev = newObject;
					head = newObject;
				}
				else
				{
					newObject->next = objectPtr;
					newObject->prev = objectPtr->prev;
					objectPtr->prev = newObject;
					newObject->prev->next = newObject;
				}
			}
			else if (objectPtr->next == nullptr) {
				objectPtr->next = newObject;
				newObject->prev = objectPtr;
				tail = newObject;
				cout << "Out of range! Add on position " << i + 1 << endl;
				break;
			}
			else {
				objectPtr = objectPtr->next;
			}
			i++;
		}
	}
}

template <class T>
void List<T>::info() {
	cout << "Number of records in list: " << size << endl;
	cout << "Position of list in memory: " << this << endl;
}
#endif // !LINKEDLIST_H