#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include "queue.h"
#include <vector>
#include "client.h"

TEST_CASE("Test Queue")
{
	Client first;
	Client second;

	std::vector<Client> clients = { first, second };

	Queue queue(clients);

	SECTION("test vector")
	{
		REQUIRE(queue.get_clients().size() == 2);
	}

	SECTION("add method")
	{
		Client third;
		queue.add_client(third);

		REQUIRE(queue.get_clients().size() == 3);
	}

	SECTION("remove client")
	{
		queue.remove_client();

		REQUIRE(queue.get_clients().size() == 1);
	}
}
/*
TEST_CASE("test client")
{
	Medicine first;
	Medicine second;
	Medicine third;

	std::vector<Medicine> medicines = { first, second };

	Client First_c("Andrzej", medicines);

	SECTION("test name")
	{
		REQUIRE(First_c.get_name() == "Andrzej");
	}

	SECTION("add medicine")
	{
		REQUIRE(First_c.get_medicines().size() == 2);
		First_c.add_medicine(third);
		REQUIRE(First_c.get_medicines().size() == 3);
	}
	*/
/*
	SECTION("remove medicine")
	{
		REQUIRE(First_c.get_medicines().size() == 2);
		First_c.remove_medicine(first);
		REQUIRE(First_c.get_medicines().size() == 1);
	}
	*/
