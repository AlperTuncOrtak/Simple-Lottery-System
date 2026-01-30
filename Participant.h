#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

class Participant {
private:
    std::string name;
    int ticketNumber;

public:
    Participant(std::string name, int ticketNumber);
    std::string getName() const;
    int getTicketNumber() const;
};

#endif
