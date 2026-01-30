#include <iostream>
#include <limits>
#include "Lottery.h"

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Lottery lottery;
    int choice;
    std::string inputName;

    std::cout << "Welcome to the Expanded Lottery System!" << std::endl;

    while (true) {
        std::cout << "\nMAIN MENU" << std::endl;
        std::cout << "0. Name Entry (Join Lottery)" << std::endl;
        std::cout << "1. Admin Panel (Default PW: 1234)" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Select option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            clearInputBuffer();
            continue;
        }

        if (choice == 2) {
            std::cout << "Exiting... Goodbye!" << std::endl;
            break;
        } else if (choice == 0) {
            // Name Entry Mode
            clearInputBuffer(); // Clear newline from menu selection
            std::cout << "\n--- Name Entry Mode ---" << std::endl;
            while (true) {
                std::cout << "Enter participant name (or type 'back' to return): ";
                std::getline(std::cin, inputName);

                if (inputName == "back") {
                    break;
                }
                if (!inputName.empty()) {
                    lottery.addParticipant(inputName);
                }
            }
        } else if (choice == 1) {
            // Admin Panel
            std::string password;
            std::cout << "Enter Admin Password: ";
            std::cin >> password;

            if (password == "1234") {
                int adminChoice;
                bool stayInAdmin = true;
                while (stayInAdmin) {
                    std::cout << "\n--- ADMIN PANEL ---" << std::endl;
                    std::cout << "0. See Participants" << std::endl;
                    std::cout << "1. See Winning Number" << std::endl;
                    std::cout << "2. See Previous Winners" << std::endl;
                    std::cout << "3. Draw Winner & End Round" << std::endl;
                    std::cout << "4. Back to Main Menu" << std::endl;
                    std::cout << "Select option: ";
                    
                    if (!(std::cin >> adminChoice)) {
                        std::cout << "Invalid input." << std::endl;
                        std::cin.clear();
                        clearInputBuffer();
                        continue;
                    }

                    switch (adminChoice) {
                        case 0: {
                            const auto& participants = lottery.getParticipants();
                            std::cout << "\nCurrent Participants:" << std::endl;
                            if (participants.empty()) {
                                std::cout << "No participants yet." << std::endl;
                            } else {
                                for (const auto& p : participants) {
                                    std::cout << "Name: " << p.getName() << " | Ticket: " << p.getTicketNumber() << std::endl;
                                }
                            }
                            break;
                        }
                        case 1:
                            std::cout << "\nCurrent Winning Number (Hidden from Public): " << lottery.getWinningNumber() << std::endl;
                            break;
                        case 2:
                            lottery.showPreviousWinners();
                            break;
                        case 3:
                            lottery.drawWinnerAndEndRound();
                            break;
                        case 4:
                            stayInAdmin = false;
                            break;
                        default:
                            std::cout << "Invalid option." << std::endl;
                    }
                }
            } else {
                std::cout << "Incorrect password!" << std::endl;
            }
        } else {
            std::cout << "Invalid selection." << std::endl;
        }
    }

    return 0;
}