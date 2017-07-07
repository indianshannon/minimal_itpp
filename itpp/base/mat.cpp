/*!
 * \file
 * \brief Matrix Class Implementation
 * \author Tony Ottosson, Tobias Ringstrom, Adam Piatyszek and Conrad Sanderson
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

#include <itpp/base/mat.h>

#ifndef _MSC_VER
#  include <itpp/config.h>
#else
#  include <itpp/config_msvc.h>
#endif

//! \cond

namespace itpp
{

template<>
cmat cmat::hermitian_transpose() const
{
  cmat temp(no_cols, no_rows);
  for (int i = 0; i < no_rows; i++)
    for (int j = 0; j < no_cols; j++)
      temp(j, i) = std::conj(operator()(i,j));

  return temp;
}


// -------- Multiplication operator -------------
template<>
mat& mat::operator*=(const mat &m)
{
  it_assert_debug(no_cols == m.no_rows, "Mat<>::operator*=(): Wrong sizes");
  mat r(no_rows, m.no_cols);
  int r_pos = 0, pos = 0, m_pos = 0;

  for (int i = 0; i < r.no_cols; i++) {
    for (int j = 0; j < r.no_rows; j++) {
      double tmp = 0.0;
      pos = 0;
      for (int k = 0; k < no_cols; k++) {
        tmp += data[pos+j] * m.data[m_pos+k];
        pos += no_rows;
      }
      r.data[r_pos+j] = tmp;
    }
    r_pos += r.no_rows;
    m_pos += m.no_rows;
  }
  operator=(r); // time consuming
  return *this;
}

template<>
cmat& cmat::operator*=(const cmat &m)
{
  it_assert_debug(no_cols == m.no_rows, "Mat<>::operator*=(): Wrong sizes");
  cmat r(no_rows, m.no_cols);
  int r_pos = 0, pos = 0, m_pos = 0;

  for (int i = 0; i < r.no_cols; i++) {
    for (int j = 0; j < r.no_rows; j++) {
      std::complex<double> tmp(0.0);
      pos = 0;
      for (int k = 0; k < no_cols; k++) {
        tmp += data[pos+j] * m.data[m_pos+k];
        pos += no_rows;
      }
      r.data[r_pos+j] = tmp;
    }
    r_pos += r.no_rows;
    m_pos += m.no_rows;
  }
  operator=(r); // time consuming
  return *this;
}


template<>
mat operator*(const mat &m1, const mat &m2)
{
  it_assert_debug(m1.rows() == m2.cols(),
                  "Mat<>::operator*(): Wrong sizes");
  mat r(m1.rows(), m2.cols());
  double *tr = r._data();
  const double *t1;
  const double *t2 = m2._data();
  for (int i = 0; i < r.cols(); i++) {
    for (int j = 0; j < r.rows(); j++) {
      double tmp = 0.0;
      t1 = m1._data() + j;
      for (int k = m1.cols(); k > 0; k--) {
        tmp += *(t1) * *(t2++);
        t1 += m1.rows();
      }
      *(tr++) = tmp;
      t2 -= m2.rows();
    }
    t2 += m2.rows();
  }
  return r;
}

template<>
cmat operator*(const cmat &m1, const cmat &m2)
{
  it_assert_debug(m1.cols() == m2.rows(),
                  "Mat<>::operator*(): Wrong sizes");
  cmat r(m1.rows(), m2.cols());
  std::complex<double> *tr = r._data();
  const std::complex<double> *t1;
  const std::complex<double> *t2 = m2._data();
  for (int i = 0; i < r.cols(); i++) {
    for (int j = 0; j < r.rows(); j++) {
      std::complex<double> tmp(0.0);
      t1 = m1._data() + j;
      for (int k = m1.cols(); k > 0; k--) {
        tmp += *(t1) * *(t2++);
        t1 += m1.rows();
      }
      *(tr++) = tmp;
      t2 -= m2.rows();
    }
    t2 += m2.rows();
  }
  return r;
}


template<>
vec operator*(const mat &m, const vec &v)
{
  it_assert_debug(m.cols() == v.size(),
                  "Mat<>::operator*(): Wrong sizes");
  vec r(m.rows());
  for (int i = 0; i < m.rows(); i++) {
    r(i) = 0.0;
    int m_pos = 0;
    for (int k = 0; k < m.cols(); k++) {
      r(i) += m._data()[m_pos+i] * v(k);
      m_pos += m.rows();
    }
  }
  return r;
}

template<>
cvec operator*(const cmat &m, const cvec &v)
{
  it_assert_debug(m.cols() == v.size(),
                  "Mat<>::operator*(): Wrong sizes");
  cvec r(m.rows());
  for (int i = 0; i < m.rows(); i++) {
    r(i) = std::complex<double>(0.0);
    int m_pos = 0;
    for (int k = 0; k < m.cols(); k++) {
      r(i) += m._data()[m_pos+i] * v(k);
      m_pos += m.rows();
    }
  }
  return r;
}

//---------------------------------------------------------------------
// Instantiations
//---------------------------------------------------------------------

// class instantiations

template class ITPP_EXPORT Mat<double>;
template class ITPP_EXPORT Mat<std::complex<double> >;
template class ITPP_EXPORT Mat<int>;
template class ITPP_EXPORT Mat<short int>;

// addition operators

template ITPP_EXPORT  mat operator+(const mat &m1, const mat &m2);
template ITPP_EXPORT  cmat operator+(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  imat operator+(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat operator+(const smat &m1, const smat &m2);

template ITPP_EXPORT  mat operator+(const mat &m, double t);
template ITPP_EXPORT  cmat operator+(const cmat &m, std::complex<double> t);
template ITPP_EXPORT  imat operator+(const imat &m, int t);
template ITPP_EXPORT  smat operator+(const smat &m, short t);

template ITPP_EXPORT  mat operator+(double t, const mat &m);
template ITPP_EXPORT  cmat operator+(std::complex<double> t, const cmat &m);
template ITPP_EXPORT  imat operator+(int t, const imat &m);
template ITPP_EXPORT  smat operator+(short t, const smat &m);

// subraction operators

template ITPP_EXPORT  mat operator-(const mat &m1, const mat &m2);
template ITPP_EXPORT  cmat operator-(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  imat operator-(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat operator-(const smat &m1, const smat &m2);

template ITPP_EXPORT  mat operator-(const mat &m, double t);
template ITPP_EXPORT  cmat operator-(const cmat &m, std::complex<double> t);
template ITPP_EXPORT  imat operator-(const imat &m, int t);
template ITPP_EXPORT  smat operator-(const smat &m, short t);

template ITPP_EXPORT  mat operator-(double t, const mat &m);
template ITPP_EXPORT  cmat operator-(std::complex<double> t, const cmat &m);
template ITPP_EXPORT  imat operator-(int t, const imat &m);
template ITPP_EXPORT  smat operator-(short t, const smat &m);

// unary minus

template ITPP_EXPORT  mat operator-(const mat &m);
template ITPP_EXPORT  cmat operator-(const cmat &m);
template ITPP_EXPORT  imat operator-(const imat &m);
template ITPP_EXPORT  smat operator-(const smat &m);

// multiplication operators

template ITPP_EXPORT  imat operator*(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat operator*(const smat &m1, const smat &m2);

template ITPP_EXPORT  ivec operator*(const imat &m, const ivec &v);
template ITPP_EXPORT  svec operator*(const smat &m, const svec &v);

template ITPP_EXPORT  mat operator*(const mat &m, double t);
template ITPP_EXPORT  cmat operator*(const cmat &m, std::complex<double> t);
template ITPP_EXPORT  imat operator*(const imat &m, int t);
template ITPP_EXPORT  smat operator*(const smat &m, short t);

template ITPP_EXPORT  mat operator*(double t, const mat &m);
template ITPP_EXPORT  cmat operator*(std::complex<double> t, const cmat &m);
template ITPP_EXPORT  imat operator*(int t, const imat &m);
template ITPP_EXPORT  smat operator*(short t, const smat &m);

// elementwise multiplication

template ITPP_EXPORT  mat elem_mult(const mat &m1, const mat &m2);
template ITPP_EXPORT  cmat elem_mult(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  imat elem_mult(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat elem_mult(const smat &m1, const smat &m2);

template ITPP_EXPORT  void elem_mult_out(const mat &m1, const mat &m2, mat &out);
template ITPP_EXPORT  void elem_mult_out(const cmat &m1, const cmat &m2, cmat &out);
template ITPP_EXPORT  void elem_mult_out(const imat &m1, const imat &m2, imat &out);
template ITPP_EXPORT  void elem_mult_out(const smat &m1, const smat &m2, smat &out);

template ITPP_EXPORT  void elem_mult_out(const mat &m1, const mat &m2,
                            const mat &m3, mat &out);
template ITPP_EXPORT  void elem_mult_out(const cmat &m1, const cmat &m2,
                            const cmat &m3, cmat &out);
template ITPP_EXPORT  void elem_mult_out(const imat &m1, const imat &m2,
                            const imat &m3, imat &out);
template ITPP_EXPORT  void elem_mult_out(const smat &m1, const smat &m2,
                            const smat &m3, smat &out);

template ITPP_EXPORT  void elem_mult_out(const mat &m1, const mat &m2, const mat &m3,
                            const mat &m4, mat &out);
template ITPP_EXPORT  void elem_mult_out(const cmat &m1, const cmat &m2,
                            const cmat &m3, const cmat &m4, cmat &out);
template ITPP_EXPORT  void elem_mult_out(const imat &m1, const imat &m2,
                            const imat &m3, const imat &m4, imat &out);
template ITPP_EXPORT  void elem_mult_out(const smat &m1, const smat &m2,
                            const smat &m3, const smat &m4, smat &out);

template ITPP_EXPORT  void elem_mult_inplace(const mat &m1, mat &m2);
template ITPP_EXPORT  void elem_mult_inplace(const cmat &m1, cmat &m2);
template ITPP_EXPORT  void elem_mult_inplace(const imat &m1, imat &m2);
template ITPP_EXPORT  void elem_mult_inplace(const smat &m1, smat &m2);

template ITPP_EXPORT  double elem_mult_sum(const mat &m1, const mat &m2);
template ITPP_EXPORT  std::complex<double> elem_mult_sum(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  int elem_mult_sum(const imat &m1, const imat &m2);
template ITPP_EXPORT  short elem_mult_sum(const smat &m1, const smat &m2);

// division operator

template ITPP_EXPORT  mat operator/(double t, const mat &m);
template ITPP_EXPORT  cmat operator/(std::complex<double> t, const cmat &m);
template ITPP_EXPORT  imat operator/(int t, const imat &m);
template ITPP_EXPORT  smat operator/(short t, const smat &m);

template ITPP_EXPORT  mat operator/(const mat &m, double t);
template ITPP_EXPORT  cmat operator/(const cmat &m, std::complex<double> t);
template ITPP_EXPORT  imat operator/(const imat &m, int t);
template ITPP_EXPORT  smat operator/(const smat &m, short t);

// elementwise division

template ITPP_EXPORT  mat elem_div(const mat &m1, const mat &m2);
template ITPP_EXPORT  cmat elem_div(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  imat elem_div(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat elem_div(const smat &m1, const smat &m2);

template ITPP_EXPORT  void elem_div_out(const mat &m1, const mat &m2, mat &out);
template ITPP_EXPORT  void elem_div_out(const cmat &m1, const cmat &m2, cmat &out);
template ITPP_EXPORT  void elem_div_out(const imat &m1, const imat &m2, imat &out);
template ITPP_EXPORT  void elem_div_out(const smat &m1, const smat &m2, smat &out);

template ITPP_EXPORT  double elem_div_sum(const mat &m1, const mat &m2);
template ITPP_EXPORT  std::complex<double> elem_div_sum(const cmat &m1,
    const cmat &m2);
template ITPP_EXPORT  int elem_div_sum(const imat &m1, const imat &m2);
template ITPP_EXPORT  short elem_div_sum(const smat &m1, const smat &m2);

// concatenation

template ITPP_EXPORT  mat concat_horizontal(const mat &m1, const mat &m2);
template ITPP_EXPORT  cmat concat_horizontal(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  imat concat_horizontal(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat concat_horizontal(const smat &m1, const smat &m2);

template ITPP_EXPORT  mat concat_vertical(const mat &m1, const mat &m2);
template ITPP_EXPORT  cmat concat_vertical(const cmat &m1, const cmat &m2);
template ITPP_EXPORT  imat concat_vertical(const imat &m1, const imat &m2);
template ITPP_EXPORT  smat concat_vertical(const smat &m1, const smat &m2);

// I/O streams

template ITPP_EXPORT  std::ostream &operator<<(std::ostream &os, const mat  &m);
template ITPP_EXPORT  std::ostream &operator<<(std::ostream &os, const cmat &m);
template ITPP_EXPORT  std::ostream &operator<<(std::ostream &os, const imat  &m);
template ITPP_EXPORT  std::ostream &operator<<(std::ostream &os, const smat  &m);

template ITPP_EXPORT  std::istream &operator>>(std::istream &is, mat  &m);
template ITPP_EXPORT  std::istream &operator>>(std::istream &is, cmat &m);
template ITPP_EXPORT std::istream &operator>>(std::istream &is, imat  &m);
template ITPP_EXPORT std::istream &operator>>(std::istream &is, smat  &m);

} // namespace itpp

//! \endcond
