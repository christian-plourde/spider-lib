#include <iostream>
namespace SpiderLib::DataStructures
{
    #ifndef DATA_STRUCTURES_LIBRARY_H
    #define DATA_STRUCTURES_LIBRARY_H

    template <class T>
    class LinkedListNode
    {
        private:
            T value;
            LinkedListNode<T>* next;
        public:
            explicit LinkedListNode(T val)
            {
                value = val;
                next = NULL;
            };
            LinkedListNode<T>* Next(){return next;};
            T Value(){return value;};
            void setValue(T val){value = val;};
            void setNext(LinkedListNode<T>* n){next = n;};
            template <class U>
                friend std::ostream& operator<<(std::ostream& out, const LinkedListNode<U>& node);
            template <class U>
                friend bool operator==(const LinkedListNode<U>& node_1, const LinkedListNode<U>& node_2);
    };

    template <class U>
    std::ostream& operator<<(std::ostream& os, const LinkedListNode<U>& node)
    {
        os << node.value;
        return os;
    }

    template <class U>
    bool operator==(const LinkedListNode<U>& node_1, const LinkedListNode<U>& node_2)
    {
        return node_1.value == node_2.value;
    }

    template <class T>
    class LinkedList
    {
        private:
            LinkedListNode<T>* head;
            LinkedListNode<T>* tail;
            int count;
        public:
            LinkedList<T>()
            {
                count = 0;
            };
            ~LinkedList<T>()
            {
                if(count == 0)
                    std::cout << "Linked List deleted." << std::endl;
                else if(count == 1)
                {
                    delete head;
                    std::cout << "Linked List deleted." << std::endl;
                }
                else
                {
                    LinkedListNode<T>* old = head;
                    LinkedListNode<T>* current = head->Next();
                    while(current)
                    {
                        delete old;
                        old = current;
                        current = current->Next();
                    }
                    std::cout << "Linked List deleted." << std::endl;
                }
            };
            int Count(){return count;};
            void addFirst(T val)
            {
                if(count == 0)
                {
                    //if there are no elements in the list, then we add to the head and the tail points to the same
                    //thing
                    LinkedListNode<T>* node = new LinkedListNode<T>(val);
                    head = node;
                    tail = NULL;
                    head->setNext(tail);
                }

                if(count == 1)
                {
                    LinkedListNode<T>* node = new LinkedListNode<T>(val);
                    tail = head;
                    head = node;
                    head->setNext(tail);
                }

                else
                {
                    //add to the head of the list
                    LinkedListNode<T>* node = new LinkedListNode<T>(val);
                    node->setNext(head);
                    head = node;
                }

                //increment the count of elements in the list
                count++;
            }
            void addLast(T val)
            {
                if(count == 0)
                {
                    //if there are no elements in the list, then we add to the head and the tail points to the same
                    //thing
                    LinkedListNode<T>* node = new LinkedListNode<T>(val);
                    head = node;
                    tail = NULL;
                    head->setNext(tail);
                }


                else if(count == 1)
                {
                    LinkedListNode<T>* node = new LinkedListNode<T>(val);
                    head->setNext(node);
                    tail = node;
                }

                else
                {
                    //add to the tail of the list
                    LinkedListNode<T>* node = new LinkedListNode<T>(val);
                    tail->setNext(node);
                    tail = node;
                }

                //increment the count of elements in the list
                count++;
            }
            bool Contains(T val)
            {
                int i = 0;
                LinkedListNode<T>* current = head;
                while(i < count)
                {
                    if(current->Value() == val)
                        return true;
                    i++;
                    current = current->Next();
                }

                return false;
            }
            void Remove(T val)
            {
                //removes the first occurence of a found value
                if(count == 0)
                {
                    return;
                }

                else if(count == 1 && head->Value() == val )
                {
                    delete head;
                    count--;
                }

                else
                {
                    LinkedListNode<T>* current = head;
                    LinkedListNode<T>* previous = head;
                    int iteration = 0;
                    while(current)
                    {
                        LinkedListNode<T>* to_delete = NULL;

                        if(current->Value() == val)
                        {
                            if(current == head)
                            {
                                head = current->Next();
                                delete current;
                                count--;
                                break;
                            }

                            if(current == tail)
                            {
                                tail = previous;
                                previous->setNext(NULL);
                                delete current;
                                count--;
                                break;
                            }

                            else
                            {
                                to_delete = previous->Next();
                                previous->setNext(current->Next());
                                count--;
                                break;
                            }

                        }

                        current = current->Next();
                        if(to_delete)
                            delete to_delete;
                        if(iteration > 0)
                            previous = previous->Next();
                        iteration++;
                    }
                }
            }
            void RemoveAll(T val)
            {
                while(this->Contains(val))
                    this->Remove(val);
            }

            template <class U>
                friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
    };

    template <class U>
    std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list)
    {
        if(list.count == 0)
            os << "[]";
        else
        {
            os << "[";
            LinkedListNode<U>* current = list.head;
            int i = 0;
            while(i < list.count)
            {
                if(i == list.count - 1)
                    os << *current;
                else
                    os << *current << ", ";
                current = current->Next();
                i++;
            }
            os << "]";
        }
        return os;
    }

    #endif //DATA_STRUCTURES_LIBRARY_H
}
