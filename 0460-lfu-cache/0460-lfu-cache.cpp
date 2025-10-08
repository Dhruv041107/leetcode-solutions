class Node {
public:
    int key, value, freq;
    Node *next, *prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        freq = 1;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node *head, *tail;
    int size;

    DoublyLinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DoublyLinkedList*> freqListMap;
    int maxSize;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqList(Node *node) {
        int oldFreq = node->freq;
        freqListMap[oldFreq]->removeNode(node);

        if (oldFreq == minFreq && freqListMap[oldFreq]->size == 0)
            minFreq++;

        node->freq++;

        if (!freqListMap.count(node->freq))
            freqListMap[node->freq] = new DoublyLinkedList();

        freqListMap[node->freq]->addFront(node);
    }

    int get(int key) {
        if (!keyNode.count(key))
            return -1;

        Node *node = keyNode[key];
        int val = node->value;
        updateFreqList(node);
        return val;
    }

    void put(int key, int value) {
        if (maxSize == 0)
            return;

        if (keyNode.count(key)) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
            return;
        }

        if (curSize == maxSize) {
            DoublyLinkedList *list = freqListMap[minFreq];
            Node *toRemove = list->tail->prev;

            keyNode.erase(toRemove->key);
            list->removeNode(toRemove);
            curSize--;
        }

        Node *newNode = new Node(key, value);
        minFreq = 1;

        if (!freqListMap.count(minFreq))
            freqListMap[minFreq] = new DoublyLinkedList();

        freqListMap[minFreq]->addFront(newNode);
        keyNode[key] = newNode;
        curSize++;
    }
};