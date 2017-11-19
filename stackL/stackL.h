#ifndef KIRSANOV_G_V_STACKL_H
#define KIRSANOV_G_V_STACKL_H

#include <iostream>
template <typename T>
class StackL{
public:
    StackL() = default;
    ~StackL()
    {

    }
    bool isEmpty()
    {
        return pHead_.pNext_ == nullptr;
    }
private:
    struct Node{
        Node(Node* pNext_,const T& value):
                pNext_(pNext_),
                data_(value)
        {

        }
        Node* pNext_{nullptr};
        T data_{T()};
    };
    Node pHead_{nullptr};
};
#endif //KIRSANOV_G_V_STACKL_H
