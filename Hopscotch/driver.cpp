#include <iostream>

#include "StudentSolver.h"
using namespace std;

int main() {
	vector<vector<int>> test = {};

	//test.push_back({3, 4, 1, 2, 8, 6});
	//test.push_back({6, 1, 8, 2, 7, 4});
	//test.push_back({5, 4, 3, 9, 9, 5});
	//test.push_back({5, 9, 8, 3, 2, 6});
	//test.push_back({8, 7, 2, 9, 6, 4});
	//test.push_back({ 1,4,4,8 });
	//test.push_back({ 7,5,8,9 });
	//test.push_back({ 2,3,6,3 });
	//test.push_back({ 4,1,2,2 });
	test.push_back({ 8,9,1,6,3,3,3,3,2 });
	test.push_back({ 3,8,7,7,8,8,8,7,8 });
	test.push_back({ 5,2,5,9,2,4,2,2,5 });
	test.push_back({ 9,9,5,7,1,3,6,7,1 });
	test.push_back({ 9,5,2,6,1,5,6,6,4 });
	vector<int> answer;
	StudentSolver testing;
	answer = testing.solve(test);
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
	cout << endl;
	return 0;
}