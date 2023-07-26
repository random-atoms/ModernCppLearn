#pragma once

#include <iostream>
#include <stdexcept>

namespace NVector {

    template <typename T> class Vector {
    public:
        Vector() : m_size{ 0 }, m_data{ nullptr } { std::cout << "Vector: defc" << std::endl; }
        explicit Vector(int s) {
            std::cout << "Vector: size defc" << std::endl;
            if (s <= 0) {
                throw std::length_error("Size should be greater than 0");
            }
            m_size = s;
            m_data = new T[m_size];
        }
        ~Vector() {
            std::cout << "Vector: dest" << std::endl;
            delete[] m_data;
            m_size = 0;
        }
        Vector(const Vector& vin) : m_size{ vin.m_size }, m_data{ new T[vin.m_size] } {
            std::cout << "Vector: copy cons" << std::endl;

            for (auto ii = 0; ii < m_size; ++ii) m_data[ii] = vin.m_data[ii];
        }

        Vector(Vector&& vin) noexcept : m_size{ vin.m_size }, m_data{ vin.m_data } {
            std::cout << "Vector: move cons" << std::endl;
            vin.m_data = nullptr;
            vin.m_size = 0;
        }


        Vector& operator=(const Vector& vin) {
            std::cout << "Vector: = copy fxn" << std::endl;

            T* temp = new T[vin.m_size];

            for (auto ii = 0; ii < vin.m_size; ++ii) {
                temp[ii] = vin.m_data[ii];
            }

            delete[] m_data;
            m_data = temp;
            m_size = vin.m_size;

            return *this;
        }

        Vector& operator=(Vector&& vin) noexcept {
            if (this != &vin) {
                std::cout << "Vector: = move fxn" << std::endl;
                delete[] m_data;
                m_size = vin.m_size;
                m_data = vin.m_data;
                vin.m_data = nullptr;
                vin.m_size = 0;
                return *this;
            }
            return *this;
        }

        T& operator[](int ii) {
            if (ii >= m_size) {
                throw std::range_error("Out of range");
            }
            return m_data[ii];
        }

        const T& operator[](int ii) const {
            if (ii >= m_size) {
                throw std::range_error("Out of range");
            }
            return m_data[ii];
        }
        int size() const { return m_size; }
    private:
        T* m_data;
        int m_size;
    };

    template <typename T>
    Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
        std::cout << "add operator" << std::endl;
        if (a.size() != b.size()) {
            throw std::length_error("Vectors not same size");
        }
        Vector<T> res(a.size());
        for (auto ii = 0; ii < res.size(); ++ii) {
            res[ii] = a[ii] + b[ii];
        }
        return res;
    }

    template <typename T>
    T* begin(Vector<T>& in) {
        return &in[0];
    }

    template <typename T>
    T* end(Vector<T>& in) {
        return &in[0] + in.size();
    }

}