#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Class to store task frequencies
class freq {
public:
    int amount;
    char lable;

    // Constructor
    freq(char lable, int amount) {
        this->lable = lable;
        this->amount = amount;
    }

    // Operator overload for priority queue
    bool operator<(const freq &other) const {
        return this->amount < other.amount;
    }
};

int main() {
    int numOfElement, n;
    cin >> numOfElement >> n;
    char lable;

    // Map for frequency calculation
    map<char, int> freqMap;
    while (numOfElement--) {
        cin >> lable;
        freqMap[lable]++;
    }

    // Priority queue to store tasks by frequency
    priority_queue<freq> SortedByfreq;
    for (auto &entry : freqMap) {
        SortedByfreq.push(freq(entry.first, entry.second));
    }

    int result = 0; // Total intervals required

    // Process tasks
    while (!SortedByfreq.empty()) {
        vector<freq> temp; // Temporary storage for tasks
        for (int i = 0; i < n + 1; i++) {
            if (!SortedByfreq.empty()) {
                freq current = SortedByfreq.top();
                SortedByfreq.pop();
                current.amount--;
                if (current.amount > 0) {
                    temp.push_back(current);
                }
            }
            result++; // Increment time for each interval
            if (SortedByfreq.empty() && temp.empty()) {
                break;
            }
        }
        // Reinsert remaining tasks back into the priority queue
        for (auto &task : temp) {
            SortedByfreq.push(task);
        }
    }

    cout << result << endl;
    return 0;
}
    // finding the minimum number of CPU intervals required to complete all tasks.
    // The CPU is idle at the beginning of the first interval.
    // The CPU can finish at most one task in each interval.
    // The CPU can finish the same task in multiple intervals.
    /**
        You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n.
        Each CPU interval can be idle or allow the completion of one task. Tasks can be completed
        in any order, but there's a constraint: there has to be a gap of at least n intervals between
        two tasks with the same label.
        Return the minimum number of CPU intervals required to complete all tasks.
     */

    // Input: tasks = ["A","A","A","B","B","B"], n = 2
// mahmoudadam5555@gmail.com
