<h1 align="center">🎟️ Lottery System (C++)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C++-blue"/>
  <img src="https://img.shields.io/badge/status-Completed-green"/>
  <img src="https://img.shields.io/badge/type-University%20Project-orange"/>
</p>


This project is a simple Object-Oriented Lottery System developed in C++ as part of a university assignment. It demonstrates core OOP principles such as encapsulation, class design, and basic file handling.

⸻⸻⸻⸻⸻⸻

📌 Features
	•	👤 Add participants with a name
	•	🎫 Automatically assign random ticket numbers
	•	🔐 Admin panel with password access
	•	🎲 Draw a winning number and determine the winner
	•	📄 Save winners to a file (winners.txt)
	•	📜 View previous winners

⸻⸻⸻⸻⸻⸻

🧱 Project Structure
```

├── main.cpp
├── Lottery.h
├── Lottery.cpp
├── Participant.h
├── Participant.cpp
├── winners.txt

```

⸻⸻⸻⸻⸻⸻

🧩 Classes

Participant

Represents a participant in the lottery.

Attributes:
	•	name
	•	ticketNumber

Methods:
	•	getName()
	•	getTicketNumber()

⸻⸻⸻⸻⸻⸻

Lottery

Manages the lottery system.

Responsibilities:
	•	Generating random ticket numbers
	•	Storing participants
	•	Drawing the winning number
	•	Determining the winner
	•	Saving results to a file

Key Methods:
	•	addParticipant(name)
	•	drawWinnerAndEndRound()
	•	showPreviousWinners()
	•	resetLottery()

⸻⸻⸻⸻⸻⸻

🖥️ How It Works

User Mode
	•	Users enter their name to join the lottery
	•	Each user receives a randomly generated ticket number

Admin Mode
	•	Accessed via password (hardcoded in the system)
	•	Allows:
	•	Viewing participants
	•	Revealing the winning number
	•	Viewing previous winners
	•	Drawing the winner

⸻⸻⸻⸻⸻⸻

⚙️ Compilation & Execution

Compile
```
g++ main.cpp Lottery.cpp Participant.cpp -o lottery
```

Run
```
./lottery
```

⸻⸻⸻⸻⸻⸻

📂 File Handling

    •	Winners are stored in winners.txt
	•	Each winner is saved with their name and ticket number
	•	The file keeps a record of previous lottery results

⸻⸻⸻⸻⸻⸻

📚 Concepts Used

	•	Object-Oriented Programming (OOP)
	•	Classes and Encapsulation
	•	STL (e.g., vectors)
	•	File I/O (fstream)
	•	Random number generation

⸻⸻⸻⸻⸻⸻

🧑‍💻 Author

Alper Ortak
GitHub: https://github.com/AlperTuncOrtak

