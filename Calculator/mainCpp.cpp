#include <iostream>

bool opSelector(char Op, double numInput_1, double numInput_2);
bool isDouble(double number);
void getChoice();

double result = 0;
char choice;
std::string fillString (19, '#');

int main(){
    do{
        std::cout << '\n';
        system("cls");
        std::cout << fillString << fillString << fillString << '\n';
        std::cout << fillString << " Simple Calculator " << fillString << '\n';
        std::cout << fillString << fillString << fillString << '\n' << '\n';
        std::cout << "Please enter the numbers you wish to calculate in the \ncorrect order with using the operations '+,-,/,*'.\n";
        std::cout << "Enter 'q' to quit.\n";

        double numInput_1;
        double numInput_2;
        char Op;

        if (result == 0){
            do{
            std::cout << "Enter the first number: ";
            std::cin >> numInput_1;
            std::cout << '\n';
            } while (isDouble(numInput_1));
        }
        else {
            numInput_1 = result;
            std::cout << "Your first number: " << numInput_1;
            std::cout << '\n';
        }

        do{
        std::cout << "Enter the second number: ";
        std::cin >> numInput_2;
        std::cout << '\n';
        } while (isDouble(numInput_2));

        do{
        std::cout << "Enter the operation: ";
        std::cin >> Op;
        std::cout << '\n';
        } while (opSelector(Op, numInput_1, numInput_2));

        std::cout << "Operation: " << numInput_1 << " " << Op << " " << numInput_2 <<'\n';
        std::cout << "Result: " << result << '\n' << '\n';
        
        getChoice();

    } while(choice != 'q');
    std::cout << '\n';
    std::cout << fillString << fillString << fillString << '\n';
    std::cout << fillString << " Fahreddin  Sengul " << fillString << '\n';
    std::cout << fillString << fillString << fillString << '\n' << '\n';
    return 0;
}

bool isDouble(double number){
    if (!std::cin.fail()){
        return false;
    }
    else{
        std::cin.clear ();
        std::cin.ignore ( 100 , '\n' );
        std::cout << "Please enter a valid number." << '\n';
        return true;
    }
}

bool opSelector(char Op, double numInput_1, double numInput_2){
    switch (Op)
    {
    case '+':
        result = numInput_1 + numInput_2;
        return false;
    case '-':
        result = numInput_1 - numInput_2;
        return false;
    case '/':
        result = numInput_1 / numInput_2;
        return false;
    case '*':
        result = numInput_1 * numInput_2;
        return false;
    default:
        std::cin.clear ();
        std::cin.ignore ( 100 , '\n' );
        std::cout << "Please enter a correct operation (+,-,/,*).";
        return true;
    }
}

void getChoice(){
    if (choice != 'c' && choice != 'q'){
        std::cout << "Press 'c' to continue calculation, press 'q' to quit: " << '\n';
        std::cin >> choice;
        getChoice();
    }
    else if (choice == 'c'){
        std::cout << "Press 'n' to start new calculation, press 'e' to use existing result as your first number: " << '\n';
        std::cin >> choice;
        if (choice == 'n'){
            result = 0;
        }
        else if (choice != 'e'){
            std::cout << "Please enter a valid choice.";
            choice = 'c';
            getChoice();
        }
    }
    else if (choice != 'q'){
        std::cin.clear ();
        std::cin.ignore ( 100 , '\n' );
        std::cout << "Please enter a valid choice.";
        getChoice();
    }
}