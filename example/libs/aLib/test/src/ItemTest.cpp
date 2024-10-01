#include "ItemTest.h"
#include "atl_includes.h"
#include "Item.h"

void ItemTest::addUnitTests() {
	createUnitTest("Item should be equal",
		[]()->vector<Result>
		{
			vector<Result> assertions;
			Item item1("item_1", 4);
			Item item2("item_2", 3);

			// an example that use custom toString
			assertions.push_back(IsEqualTo<Item>(item1, item2)
				.getResultWithCustomToString(ItemtoString));

			return assertions;
		}
	);
	createUnitTest("Use custom assert",
		[]()->vector<Result>
		{
			vector<Result> assertions;

			// an example that create directly a Result
			assertions.push_back(Result(false,
				vector<string>({ "This is a custom assert","this test do not pass" })));

			return assertions;
		});
}
