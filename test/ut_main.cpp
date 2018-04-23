#include <gtest/gtest.h>

#include "test_dot.h"
#include "test_string.h"
#include "test_fraction.h"
#include "test_vector.h"
#include "test_polygon.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS() ;
}
