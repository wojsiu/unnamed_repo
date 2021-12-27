#ifndef INC_44C3C8C1_GR45_REPO_LISTA_H
#define INC_44C3C8C1_GR45_REPO_LISTA_H

#include <iostream>
#include <memory>

/**
 * Lista dwukierunkowa przechowująca obiekty dowolnej klasy.
 * @tparam T klasa przechowywanego obiektu
 */
template <class T>
class Lista {
private:
    /**
     * Komórka zawierająca dane oraz wskaźnik na poprzednika i następnika.
     */
    struct Node {
        T value;
        std::shared_ptr<Node> prev = NULL, next = NULL;
        Node(T _val) : value(_val) {};
    };

    /**
     * Wskaźniki na ogon i głowę listy.
     */
    std::shared_ptr<Node> head = NULL, tail = NULL;
public:

    /**
     * @return informację, czy lista jest pusta
     */
    bool is_empty() {
        if (head == NULL and tail == NULL)
            return true;
        else return false;
    }

    /**
     *
     * @return informację, czy lista zawiera dokładnie jeden element
     */
    bool has_one_element() {
        if(!is_empty() and head == tail)
            return true;
        else
            return false;
    }

    /**
     * Wyświetla na ekranie elementy listy.
     */
    void print() {
        auto curr = head;
        while(curr) {
            std::cout << curr->value << "/";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /**
     * Umieszcza element z tyłu listy.
     * @param elem element do dodania
     */
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

    /**
     * Usuwa element z końca listy.
     * @return ostatni element
     */
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

    /**
     * Umieszcza element na początku listy.
     * @param elem element do dodania
     */
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

    /**
     * Usuwa element z początku listy.
     * @return pierwszy element
     */
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

    /**
     * Funkcja sprawwdzająca, czy w liście jest dany element.
     * @param query szukany element
     * @return informację, czy element znajduje się na liście.
     */
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

    /**
     * Funcja szukająca elementu w liście.
     * @param query szukany element
     * @return zwraca wskaźnik na szukany element
     */
    std::shared_ptr<Node> search_node(T query) {
        if (is_in(query)) {
            auto current = head;
            while(current->next != NULL) {
                if (current->value == query)
                    return current;
                current = current->next;
            }
        }
        else throw std::logic_error("nie odnaleziono elementu");
    }

    /**
     * Usuwa pierwszy napotkany element zgodny z kluczem.
     * @param elem element do usunięcia
     */
    void delete_elem(T elem) {
        auto tmp = search_node(elem);
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

};


#endif //INC_44C3C8C1_GR45_REPO_LISTA_H
