
#include "Quiz.h"
#include "QuizGame.h"

int main() {
//    Quiz quiz("labor05 kviz");
//    quiz.readFromFile("lab05/kviz.txt");
//    for (Question q : quiz.getQuestions()) {
//        cout << q.getText() << endl;
//        for(const Answer& a : q.getAnswers()){
//            cout << "\t "<< a.getText() << endl;
//        }
//    }
QuizGame game("labor5","lab05/kviz.txt" );
game.startGame();
return 0;
}