///////////////////////////////////////////////////////////////////////////////
//
//  This implments a brute force method of determining the prime numbers
//  in a given range 1..n.
//
///////////////////////////////////////////////////////////////////////////////

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include "defn.h"

bool testForPrime( int val )
{
    int limit, factor = 2;

    limit = (long)( sqrtf( (float) val ) + 0.5f );
    while( (factor <= limit) && (val % factor) )
        factor++;

    return( factor > limit );
}
