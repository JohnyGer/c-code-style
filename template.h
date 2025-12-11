/**
 * \file            template.h
 * \brief           Template header file
 */

/*
 * Copyright (c) 2025 Liamaev Mikhail
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of your_library_name.
 *
 * Author:          Liamaev Mikhail <tilen@majerle.eu>
 * Version:         $_version_$
 */
#ifndef TEMPLATE_HDR_H
#define TEMPLATE_HDR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief           Error codes enumeration
 * \note            Used for all function error reporting
 */
typedef enum {
    ERROR_NONE = 0,           /*!< No error */
    ERROR_NULL_POINTER,       /*!< Null pointer passed */
    ERROR_DIVISION_BY_ZERO,   /*!< Division by zero attempted */
    ERROR_INVALID_PARAMETER   /*!< Invalid parameter value */
} error_code_t;

/**
 * \brief           Sum two integers
 * \param[in]       a: First integer value
 * \param[in]       b: Second integer value
 * \param[out]      result: Pointer to store the sum result
 * \return          \ref ERROR_NONE on success, error code otherwise
 * \note            Both input parameters must be valid integers
 */
error_code_t
sum(int32_t a, int32_t b, int32_t* result);

/**
 * \brief           Divide two integers with error checking
 * \param[in]       a: Dividend value
 * \param[in]       b: Divisor value
 * \param[out]      result: Pointer to store the division result
 * \return          \ref ERROR_NONE on success, \ref ERROR_DIVISION_BY_ZERO 
 *                  if divisor is zero, other error codes for invalid parameters
 * \note            Divisor must not be zero to avoid undefined behavior
 * \warning         This function prevents division by zero which causes 
 *                  undefined behavior in C
 */
error_code_t
divide(int32_t a, int32_t b, int32_t* result);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TEMPLATE_HDR_H */
