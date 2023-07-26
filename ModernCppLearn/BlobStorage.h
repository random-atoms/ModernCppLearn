#pragma once

#include "Vector.h"

template <class T>
class Blob {
public:
	// Default empty blob constructor
	Blob() : m_data(nullptr) {}

	// Single dimension: setup array blob
	Blob(int dim) : m_dims(1) {
		m_dims[0] = dim;
		AllocateBuffer(dim1);
	}
	// Double dimension: setup image blob
	Blob(int dim1, int dim2) : m_dims(2) {
		m_dims[0] = dim1;
		m_dims[1] = dim2;
		AllocateBuffer(dim1 * dim2);
	}

	// Single dimension: setup volume blob
	Blob(int dim1, int dim2, int dim3) : m_dims(3) {
		m_dims[0] = dim1;
		m_dims[1] = dim2;
		m_dims[2] = dim3;
		AllocateBuffer(dim1 * dim2 * dim3);
	}
	// Destructor - delete flat memory allocated
	~Blob() { 
		delete[] m_data;
	}
private:
	void AllocateBuffer(int size) {
		m_data = new T[size];
	}
	Vector<int> m_dims;
	T* m_data;
};
