#include <iostream>
#include <stdexcept>
#include <cmath>
#include <unordered_map>

using namespace std;

class Node {
private:
    int key;
    int value;
    Node* next;
    Node* prev;

public:
    Node(int k, int v) {
        if (k < 0 || k > pow(10, 4)) {
            throw std::runtime_error("Constraints for 'key' violated");
        }
        key = k;
        setValue(v);
        next = nullptr;
        prev = nullptr;
    }

    int getKey() const { return key; }
    int getValue() const { return value; }
    void setValue(int v) {
        if (v < 0 || v > pow(10, 5)) {
            throw std::runtime_error("Constraints for 'value' violated");
        }
        value = v;
    }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
    Node* getPrev() const { return prev; }
    void setPrev(Node* p) { prev = p; }
};


class LRUCache {
public:
    LRUCache(int capacity) {
        if (capacity < 1 || capacity > 3000) {
            throw std::runtime_error("Constraints for 'capacity' violated");
        }
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    LRUCache() : LRUCache(DEFAULT_CAPACITY) {}

    void setCapacity(int value) {
        if (value < 1 || value > 3000) {
            throw std::runtime_error("Constraints for 'capacity' violated");
        }
        capacity = value;
    }

    int get(int key) {
        auto it = keyToNodeMap.find(key);
        if (it != keyToNodeMap.end()) {
            if (it->second != head) { // Move to the front of the cache if it's not already there
                unlinkNode(it->second);
                insertAtHead(it->second);
            }
            return it->second->getValue();
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = keyToNodeMap.find(key);
        if (it != keyToNodeMap.end()) {
            // Update the value of the Node
            it->second->setValue(value);
            if (it->second != head) { // Move to the front of the cache if it's not already there
                unlinkNode(it->second);
                insertAtHead(it->second);
            }
        } else { // Add new key-Node pair to keyToNodeMap and push kev-value to the front of the cache. Remove LRU item if necessary  
            if (keyToNodeMap.size() == capacity) { 
                // The cache is at its capacity, evict LRU item from cache and keyToNodeMap
                keyToNodeMap.erase(keyToNodeMap.find(tail->getKey()));
                Node* LRUNode = tail;
                unlinkNode(LRUNode);
                delete LRUNode;
            }
            Node* newNode = new Node(key, value);
            insertAtHead(newNode);
            keyToNodeMap[key] = newNode;
        }
    }

private:
    Node* head;
    Node* tail;
    int capacity;
    static const int DEFAULT_CAPACITY = 10;
    unordered_map<int, Node*> keyToNodeMap;

    void insertAtHead(Node* node) {
        node->setNext(head);
        if (head != nullptr) { // Initialization of head in the double-linked list
            head->setPrev(node);
        }
        head = node; // Insert a new node at the fron of the list
        if (tail == nullptr) { // Initialization of tail in the double-linked list
            tail = node;
        }
    }
    void unlinkNode(Node* node) {
        if (node->getNext()) {
            node->getNext()->setPrev(node->getPrev());
        } else {
            tail = node->getPrev();
        }
        if (node->getPrev()) {
            node->getPrev()->setNext(node->getNext());
        } else {
            head = node->getNext();
        }
    }
};
