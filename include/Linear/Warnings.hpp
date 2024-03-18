#pragma once

// Contains both warning and error messages
// Warnings
/// @attention 
/// @todo Create more advanced exception system
#define W_ARRAY_FILL_FLOAT "Warning: Filling the array with a decimal point value whose elements are "\
                           "of a different data type might lead to unexpected state of the array.\n"

#define W_WRONG_TYPE_FILL "Warning: Array of a data type with non-numeric elements was filled with an integer value. "\
                          "This may lead to the unexpected representation of the array during the runtime."
// Errors
#define E_RANGE_BOUNDS "Error: Index is out of bounds of the array."

#define E_MATRIX_SUM "Error: Summation of two arrays is not possible due to differences in shape."

#define E_STRING_ARRAY_NOT_SUPPORTED "Error: Array of type 'std::string' cannot be declared. Use 'const char*' type instead."

#define E_ARRAY_ASSIGNMENT_DTYPE "Error: To assign the value of one array to another, "\
                                 "their data types should match."

#define E_MATRIX_MUL_DTYPE "Error: Matrix multiplication is performed only on numeric data types."

#define E_MATRIX_MUL_SHAPE "Error: Number of columns of the first matrix should be equal to"\
                          "the number of rows of the second matrix."

#define E_WRONG_AXIS_SUM "Error: Incorrect axis provided for matrix addition."
#define E_WRONG_AXIS_PROD "Error: Incorrect axis provided for matrix product."

#define E_NOT_ITEMABLE "Error: Array with more than one element cannot be turned into an item."