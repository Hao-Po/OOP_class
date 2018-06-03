#include <gtest/gtest.h>

//#include "./test_shopping_cart.h"
//#include "./test_polygon.h"
#include "./test_shape.h"
#include "./test_prism.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
