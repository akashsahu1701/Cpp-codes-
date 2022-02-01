#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
                     int bt[], int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n,
                        int bt[], int wt[], int tat[])
{

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes  "
         << " Burst time  "
         << " Waiting time \n";

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i + 1 << "\t\t" << bt[i] << "\t    "
             << wt[i] << "\t\t  " << endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    //process id's
    int processes[20], n, burst_time[20];
    cout << "Enter total number of processes(maximum 20):\n";
    cin >> n;
    cout << "nEnter Process Burst Timen\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]:";
        cin >> burst_time[i];
        processes[i] = i + 1;
    }

    findavgTime(processes, n, burst_time);
    cout << "\n";
    cout << "submitted by 2019UEC2701 Akash Sahu ";
    return 0;
}