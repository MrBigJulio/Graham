#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Array.h"
using namespace std;

List<Object>* grahamScan(double**a, int *size) {
	if (*size < 2) {
		return nullptr;
	}
	else {
		List<Object>* s = new List<Object>();
		Object* pi = new Object();
		
		for (int i = 0; i < 3; i++) {
			pi->data1 = a[i][0];
			pi->data2 = a[i][1];
			s->addToStart(*pi);
		}
		for (int i = 3; i < *size; i++) {
			pi->data1 = a[i][0];
			pi->data2 = a[i][1];
			while (((pi->data1 - s->head->next->data1) * (s->head->data2 - s->head->next->data2) - (s->head->data1 - s->head->next->data1) * (pi->data2 - s->head->next->data2)) < 0) {
				s->deleteFirst();
			}
			s->addToStart(*pi);
		}
		return s;
	}
}

void angle(double** a, int size) {
	double x0, y0, x1, y1, x2, y2;
	x0 = a[0][0];
	y0 = a[0][1];
	x1 = 1;
	y1 = 0;

	for (int i = 1; i < size; i++) {
		x2 = a[i][0];
		y2 = a[i][1];
		
		a[i][2] = ((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0));
	}
	
}

void find(double** a, int size) {
	int id = 0;
	for (int i = 1; i < size; i++) {
		if (a[id][1] > a[i][1]) {
			id = i;
		}
		else if (a[id][1] == a[i][1]) {
			if (a[id][0] > a[i][0]) {
				id = i;
			}
		}
	}

	if (id != 0) {
		swap(a[id], a[0]);
	}
}

void swap(double** a, double** b) {
	double* copy = *a;
	*a = *b;
	*b = copy;

}

void bucketSort(double** a, int *size) {
	int n = floor(sqrt(*size));
	double w = 1.0 / n;
	Array* buckets = new Array[n];
	for (int i = 1; i < *size; i++) {
		int bucketIndex = floor(a[i][2] / w);
		buckets[bucketIndex].add(a[i]);
	}
	for (int i = 0; i < n; i++) {
		buckets[i].sort();

	}
	Array* result = new Array;
	int count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < buckets[i].numberOfRecords; j++) {
			result->add(buckets[i].ar[j]);
			count++;
		}
	}
	//result->print();
	for (int i = 1; i < count; i++) {
		a[i] = result->ar[i - 1];
	}
	if (*size > count) {
		for (int i = count; i < *size; i++) {
			delete a[i];
		}
		*size = count;
	}
}

int main() {
	string text;
	double** points;
	
	fstream file;

	file.open("points5.txt"); // 1, 2, 3, 5.        4???

	getline(file, text);
	istringstream iss(text);
	int w;
	iss >> w;

	points = new double* [w];
	for (int i = 0; i < w; i++) {
		points[i] = new double[3];
	}
	for (int i = 0; i < w; i++) {
		getline(file, text);
		istringstream iss(text);
		double a, b;
		iss >> a >> b;
		points[i][0] = a;
		points[i][1] = b;
	}
	/*for (int i = 0; i < w; i++) {
		cout << points[i][0] << " " << points[i][1] << endl;
	}
	cout << endl;*/
	file.close();

	find(points, w);
	/*for (int i = 0; i < w; i++) {
		cout << points[i][0] << " " << points[i][1] << endl;
	}
	cout << endl;*/

	angle(points, w);
	/*cout << points[0][0] << " " << points[0][1] << endl;
	for (int i = 1; i < w; i++) {
		cout << points[i][0] << " " << points[i][1] << " " << points[i][2] << endl;
	}*/


	int* size = new int;
	*size = w;

	bucketSort(points, size);
	/*cout << 0 << " " << points[0][0] << " " << points[0][1] << endl;
	for (int i = 1; i < *size; i++) {
		cout << i << " " << points[i][0] << " " << points[i][1] << " " << points[i][2] << endl;
	}*/

	List<Object>* answer = new List<Object>();

	answer = grahamScan(points, size);


}