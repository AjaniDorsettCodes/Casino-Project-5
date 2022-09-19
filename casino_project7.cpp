#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;
class Casino{
	protected:
float roulette(float& GamblingMoney) {
	string choice;
	float BettingMoney = 0.0;
	string ColourChoice;
	int rouletteNumberChoice;
	srand(time(0));
	int randomColour = (rand() % 2) + 1;
	srand(time(0));
	int randomRouletteNumber = (rand() % 100) + 1;
	string RedorBlack;
	//cout << randomRouletteNumber;
	if (randomColour == 1) {
		RedorBlack = "red";
	}if (randomColour == 2) {
		RedorBlack = "black";
	}
	if (GamblingMoney > 0.0) {
		cout << "How much money are you willing to bet?\n";
		cin >> BettingMoney;
		while (BettingMoney > GamblingMoney) {
			cout << "You don't even have that much money try again\n";
			cin >> BettingMoney;
		}
		cout << "\nAre you choosing numbers, colours or both?\n";
		cin >> choice;
		if (choice == "colours" || choice == "Colours") {
			cout << "Which colour are you choosing, red or black?\n";
			cin >> ColourChoice;

			cout << RedorBlack << endl;
			if (RedorBlack == ColourChoice) {
				GamblingMoney = GamblingMoney + BettingMoney;
				cout << "You win\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
			}
			if (!(RedorBlack == ColourChoice)) {
				GamblingMoney = GamblingMoney - BettingMoney;
				cout << "You lose\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
			}
		}// if choice = colours
		else if (choice == "numbers" || "Numbers" && choice != "colours" && choice != "Colours" && choice != "Both" && choice != "both") {
			cout << "Pick a number between 0 and 100" << endl;
			cin >> rouletteNumberChoice;
			if (randomRouletteNumber == rouletteNumberChoice) {
				GamblingMoney = GamblingMoney + BettingMoney;
				cout << "The Lucky Number is: ";
				cout << randomRouletteNumber << endl;
				cout << "You win\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
			}
			if (!(randomRouletteNumber == rouletteNumberChoice)) {
				GamblingMoney = GamblingMoney - BettingMoney;
				cout << "The Lucky Number is: ";
				cout << randomRouletteNumber << endl;
				cout << "You lost\n";
				cout << "The amount of money you have is: ";
				cout << GamblingMoney << endl;
			}
		}// if choice = numbers
		if (choice == "both") {
			cout << "What is your number and your colour?\n";
			cin >> rouletteNumberChoice;
			cout << "\n";
			cin >> ColourChoice;
			if (randomRouletteNumber == rouletteNumberChoice && RedorBlack != ColourChoice) {
				GamblingMoney = GamblingMoney + BettingMoney;
				cout << "The Lucky Number is: ";
				cout << randomRouletteNumber << endl;
				cout << "Your number matches\n";
				cout << "You win\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
			}// if random number mathces
			if (RedorBlack == ColourChoice && randomRouletteNumber != rouletteNumberChoice) {
				GamblingMoney = GamblingMoney + BettingMoney;
				cout << "Your colour matches\n";
				cout << "You win\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
			} // if random colour matches
			if (RedorBlack == ColourChoice && randomRouletteNumber == rouletteNumberChoice) {
				GamblingMoney = GamblingMoney + (BettingMoney * 2);
				cout << "My god man, you are so lucky. You guessed the right number and the right colour. Enjoy your winnngs\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney << endl;

			}
			if (RedorBlack != ColourChoice && randomRouletteNumber != rouletteNumberChoice) {
				GamblingMoney = GamblingMoney - BettingMoney;
				cout << "Unlucky, you didnt get the colour or the number right\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney << endl;
			}
		}
	}
	return GamblingMoney;
} // end of roulette

float blackjack(float& GamblingMoney) {
	string choice;
	float BettingMoney = 0.0;
	int RandomHitNumber;
	srand(time(0));
	int randomCPUNumber1 = (rand() % 20) + 1;
	int randomCPUNumber2 = (rand() % 21) + 1;
	srand(time(0));
	int sentinel = 0;
	srand(time(0));
	int HitCounter = 0;
	cout << "\nHow much money are you willing to bet?\n";
	cin >> BettingMoney;
	while (BettingMoney > GamblingMoney) {
		cout << "You don't even have that much money try again\n";
		cin >> BettingMoney;
	}
	cout << "\nThe number is:";
	cout << randomCPUNumber1 << endl;

	randomCPUNumber1 = (rand() % 20) + 1;
	do
	{
		cout << "\nWould you like to stand or hit?\n";
		cin >> choice;
		if (choice == "Hit" || choice == "hit") {
			srand((time(0)));
			RandomHitNumber = (rand() % 10) + 1;
			randomCPUNumber1 = randomCPUNumber1 + RandomHitNumber;
			cout << "The number is ";
			cout << randomCPUNumber1 << endl;
		}
		else if (choice == "stand" || choice == "Stand" && !(sentinel == 22)) {
			if (randomCPUNumber1 < randomCPUNumber2)
			{
				GamblingMoney = GamblingMoney - BettingMoney;
				cout << "The house has: ";
				cout << randomCPUNumber2;
				cout << " you lose\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
				sentinel = 22;
			}
			if (randomCPUNumber1 > randomCPUNumber2 && !(sentinel == 22)) {
				GamblingMoney = GamblingMoney + BettingMoney;
				cout << "The house has:";
				cout << randomCPUNumber2 << endl;
				cout << "You have: ";
				cout << randomCPUNumber1 << endl;
				cout << "You win\n";
				cout << "The money you have left is: ";
				cout << GamblingMoney;
				sentinel = 22;
			}
			if (randomCPUNumber1 == randomCPUNumber2 && !(sentinel == 22)) {
				cout << "It is a tie. You didn't lose or gain money\n";
				cout << "The money you have left is:";
				cout << GamblingMoney;
				sentinel = 22;
			}
		}
	} while (randomCPUNumber1 <= 21 && !(sentinel == 22));
	if (randomCPUNumber1 > 21) {
		GamblingMoney = GamblingMoney - BettingMoney;
		cout << "You lost because the number is higher than 21\n";
		cout << "The money you have left is: ";
		cout << GamblingMoney << endl;
	}
	return GamblingMoney;
}	// end of blackjack	 

float RockPaperScissors(float& GamblingMoney) {
	float BettingMoney;
	string RockPaperScissorsChoice;
	string RockPaperOrScissors;
	srand(time(0));
	int RockPaperScissorsDecider = (rand() % 3) + 1;
	if (RockPaperScissorsDecider == 1) {
		RockPaperOrScissors = "rock";
		//cout << "rock";
	}
	if (RockPaperScissorsDecider == 2) {
		RockPaperOrScissors = "paper";
		//cout << "paper";
	}
	if (RockPaperScissorsDecider == 3) {
		RockPaperOrScissors = "scissors";
		//cout << "scissors";
	}
	cout << "How much money are you willing to bet?\n";
	cin >> BettingMoney;
	while (BettingMoney > GamblingMoney) {
		cout << "You don't even have that much money try again\n";
		cin >> BettingMoney;
	}
	cout << "\nrock, paper or scissors?\n";
	cin >> RockPaperScissorsChoice;
	if (RockPaperScissorsChoice == "rock" && RockPaperOrScissors == "paper") {
		GamblingMoney = GamblingMoney - BettingMoney;
		cout << "I have: ";
		cout << RockPaperOrScissors << endl;
		cout << "You lose\n";
		cout << GamblingMoney << endl;

	}
	if (RockPaperScissorsChoice == "rock" && RockPaperOrScissors == "scissors") {
		GamblingMoney = GamblingMoney + BettingMoney;
		cout << "I have: ";
		cout << RockPaperOrScissors << endl;
		cout << "You win\n";
		cout << GamblingMoney << endl;
	}
	if (RockPaperScissorsChoice == "paper" && RockPaperOrScissors == "scissors") {
		GamblingMoney = GamblingMoney - BettingMoney;
		cout << "I have: ";
		cout << RockPaperOrScissors << endl;
		cout << "You lost\n";
		cout << "The money you have left is: ";
		cout << GamblingMoney << endl;
	}
	if (RockPaperScissorsChoice == "paper" && RockPaperOrScissors == "rock") {
		GamblingMoney = GamblingMoney + BettingMoney;
		cout << "I have: ";
		cout << RockPaperOrScissors << endl;
		cout << "You won\n";
		cout << "The money you have left is: ";
		cout << GamblingMoney << endl;
	}
	if (RockPaperScissorsChoice == "scissors" && RockPaperOrScissors == "rock") {
		GamblingMoney = GamblingMoney + BettingMoney;
		cout << "I have: ";
		cout << RockPaperOrScissors << endl;
		cout << "You lost\n";
		cout << "The money you have left is: ";
		cout << GamblingMoney << endl;
	}
	if (RockPaperScissorsChoice == "scissors" && RockPaperOrScissors == "paper") {
		GamblingMoney = GamblingMoney + BettingMoney;
		cout << "I have: ";
		cout << RockPaperOrScissors << endl;
		cout << "You won\n";
		cout << "The money you have left is: ";
		cout << GamblingMoney << endl;
	}
	if (RockPaperOrScissors == RockPaperScissorsChoice) {
		cout << "Tie. You didn't lose any money or gain money\n";
		cout << "The money you have left is: ";
		cout << GamblingMoney;
	}
	return GamblingMoney;
}//end of rock paper scissors

 float Slots(float& GamblingMoney){
float BettingMoney;
int ForLoopCounter = 5;
cout << "How much money do you wanna bet on slots? \n";
cin >> BettingMoney;
while (BettingMoney > GamblingMoney){
cout << "\nYou don't even have that much money, try again\n";
cin >> BettingMoney;
}
srand(time(0));
int slotNumber1 = (rand() % 5) + 1;
srand(time(0));
int slotNumber2 = (rand() % 5) + 1;
srand(time(0));
int slotNumber3 = (rand() % 5) + 1;
char XorO1;
char XorO2;
char XorO3;
if(!(GamblingMoney <=0)){
if(slotNumber1 == 1){
	XorO1 = 'X';
}
else if(slotNumber1 == 5){
	XorO1 = 'O';
}
else if(slotNumber1 == 2){
	XorO1 = '@';
}
else if(slotNumber1 == 3){
	XorO1 = '#';
}
else if(slotNumber1 == 4){
	XorO1 = 'L';
}
if(slotNumber2 == 1){
XorO2 = 'X';
}
else if(slotNumber2 == 3){
XorO2 = 'O';
}
else if(slotNumber2 == 5){
	XorO2 = '@';
}
else if(slotNumber2 == 2){
	XorO2 = '#';
}
else if(slotNumber2 == 4){
	XorO2 = 'L';
}
if(slotNumber3 == 1){
	XorO3 = 'X';
}
else if(slotNumber3 == 2){
	XorO3 = 'O';
}
else if(slotNumber3 == 5){
	XorO3 = '@';
}
else if(slotNumber3 == 3){
	XorO3 = '#';
}
else if(slotNumber3 == 4){
	XorO3 = 'L';
}
cout << XorO1;
Sleep(1000);
cout << "\t" <<XorO2;
Sleep(1000);
cout << " \t"<< XorO3 << endl;
Sleep(500);
if(XorO1 == 'L' && XorO2 == 'L' && XorO3 == 'L'){
	GamblingMoney = GamblingMoney/2;
	cout << "Uh-Oh! You just took a major L\n";
	cout << "The amount of money you have left is " << GamblingMoney << endl;
}
else if(XorO1 == XorO2 && XorO1 == XorO3){
	GamblingMoney = GamblingMoney * 2;
	cout << "You got them all right\n";
	cout << "The money you have left is " << GamblingMoney << endl;
}
else if(XorO1 == XorO2 && XorO1 != XorO3){
	GamblingMoney = GamblingMoney + BettingMoney;
	cout << "You got some of them right, nice job\n";
	cout << "The money you have left is " << GamblingMoney << endl;

}
else if(XorO2 == XorO3){
	GamblingMoney = GamblingMoney + BettingMoney;
	cout << "You got some of them right, nice job\n";
	cout << "The money you have left is " << GamblingMoney << endl;
}
else if (XorO1 != XorO2 && XorO1 != XorO3){
	GamblingMoney = GamblingMoney - BettingMoney;
	cout << "You didn't get anything right\n";
	cout << "The money you have left is " << GamblingMoney << endl;
}
else if(XorO1 == XorO3){
	GamblingMoney = GamblingMoney + BettingMoney;
	cout << "You got some of them right, nice job\n";
	cout << "The money you have left is " << GamblingMoney << endl;
}
}
return GamblingMoney;
}// end of Slots

float horses(float& GamblingMoney){
float BettingMoney;
int HorseNumber;
srand(time(0));
int RandomHorse1Number;
srand(time(0));
int RandomHorse2Number;
srand(time(0));
int RandomHorse3Number;
int HorseNumber1;
int HorseNumber2;
int HorseNumber3;
cout << "How much money do you want to bet?\n";
cin >> BettingMoney;
while(BettingMoney > GamblingMoney){
	cout << " You don't even have that much money, try again.\n";
	cin >> BettingMoney;
}
cout << "\nPick a horse, whichever horse goes farther wins. Second place gets half\n";
cout << "Do you pick horse 1,2 or 3?\n";
cin >> HorseNumber;
while(HorseNumber != 1 && HorseNumber != 2 && HorseNumber!= 3){
	cout << "We don't have a horse number: " << HorseNumber << " Enter either 1,2 or 3\n";
	cin >> HorseNumber;
}
cout << endl;
cout << "Horse 1: ";
for (int i = 0; i < 1; i++ ){
	srand(time(0));
	RandomHorse1Number = (rand() % 15) + 1;
	for(int i =0; i < RandomHorse1Number; i++){
	cout << "*";
	Sleep(250);
	HorseNumber1 = RandomHorse1Number;
	}
}
cout << endl;
cout << "Horse 2: ";
for (int i = 0; i < 1; i++ ){
	srand(time(0));
 	RandomHorse2Number = (rand() % 15) + 1;
	for(int i =0; i < RandomHorse2Number; i++){
	cout << "*";
	Sleep(250);
	HorseNumber2 = RandomHorse2Number;
	}
}
cout << endl;
cout << "Horse 3: ";
for (int i = 0; i < 1; i++ ){
	srand(time(0));
	RandomHorse3Number = (rand() % 15) + 1;
	for(int i = 0; i < RandomHorse3Number; i++){
	cout << "*";
	Sleep(250);
	HorseNumber3 = RandomHorse3Number;
	}
}

cout << endl;
if (HorseNumber == 1 && HorseNumber1 > HorseNumber2 && HorseNumber1 > HorseNumber3){
	GamblingMoney = GamblingMoney + BettingMoney;
	cout << "You win\n";
	cout << "The money you have left is: " << GamblingMoney << endl;
}
else if(HorseNumber == 2 && HorseNumber2 > HorseNumber1 && HorseNumber2 >HorseNumber3){
	GamblingMoney = GamblingMoney + BettingMoney;
	cout << "You win\n";
	cout << "The money you have left is: " << GamblingMoney << endl;
}
else if(HorseNumber == 3 && HorseNumber3 > HorseNumber1 && HorseNumber3 > HorseNumber2){
	GamblingMoney = GamblingMoney + BettingMoney;
	cout << "You win\n";
	cout << "The money you have left is: " << GamblingMoney << endl;
}
else if(HorseNumber == 1 && HorseNumber1 > HorseNumber2){
	GamblingMoney = GamblingMoney + (BettingMoney/2);
	cout << "There's no shame in second place.\n";
	cout << "The money you have left is: " << GamblingMoney << endl;
}
else if(HorseNumber== 1 && HorseNumber1 > HorseNumber3){
	GamblingMoney = GamblingMoney + (BettingMoney/2);
	cout << "There's no shame in second place.\n";
	cout << "The money you have left is: " << GamblingMoney <<endl;
}
else if(HorseNumber == 2 && HorseNumber2 > HorseNumber3){
	GamblingMoney = GamblingMoney + (BettingMoney/2);
	cout << "There's no shame in second place.\n";
	cout << "The money you have left is: " << GamblingMoney <<endl;
}
else if(HorseNumber == 2 && HorseNumber2 > HorseNumber1){
	GamblingMoney = GamblingMoney + (BettingMoney/2);
	cout << "There's no shame in second place.\n";
	cout << "The money you have left is: " << GamblingMoney <<endl;
}
else if(HorseNumber == 3 && HorseNumber3 > HorseNumber1){
	GamblingMoney = GamblingMoney + (BettingMoney/2);
	cout << "There's no shame in second place.\n";
	cout << "The money you have left is: " << GamblingMoney <<endl;
}
else if(HorseNumber ==3 && HorseNumber3 > HorseNumber2){
	GamblingMoney = GamblingMoney + (BettingMoney/2);
	cout << "There's no shame in second place.\n";
	cout << "The money you have left is: " << GamblingMoney <<endl;
}
else if(HorseNumber1 == HorseNumber2 && HorseNumber1 == HorseNumber3){
	cout << "It's a tie, you didn't win or lose money\n";
	cout << "The money you have left is: " << GamblingMoney;
}
else if(HorseNumber == 1 && (HorseNumber1 == HorseNumber2 || HorseNumber1 == HorseNumber3)){
cout << "It's a tie, you didn't win or lose money\n";
	cout << "The money you have left is: " << GamblingMoney;
}
else if(HorseNumber == 2 && (HorseNumber2 == HorseNumber1 || HorseNumber2 == HorseNumber3))
{
	cout << "It's a tie, you didn't win or lose money\n";
	cout << "The money you have left is: " << GamblingMoney;
}
else if(HorseNumber == 3 && (HorseNumber3 == HorseNumber1 || HorseNumber3 == HorseNumber2)){
	cout << "It's a tie, you didn't win or lose money\n";
	cout << "The money you have left is: " << GamblingMoney;
}
else{
	GamblingMoney = GamblingMoney - BettingMoney;
	cout << "You lost,sorry\n";
	cout << "The money you have left is: " << GamblingMoney << endl;
}
return GamblingMoney;
}// end of horses
public:
void EnterInfo() {
	float GamblingMoney = 1.00;
	string game;
	string DoYouWantToPlayAgain;
	cout << "Do you want to play a game?\n";
	cin >> DoYouWantToPlayAgain;
	cout << "Please enter the amount of money you wish to deposit\n";
	cin >> GamblingMoney;
	while (DoYouWantToPlayAgain == "yes" || DoYouWantToPlayAgain == "Yes") {
		if (GamblingMoney > 0) {
			cout << "\nwhat game do you want to play?\n";
			cout << "We have blackjack, roulette, rock paper scissors, slots, and horses\n";
			cin.ignore();
			getline(cin, game);

			if (game == "blackjack" || game == "Blackjack") {
				blackjack(GamblingMoney);
			}
			else if (game == "roulette" || game == "Roulette") {
				roulette(GamblingMoney);

			}
			else if (game == "rock paper scissors") {
				RockPaperScissors(GamblingMoney);
			}
			else if (game == "slots") {
				Slots(GamblingMoney);
			}
			else if (game == "horses"){
				horses(GamblingMoney);
			}
			cout << "\nDo you want to play again?\n";
			cin >> DoYouWantToPlayAgain;
		}
		if (GamblingMoney <= 0 && DoYouWantToPlayAgain == "yes") {
			cout << "\nOops, You're broke. Have a nice day\n";
			break;
		}
	}
	if (GamblingMoney > 0) {
		cout << "Your total amount is: ";
		cout << GamblingMoney;
	}
} // end of enter info
};

int main()
{
	Casino ajani;
	
	ajani.EnterInfo();

	return 0;
}