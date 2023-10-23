#ifndef GIT322_H
#define GIT322_H

#include "LinkedList.h"

// class Git322 {
// private:
//     LinkedList myList;

// public:
//     Git322();
//     ~Git322();

//     void add();
//     void remove();
//     void print();
//     void load();
//     void compare();
//     void search();
// };

class Git322 {
public:
    Git322();
    ~Git322();

    virtual void add();
    virtual void remove();
    virtual void print();
    virtual void load();
    virtual void compare();
    virtual void search();

protected:
    LinkedList myList;
};


#endif /* GIT322_H */
