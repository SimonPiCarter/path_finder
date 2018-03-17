#include <gtest/gtest.h>

#include "entity/Move.hpp"
#include "entity/Entity.hpp"
#include "tools/Utils.hpp"

TEST(MoveTest, TestCollision)
{
    using namespace path;

    Vector<double> vector_l;    vector_l.y = 0;
    vector_l.x = 0;
    Entity entity1_l(vector_l, 1);
    vector_l.x = 5;
    Entity entity2_l(vector_l, 1);

    vector_l.x = 4;
    Move move1_l(entity1_l, vector_l);
    Move move2_l(entity2_l, -1.0*vector_l);

    EXPECT_TRUE(tools::checkAndUpdateMoves(move1_l, move2_l));

    EXPECT_NEAR(move1_l.getVector().x, 1.5, 1e-5);
    EXPECT_NEAR(move2_l.getVector().x, -1.5, 1e-5);
}

TEST(MoveTest, TestCollisionRadius2)
{
    using namespace path;

    Vector<double> vector_l;    vector_l.y = 0;
    vector_l.x = 0;
    Entity entity1_l(vector_l, 2.0);
    vector_l.x = 5;
    Entity entity2_l(vector_l, 2.0);

    vector_l.x = 4;
    Move move1_l(entity1_l, vector_l);
    Move move2_l(entity2_l, -1.0*vector_l);

    EXPECT_TRUE(tools::checkAndUpdateMoves(move1_l, move2_l));

    EXPECT_NEAR(move1_l.getVector().x, 0.5, 1e-5);
    EXPECT_NEAR(move2_l.getVector().x, -0.5, 1e-5);
}

TEST(MoveTest, TestNoCollision)
{
    using namespace path;

    Vector<double> vector_l;    vector_l.y = 0;
    vector_l.x = 0;
    Entity entity1_l(vector_l, 1);
    vector_l.x = 5;
    Entity entity2_l(vector_l, 1);

    vector_l.x = 1;
    Move move1_l(entity1_l, vector_l);
    Move move2_l(entity2_l, -1.0*vector_l);

    EXPECT_FALSE(tools::checkAndUpdateMoves(move1_l, move2_l));

    EXPECT_NEAR(move1_l.getVector().x, 1.0, 1e-5);
    EXPECT_NEAR(move2_l.getVector().x, -1.0, 1e-5);
}

TEST(MoveTest, TestNoCollisionParallelMove)
{
    using namespace path;

    Vector<double> vector_l;    vector_l.y = 0;
    vector_l.x = 0;
    Entity entity1_l(vector_l, 1);
    vector_l.x = 2;
    Entity entity2_l(vector_l, 1);

    vector_l.x = 1;
    Move move1_l(entity1_l, vector_l);
    Move move2_l(entity2_l, vector_l);

    EXPECT_FALSE(tools::checkAndUpdateMoves(move1_l, move2_l));

    EXPECT_NEAR(move1_l.getVector().x, 1.0, 1e-5);
    EXPECT_NEAR(move2_l.getVector().x, 1.0, 1e-5);
}

TEST(MoveTest, TestCollisionParallelMove)
{
    using namespace path;

    Vector<double> vector_l;    vector_l.y = 0;
    vector_l.x = 0;
    Entity entity1_l(vector_l, 1);
    vector_l.x = 2;
    Entity entity2_l(vector_l, 1);

    vector_l.x = 1;
    Move move1_l(entity1_l, 2.0*vector_l);
    Move move2_l(entity2_l, vector_l);

    EXPECT_TRUE(tools::checkAndUpdateMoves(move1_l, move2_l));

    EXPECT_NEAR(move1_l.getVector().x, 0.0, 1e-5);
    EXPECT_NEAR(move2_l.getVector().x, 0.0, 1e-5);
}
