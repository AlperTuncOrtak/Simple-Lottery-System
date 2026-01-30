#include "Participant.h"

Participant::Participant(std::string name, int ticketNumber) 
    : name(name), ticketNumber(ticketNumber) {}

std::string Participant::getName() const {
    return name;
}

int Participant::getTicketNumber() const {
    return ticketNumber;
}
