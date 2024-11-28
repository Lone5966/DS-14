#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    string name;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

// Function for Round Robin Scheduling
void round_robin_scheduling(vector<Process>& processes, int time_quantum) {    // Function for Round Robin Scheduling
    int time = 0;
    queue<Process*> ready_queue;
    int n = processes.size();
    int remaining_processes = n;
    int process_index = 0;

    while (remaining_processes > 0) {
        while (process_index < n && processes[process_index].arrival_time <= time) {
            ready_queue.push(&processes[process_index]);
            process_index++;
        }

        if (!ready_queue.empty()) {
            Process* current_process = ready_queue.front();
            ready_queue.pop();

            int execution_time = min(current_process->remaining_time, time_quantum);
            time += execution_time;
            current_process->remaining_time -= execution_time;

            if (current_process->remaining_time == 0) {
                current_process->completion_time = time;
                current_process->turnaround_time = current_process->completion_time - current_process->arrival_time;
                current_process->waiting_time = current_process->turnaround_time - current_process->burst_time;
                remaining_processes--;
            } else {
                ready_queue.push(current_process);
            }
        } else {
            time++;
        }
    }

    cout << "Process   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n";
    for (const auto& process : processes) {
        cout << process.name << "          " << process.arrival_time << "              "
             << process.burst_time << "            " << process.completion_time << "                 "
             << process.turnaround_time << "              " << process.waiting_time << "\n";
    }
}

// Main function to initialize processes and run the scheduler
int main() {
    vector<Process> processes = {
        {"P1", 0, 5, 5, 0, 0, 0},
        {"P2", 1, 3, 3, 0, 0, 0},
        {"P3", 2, 1, 1, 0, 0, 0},
        {"P4", 3, 2, 2, 0, 0, 0},
        {"P5", 4, 3, 3, 0, 0, 0}
    };

    int time_quantum = 2;

    round_robin_scheduling(processes, time_quantum);

    return 0;
}
