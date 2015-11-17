#pragma once
#include <iostream>
using namespace std;

class Array {
	int * data = new int[0];
	int size = 0;
public:
	Array(int size) {
		delete[] data;
		this->size = size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = 0;
		}
	}
	Array(const Array & Copy) {
		delete[] data;
		size = Copy.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = Copy.data[i];
		}
	}
	~Array() {
		delete[] data;
	}
	void Set(int number, int index) {
		if (index > -1) if (index < size) {
			data[index] = number;
		}
	}
	void SetRand(int min, int max) {
		for (int i = 0; i < size; i++) {
			int r = abs(max - min) + 1;
			data[i] = rand() % r + min;
		}
	}
	int Get(int index) {
		if (index > -1) if (index < size) {
			return data[index];
		}
		return 0;
	}
	int GetSize() {
		return size;
	}
	void Resize(int size) {
		Array temp = *this;
		delete[] data;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = temp.Get(i);
		}
	}
	friend Array operator * (Array & left, Array & right) {
		int min;
		if (left.size < right.size) {
			min = left.size;
		}
		else {
			min = right.size;
		}
		Array temp(min);
		for (int i = 0; i < min; i++) {
			temp.data[i] = left[i] * right[i];
		}
		return temp;
	}
	Array & operator = (Array & right) {
		delete[] data;
		size = right.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = right[i];
		}
		return *this;
	}
	int operator [] (int index) {
		return Get(index);
	}
	operator int() {
		return size;
	}
	friend bool operator == (Array & left, Array & right) {
		if (left.size != right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left[i] != right[i]) {
					return false;
				}
			}
			return true;
		}
	}
	friend bool operator <= (Array & left, Array & right) {
		if (left.size < right.size) {
			return true;
		}
		else if (left.size > right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left[i] < right[i]) {
					return true;
				}
				else if (left[i] > right[i]) {
					return false;
				}
			}
			return true;
		}
	}
	void print() {
		cout << *this;
	}
	friend ostream & operator << (ostream & output, Array & arr) {
		output << "(";
		for (int i = 0; i < arr.size; i++) {
			if (i > 0) {
				output << ",";
			}
			output << " " << arr.data[i];
		}
		output << " )";
		return output;
	}
};