
#ifndef NOTIFICATIONOBSERVER_H
#define NOTIFICATIONOBSERVER_H

#include <string>

class NotificationObserver {

public:
    virtual ~NotificationObserver() {}
    virtual void update(const std::string& message) = 0;
};

#endif // NOTIFICATIONOBSERVER_H
