#include <iostream>
#include <string> 
#include <stdlib.h> 
#include <ctime>
#include <conio.h> 
#include <curses.h>
#include <windows.h> 
#define WRONGTRIES 5

using namespace std;
void close(){
	
	cout<<"\n\t\t\t\t\t Terima Kasih Sudah Bermain\n\n ";
	system("pause");
	system("cls");
	
}


void loading(){
	initscr();
	mvprintw(12, 55, "Loading");

	for(int n=1;n<5;n++){
	mvprintw(12,61+n, ".");
	refresh();
	Sleep(1000);   
	}
	refresh();
	

	endwin();    
}
void enter(){
	cout<< "\n\t\t\t\t\t          [ Klik Enter ]";
    cout<< "\n\t\t\t\tkenapa klik enter? karna kalo klik Entar program nya ga jalan\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	
	char mulai;
	
	cout<< "\n\t\t\t\t\t        Mulai Bermain?\n";
	cout<< "\t\t\t\t\t          (y/t) ? ";cin>>mulai;
	
	if(mulai=='y'||mulai=='Y')
	{
		loading();
	}
	else
	{
		close();
		system("cls");
	}

}
void header(){
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t     ~ SELAMAT DATANG DI GAME ~\n\n"<<endl;
	cout << 

"\t\t\t\t __ __  _____  _____   ____  ___ ___  _____  _____     \n"
"\t\t\t\t|  |  ||     ||     ||     ||   |   ||     ||     |    \n"
"\t\t\t\t|  |  ||  o  ||  _  ||   __|| _   _ ||  o  ||  _  |    \n"
"\t\t\t\t|  _  ||     ||  |  ||  |  ||  |_|  ||     ||  |  |    \n"
"\t\t\t\t|  |  ||  _  ||  |  ||  |__||   |   ||  _  ||  |  |    \n"
"\t\t\t\t|  |  ||  |  ||  |  ||     ||   |   ||  |  ||  |  |    \n"
"\t\t\t\t|__|__||__|__||__|__||___,_||___|___||__|__||__|__|    \n"<<endl;
         					enter();
    
}


void DrawMan(int tries){
	cout<<endl<<endl;
	cout<<"  -----"<<endl;
	cout<<"  |   |"<<endl; 
	cout<<"  |"; if(tries>=1) cout<<"   O    "; cout<<endl;
	cout<<"  |"; if(tries>=3) cout<<"  /|\\   "; cout<<endl;
	cout<<"  |"; if(tries>=5) cout<<"  / \\    "; cout<<endl;
	cout<<"  |"<<endl; 
	cout<<"__|__"<<endl;
}

int main (){
	system("color 5E");
	header();
	srand (time(NULL));
	string wordList[10] = {"naura","adelia","cakrawangsa","marcel","habibullah","riziq","mukti","fahreza","akmal","irma"};
	string word;
	string guessed;
	
	word = wordList[rand()%10];
	
	int wordLength = word.length();
	string dispWord (wordLength, '_');
	
	int found = 0;
	char guess = ' ';
	int tries = 5; //No of wrong tries
	int flagFound = 0; 

	while(tries>=0){
		system("cls");
		cout<<"Tebak Nama Mahasiswa Ilkomp 22 : "<<endl<<endl;
		 
		for(int i=0; i<wordLength; i++)
			cout<<" "<<dispWord[i]<<" "; 
		cout<<endl<<endl<<endl;
		 		
		cout<<"Nyawa : "<<tries<<" / "<<WRONGTRIES<<endl;
		cout<<"Tebakan Huruf : "<<guessed<<endl; 
		
		DrawMan(tries);
		
		if( found == wordLength ){
			cout<<endl;
			cout<<"*****************"<<endl;
			cout<<"*    Yeay Menang    *"<<endl;
			cout<<"*    Selamat yaa!!  *"<<endl;
			cout<<"*****************"<<endl;
			break;
		}
		
		if( tries == 0) break; 
		
		cout<<"Pilihan Huruf :";
		guess = getche();
		
		guessed = guessed + " " + guess;
		
		if( dispWord.find(guess)!=string::npos ) tries++;
		
		flagFound = 0;
		for(int i=0; i<wordLength; i++){
			if( word[i]==guess && dispWord[i]=='_' ){
				dispWord[i] = guess;
				found++;
				flagFound = 1; 
			}
		}
		 
		if( !flagFound )
			tries--;
	}
	if( found != wordLength ){
		cout<<endl;
	
		cout<<"\t\t\t\t\t          Yah Kalah   "<<endl;
		cout<<"\t\t\t\t\t        Semangat yah!! "<<endl;
	
	}
	
	getch();
	system("cls");
	return 0;
}

void lagi(){
	cout<<" Mau Main Lagi y/t ";
	
	char mulai;
	if(mulai=='y'||mulai=='Y')
	{
		loading();
	}
	else
	{
		header();
	}

}

