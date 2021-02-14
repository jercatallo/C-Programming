#include <iostream>
#include <windows.h>
#include "mmsystem.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <winable.h>

using namespace std;
//Variables
int coin = 0,coinsLength = 1;
string menu[3] = {"1 Player", "2 Players","Controls"};
int main();
int pointer = 0;
//Color Files
void colorBlue(){
HANDLE yourScoreColor = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute(yourScoreColor, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void colorRed(){
HANDLE computerScoreColor = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute(computerScoreColor, FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void colorWhite(){
HANDLE defaultColor = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute(defaultColor, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void colorGreen(){
HANDLE defaultColor = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute(defaultColor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
//Sound Files
void homeSound(){
PlaySound(TEXT("sounds/homemusic.wav"),NULL,SND_ASYNC);
}
void gameOverSound() {
PlaySound(TEXT("sounds/gameover.wav"),NULL, SND_ASYNC);
}
void coinSound(){
PlaySound(TEXT("sounds/coin.wav"),NULL, SND_ASYNC);
}
void overCoinSound(){
 PlaySound(TEXT("sounds/yamete.wav"),NULL, SND_ASYNC);
}
void attackSound(){
PlaySound(TEXT("sounds/attacksound/sworddraw.wav"),NULL, SND_ASYNC);
}
void attackSound2(){
PlaySound(TEXT("sounds/attacksound/kungfu.wav"),NULL, SND_ASYNC);
}
//Home Screen
void intro(){
system("cls");
PlaySound(TEXT("sounds/intro.wav"),NULL, SND_ASYNC);
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"      Once Upon a time";
Sleep(5000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"    There are THREE Legends ";
Sleep(4000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"  THE ROCK";
Sleep(4000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<" THE PAPER";
Sleep(4000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"AND THE SCISSORS";
Sleep(4000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
Sleep(5000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"THEN THERE IS A WOMAN PASSING BY";
Sleep(4000);
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"And then";
Sleep(3000);
PlaySound(TEXT("sounds/lee.wav"),NULL, SND_ASYNC);
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(18000);
system("cls");
}
void loading(){
    system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"  LOADING";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
}
void Home(){
    PlaySound(TEXT("sounds/homemusic.wav"),NULL, SND_ASYNC);
    HANDLE titleColor = GetStdHandle( STD_OUTPUT_HANDLE );
cout<<endl;
// Please insert Coin and Credits Counter
if(coin >=1) {
colorWhite();
cout<<" Please Press S....."<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"   Credits: "<<coin;
cout<<endl<<endl<<endl<<endl<<endl;

} else {
colorWhite();
cout<<" Please Insert Coin....."<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"   Credits: "<<coin;
cout<<endl<<endl<<endl;
}
//ROCK PAPER SCISSORS TITLE
colorWhite();
cout<<"______________ _____________ ______ _________ _________ ___________ _____ _ ___"<<endl;
cout<<"______ ____ ____ ________ _____ ______ _________ ___ ______ _______ ______"<<endl;
cout<<"______________ _____________ ______ _________ _________ _____________"<<endl<<endl<<endl;
colorBlue();
cout<<"     __ _ ___ __ ___ ___"<<" ROCK! PAPER! SCISSORS! GO!"<<" __ _ ___ __ ___ __"<<endl;
colorRed();
cout<<"   __ _ ___ __ ___ _____"<<" ROCK! PAPER! SCISSORS! GO!"<<" ____ ___ ____ __ __ __"<<endl;
colorGreen();
cout<<" __ _ ___ __ ___ _______"<<" ROCK! PAPER! SCISSORS! GO!"<<" ___________ _____ ____ __"<<endl;
colorWhite();
cout<<endl<<"          ___________ ______ __________ _________ ______________ ______________"<<endl;
cout<<"   _______ ____ _______ ______ __________ _________ ______________ ____________"<<endl;
cout<<" ______ _____ ______ __________ _________ ______________ ______________"<<endl;
cout<<endl<<endl<<endl;
//1 PLAYER AND TWO PLAYER AND MY NAME AND CREDITS
HANDLE textsColor = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute(textsColor, FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
if(coin >=1){
cout<<"\t""\t""\t"<<"Press S to Continue"<<endl;
}
cout<<endl;
cout<<"\t""\t""\t"<<"(c)"<<"2019 Jer Carlo D. Catallo"<<endl;
}
void options(){
colorBlue();
cout<<"Player 1:"<<"\t"<<"\t";
colorRed();
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"Player 2:"<<endl;
colorWhite();
cout<<"Rock -  a "<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"Rock -  1 "<<endl;
cout<<"Paper - s "<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"Paper -  2 "<<endl;
cout<<"Scissors -  d "<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"Scissors -  3 "<<endl;
}
// Game Stage
void gameOver(){
    system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"  GAME OVER";
gameOverSound();
}
void onePlayer(){
Sleep(2000);
string pick;
int picked,compPick,i;
int compScore = 0,yourScore = 0,draw = 0;
string result[3] = {"Rock","Paper","Scissors"};

cout<<"Get Ready";
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(2000);
            cout<<".";
            Sleep(4000);
loading();
PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
for(i=0;i<11;i++) {

system("cls");
Sleep(1000);
srand (time(NULL));
compPick = rand() % 3;
colorBlue();
cout<<endl<<endl<<"Your Score: "<<yourScore;
colorRed();
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"       Computer Score: "<<compScore;
colorWhite();
cout<<endl<<"________________________________________________________________________________";
cout<<endl<<"Draw: "<<draw<<endl;
Sleep(2000);

cout<<endl<<endl<<endl<<"\t"<<"\t"<<"    Let's play Rock, Paper, Scissors!!!"<<endl;
cout<<endl<<"\t"<<"\t"<<"\t"<<"\t"<<"Round: "<<i<<endl;

if(_getch() == 'a'){
       picked=0;
       pick = "Rock";
       attackSound();
} else if (_getch() == 's'){
    picked=1;
      pick = "Paper";
       attackSound();
} else if (_getch() == 'd'){
 picked=2;
     pick = "Scissors";
      attackSound();
} else {
    colorRed();
    cout<<endl<<"\t"<<"\t"<<"\t"<<"          Disqualified"<<endl;
    cout<<endl<<"\t"<<"\t"<<"\t"<<"     Score is Deducted"<<endl;
    yourScore-= 1;
}

cout<<endl<<"\t"<<"\t"<<"     Fight Between: "<<pick<<" vs "<<result[compPick]<<endl<<endl;
cout<<"\t"<<"     Processing.............................Please Wait"<<endl<<endl;
Sleep(1000);
if(picked == compPick){
        colorWhite();
    cout<<"\t"<<"\t"<<"\t"<<"       >>>Draw<<<"<<endl;
    draw++;
    PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
Sleep(3000);
} else if ((picked == 0 && compPick == 1) || (picked == 1 && compPick == 2) || (picked == 2 && compPick == 0)) {
    colorRed();
    cout<<"\t"<<"\t"<<"\t"<<"     >>>You Lose!<<<";
    compScore++;
    PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
    Sleep(3000);
} else if(picked != 0 && picked != 1 && picked != 2){
    cout<<" ";
}

else {
    colorBlue();
      cout<<"\t"<<"\t"<<"\t"<<"    >>>You Win!<<<"<<endl;
      yourScore++;
      PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
      Sleep(3000);

}


cout<<endl<<endl<<endl<<endl<<endl<<endl;


if(i==10){
system("cls");
if(yourScore > compScore) {
        cout<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"Calculating the Final score................Please Wait"<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"LOADING"<<endl<<endl<<endl<<endl<<endl;
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
    cout<<"\t"<<"\t<"<<"\t"<<"\t"<<">>>>>>>>>>You are the new Champion<<<<<<<<<<<"<<endl;
    PlaySound(TEXT("sounds/champion.wav"),NULL, SND_ASYNC);
    Sleep(20000);
    gameOver();
    Sleep(5000);
    coin = 0;
    Sleep(5000);
    Home();

} else if(yourScore == compScore) {
       cout<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"Calculating the Final score................Please Wait"<<endl<<endl<<endl<<endl<<endl;
         cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"LOADING"<<endl<<endl<<endl<<endl<<endl;
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<">>>>>>>>>>DRAW<<<<<<<<<<<"<<endl;
    Sleep(7000);
      gameOver();
      Sleep(5000);
      coin = 0;
      Sleep(5000);
      Home();
} else {
  cout<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"Calculating the Final score................"<<endl<<endl<<endl<<endl<<endl;
   cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"LOADING"<<endl<<endl<<endl<<endl<<endl;
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<">>>>>>>>>>You lose<<<<<<<<<<<"<<endl;
    Sleep(7000);
       gameOver();
       Sleep(5000);
       coin = 0;
       Sleep(5000);
       Home();
}
}
}

}
void twoPlayer(){
Sleep(2000);
string pick,pick2;
int picked,picked2,compPick,i;
int secondScore = 0,yourScore = 0,draw = 0;
string result[3] = {"Rock","Paper","Scissors"};
cout<<"Get Ready";
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(2000);
            cout<<".";
            Sleep(4000);
loading();
PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
for(i=0;i<11;i++) {

system("cls");
Sleep(1000);
colorBlue();
cout<<endl<<endl<<"Player 1 Score: "<<yourScore;
colorRed();
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"      Player 2 Score: "<<secondScore;
colorWhite();
cout<<endl<<"________________________________________________________________________________";
cout<<endl<<"Draw: "<<draw<<endl;
Sleep(2000);

cout<<endl<<endl<<endl<<"\t"<<"\t"<<"    Let's play Rock, Paper, Scissors!!!"<<endl;
cout<<endl<<"\t"<<"\t"<<"\t"<<"\t"<<"Round: "<<i<<endl;

if(_getch() == 'a'){
       picked=0;
       pick = "Rock";
       attackSound();
} else if (_getch() == 's'){
    picked=1;
      pick = "Paper";
       attackSound();
} else if (_getch() == 'd'){
 picked=2;
     pick = "Scissors";
      attackSound();
} else {
    colorRed();
    cout<<endl<<"\t"<<"\t"<<"\t"<<"\t"<<"Disqualified"<<endl;
    cout<<endl<<"\t"<<"\t"<<"\t"<<"    Score is Deducted"<<endl;
    yourScore-= 1;
    Sleep(3000);
    continue;
}

if(_getch() == '1'){
       picked2=0;
       attackSound2();
} else if (_getch() == '2'){
       picked2=1;
       attackSound2();
} else if (_getch() == '3'){
        picked2=2;
        attackSound2();
} else {
    colorRed();
    cout<<endl<<"\t"<<"\t"<<"\t"<<"\t"<<"Disqualified"<<endl;
    cout<<endl<<"\t"<<"\t"<<"\t"<<"    Score is Deducted"<<endl;
    secondScore-= 1;
    Sleep(3000);
    continue;
}

cout<<endl<<"\t"<<"\t"<<"     Fight Between: "<<pick<<" vs "<<result[picked2]<<endl<<endl;
cout<<"\t"<<"     Processing.............................Please Wait"<<endl<<endl;
Sleep(1000);
if(picked == picked2){
        colorWhite();
    cout<<"\t"<<"\t"<<"\t"<<"       >>>Draw<<<"<<endl;
    draw++;
    PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
    Sleep(3000);
} else if ((picked == 0 && picked2 == 1) || (picked == 1 && picked2 == 2) || (picked == 2 && picked2 == 0)) {
    colorRed();
    cout<<"\t"<<"\t"<<"\t"<<"   >>>Player 2 Wins<<<";
    secondScore++;
    PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
    Sleep(3000);
} else if(picked != 0 && picked != 1 && picked != 2){
    cout<<" ";
}

else {
    colorBlue();
      cout<<"\t"<<"\t"<<"\t"<<"  >>>Player 1 Wins<<<"<<endl;
      yourScore++;
      PlaySound(TEXT("sounds/fight.wav"),NULL, SND_ASYNC);
      Sleep(3000);
}


cout<<endl<<endl<<endl<<endl<<endl<<endl;


if(i==10){
system("cls");
if(yourScore > secondScore) {
        cout<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"Calculating the Final score................Please Wait"<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"   LOADING";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
    cout<<endl<<endl<<endl<<endl<<endl<<"\t"<<"\t<"<<">>>>>>>>>>Player 1 is the New Champion<<<<<<<<<<<"<<endl;
      PlaySound(TEXT("sounds/champion.wav"),NULL, SND_ASYNC);
    Sleep(20000);
    gameOver();
    Sleep(5000);
    coin = 0;
    Sleep(5000);
    system("cls");
    main();

} else if(yourScore == secondScore) {
       cout<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"Calculating the Final score................Please Wait"<<endl<<endl<<endl<<endl<<endl;
         cout<<"\t"<<"\t"<<"\t"<<"   LOADING";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
    cout<<endl<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"\t"<<">>>>>>>>>>DRAW<<<<<<<<<<<"<<endl;
    Sleep(20000);
      gameOver();
      Sleep(5000);
      coin = 0;
      Sleep(5000);
      system("cls");
      main();


} else {
  cout<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"Calculating the Final score................"<<endl<<endl<<endl<<endl<<endl;
   cout<<"\t"<<"\t"<<"\t"<<"   LOADING";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
        Sleep(3000);
        cout<<".";
    cout<<endl<<endl<<endl<<endl<<endl<<"\t"<<"\t"<<"\t"<<">>>>>>>>>>Player 2 is the New Champion<<<<<<<<<<<"<<endl;
      PlaySound(TEXT("sounds/champion.wav"),NULL, SND_ASYNC);
    Sleep(20000);
       gameOver();
       Sleep(5000);
       coin = 0;
       Sleep(5000);
       system("cls");
       main();
}
}
}
}

//One player,Two Player and Option Select
void playerSelect() {
while(true)
	{
		system("cls");
		HANDLE titleColor = GetStdHandle( STD_OUTPUT_HANDLE );
cout<<endl;
// Please insert Coin and Credits Counter
if(coin >=1) {
    colorWhite();
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

} else {
  colorWhite();
cout<<" Please Insert Coin....."<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"   Credits: "<<coin;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}
//ROCK PAPER SCISSORS TITLE
colorBlue();
cout<<"\t"<<"\t"<<"\t"<<" ROCK! PAPER! SCISSORS! GO!"<<endl;
colorRed();
cout<<"\t"<<"\t"<<"\t"<<" ROCK! PAPER! SCISSORS! GO!"<<endl;
colorGreen();
cout<<"\t"<<"\t"<<"\t"<<" ROCK! PAPER! SCISSORS! GO!"<<endl;
colorWhite();
cout<<endl<<endl<<endl<<endl<<endl<<endl;
//1 PLAYER AND TWO PLAYER AND MY NAME AND CREDITS
  colorWhite();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<"\t"<<"\t"<<"\t"<<"\t"<<"Select Player"<<endl;

		for (int i = 0; i < 3; ++i)
		{
		     PlaySound(TEXT("sounds/menusound/choose.wav"),NULL, SND_ASYNC);
			if (i == pointer)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout<<"\t"<<"\t"<<"\t"<<"\t"<< menu[i]<< endl;
			}
			else
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout<<"\t"<<"\t"<<"\t"<<"\t"<< menu[i]<< endl;
			}
		}
		while(true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{

				pointer -= 1;
				if (pointer == -1)
				{

					pointer = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
					case 0:
					{	PlaySound(TEXT("sounds/menusound/select.wav"),NULL, SND_ASYNC);
						cout << "\n\n\nStarting new game...";
						onePlayer();

					} break;
					case 1:
					{
					    PlaySound(TEXT("sounds/menusound/select.wav"),NULL, SND_ASYNC);
						cout << "\n\n\nStarting new game...";
							twoPlayer();
					} break;
					case 2: {

					options();
					Sleep(5000);
					} break;

				}
				break;
			}
		}

		Sleep(150);
	}
cout<<endl<<endl<<endl;
cout<<"\t""\t""\t"<<"(c)"<<"2019 Jer Carlo D. Catallo"<<endl;
}
//Main Game
int main() {
//Main Game
int i,sel;
intro();
homeSound();
Home();
//Insert coin
for(i=0;i<coinsLength;i++) {
 switch (_getch()){
        case '0':
            system("cls");
            coin++;
            Home();
            coinsLength++;
            if(coin >= 15){
           overCoinSound();
            }else {
             coinSound();
            }
            break;
            case 's':
                system("cls");
                playerSelect();
            break;
        }
}
}
