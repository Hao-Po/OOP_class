#include <gtest/gtest.h>

#include "test_dot.h"
#include "test_string.h"
#include "test_fraction.h"
#include "test_vector.h"
#include "test_polygon.h"
#include "test_bubbleSort.h"
#include "test_term.h"
#include "test_polynomial.h"
#include "test_template.h"


int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS() ;
}
