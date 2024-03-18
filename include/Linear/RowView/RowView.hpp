/// @class 'RowView' class delcaration
/// @category Linear Algebra utilities
/// @details Part of the ln::Matrix class

#pragma once

#include "../Base/Matrix.hpp"

namespace ln {
    template<typename DTYPE>
    class RowView {
    public:
        RowView(DTYPE* data, size_t size0): row(data), size0(size0) {};

        DTYPE& operator[](size_t index);

        DTYPE item();

        const DTYPE& operator[](size_t index) const;

        RowView& operator=(const DTYPE& element);

        template <typename N>
        friend std::ostream& operator<<(std::ostream& os, const RowView<N>& view);

        template <typename N>
        RowView& operator+=(const N& n);

        template <typename N>
        RowView& operator-=(const N& n);

    private:
        DTYPE* row;
        size_t size0;
    };
}

#include "RowViewOperators.cpp"
#include "RowView.cpp"
