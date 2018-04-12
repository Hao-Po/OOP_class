#include <gtest/gtest.h>

#include "test_dot.h"
#include "test_string.h"
#include "test_fraction.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS() ;
}
