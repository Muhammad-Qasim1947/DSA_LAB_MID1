#include <iostream>
using namespace std;
#define max 100

class queue
{
private:
    int data_arr[max];
    int front;
    int rear;
    int count;

public:
    queue() : front(0), rear(-1), count(0)
    {
    }

    bool isempty()
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == max;
    }

    int size() const
    {
        return count;
    }

    bool enqueue(int id)
    {
        if (isFull())
        {
            cout << "Queue full! Cannot add patient " << id << endl;
            return false;
        }

        rear++;

        if (rear == max)
        {
            rear = 0;
        }

        data_arr[rear] = id;
        count++;
        return true;
    }

    int dequeue()
    {
        if (isempty())
        {
            return -1; // Indicator for empty queue
        }

        int id = data_arr[front];
        front = (front + 1) % max;
        count--;
        return id;
    }

    int total() const { return count; }
};

int main()
{
    queue qCritical; // Severity 1
    queue qSerious;  // Severity 2
    queue qNormal;   // Severity 3

    int total_patient_treated = 0;
    int treated_patients[max];

    int n;
    cout << "Enter total operations count: ";
    cin >> n;

    cout << "Enter operations (ARRIVE ID SEVERITY or TREAT):\n";

    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;

        if (op == "ARRIVE" || op == "arrive")
        {
            int id, severity;
            cin >> id >> severity;

            if (severity == 1)
            {
                qCritical.enqueue(id);
            }
            else if (severity == 2)
            {
                qSerious.enqueue(id);
            }
            else if (severity == 3)
            {
                qNormal.enqueue(id);
            }
            else
            {
                cout << "Invalid severity level!" << endl;
            }
        }

        else if (op == "TREAT" || op == "treat")
        {
            if (!qCritical.isempty())
            {
                treated_patients[total_patient_treated++] = qCritical.dequeue();
            }
            else if (!qSerious.isempty())
            {
                treated_patients[total_patient_treated++] = qSerious.dequeue();
            }
            else if (!qNormal.isempty())
            {
                treated_patients[total_patient_treated++] = qNormal.dequeue();
            }
            else
            {
                cout << "No patients waiting to be treated!" << endl;
            }
        }
    }
    
    int remCritical = qCritical.size();
    int remSerious = qSerious.size();
    int remNormal = qNormal.size();
    int totalRemaining = remCritical + remSerious + remNormal;

    cout << "\n================ Summary ================\n";
    cout << "Treatment Order: ";
    if (total_patient_treated == 0)
    {
        cout << "None";
    }
    else
    {
        for (int i = 0; i < total_patient_treated; i++)
        {
            cout << treated_patients[i] << " ";
        }
    }
    cout << endl;

    cout << "Total Patients Treated: " << total_patient_treated << endl;
    cout << "Total Patients Remaining: " << totalRemaining << endl;
    cout << "  - Critical Remaining: " << remCritical << endl;
    cout << "  - Serious Remaining: " << remSerious << endl;
    cout << "  - Normal Remaining: " << remNormal << endl;
}