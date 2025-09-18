class TaskManager {
public:
    struct Node {
        int taskId, priority, id;
        Node(int _, int __, int ___) {
            taskId = _;
            priority = __;
            id = ___;
        }
    };

    struct Comparator {
        bool operator()(const Node &A, const Node &B) {
            if (A.priority == B.priority) return A.taskId < B.taskId;
            return A.priority < B.priority;
        }
    };

    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            pq.push(Node(task[1], task[2], globalId));
            taskToUserMapping[task[1]] = task[0];
            idMapping[task[1]] = globalId;
            globalId++;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push(Node(taskId, priority, globalId));
        taskToUserMapping[taskId] = userId;
        idMapping[taskId] = globalId;
        globalId++;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push(Node(taskId, newPriority, globalId));
        idMapping[taskId] = globalId;
        globalId++;
    }
    
    void rmv(int taskId) {
        pq.push(Node(taskId, -1, globalId));
        idMapping[taskId] = globalId;
        globalId++;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (idMapping[top.taskId] != top.id || top.priority == -1) continue;
            return taskToUserMapping[top.taskId];
        }
        return -1;
    }
private:
    int globalId = 0;
    unordered_map<int, int> taskToUserMapping, idMapping;
    priority_queue<Node, vector<Node>, Comparator> pq;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */