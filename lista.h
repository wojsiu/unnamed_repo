#ifndef INC_44C3C8C1_GR45_REPO_LISTA_H
#define INC_44C3C8C1_GR45_REPO_LISTA_H

#include <iostream>
#include <memory>

template <class T>
class Lista {
private:
    struct Node {
        T value;
        std::shared_ptr<Node> prev = NULL, next = NULL;
        Node(T _val) : value(_val) {};
    };

    std::shared_ptr<Node> head = NULL, tail = NULL;
public:
    bool is_empty() {
        if (head == NULL and tail == NULL)
            return true;
        else return false;
    }

    bool has_one_element() {
        if(!is_empty() and head == tail)
            return true;
        else
            return false;
    }

    void print() {
        auto curr = head;
        while(curr) {
            std::cout << curr->value << "/";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    void push_back(T elem) {
        std::shared_ptr<Node> tmp(new Node(elem));
        if (is_empty()) {
            tail = tmp;
            head = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }

    T pop_back() {
        if (is_empty()) throw std::range_error("pop empty list");
        auto tmp = tail;
        if (has_one_element()) {
            tail = NULL;
            head = NULL;
            return tmp->value;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
            return tmp->value;
        }
    }

    void push_front(T elem) {
        std::shared_ptr<Node> tmp(new Node(elem));
        if (is_empty()) {
            tail = tmp;
            head = tmp;
        }
        else {
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
    }

    T pop_front() {
        if (is_empty()) throw std::range_error("pop empty list");
        auto tmp = head;
        if (has_one_element()) {
            tail = NULL;
            head = NULL;
            return tmp->value;
        }
        else {
            head = head->next;
            head->prev = NULL;
            return tmp->value;
        }
    }

    bool is_in(T query) {
        auto current = head;
        if (is_empty()) return false;
        if (has_one_element() and head->value == query)
            return true;
        while (current->next != NULL) {
            if (current->value == query)
                return true;
            current = current->next;
        }
        return false;
    }

    T search(T query) {
        if (is_in(query)) {
            auto current = head;
            while(current->next != NULL) {
                if (current->value == query)
                    return current->value;
                current = current->next;
            }
        }
    }

};


#endif //INC_44C3C8C1_GR45_REPO_LISTA_H
