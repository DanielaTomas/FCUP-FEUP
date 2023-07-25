#include <clocale>

namespace leic {
    template <typename T>
    class deque {
    private:
        struct Node {
            T value;
            Node* prev;
            Node* next;
        };
        int l_size;
        Node* head;
        Node* tail;
    public:
        deque() {
           l_size = 0;
           head = NULL;
           tail = NULL;
        }
        ~deque() {
            for(Node* node = head; node != NULL; node = node->next)
                delete node;
        }
        int size() const {
            return l_size;
        }
        bool empty() const {
            return l_size == 0;
        }
        void add_first(const T& value) {

        }
        void add_last(const T& value) {
            Node* node = new Node;
            node -> value = value;
            node -> next = NULL;
            if (tail != NULL) tail -> next = node;
            else head = node;
            tail = node;
            l_size++;
        }
        T remove_first() {
            Node* node = head;
            T value = node -> value;
            head = node -> next;
            l_size--;
            delete node;
            return value;
        }
        T remove_last() {

        }
    };
};
