
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <memory>

using namespace std;


void ThreadFunc(int index, vector<int>& data)
{
	data[index] = index;
}

int main()
{
	vector<int> data{ 5, 5, 5, 5, 5 };
	vector<std::thread> vt;

	for (int i = 0; i < 5; ++i)
	{
		//vt.push_back(std::move(thread(ThreadFunc, i, std::ref(data))));
		vt.push_back(std::move(thread(ThreadFunc, i, std::ref(data))));
	}

	for (auto& t : vt)
	{
		t.join();
	}

	for (auto d : data)
	{
		cout << d << endl;
	}
}
