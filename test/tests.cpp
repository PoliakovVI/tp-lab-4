#include "gtest/gtest.h"

#include "Automata.h"

//check state
TEST(state,state_1)
{
	Automata A;
	EXPECT_EQ(A.getState(), 0);
}
TEST(state, state_2)
{
	Automata A;
	A.on();
	EXPECT_EQ(A.getState(), 1);
}
TEST(state, state_3)
{
	Automata A;
	A.on();
	A.coin(10);
	EXPECT_EQ(A.getState(), 2);
}
TEST(state, state_4)
{
	Automata A;
	A.on();
	A.coin(10);
	A.choice();
	EXPECT_EQ(A.getState(), 3);
}
TEST(state, state_5)
{
	Automata A;
	A.on();
	A.coin(10);
	A.choice();
	A.cook();
	EXPECT_EQ(A.getState(), 4);
}
TEST(state, state_6)
{
	Automata A;
	A.on();
	A.coin(10);
	A.choice();
	A.cook();
	A.finish();
	EXPECT_EQ(A.getState(), 1);
}
TEST(state, state_7)
{
	Automata A;
	A.coin(10);
	A.choice();
	A.cook();
	A.finish();
	EXPECT_EQ(A.getState(), 0);
}
//check money
TEST(money, money_1)
{
	Automata A;
	A.on();
	A.coin(10);
	int buf = A.cancel();
	EXPECT_EQ(buf, 10);
}
TEST(money, money_2)
{
	Automata A;
	A.on();
	A.coin(10);
	A.coin(15);
	int buf = A.cancel();
	EXPECT_EQ(buf, 25);
}
TEST(money, money_3)
{
	Automata A;
	A.on();
	A.coin(10);
	A.choice();
	A.cancel();
	A.coin(15);
	int buf = A.cancel();
	EXPECT_EQ(buf, 25);
}
TEST(money, money_4)
{
	Automata A;
	A.on();
	A.coin(10);
	A.choice();
	A.cook();
	int buf = A.finish();
	EXPECT_EQ(buf, 10);
}