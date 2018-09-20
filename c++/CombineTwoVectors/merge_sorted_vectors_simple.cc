#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <mutex>
#include <deque>

struct task_queue_t {
	typedef std::function<void ()> task_t;
	typedef std::deque<task_t> task_deque_t; // Must ASSERT that this is only ever modified by a single thread. Note: Double Ended queue, not dequeue
	// Mutex and Lock are used to control resource ownership
	typedef std::mutex mutex_t; 
	typedef std::unique_lock<mutex_t> lock_t;
};


std::vector<std::pair<int, int>> merge_sorted_vector_pairs(const std::vector<std::pair<int, int>>& myseta, const std::vector<std::pair<int, int>>& mysetb) {

	std::vector<std::pair<int,int>> combined_vector;

	for (auto pair : myseta) {
		std::cout << "Thread ID: " << std::this_thread::get_id() << " pair key: " << pair.first << "\n";
	}

	return combined_vector;
}

void spawn_threads() {
	//create a vector of threads that can service tasks
}

void destroy_threads() {
	//unlock the threads, join etc
	//remember to acquire the mutex when doing this
}

int main(int argc, char**argv) {
    std::vector<std::pair<int, int>> seta;
    std::vector<std::pair<int, int>> setb;
    
    seta.push_back({1,2});
    seta.push_back(std::make_pair(2,4));
    seta.emplace_back(9,3);
    seta.emplace_back(4,2);
    seta.emplace_back(7,5);
    seta.emplace_back(23,100);
    
    setb.insert(setb.end(), {{9,4}, {1,1000}, {23,123}, {7,7}, {8,8}, {11,11}});
    setb.push_back(std::make_pair(50,3));

	std::sort(seta.begin(), seta.end());
	std::sort(setb.begin(), setb.end());

    merge_sorted_vector_pairs(seta, setb);

    return 0;
}
