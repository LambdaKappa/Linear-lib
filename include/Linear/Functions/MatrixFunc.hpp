#pragma once

#include "../Base/Matrix.hpp"

namespace ln {

    /// @brief Creates a Matrix/Array filled with zeroes
    /// @param size0 Size of the 0-th dimension (size in rows)
    /// @param size1 Size of the first dimension (size in columns)
    /// @return Returns the new Matrix object filled with zeroes
    template <typename type>
    Matrix<type> zeroes(size_t size0, size_t size1) {
        Matrix<type> newMatrix = Matrix<type>(size0, size1);
        for (size_t i = 0; i < size0; ++i) {
            std::memset(newMatrix.data[i], 0, size1 * sizeof(type));
        }
        return newMatrix;
    }


    /// @brief Creates a matrix/array filled with ones
    /// @param size0 Size of the 0-th dimension (size in rows)
    /// @param size1 Size of the first dimension (size in columns)
    /// @return New Matrix object filled with ones
    template <typename type>
    Matrix<type> ones(size_t size0, size_t size1) {
        Matrix<type> newMatrix = Matrix<type>(size0, size1);

        for (size_t i = 0; i < size0; ++i) {
            for (size_t j = 0; j < size1; ++j) 
                newMatrix.data[i][j] = 1;
        }
        return newMatrix;
    }


    /// @brief Creates a matrix/array filled with a specified value
    /// @param size0 Size of the 0-th dimension (size in rows)
    /// @param size1 Size of the first dimension (size in columns)
    /// @param valueToFillWith Value all the elements should inherit
    /// @return New Matrix object whose elements are filled with desired value
    template <typename type>
    Matrix<type> fill(size_t size0, size_t size1, const type& valueToFillWith) {
        Matrix<type> newMatrix = Matrix<type>(size0, size1);

        for (size_t i = 0; i < size0; ++i) {
            for (size_t j = 0; j < size1; ++j) 
                newMatrix.data[i][j] = valueToFillWith;
        }
        return newMatrix;
    }


    /// @brief 
    /// @param start 
    /// @param stop
    /// @param step For 'step' > 0, 'start' should be less than 'stop' and vice versa.
    /// @return 
    template <typename type, typename A, typename B, typename C>
    Matrix<type> range(A start, B stop, C step) {
        if constexpr (!isNumeric<A>() || !isNumeric<B>() || !isNumeric<C>()) throw std::logic_error("Arguments should have numeric type for readability.");
        if (step == 0) throw std::logic_error("Step cannot be zero. This would result into the array with an infinite amount of elements.");
        if ((start >= stop && step > 0) || (start < stop && step < 0)) throw std::logic_error("Size of the array returned by the function 'Matrix::range' cannot be zero. Change 'stop', 'start' or 'step' arguments.");

        size_t dim1Size = size_t((stop - start) / step) + 1;
        Matrix<type> newMatrix = Matrix<type>(1, dim1Size);

        for (int j = 0; j < dim1Size; ++j) {
            newMatrix.data[0][j] = start + step * j;
        }

        return newMatrix;
    }


    /// @brief 
    /// @tparam A 
    /// @tparam B 
    /// @tparam C 
    /// @param start 
    /// @param stop 
    /// @param size 
    /// @return 
    template <typename type, typename A, typename B, typename C>
    Matrix<type> linspace(A start, B stop, C size) {
        if constexpr (!isNumeric<type>()) std::cerr << "Warning: 'ln::linspace' function was used for array with non-numeric representation or for array with unknown data type.";

        if (size == 1) {
            Matrix<type> newMatrix = Matrix<type>(1, 1);
            newMatrix.data[0][0] = start;
            return newMatrix;
        }
        else if (size < 1) throw std::range_error("Invalid value chosen for the array size.");

        constexpr type epsilon = EPSILON<type>();

        double step = (double)(stop - start) / (size - 1 + epsilon);
        return range<type>(start, stop, step);
    }



    template <typename type>
    Matrix<type> sum(const Matrix<type>& matrix, int axis) {
        if (axis == 0) {
            Matrix<type> newMatrix = Matrix<type>(1, matrix.size1);

            for (int j = 0; j < matrix.size1; ++j) {
                type localSum = 0;
                for (int i = 0; i < matrix.size0; ++i) {
                    localSum += matrix.data[i][j];
                }
                newMatrix.data[0][j] = localSum;
            }
            return newMatrix;
        }
        
        else if (axis == 1) {
            Matrix<type> newMatrix = Matrix<type>(matrix.size0, 1);
            
            for (int i = 0; i < matrix.size0; ++i) {
                type localSum = 0;
                for (int j = 0; j < matrix.size1; ++j) {
                    localSum += matrix.data[i][j];
                }

                newMatrix.data[i][0] = localSum;
            }
            return newMatrix;
        }
        throw std::domain_error(E_WRONG_AXIS_SUM);
    }



    template <typename type>
    Matrix<type> product(const Matrix<type>& matrix, int axis) {
        if (axis == 0) {
            Matrix<type> newMatrix = Matrix<type>(1, matrix.size1);

            for (int j = 0; j < matrix.size1; ++j) {
                type localProduct = 1;
                for (int i = 0; i < matrix.size0; ++i) {
                    localProduct *= matrix.data[i][j];
                }
                newMatrix.data[0][j] = localProduct;
            }
            return newMatrix;
        }
        
        else if (axis == 1) {
            Matrix<type> newMatrix = Matrix<type>(matrix.size0, 1);
            
            for (int i = 0; i < matrix.size0; ++i) {
                type localProduct = 1;
                for (int j = 0; j < matrix.size1; ++j) {
                    localProduct *= matrix.data[i][j];
                }

                newMatrix.data[i][0] = localProduct;
            }
            return newMatrix;
        }
        throw std::domain_error(E_WRONG_AXIS_SUM);
    }
}