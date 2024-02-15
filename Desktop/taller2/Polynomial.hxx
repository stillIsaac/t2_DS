#ifndef __POLYNOMIAL__HXX__
#define __POLYNOMIAL__HXX__
#include <cmath>
// -------------------------------------------------------------------------
template <class S>
Polynomial<S>::
    Polynomial()
{
}

// -------------------------------------------------------------------------
template <class S>
Polynomial<S>::
    ~Polynomial()
{
}

// -------------------------------------------------------------------------
template <class S>
void Polynomial<S>::
    SetCoefficient(unsigned int degree, const S &coefficient)
{
  if (degree >= this->size())
    this->resize(degree + 1, S(0));
  (*this)[degree] = coefficient;
}

// -------------------------------------------------------------------------
template <class S>
Polynomial<S> Polynomial<S>::
operator+(const Polynomial<S> &right) const
{

  Polynomial<S> result;

  // TODO #1
  if (this->size() > right.size())
  {
    result.resize(this->size());
    for (int i = this->size() - 1; i >= 0; i--)
    {

      if (i > right.size())
      {

        result[i] = (*this)[i];
      }
      else
      {

        S sum_coef = right.getCoeff(i) + (*this)[i];
        result[i] = sum_coef;
      }
    }
  }
  else
  {
    result.resize(right.size());
    for (int i = right.size() - 1; i >= 0; i--)
    {

      if (i > this->size())
      {

        result[i] = right.getCoeff(i);
      }
      else
      {

        result[i] = right.getCoeff(i) + (*this)[i];
      }
    }
  }

  return (result);
}

// -------------------------------------------------------------------------
// TODO #2
template <class S>
Polynomial<S> &Polynomial<S>::operator*(const Polynomial<S> &right) const
{
  Polynomial<S> result;

  for (unsigned int i = 0; i < this->size(); ++i)
  {
    for (unsigned int j = 0; j < right.size(); ++j)
    {
      S coefficient = (*this)[i] * right[j];
      unsigned int degree = i + j;
      if (degree >= result.size())
      {
        result.resize(degree + 1, S(0));
      }
      result[degree] += coefficient;
    }
  }
  Polynomial<S> *newPolynomial = new Polynomial<S>(result);
  if (newPolynomial == nullptr)
  {
    throw std::bad_alloc();
  }
  return *newPolynomial;
}

// -------------------------------------------------------------------------
template <class S>
S Polynomial<S>::
operator()(const S &x) const
{

  S result = S(0);
  for (int i = this->size() - 1; i >= 0; i--)
  {

    result = result + (pow(x, i) * this->getCoeff(i));
  }

  return (result);
}

template <class S>
S Polynomial<S>::
    getCoeff(int coef) const
{

  return (*this)[coef];
}

#endif // __POLYNOMIAL__HXX__

// eof - Polynomial.hxx
