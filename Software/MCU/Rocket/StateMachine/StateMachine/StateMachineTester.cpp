#include <iostream>
#include "StateMachine.h"

using namespace std;

int main()
{
	StateMachine run;
	int testType;
	std::cout << "Press 1 for Manual test, 2 for Automatic" << endl;
	std::cin >> testType;
	int state;

	if (testType == 1)
	{	
		bool running = true;
		while (running)
		{
			std::cout << "Input State: " << endl;
			std::cin >> state;

			switch (state)
			{
			case 0:
				run.switchState(UNARMED);
				break;
			case 1:
				run.switchState(READY);
				break;
			case 2:
				run.switchState(STAGE1POWERED);
				break;
			case 3:
				run.switchState(STAGE1COAST);
				break;
			case 4:
				run.switchState(STAGE2POWERED);
				break;
			case 5:
				run.switchState(STAGE2COAST);
				break;
			case 6:
				run.switchState(DROGUEPAR);
				break;
			case 7:
				run.switchState(MAINPAR);
				break;
			case 8:
				run.switchState(LANDED);
				break;
			case 9:
				run.switchState(RESET);
				break;
			}
		}
	}
	
	if (testType == 2)
	{
		for (int i = 0; i < 1000; i++)
		{
			state = rand() % 10;
			switch (state)
			{
			case 0:
				run.switchState(UNARMED);
				break;
			case 1:
				run.switchState(READY);
				break;
			case 2:
				run.switchState(STAGE1POWERED);
				break;
			case 3:
				run.switchState(STAGE1COAST);
				break;
			case 4:
				run.switchState(STAGE2POWERED);
				break;
			case 5:
				run.switchState(STAGE2COAST);
				break;
			case 6:
				run.switchState(DROGUEPAR);
				break;
			case 7:
				run.switchState(MAINPAR);
				break;
			case 8:
				run.switchState(LANDED);
				break;
			case 9:
				run.switchState(RESET);
				break;
			}
		}
		run.testFinalize(1, 0);
	}
}