#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 10;

class Task {
protected:
    string name;
    int duration;
    bool completed;

public:
    Task() : name(""), duration(0), completed(false) {} // Default constructor

    Task(const string& _name, int _duration) : name(_name), duration(_duration), completed(false) {}

    virtual void display() const {
        cout << "Name: " << name << "\n";
        cout << "Duration: " << duration << " minutes\n";
        cout << "Status: " << (completed ? "Completed" : "Pending") << "\n";
    }

    void markAsCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    virtual ~Task() {}
};

class ToDoList {
private:
    Task* tasks[MAX_TASKS];
    int numTasks;

public:
    ToDoList() : numTasks(0) {
        for (int i = 0; i < MAX_TASKS; ++i) {
            tasks[i] = nullptr;
        }
    }

    void display() const {
        cout << "-------------------------\n";
        cout << "  To-Do List for Today\n";
        cout << "-------------------------\n";
        for (int i = 0; i < numTasks; ++i) {
            cout << "Task " << i + 1 << ": ";
            if (tasks[i]->isCompleted()) {
                cout << "[✔] ";
            } else {
                cout << "[✘] ";
            }
            tasks[i]->display();
            cout << "-------------------------\n";
        }
    }

    void addTask(const Task& task) {
        if (numTasks < MAX_TASKS) {
            tasks[numTasks++] = new Task(task);
        } else {
            cout << "Cannot add more tasks, maximum limit reached.\n";
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= numTasks) {
            delete tasks[index - 1];
            for (int i = index - 1; i < numTasks - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            tasks[numTasks - 1] = nullptr;
            --numTasks;
        } else {
            cout << "Invalid index\n";
        }
    }

    int getNumTasks() const {
        return numTasks;
    }

    Task* getTask(int index) const {
        if (index >= 1 && index <= numTasks) {
            return tasks[index - 1];
        } else {
            cout << "Invalid index\n";
            return nullptr;
        }
    }

    bool allTasksCompleted() const {
        for (int i = 0; i < numTasks; ++i) {
            if (!tasks[i]->isCompleted()) {
                return false;
            }
        }
        return true;
    }

    ~ToDoList() {
        for (int i = 0; i < numTasks; ++i) {
            delete tasks[i];
        }
    }
};
int main() {
    ToDoList toDoList;

    cout << "Enter the number of tasks for today (maximum " << MAX_TASKS << "): ";
    int numTasks;
    cin >> numTasks;

    for (int i = 0; i < numTasks; ++i) {
        string taskName;
        int duration;
        cout << "Enter task " << i + 1 << " name: ";
        cin >> taskName;
        cout << "Enter duration required for completion (in minutes): ";
        cin >> duration;
        toDoList.addTask(Task(taskName, duration));
    }

    toDoList.display();

    char choice;
    do {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                if (toDoList.getNumTasks() < MAX_TASKS) {
                    string taskName;
                    int duration;
                    cout << "Enter task name: ";
                    cin >> taskName;
                    cout << "Enter duration required for completion (in minutes): ";
                    cin >> duration;
                    toDoList.addTask(Task(taskName, duration));
                    toDoList.display();
                } else {
                    cout << "Cannot add more tasks, maximum limit reached.\n";
                }
                break;
            }
            case '2': {
                int index;
                cout << "Enter index of task to remove: ";
                cin >> index;
                toDoList.removeTask(index);
                toDoList.display();
                break;
            }
            case '3': {
                int index;
                cout << "Enter index of task to mark as completed: ";
                cin >> index;
                Task* task = toDoList.getTask(index);
                if (task) {
                    task->markAsCompleted();
                    toDoList.display();
                }
                break;
            }
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != '4');

    if (toDoList.allTasksCompleted()) {
        cout << "\nCongratulations! You've completed all your tasks for today. Great job!\n";
    } else {
        cout << "\nYou can perform better next time!\n";
    }

    return 0;
}