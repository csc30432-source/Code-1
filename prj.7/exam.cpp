#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Global constant for the number of exam questions
const int NUM_QUESTIONS = 20;

// Function Prototypes for procedural decomposition
void getAnswers(string filename, char answers[]);
int gradeExam(const char answerKey[], const char studentAnswers[],
              int missedQuestions[], char correctMissed[],
              char studentMissed[]);
void writeReport(int numIncorrect, const int missedQuestions[],
                 const char correctMissed[], const char studentMissed[]);

int main() {
  // Arrays to store the correct answers and student responses
  char correctKey[NUM_QUESTIONS];
  char studentAnswers[NUM_QUESTIONS];
  // Parallel arrays to track which questions were missed
  int missedQuestions[NUM_QUESTIONS];
  char correctMissed[NUM_QUESTIONS];
  char studentMissed[NUM_QUESTIONS];

  // Read answer data from the provided text files
  getAnswers("CorrectAnswers.txt", correctKey);
  getAnswers("StudentAnswers.txt", studentAnswers);

  // Identify mismatches and compute the number of incorrect answers
  int numIncorrect = gradeExam(correctKey, studentAnswers, missedQuestions,
                               correctMissed, studentMissed);

  // Generate and display the formatted exam report
  writeReport(numIncorrect, missedQuestions, correctMissed, studentMissed);

  return 0;
}

/**
 * Opens a file, validates successful opening, and reads answers into an array
 */
void getAnswers(string filename, char answers[]) {
  ifstream inputFile;
  inputFile.open(filename);

  // Perform file input validation
  if (!inputFile) {
    cout << "Error opening file: " << filename << endl;
    exit(EXIT_FAILURE);
  }

  // Read one character per line as specified in the problem description
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    inputFile >> answers[i];
  }

  inputFile.close();
}

/**
 * Compares parallel arrays to identify mismatched data and tracks incorrect
 * questions  Returns the total number of incorrect answers
 */
int gradeExam(const char answerKey[], const char studentAnswers[],
              int missedQuestions[], char correctMissed[],
              char studentMissed[]) {
  int incorrectCount = 0;

  // Use a loop to compare each question index
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    if (answerKey[i] != studentAnswers[i]) {
      // Track the index and the specific answers for the report
      missedQuestions[incorrectCount] = i;
      correctMissed[incorrectCount] = answerKey[i];
      studentMissed[incorrectCount] = studentAnswers[i];
      incorrectCount++;
    }
  }

  return incorrectCount;
}

/**
 * Calculates percentage, determines pass/fail status, and displays formatted
 * results
 */
void writeReport(int numIncorrect, const int missedQuestions[],
                 const char correctMissed[], const char studentMissed[]) {
  // Compute the score percentage based on 20 questions
  double score =
      ((NUM_QUESTIONS - numIncorrect) / static_cast<double>(NUM_QUESTIONS)) *
      100.0;

  // Produce formatted output matching the expected results
  cout << "Exam Report Details" << endl;
  cout << "Number questions missed: " << numIncorrect << endl;

  if (numIncorrect > 0) {
    cout << "Missed questions and correct answers:" << endl;
    cout << left << setw(10) << "Question" << setw(16) << "Correct Answer"
         << "Your Answer" << endl;

    for (int i = 0; i < numIncorrect; i++) {
      // Display missed question details: Index, Correct Answer, and Student
      // Answer
      cout << left << setw(10) << missedQuestions[i] << setw(16)
           << correctMissed[i] << studentMissed[i] << endl;
    }
  }

  // Determine pass/fail result based on a 70% threshold
  cout << fixed << setprecision(2);
  cout << "Test score: " << score << "%" << endl;
  if (score >= 70.0) {
    cout << "You passed the exam." << endl;
  } else {
    cout << "You failed the exam." << endl;
  }
}