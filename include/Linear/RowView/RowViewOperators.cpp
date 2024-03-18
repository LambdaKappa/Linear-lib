#include "RowView.hpp"

namespace ln {

    /// @brief Get a pointer to a particular element in a Matrix row/column using [] operator
    /// @tparam DTYPE - Matrix data type
    /// @param index Index of the element to access
    /// @return Mutable row/column element
    template <typename DTYPE>
    DTYPE& RowView<DTYPE>::operator[](size_t index) {
        if (index >= this->size0) throw std::range_error(E_RANGE_BOUNDS);

        return this->row[index];
    }   
    
    /// @brief [] Operator overloading to return an immutable element of a row/column
    /// @tparam DTYPE - Matrix data type
    /// @param index Index of the element to access
    /// @return Immutable row/column element
    template <typename DTYPE>
    const DTYPE& RowView<DTYPE>::operator[](size_t index) const {
        if (index >= this->size0) throw std::range_error(E_RANGE_BOUNDS);

        return this->row[index];
    }


    template <typename DTYPE>
    RowView<DTYPE>& RowView<DTYPE>::operator=(const DTYPE& element) {
        if (this->size0 == 1) this->row[0] = element;
        else throw std::length_error("Error: Not possible to assign an entire array/row/column to a single element.");
        return *this;
    }


    template <typename DTYPE>
    template <typename N>
    RowView<DTYPE>& RowView<DTYPE>::operator+=(const N& n) {
        for (int i = 0; i < this->size0; ++i)
            this->row[i] += n;
        return *this;
    }


    template <typename DTYPE>
    template <typename N>
    RowView<DTYPE>& RowView<DTYPE>::operator-=(const N& n) {
        for (int i = 0; i < this->size0; ++i)
            this->row[i] -= n;
        return *this;
    }


    template <typename N>
    std::ostream& operator<<(std::ostream& os, const RowView<N>& view) {
        if (view.size0 == 1) {
            os << view.row[0];
            return os;
        }

        os << ARRAY_OPEN;
        for (int i = 0; i < view.size0; ++i) {
            os << view.row[i] << ((i == view.size0 - 1) ? "" : ", ");
        }
        os << ARRAY_CLOSE;
        return os;
    }
}