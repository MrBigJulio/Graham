#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class Array {
private:

	int arraySize;
	int startArraySize = 1;

	int resizeCoefficent = 2;

public:
	double** ar;
	int numberOfRecords = 0;
	Array();
	Array(const Array&);
	void resize();
	void add(double*);
	void print(int);
	void edit(int, double);
	void clear();
	void swap(double**, double**);
	void sort();
	void info();
	void print() {
		for (int i = 0; i < numberOfRecords; i++) {
			cout << i << " " << ar[i][0] << " " << ar[i][1] << " " << ar[i][2] << endl;
		}
		cout << endl;
	}

	void deleteEqual(int);
};

Array::Array() {
	arraySize = startArraySize;
	ar = new double*[arraySize];
	*ar = 0;
}

Array::Array(const Array& obj) {
	arraySize = obj.arraySize;
	numberOfRecords = obj.numberOfRecords;
	ar = new double*[arraySize];
	for (int i = 0; i < arraySize; i++) {
		ar[i] = obj.ar[i];
	}
}

void Array::resize() {
	Array* copyArray = new Array(*this);
	arraySize = copyArray->arraySize * resizeCoefficent;
	numberOfRecords = copyArray->numberOfRecords;
	delete[] ar;
	ar = new double*[arraySize];
	for (int i = 0; i < arraySize; i++) {
		if (i < copyArray->arraySize) {
			ar[i] = copyArray->ar[i];
		}
		else
		{
			ar[i] = 0;
		}
	}
	delete copyArray;
}

void Array::add(double* record) {
	if (numberOfRecords >= arraySize)
		resize();
	ar[numberOfRecords] = record;
	numberOfRecords++;
};

void Array::print(int index) {
	if (index >= arraySize) {
		cout << "Error! Out of range!" << endl;
	}
	else
		cout << ar[index] << endl;
}

void Array::edit(int index, double record) {
	if (index >= numberOfRecords)
		cout << "Error! Out of range!" << endl;
	else
		*ar[index] = record;
}

void Array::clear() {
	for (int i = 0; i < numberOfRecords; i++) {
		ar[i] = 0;
	}
	numberOfRecords = 0;
}

void Array::swap(double** a, double** b) {
	double* copy = *a;
	*a = *b;
	*b = copy;
	
}

void Array::sort() {
	for (int i = 0; i < numberOfRecords - 1; i++) {
		for (int j = 0; j < numberOfRecords - i - 1; j++) {
			if (ar[j][2] > ar[j + 1][2]) {
				swap(&ar[j], &ar[j + 1]);
			}
			else if (ar[j][2] == ar[j + 1][2]) {
				if (ar[j][1] < ar[j + 1][1]) {
					deleteEqual(j);
				}
				else {
					deleteEqual(j + 1);
				}
				j--;
			}
		}
	}
}

void Array::deleteEqual(int index) {
	for (int i = index; index < numberOfRecords - 1; i++) {
		swap(&ar[i], &ar[i + 1]);
	}
	numberOfRecords--;
}

void Array::info() {
	cout << "Number of records in array: " << numberOfRecords << endl;
	cout << "Actual size of array: " << arraySize << endl;
	cout << "Position of array in memory: " << this << endl;
}


#endif // !ARRAY_H

