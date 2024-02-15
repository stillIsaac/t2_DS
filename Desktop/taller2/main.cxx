#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Polynomial.h"
// -------------------------------------------------------------------------
typedef double TScalar;
typedef Polynomial< TScalar > TPolynomial; // TPolynomial es un Polinomio de tipo Tscalar
typedef std::vector< TPolynomial > TPolynomials; // TPolynomialS es un vector de polinomios

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  if( argc < 2 )
  {
    std::cout << "Usage: " << argv[ 0 ]  << "input" << std::endl;
    return( 1 );

  } // fi
  std::string input_filename = argv[ 2 ];

  // Open text file
  std::ifstream input( input_filename );
  if( !input )
  {
    std::cout << "Error opening \"" << input_filename << "\"" << std::endl;
    return( 1 );

  } // fi

  // Data for analysis
  TPolynomials polys;

  // Read the line containing the number of polynomials

  std::string input_line;
  std::getline( input, input_line );
  unsigned int nPolys = std::atoi(  input_line.c_str());

  // Read polynomials
  for( unsigned int p = 0; p < nPolys; ++p )
  {
    // Create empty polynomial
    polys.push_back( TPolynomial( ) ); //Empty Polynomial enters into the array of polynomials

    // Read line
    std::getline( input, input_line );

    // Tokenize
    std::stringstream tokens( input_line );

    // Extract data from tokens
    std::string token;
    while( tokens >> token )
    {
      unsigned int degree = std::atoi( token.c_str() );
      tokens >> token;
      TScalar coefficient = std::atof( token.c_str( ) ); // Create a TScalar to store the coefficient in double

      // Update polynomial
      polys[ p ].SetCoefficient( degree, coefficient ); //  uses the function setCoefficient to ad the coefficient and degree

    } // elihw
    std::cout << "Input " << p << " = " << polys[ p ] << std::endl;

  } // rof
  
  // Execute desired operations
  bool stop = false;
  while( std::getline( input, input_line ) && !stop )
  {
    // Tokenize
    std::stringstream tokens( input_line );

    // Get operator and operands
    char type;
    tokens >> type;

    if( type != 'E' )
    {
      switch( type )
      {

      case 'A':
      {

        unsigned int a_id, b_id;
        tokens >> a_id >> b_id;
        std::cout << "Add (" << a_id << ", " << b_id << ") = ";
        std::cout << polys[a_id].operator+(polys[b_id]) <<std::endl;    
      }
      break;

      case 'M':
      {
        // std::cout << "esto es multiplicacion" << std::endl;

        unsigned int a_id, b_id;
        tokens >> a_id >> b_id;
        std::cout
          << "Multiplication (" << a_id << ", " << b_id << ") = "
          << ( polys[ a_id ] * polys[ b_id ] ) << std::endl;
      }
      break;
      case 'P':
      {
        unsigned int id;
        TScalar x;
        tokens >> id >> x;
        std::cout
          << "Polynomial (" << id << ", " << x << ") = "
          << polys[ id ].operator()(x) << std::endl;
      }
      break;
      default:
        break;
      }
    }
    else
      stop = true;

  } // elihw

  // Close text file
  ( input ).close( );

  return( 0 );
}

// eof - main.cxx
