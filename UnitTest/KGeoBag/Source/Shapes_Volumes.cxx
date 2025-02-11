/**
 * Unit testing for KGeoBag shape classes
 * @author J. Behrens, N. Trost
 *
 * This file contains a unit tests for most of KGeoBag's shape classes.
 * All tests should be grouped together in a meaningful way, and should use
 * a fixture class which is derived from TimeoutTest. Please keep unit tests
 * as simple as possible (think of a minimal example of how to use a certain
 * class). It is a good idea to also include a death-test for each class.
 *
 * See the official GoogleTest pages for more info:
 *   https://code.google.com/p/googletest/wiki/Primer
 *   https://code.google.com/p/googletest/wiki/AdvancedGuide
 */

#include "KGBox.hh"
#include "Shapes.h"

using namespace KGeoBag;

using katrin::KThreeVector;

/////////////////////////////////////////////////////////////////////////////
// Shapes (Volumes) Unit Testing
/////////////////////////////////////////////////////////////////////////////

TEST_F(KGeoBagShapeTest, KGBox)
{
    auto* tSurface1 = new KGBox(0.1, 1., 0.2, 2., 0.3, 3.);

    EXPECT_EQ(tSurface1->GetP0(), KThreeVector(0.1, 0.2, 0.3));
    EXPECT_EQ(tSurface1->GetP1(), KThreeVector(1., 2., 3.));

    delete tSurface1;

    auto* tSurface2 = new KGBox(KThreeVector(0.1, 0.2, 0.3), KThreeVector(1., 2., 3.));

    EXPECT_EQ(tSurface2->GetP0(), KThreeVector(0.1, 0.2, 0.3));
    EXPECT_EQ(tSurface2->GetP1(), KThreeVector(1., 2., 3.));

    delete tSurface2;

    auto* tSurface3 = new KGBox();
    tSurface3->SetP0(KThreeVector(0.1, 0.2, 0.3));
    tSurface3->SetP1(KThreeVector(1., 2., 3.));

    EXPECT_EQ(tSurface2->GetP0(), KThreeVector(0.1, 0.2, 0.3));
    EXPECT_EQ(tSurface2->GetP1(), KThreeVector(1., 2., 3.));

    tSurface3->SetX0(1.1);
    tSurface3->SetX1(2.1);
    tSurface3->SetY0(2.2);
    tSurface3->SetY1(3.1);
    tSurface3->SetZ0(3.3);
    tSurface3->SetZ1(4.1);

    EXPECT_EQ(tSurface3->GetP0(), KThreeVector(1.1, 2.2, 3.3));
    EXPECT_EQ(tSurface3->GetP1(), KThreeVector(2.1, 3.1, 4.1));

    tSurface3->SetP0(KThreeVector(0.1, 0.2, 0.3));
    tSurface3->SetP1(KThreeVector(1., 2., 3.));

    EXPECT_EQ(tSurface2->GetP0(), KThreeVector(0.1, 0.2, 0.3));
    EXPECT_EQ(tSurface2->GetP1(), KThreeVector(1., 2., 3.));

    delete tSurface3;
}


//////////////////////////////////////////////////////////////////////////////
// DEATH TESTS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

TEST(KGeoBagShapeDeathTest, KGBox) {}
