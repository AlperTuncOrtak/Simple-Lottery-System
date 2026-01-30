#include "Lottery.h"
#include <iostream>
#include <random>
#include <fstream>

//object creating
Lottery::Lottery() {
    winningNumber = generateTicketNumber();
}
//ticket number creation range, etc
int Lottery::generateTicketNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // Define the range [1, 50]
    std::uniform_int_distribution<> distrib(1, 50);
    
    return distrib(gen);
}

void Lottery::addParticipant(const std::string& name) {
    int ticket = generateTicketNumber();
    Participant newParticipant(name, ticket);
    participants.push_back(newParticipant);
    
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Participant: " << name << std::endl;
    std::cout << "Assigned Ticket Number: " << ticket << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

void Lottery::drawWinnerAndEndRound() {
    std::cout << "\n================================================" << std::endl;
    std::cout << "LOTTERY DRAW" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "The Winning Number was: " << winningNumber << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    bool winnerFound = false;
    for (const auto& participant : participants) {
        if (participant.getTicketNumber() == winningNumber) {
            std::cout << "WINNER! " << participant.getName() << " has the winning ticket!" << std::endl;
            saveWinnerToFile(participant.getName(), winningNumber);
            winnerFound = true;
        }
    }

    if (!winnerFound) {
        std::cout << "No one won the lottery this time." << std::endl;
    }
    
    std::cout << "------------------------------------------------" << std::endl;
    resetLottery();
    std::cout << "================================================" << std::endl;
}

void Lottery::saveWinnerToFile(const std::string& name, int ticket) {
    std::ofstream outFile("winners.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Winner: " << name << " | Ticket: " << ticket << std::endl;
        outFile.close();
    } else {
        std::cerr << "Unable to open winners.txt for writing." << std::endl;
    }
}

int Lottery::getWinningNumber() const {
    return winningNumber;
}

const std::vector<Participant>& Lottery::getParticipants() const {
    return participants;
}

void Lottery::showPreviousWinners() const {
    std::cout << "\n--- Previous Winners ---" << std::endl;
    std::ifstream inFile("winners.txt");
    std::string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cout << "(No previous winners found or file missing)" << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void Lottery::resetLottery() {
    participants.clear();
    winningNumber = generateTicketNumber();
    std::cout << "System Reset: Participants cleared. New winning number generated." << std::endl;
}