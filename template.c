/**
 * \file            template_compliant.c
 * \brief           Template source file compliant with Barr-C:2018 and MISRA C:2023
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
 * This file is part of my_library.
 *
 * Author:          Liamaev Mikhail <misha25_live@mail.ru>
 * Version:         v1.0.0
 */

/*--------------------------- Includes ----------------------------------------*/
#include <stdint.h>
#include "template_compliant.h"

/*--------------------------- Defines -----------------------------------------*/

/*--------------------------- Typedefs ----------------------------------------*/

/*--------------------------- Variables ---------------------------------------*/

/*--------------------------- Static Functions --------------------------------*/

/*--------------------------- Public Functions --------------------------------*/

/**
 * \brief           Calculate the sum of two signed 32-bit integers
 * \param[in]       a: First addend value
 * \param[in]       b: Second addend value
 * \return          Result of addition operation as signed 32-bit integer
 * \note            This function performs simple integer addition without
 *                  overflow detection. For production use, consider adding
 *                  overflow checking mechanisms.
 */
int32_t 
sum_two_numbers(int32_t a, int32_t b) {
    return (a + b);
}

/**
 * \brief           Calculate the difference of two signed 32-bit integers
 * \param[in]       a: Minuend value
 * \param[in]       b: Subtrahend value
 * \return          Result of subtraction operation as signed 32-bit integer
 */
int32_t 
subtract_two_numbers(int32_t a, int32_t b) {
    return (a - b);
}

/**
 * \brief           Calculate the maximum of two signed 32-bit integers
 * \param[in]       a: First value for comparison
 * \param[in]       b: Second value for comparison
 * \return          Maximum value between a and b as signed 32-bit integer
 */
int32_t 
find_maximum(int32_t a, int32_t b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

