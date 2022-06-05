#define CATCH_CONFIG_MAIN
#include "test_and_main_includes.h"

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

//TEST_CASE("test client")
//{
//	Medicine first;
//	Medicine second;
//	Medicine third;
//
//	std::vector<Medicine> medicines = { first, second };
//
//	Client First_c("Andrzej", medicines);
//
//	SECTION("test name")
//	{
//		REQUIRE(First_c.get_name() == "Andrzej");
//	}
//
//	SECTION("add medicine")
//	{
//		REQUIRE(First_c.get_medicines().size() == 2);
//		First_c.add_medicine(third);
//		REQUIRE(First_c.get_medicines().size() == 3);
//	}
//	
//
//	SECTION("remove medicine")
//	{
//		REQUIRE(First_c.get_medicines().size() == 2);
//		First_c.remove_medicine(first);
//		REQUIRE(First_c.get_medicines().size() == 1);
//	}
//	



TEST_CASE("Testing base class methods")
{
/*		Tested base class methods:

	int get_position() const;
	std::string get_name() const;
	std::string get_producer() const;
	std::string get_substance() const;
	int get_amount() const;
	int get_base_price_gr() const;
	bool get_prescription() const;
	double get_calculated_price() const;
	std::string get_med_type() const;
	std::vector<std::string> get_symptoms(); const;

	void set_name(std::string);
	void set_producer(std::string);
	void set_substance(std::string);
	void set_amount(int);
	void set_base_price_gr(int);
	void set_position(int);
*/
	std::vector<std::string> test_med_symptoms = {"dry_cough", "wet_cough", "runny_nose", "sinus"};
	Medicine TestMed("Test medicine", "Bayer", "Paracetamol", test_med_symptoms, 10, 6550, false);
	REQUIRE(TestMed.get_name() == "Test medicine");
	REQUIRE(TestMed.get_producer() == "Bayer");
	REQUIRE(TestMed.get_substance() == "Paracetamol");
	REQUIRE(TestMed.get_symptoms() == test_med_symptoms);
	REQUIRE(TestMed.get_amount() == 10);
	REQUIRE(TestMed.get_base_price_gr() == 6550);
	REQUIRE(TestMed.get_calculated_price() == 65.5);
	REQUIRE(TestMed.get_prescription() == false);
	REQUIRE(TestMed.get_med_type() == "No data");
	REQUIRE(TestMed.get_position() == 0);
	REQUIRE_THROWS_AS(TestMed.set_amount(-1), NegativeAmountException);
	REQUIRE_THROWS_AS(TestMed.set_base_price_gr(-100), NegativePriceTagException);
	REQUIRE_THROWS_AS(TestMed.set_position(-1), NegativePositionException);
}



TEST_CASE("Testing derived classes")
{
	/*
	* testing uniqe derived classes parameters and overloaded functions
	* such as: tax_value, special_type, med_type
	*/
	SECTION("Testing Syrup class")
	{
		std::vector<std::string> test_med_symptoms1 = { "dry_cough", "pain", "headache" };
		Syrup SyrupTest("Syrup_test", "Polpharm", "Vitamin", test_med_symptoms1, 15, 5671, true, "dry");
		REQUIRE(SyrupTest.get_name() == "Syrup_test");
		REQUIRE(SyrupTest.get_producer() == "Polpharm");
		REQUIRE(SyrupTest.get_substance() == "Vitamin");
		REQUIRE(SyrupTest.get_symptoms() == test_med_symptoms1);
		REQUIRE(SyrupTest.get_amount() == 15);
		REQUIRE(SyrupTest.get_base_price_gr() == 5671);
		REQUIRE(SyrupTest.get_calculated_price() == 61.25);
		REQUIRE(SyrupTest.get_prescription() == true);
		REQUIRE(SyrupTest.get_med_type() == "Syrup");
		REQUIRE(SyrupTest.get_cough_type() == "dry");
		REQUIRE(SyrupTest.get_position() == 0);
		REQUIRE_THROWS_AS(SyrupTest.set_amount(-4), NegativeAmountException);
		REQUIRE_THROWS_AS(SyrupTest.set_base_price_gr(-200), NegativePriceTagException);
		REQUIRE_THROWS_AS(SyrupTest.set_position(-8), NegativePositionException);
	}
	SECTION("Testing Drops class")
	{
		std::vector<std::string> test_med_symptoms2 = { "dry_cough", "headache", "sinus" };
		Drops DropsTest("Drops_test", "Polpharm", "Glucose", test_med_symptoms2, 400, 31244, true,"solution");
		REQUIRE(DropsTest.get_name() == "Drops_test");
		REQUIRE(DropsTest.get_producer() == "Polpharm");
		REQUIRE(DropsTest.get_substance() == "Glucose");
		REQUIRE(DropsTest.get_symptoms() == test_med_symptoms2);
		REQUIRE(DropsTest.get_amount() == 400);
		REQUIRE(DropsTest.get_base_price_gr() == 31244);
		REQUIRE(DropsTest.get_calculated_price() == 349.93);
		REQUIRE(DropsTest.get_prescription() == true);
		REQUIRE(DropsTest.get_med_type() == "Drops");
		REQUIRE(DropsTest.get_drops_type() == "solution");
		REQUIRE(DropsTest.get_position() == 0);
		REQUIRE_THROWS_AS(DropsTest.set_amount(-5), NegativeAmountException);
		REQUIRE_THROWS_AS(DropsTest.set_base_price_gr(-654), NegativePriceTagException);
		REQUIRE_THROWS_AS(DropsTest.set_position(-83), NegativePositionException);
	}
	SECTION("Testing Pills class")
	{
		std::vector<std::string> test_med_symptoms3 = {"memory_disorder", "after_stroke"};
		Pills PillsTest("Pills_test", "Bayer", "Magnesium", test_med_symptoms3, 25, 768, false, "disintegrating");
		REQUIRE(PillsTest.get_name() == "Pills_test");
		REQUIRE(PillsTest.get_producer() == "Bayer");
		REQUIRE(PillsTest.get_substance() == "Magnesium");
		REQUIRE(PillsTest.get_symptoms() == test_med_symptoms3);
		REQUIRE(PillsTest.get_amount() == 25);
		REQUIRE(PillsTest.get_base_price_gr() == 768);
		REQUIRE(PillsTest.get_calculated_price() == 9.45);
		REQUIRE(PillsTest.get_prescription() == false);
		REQUIRE(PillsTest.get_med_type() == "Pills");
		REQUIRE(PillsTest.get_pills_type() == "disintegrating");
		REQUIRE(PillsTest.get_position() == 0);
		REQUIRE_THROWS_AS(PillsTest.set_amount(-87), NegativeAmountException);
		REQUIRE_THROWS_AS(PillsTest.set_base_price_gr(-62), NegativePriceTagException);
		REQUIRE_THROWS_AS(PillsTest.set_position(-843), NegativePositionException);
	}
	SECTION("Testing Ointment class")
	{
		std::vector<std::string> test_med_symptoms4 = { "ethanol", "scrapes", "bruises" };
		Ointment OintmentTest("Ointment_Test", "Medicineproducer", "Ketamin", test_med_symptoms4, 250, 64567, true, "cream");
		REQUIRE(OintmentTest.get_name() == "Ointment_Test");
		REQUIRE(OintmentTest.get_producer() == "Medicineproducer");
		REQUIRE(OintmentTest.get_substance() == "Ketamin");
		REQUIRE(OintmentTest.get_symptoms() == test_med_symptoms4);
		REQUIRE(OintmentTest.get_amount() == 250);
		REQUIRE(OintmentTest.get_base_price_gr() == 64567);
		REQUIRE(OintmentTest.get_calculated_price() == 742.52);
		REQUIRE(OintmentTest.get_prescription() == true);
		REQUIRE(OintmentTest.get_med_type() == "Ointment");
		REQUIRE(OintmentTest.get_ointment_type() == "cream");
		REQUIRE(OintmentTest.get_position() == 0);
		REQUIRE_THROWS_AS(OintmentTest.set_amount(-87), NegativeAmountException);
		REQUIRE_THROWS_AS(OintmentTest.set_base_price_gr(-62), NegativePriceTagException);
		REQUIRE_THROWS_AS(OintmentTest.set_position(-843), NegativePositionException);
	}
}


TEST_CASE("Testing MDatabase methods")
{
	/*

Public database methods testing:

	void add_Syrup(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string cough_type);
	void add_Pills(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string pills_type);
	void add_Drops(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string drops_type);
	void add_Ointment(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string ointment_type);
	void print_total_value() const noexcept;
	void print_all_data() const noexcept;
	void print_by_name(std::string) const;
	void delete_medicine(int);
	Medicine find_by_position(int pos) const;
	Medicine find_by_name(std::string name) const;
	bool check_if_exist_pos(int pos) const;
	bool check_if_exist_name(std::string name) const;
	int get_syrups_num() const;
	int get_pills_num() const;
	int get_drops_num() const;
	int get_ointments_num() const;

*/

	MDatabase data_base;
	std::vector<std::string> test_med_symptoms1 = { "dry_cough", "pain", "headache" };
	data_base.add_Syrup("Syrup_test", "Polpharm", "Vitamin", test_med_symptoms1, 15, 5671, true, "dry");
	std::vector<std::string> test_med_symptoms2 = { "dry_cough", "headache", "sinus" };
	data_base.add_Drops("Drops_test", "Polpharm", "Glucose", test_med_symptoms2, 400, 31244, true, "solution");
	std::vector<std::string> test_med_symptoms3 = { "memory_disorder", "after_stroke" };
	data_base.add_Pills("Pills_test", "Bayer", "Magnesium", test_med_symptoms3, 25, 768, false, "disintegrating");
	std::vector<std::string> test_med_symptoms4 = { "ethanol", "scrapes", "bruises" };
	data_base.add_Ointment("Ointment_test", "Medicineproducer", "Ketamin", test_med_symptoms4, 250, 64567, false, "cream");
	std::vector<std::string> test_med_symptoms5 = { "depression", "insomnia" };
	data_base.add_Syrup("Syrup_test2", "Polpharm", "VitaminC", test_med_symptoms5, 30, 5983, false, "wet");

	REQUIRE(data_base.find_by_position(1).get_med_type() == "Syrup");
	REQUIRE(data_base.find_by_position(1).get_name() == "Syrup_test");
	REQUIRE(data_base.find_by_position(1).get_position() == 1);
	REQUIRE(data_base.find_by_position(2).get_med_type() == "Syrup");
	REQUIRE(data_base.find_by_position(2).get_name() == "Syrup_test2");
	REQUIRE(data_base.find_by_position(2).get_position() == 2);
	REQUIRE(data_base.check_if_exist_pos(1) == true);
	REQUIRE(data_base.get_syrups_num() == 2);
	data_base.delete_medicine(1);
	REQUIRE_THROWS_AS(data_base.find_by_position(1), MedicineNotFoundException);
	REQUIRE(data_base.check_if_exist_pos(1) == false);
	REQUIRE(data_base.find_by_position(101).get_med_type() == "Pills");
	REQUIRE(data_base.find_by_position(101).get_position() == 101);
	REQUIRE(data_base.find_by_name("Drops_test").get_med_type() == "Drops");
	REQUIRE(data_base.find_by_name("Drops_test").get_position() == 201);
	REQUIRE(data_base.find_by_name("Ointment_test").get_med_type() == "Ointment");
	REQUIRE(data_base.find_by_name("Ointment_test").get_position() == 301);
	REQUIRE(data_base.get_pills_num() == 1);
	REQUIRE(data_base.get_ointments_num() == 1);
	REQUIRE(data_base.get_drops_num() == 1);
	std::vector<std::string> test_med_symptoms6 = { "wet_cough", "throatache", "sinus" };
	data_base.add_Drops("Drops_test2", "Polpharm", "codeine_phosphoran", test_med_symptoms6, 3000, 2100, false, "slime");
	REQUIRE(data_base.get_drops_num() == 2);

}
