#ifndef __POLYNOMIAL__HXX__
#define __POLYNOMIAL__HXX__

// -------------------------------------------------------------------------
template< class S > 
Polynomial< S >::
Polynomial( )
{
}

// -------------------------------------------------------------------------
template< class S > 
Polynomial< S >::
~Polynomial( )
{
}

// -------------------------------------------------------------------------
template< class S > 
void  Polynomial< S >::
SetCoefficient( unsigned int degree, const S& coefficient )
{
  if( degree >= this->size( ) )
    this->resize( degree + 1, S( 0 ) );
  ( *this )[ degree ] = coefficient;
}

// -------------------------------------------------------------------------
template< class S > 
Polynomial< S > Polynomial< S >::
operator+( const Polynomial< S >& right ) const 
{

  Polynomial< S > result;
       
  // TODO #1
   if(this->size( ) > right.size()) {
    result.resize(this->size());
    for(int i = this->size()-1; i >= 0; i--) {
        
      if(i > right.size()) {
       
         result[i] = (*this)[i];
      }
      else {

         S sum_coef = right.getCoeff(i)+(*this)[i];
        result[i] = sum_coef;
      }
    }
  }
  else {
    result.resize(right.size());
    for(int i = right.size() - 1; i >= 0; i--) {

      if(i > this->size()) {

        result[i] = right.getCoeff(i) ;
      }
      else {

        result[i] = right.getCoeff(i)+(*this)[i];
      }
    }
  }
   //polys[ p ].SetCoefficient( degree, coefficient ); 
 // std::cout << result << std::endl;
  return( result );
}

// -------------------------------------------------------------------------
template< class S > 
Polynomial< S >& Polynomial< S >::
operator*( const Polynomial< S >& right ) const
{

  Polynomial< S > result;

  // TODO #2
 
  return( result );
}

// -------------------------------------------------------------------------
template< class S > 
S Polynomial< S >::
operator()( const S& x ) const
{
  S result = S( 0 );

  // TODO #3

  return( result );
}


template< class S > 
S Polynomial< S >::
getCoeff( int coef) const
{
  return (*this)[coef];
 
  // TODO #3

}

#endif // __POLYNOMIAL__HXX__

// eof - Polynomial.hxx



