#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex mu;

void print()
{
	mu.lock();
	for (int i=1;i<11;++i)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	mu.unlock();
}


int main()
{
	vector<thread> threads;
	for (int i=0;i<10;++i)
	{
		threads.push_back(thread(print)); 
	}
	for (auto& thread : threads)
	{
		thread.join(); 
	}
	return 0;
}
