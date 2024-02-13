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
Polynomial< S >& Polynomial< S >::
operator+( const Polynomial< S >& right ) const
{
  Polynomial< S > result;

  // TODO #1

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

#endif // __POLYNOMIAL__HXX__

// eof - Polynomial.hxx
