#include "../Base/Matrix.hpp"

namespace ln {
    /// @section Constructors
    /// @brief This constructor takes a list of initializer lists of the 'DTYPE' type and assings the list data to a new Matrix object
    /// @param init initializer list like '{{A, B, C}}'. Implicit conversion is possible like {{'a', 2, 5.5}} -> {{97.0, 2.0, 5.5}}
    /// @details Currently constructor to take an 'const std::initializer_list<DTYPE>&' argument is not implemented
    template <typename DTYPE>
    Matrix<DTYPE>::Matrix(const std::initializer_list<std::initializer_list<DTYPE>>& init): size0(init.size()), size1(init.begin()->size()) {
        this->data = new DTYPE*[size0];

        int i = 0;
        for (const auto& row: init) {
            this->data[i] = new DTYPE[size1];
            int j = 0;
            for (const auto& element: row) {
                this->data[i][j] = element;
                j++;
            } 
            if (j != size1) throw std::range_error("Error: Number of elements in rows of provided initializer list is not consistent.");
            i++;
        }        
    } 



    /// @brief This constructor allocates memory for a Matrix based on dimensions specified 
    /// @param size0 Size of the 0-th dimension (size in rows).
    /// @param size1 Size of the first dimension (size in columns).
    template <typename DTYPE>
    Matrix<DTYPE>::Matrix(size_t size0, size_t size1): size0(size0), size1(size1) {
        this->data = new DTYPE*[size0];
        for (int i = 0; i < size0; ++i) {
            this->data[i] = new DTYPE[size1];
        }
    }



    /// @brief Allocates the new matrix dynamically based on provided reference
    /// @param sample Matrix to take as a reference for deep copy allocation
    template<typename DTYPE>
    Matrix<DTYPE>::Matrix(const Matrix& sample): size0(sample.size0), size1(sample.size1) {
        this->data = new DTYPE*[sample.size0];
        for (int i = 0; i < sample.size0; ++i) {
            this->data[i] = new DTYPE[sample.size1];
            std::memcpy(this->data[i], sample.data[i], sample.size1 * sizeof(DTYPE));
        }
    }



    /// @brief Constructor to make a Matrix based on a standard two-dimensional arra.
    /// @param array Two-dimensional array
    template <typename DTYPE>
    template<size_t rows, size_t cols> 
    Matrix<DTYPE>::Matrix(const DTYPE(&array)[rows][cols]): size0(rows), size1(cols) {
        this->data = new DTYPE*[size0];
        for (int i = 0; i < size0; ++i) {
            this->data[i] = new DTYPE[size1];
            std::memcpy(this->data[i], array[i], size1 * sizeof(DTYPE));
        }
    }
}