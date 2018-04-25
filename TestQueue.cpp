#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
        Queue<long> ql;
        Queue<string> qs;

	if (!ql.isEmpty())
		cout << "Error in isEmpty() 1!\n";

	ql.push(4);

	if (ql.isEmpty())
		cout << "Error in isEmpty() 2!\n";

	ql.push(3.5);
	ql.push(9);

	if (ql.peek() != 4)
		cout << "Error in peek 1!\n";

	if (ql.pop() != 4)
		cout << "Error in pop 1!\n";

	if (ql.peek() != 3)
		cout << "Error in peek 2!\n";

	ql.push(7);

	if (ql.pop() != 3)
		cout << "Error in pop 2!\n";

	if (ql.pop() != 9)
		cout << "Error in pop 3!\n";

	if (ql.isEmpty())
		cout << "Error in isEmpty() 3!\n";

	if (ql.pop() != 7)
		cout << "Error in pop 4!\n";

	if (!ql.isEmpty())
		cout << "Error in isEmpty() 4!\n";

	if (!qs.isEmpty())
		cout << "Error in isEmpty() 5!\n";

	qs.push("four");

	if (qs.isEmpty())
		cout << "Error in isEmpty() 6!\n";

	qs.push("3.5");
	qs.push("nine");

	if (qs.peek() != "four")
		cout << "Error in peek 3!\n";

	if (qs.pop() != "four")
		cout << "Error in pop 5!\n";

	if (qs.peek() != "3.5")
		cout << "Error in peek 4!\n";

	qs.push("seven");

	if (qs.pop() != "3.5")
		cout << "Error in pop 6!\n";

	if (qs.pop() != "nine")
		cout << "Error in pop 7!\n";

	if (qs.isEmpty())
		cout << "Error in isEmpty() 7!\n";

	if (qs.pop() != "seven")
		cout << "Error in pop 8!\n";

	if (!qs.isEmpty())
		cout << "Error in isEmpty() 8!\n";


	cout << "Testing complete!\n";

	system("pause");
	return 0;
}