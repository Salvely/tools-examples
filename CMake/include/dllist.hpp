#include <iostream>
template <typename E>
class dllist
{
    typedef struct node
    {
        struct node *prev;
        E val;
        struct node *next;
    } node_t;

private:
    node_t *head;
    int size;

public:
    dllist();
    ~dllist();
    void insert_front(E val);
    void insert_back(E val);
    void insert_item(E val, int index);
    E delete_front();
    E delete_back();
    E delete_item(int index);
    int find(E val);
    void modify(E old_val, E new_val);
    bool empty();
    int size();
    void print_list();
};

template <typename E>
inline dllist<E>::dllist()
{
}

template <typename E>
inline dllist<E>::~dllist()
{
}

template <typename E>
inline void dllist<E>::insert_front(E val)
{
}

template <typename E>
inline void dllist<E>::insert_back(E val)
{
}

template <typename E>
inline void dllist<E>::insert_item(E val, int index)
{
}

template <typename E>
inline E dllist<E>::delete_front()
{
    return E();
}

template <typename E>
inline E dllist<E>::delete_back()
{
    return E();
}

template <typename E>
inline E dllist<E>::delete_item(int index)
{
    return E();
}

template <typename E>
inline int dllist<E>::find(E val)
{
    return 0;
}

template <typename E>
inline void dllist<E>::modify(E old_val, E new_val)
{
}

template <typename E>
inline bool dllist<E>::empty()
{
    return false;
}

template <typename E>
inline int dllist<E>::size()
{
    return 0;
}

template <typename E>
inline void dllist<E>::print_list()
{
}
