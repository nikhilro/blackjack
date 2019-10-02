#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include <memory>

#include "observer.h"

class Subject {
    std::vector<Observer*> observers;

public:
    Subject() = default;
    
    void attach(Observer*);
    void detach(Observer*);

    void notifyAllObservers();

    virtual ~Subject() = 0;
};

#endif
