//
// Created by JoachimWagner on 26.02.2025.
//

#include "UniqueServiceTest.h"

TEST_F(UniqueServiceTest, xyz){
    EXPECT_CALL(*mockPtr, foo()).WillOnce(Return (47));

    EXPECT_EQ(57, objectUnderTest->doWork());
}