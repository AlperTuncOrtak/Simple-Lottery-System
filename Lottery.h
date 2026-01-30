#ifndef LOTTERY_H
#define LOTTERY_H

#include <vector>
#include <string>
#include "Participant.h"

class Lottery {
private:
    std::vector<Participant> participants;
    int winningNumber;

    int generateTicketNumber();
    void saveWinnerToFile(const std::string& name, int ticket);

public:
    Lottery();
    void addParticipant(const std::string& name);
    void drawWinnerAndEndRound();
    int getWinningNumber() const;
    const std::vector<Participant>& getParticipants() const;
    void showPreviousWinners() const;
    void resetLottery();
};

#endif