/*!
 * \file
 * \brief Vector copy functions for internal use
 * \author Adam Piatyszek
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 1995-2008  (see AUTHORS file for a list of contributors)
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

#include <itpp/base/copy_vector.h>

namespace itpp
{

void copy_vector(int n, const double *x, double *y)
{
  memcpy(y, x, static_cast<unsigned int>(n) * sizeof(double));
}
void copy_vector(int n, const std::complex<double> *x, std::complex<double> *y)
{
  memcpy(y, x, static_cast<unsigned int>(n) * sizeof(std::complex<double>));
}


void copy_vector(int n, const double *x, int incx, double *y, int incy)
{
  for (int i = 0; i < n; i++)
    y[i*incy] = x[i*incx];
}
void copy_vector(int n, const std::complex<double> *x, int incx,
                 std::complex<double> *y, int incy)
{
  for (int i = 0; i < n; i++)
    y[i*incy] = x[i*incx];
}


void swap_vector(int n, double *x, double *y)
{
  for (int i = 0; i < n; i++)
    std::swap(x[i], y[i]);
}
void swap_vector(int n, std::complex<double> *x, std::complex<double> *y)
{
  for (int i = 0; i < n; i++)
    std::swap(x[i], y[i]);
}


void swap_vector(int n, double *x, int incx, double *y, int incy)
{
  for (int i = 0; i < n; i++)
    std::swap(x[i*incx], y[i*incy]);
}
void swap_vector(int n, std::complex<double> *x, int incx,
                 std::complex<double> *y, int incy)
{
  for (int i = 0; i < n; i++)
    std::swap(x[i*incx], y[i*incy]);
}


void scal_vector(int n, double alpha, double *x)
{
  if (alpha != 1.0) {
    for (int i = 0; i < n; ++i) {
      x[i] *= alpha;
    }
  }
}
void scal_vector(int n, std::complex<double> alpha, std::complex<double> *x)
{
  if (alpha != std::complex<double>(1.0)) {
    for (int i = 0; i < n; ++i) {
      x[i] *= alpha;
    }
  }
}


void scal_vector(int n, double alpha, double *x, int incx)
{
  if (alpha != 1.0) {
    for (int i = 0; i < n; ++i) {
      x[i*incx] *= alpha;
    }
  }
}
void scal_vector(int n, std::complex<double> alpha, std::complex<double> *x,
                 int incx)
{
  if (alpha != std::complex<double>(1.0)) {
    for (int i = 0; i < n; ++i) {
      x[i*incx] *= alpha;
    }
  }
}


void axpy_vector(int n, double alpha, const double *x, double *y)
{
  if (alpha != 1.0) {
    for (int i = 0; i < n; ++i) {
      y[i] += alpha * x[i];
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      y[i] += x[i];
    }
  }
}
void axpy_vector(int n, std::complex<double> alpha,
                 const std::complex<double> *x, std::complex<double> *y)
{
  if (alpha != std::complex<double>(1.0)) {
    for (int i = 0; i < n; ++i) {
      y[i] += alpha * x[i];
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      y[i] += x[i];
    }
  }
}


void axpy_vector(int n, double alpha, const double *x, int incx, double *y,
                 int incy)
{
  if (alpha != 1.0) {
    for (int i = 0; i < n; ++i) {
      y[i*incy] += alpha * x[i*incx];
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      y[i*incy] += x[i*incx];
    }
  }
}
void axpy_vector(int n, std::complex<double> alpha,
                 const std::complex<double> *x, int incx,
                 std::complex<double> *y, int incy)
{
  if (alpha != std::complex<double>(1.0)) {
    for (int i = 0; i < n; ++i) {
      y[i*incy] += alpha * x[i*incx];
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      y[i*incy] += x[i*incx];
    }
  }
}

} // namespace itpp
