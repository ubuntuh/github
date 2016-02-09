#include <cstdio>

struct Process {
    char name[11];
    int time;
};

#define QUEUE_MAX 100000
Process* queue[QUEUE_MAX];
int head;
int tail;
void printQueue() {
    int i = tail;
    while (i != head) {
        printf("[%d]", queue[i]->time);
        ++i %= QUEUE_MAX;
    }
    printf("\n");
}
void enqueue(Process* value) {
    queue[head++] = value;
    head %= QUEUE_MAX;
}
Process* dequeue() {
    Process* value = queue[tail++];
    tail %= QUEUE_MAX;
    return value;
}
bool isEmpty() {
    return head == tail;
}
int n; // numProcesses [1, 100000]
int q; // timeQuantum [1, 1000]

int main() {
    scanf("%d %d\n", &n, &q);
    for (int i = 0; i <= n - 1; ++i) {
        Process* process = new Process();
        scanf("%s %d\n", process->name, &process->time);
        enqueue(process);
    }
    int totalTime = 0;
    while (! isEmpty()) {
        // printQueue();
        Process* process = dequeue();
        char* name = process->name;
        int time = process->time;
        if (time <= q) {
            totalTime += time;
            printf("%s %d\n", name, totalTime);
        } else {
            process->time -= q;
            totalTime += q;
            enqueue(process);
        }
    }
    return 0;
}
