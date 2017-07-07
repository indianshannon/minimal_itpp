/*!
 * \file
 * \brief Include file for the IT++ base module
 * \author Tony Ottosson
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 1995-2010  (see AUTHORS file for a list of contributors)
 *
 * This file is part of IT++ - a C++ library of mathematical, signal
 * processing, speech processing, and communications classes and functions.
 *
 * IT++ is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * IT++ is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along
 * with IT++.  If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef ITBASE_H
#define ITBASE_H

/*!
 * \defgroup base Base Module
 * @{
 */

//! \defgroup arr_vec_mat Array, Vector and Matrix Classes
//! \defgroup parser Argument Parser

/*!
 * \defgroup math Basic and Miscellaneous Math Functions
 * @{
 */

//! \defgroup errorfunc Error Functions
//! \defgroup hypfunc Hyperbolic Functions
//! \defgroup logexpfunc Logarithmic and Exponential Functions
//! \defgroup miscfunc Miscellaneous Functions
//! \defgroup integration Numerical Integration
//! \defgroup trifunc Trigonometric Functions

/*!
 * @} end of math group
 */

//! \defgroup besselfunctions Bessel Functions
//! \defgroup convertfunc Conversion Functions
//! \defgroup diag Diagonal Matrices and Functions
//! \defgroup errorhandlingfunc Error and Warning Handling
//! \defgroup matrix_functions Functions on Matrices
//! \defgroup itfile IT++ File Format

/*!
 * \defgroup algebra Linear Algebra
 * @{
 */

//! \defgroup determinant Determinant
//! \defgroup inverse Inverse Matrix
//! \defgroup matrixdecomp Matrix Decompositions
//! \defgroup linearequations Solving Linear Equation Systems

/*!
 * @} end of algebra group
 */

//! \defgroup randgen Random Number Generation
//! \defgroup reshaping Reshaping of Vectors and Matrices
//! \defgroup specmat Special Matrices
//! \defgroup timers Timers

/*!
 * @} end of base group
 */


#include <itpp/base/math/elem_math.h>
#include <itpp/base/math/elem_math.cpp>
#include <itpp/base/math/error.h>
#include <itpp/base/math/error.cpp>
#include <itpp/base/math/log_exp.h>
#include <itpp/base/math/log_exp.cpp>
#include <itpp/base/math/min_max.h>
#include <itpp/base/math/misc.h>
#include <itpp/base/math/misc.cpp>

#include <itpp/base/converters.h>
#include <itpp/base/converters.cpp>

#include <itpp/base/copy_vector.h>
#include <itpp/base/copy_vector.cpp>

#include <itpp/base/factory.h>

#include <itpp/base/help_functions.h>
#include <itpp/base/help_functions.cpp>

#include <itpp/base/itassert.h>
#include <itpp/base/itassert.cpp>

#include <itpp/base/ittypes.h>

#include <itpp/base/mat.h>
#include <itpp/base/mat.cpp>

#include <itpp/base/matfunc.h>
#include <itpp/base/matfunc.cpp>

#include <itpp/base/operators.h>
#include <itpp/base/operators.cpp>

#include <itpp/base/random_dsfmt.h>
#include <itpp/base/random.h>
#include <itpp/base/random.cpp>

#include <itpp/base/sort.h>

#include <itpp/base/specmat.h>
#include <itpp/base/specmat.cpp>

#include <itpp/base/vec.h>
#include <itpp/base/vec.cpp>

#include <itpp/comm/crc.h>
#include <itpp/comm/crc.cpp>

#endif // #ifndef ITBASE_H
