
#ifndef NOTIFICATIONSUBJECT_H
#define NOTIFICATIONSUBJECT_H

#include "NotificationObserver.h"
#include <list>

class NotificationSubject {

public:
    virtual ~NotificationSubject() {}
    virtual void addObserver(NotificationObserver* observer) = 0;
    virtual void removeObserver(NotificationObserver* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};

#endif // NOTIFICATIONSUBJECT_H

