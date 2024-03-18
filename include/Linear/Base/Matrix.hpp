#pragma once

/// @include Standard library features
#include <initializer_list>
#include <cstring>

/// @include Dependencies using only standard library headers
#include "../Types.hpp"
#include "../Warnings.hpp"
#include "../Constants.hpp"
#include "../Base/Vector.hpp"

/// @include Dependencies important for class functionality
#include "../RowView/RowView.hpp"

namespace ln {
    ///
    /// @class Matrix - Main container used thorough the library
    ///
    template<typename DTYPE>
    class Matrix {
    public:

        /// @section Constructors
        Matrix(): size0(0), size1(0), data(nullptr) {}
        Matrix(const std::initializer_list<std::initializer_list<DTYPE>>& init);
        Matrix(size_t size0, size_t size1);
        Matrix(const Matrix& sample);

        template<size_t rows, size_t cols> 
        Matrix(const DTYPE(&array)[rows][cols]);;



        /// @section Friend functions
        template <typename type>
        friend Matrix<type> zeroes(size_t size0, size_t size1);
        template <typename type>
        friend Matrix<type> ones(size_t size0, size_t size1);
        template <typename type>
        friend Matrix<type> fill(size_t size0, size_t size1, const type& valueToFillWith);
        template <typename type, typename A, typename B, typename C>
        friend Matrix<type> range(A start, B stop, C step);
        template <typename type, typename A, typename B, typename C>
        friend Matrix<type> linspace(A start, B stop, C size);
        template <typename type>
        friend Matrix<type> sum(const Matrix<type>& matrix, int axis);
        template <typename type>
        friend Matrix<type> product(const Matrix<type>& matrix, int axis);

        /// @section Class methods 
        DTYPE sum();
        DTYPE product();

        Matrix T();
        Matrix transpose() { return this->T(); }

        DTYPE item() const {
            if (this->size0 != 1 || this->size1 != 1) throw std::length_error(E_NOT_ITEMABLE);
            return this->data[0][0];
        }

        /// @section Operators overloading
        /// @subsection Arithmetic operators
        Matrix operator+(const Matrix& other);
        Matrix operator-(const Matrix& other);
        Matrix operator*(const Matrix& other);
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);
        Matrix& operator=(const Matrix& other);

        /// @subsection The rest of the operators
        /// @todo Move implementation of operators overloading below in a corresponding file.
        RowView<DTYPE> operator[](size_t index) {
            if (index >= this->size0 && this->size0 != 1) throw std::range_error(E_RANGE_BOUNDS);
            if (index >= this->size1 && this->size0 == 1) throw std::range_error(E_RANGE_BOUNDS);

            if (this->size0 == 1) {
                RowView<DTYPE> view = RowView<DTYPE>(&this->data[0][index], 1); // Mutable object
                return view;
            } 

            RowView<DTYPE> view = RowView<DTYPE>(this->data[index], this->size1); // Mutable object
            return view;
        }

        const RowView<DTYPE> operator[](size_t index) const {
            if (index >= this->size0 && this->size0 != 1) throw std::range_error(E_RANGE_BOUNDS);
            if (this->size0 == 1) {
                RowView<DTYPE> view = RowView<DTYPE>(&this->data[0][index], 1); // Immutable object
                return view;
            } 

            RowView<DTYPE> view = RowView<DTYPE>(this->data[index], this->size1); // Immutable object
            return view;
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix<DTYPE>& matrix) {
            if (matrix.data == nullptr) return os;

            if (matrix.size0 == 1) {
                os << RowView<DTYPE>(matrix.data[0], matrix.size1);
                return os; 
            }

            size_t size0 = matrix.size0;
            size_t size1 = matrix.size1;

            os << ARRAY_OPEN;
            for (size_t i = 0; i < size0; ++i) {
                if (i != 0) std::cout << ' ';
                os << ARRAY_OPEN;

                for (size_t j = 0; j < size1; ++j) {
                    std::cout << matrix.data[i][j];
                    if (j != size1 - 1) os << ", "; 
                }
                os << ARRAY_CLOSE;
                if (i != size0 - 1)
                    os << ",\n";
            }
            os << ARRAY_CLOSE << '\n';
            return os;
        }

        // Getters
        const size_t getSize0() const { return this->size0; };
        const size_t getSize1() const { return this->size1; };

        /// @brief Get shape of the Matrix as a vector2 object
        vector2<size_t> shape() const {
            return vector2<size_t>(size0, size1);
        }

        ~Matrix() {
            // std::cout << "\nArray of type '" << typeid(DTYPE).name() << "' with shape " << shape() << " was deallocated. ";
            // std::cout << '(' << size0 * size1 * sizeof(DTYPE) << " bytes)";
            this->deallocate();
        }
    private:
        // Number of rows of the Matrix
        size_t size0;

        // Number of columns of the Matrix
        size_t size1;

        // Contains all the Matrix data. Can be dynamically reallocated during the runtime.
        DTYPE** data;

        // Deallocates all the memory allocated by a Matrix
        inline void deallocate() noexcept {
            for (int i = 0; i < this->size0; ++i) {
                delete[] this->data[i];
            }
            delete[] this->data;
        }

        inline void reallocate(size_t newSize0, size_t newSize1) noexcept {
            this->deallocate();

            this->data = new DTYPE*[newSize0];
            for (int i = 0; i < newSize0; ++i) {
                this->data[i] = new DTYPE[newSize1];
            }
            this->size0 = newSize0;
            this->size1 = newSize1;
        }
        DTYPE** getData() const { return this->data; }
    };
}

/// @include .cpp files to be included for constructors and methods definition

/// @include Constructors definition
#include "../Matrix/Matrix.cpp"
/// @include Operators overloading
#include "../Matrix/MatrixOperators.cpp"
/// @include Definition of class methods
#include "../Matrix/MatrixMethods.cpp"

