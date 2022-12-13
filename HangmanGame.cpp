#include <iostream>
#include <string> 
#include <stdlib.h> 
#include <ctime>
#include <conio.h> 
#include <windows.h> 
#define WRONGTRIES 5

using namespace std;
void loading();
void header();
void main_menu();
void peraturan();
void lagi();
void game();

int main(){
 	system("color 5E");
 	main_menu();
 	return 0;
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
         					
    
}

void loading(){
    char a = 176, b = 219;
  
    printf("\n\n\n\n\n");
    printf("\n\n\n\n\n\t\t\t\t\t\t     Menunggu kepastian...\n\n");
    printf("\t\t\t\t\t\t");
  
    for (int i = 0; i < 27; i++)
        printf("%c", a);
  
    printf("\r");
    printf("\t\t\t\t\t\t");
  
    for (int i = 0; i < 27; i++) {
        printf("%c", b);
  
        Sleep(100);
    }
}
        
void gambar(int tries){
	if(tries==5) {
    	cout<<"  +---+ \n";
    	cout<<"  |   | \n";
    	cout<<"      | \n";
    	cout<<"      | \n";
    	cout<<"      | \n";
    	cout<<"      | \n";
    	cout<<" ========= \n";
	}
  	else if(tries==4){
	cout<<"  +---+ \n";
    	cout<<"  |   | \n";
    	cout<<"  O   | \n";
   	cout<<"  |   | \n";
    	cout<<"      | \n";
    	cout<<"      | \n";
    	cout<<" ========= \n";
	}
	else if(tries==3)
	{
	cout<<"  +---+ \n";
	cout<<"  |   | \n";
    	cout<<"  O   | \n";
    	cout<<" /|   | \n";
    	cout<<"      | \n";
    	cout<<"      | \n";
    	cout<<" ========= \n";
	}
	else if(tries==2)
	{
	cout<<"  +---+ \n";
	cout<<"  |   | \n";
	cout<<"  O   | \n";
	cout<<" /|\\  | \n";
	cout<<"      | \n";
	cout<<"      | \n";
	cout<<" ========= \n";
	}
	else if(tries==1)
	{
	cout<<"  +---+ \n";
	cout<<"  |   | \n";
	cout<<"  O   | \n";
	cout<<" /|\\  | \n";
	cout<<" /    | \n";
	cout<<"      | \n";
	cout<<" ========= \n";
	}
	else if(tries==0)
	{
	cout<<"  +---+ \n";
	cout<<"  |   | \n";
	cout<<"  O   | \n";
	cout<<" /|\\  | \n";
	cout<<" / \\  | \n";
	cout<<"      | \n";
	cout<<" ========= \n";
  }
	
}

void main_menu(){
	header();
	cout<< "\n\t\t\t\t\t          [Klik Enter]";
    	cout<< "\n\t\t\tKenapa klik Enter? karena kalo klik Entar gaada di keyboard xixixi :)\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	peraturan();
	system("pause");
	system("cls");
	game ();
}
void game (){
	char shap;
	header();
	cout<< "\n\t\t\t\t\t Apakah Anda shap bermain (y/t)? ";
	cin>>shap;
	system("cls");
	if(shap=='y'||shap=='Y') {
	loading();
	system("cls");
	srand (time(NULL));
	string wordList[10] = {"komodo","tokek","monyet","bunglon","pinguin","kucing","semut","siput","tikus","bebek"};
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
		cout<<endl<<endl;
		cout<<"Tebak nama hewan yang tidak memiliki huruf A : "<<endl<<endl;
		 
		for(int i=0; i<wordLength; i++)
			cout<<" "<<dispWord[i]<<" "; 
		cout<<endl<<endl<<endl;
		 		
		cout<<"Nyawa : "<<tries<<" / "<<WRONGTRIES<<endl;
		cout<<"Tebakan Huruf : "<<guessed<<endl; 
		
		gambar(tries);
		
		if( found == wordLength ){
			cout<<endl;
			cout<<"\t\t\t\t\t          Yeay Menang   "<<endl;
			cout<<"\t\t\t\t\t         Selamat yah!!! "<<endl;
			lagi();
			break;
		}
		
		if( tries == 0) break; 
		
		cout<<"Pilihan Huruf : ";
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
		cout<<"Jawaban\t: "<<word<<endl;
		cout<<"\t\t\t\t\t          Yah Kalah   "<<endl;
		cout<<"\t\t\t\t     Tetap putus asa, jangan semangat!!! "<<endl;
		lagi();
	}
	
	getch();
	}
	else if(shap=='t'||shap=='T')
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Syukurlah kalo ga jadi main "<<endl;
		cout<<"\n\t\t\t\t\t       (^_^) byebye!! "<<endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	else{
		system("cls");
		game();
	}
	system("break");
}
void peraturan(){
	cout<<"\t\t\t\t\t______________________________________________"<<endl;
	cout<<"\t\t\t\t\t|                                            |"<<endl;  
	cout<<"\t\t\t\t\t|            PERATURAN PERMAINAN             |"<<endl;
	cout<<"\t\t\t\t\t|____________________________________________|"<<endl;
	cout<<"\t\t\t\t\t| 1. Kata yang ditebak merupakan nama-nama   |\n\t\t\t\t\t|    hewan yang tidak memiliki huruf A.\t\t     |"<<endl;
	cout<<"\t\t\t\t\t| 2. Player menebak kata dengan menginputkan |\n\t\t\t\t\t|    huruf kecil satu per satu.\t\t     |"<<endl;
	cout<<"\t\t\t\t\t| 3. Player memiliki 5 nyawa pertama.        |"<<endl;
	cout<<"\t\t\t\t\t| 4. Jika huruf inputan salah maka nyawa     |\n\t\t\t\t\t|    player berkurang 1.\t\t     |"<<endl;
	cout<<"\t\t\t\t\t| 5. Jika nyawa player sudah 0 ya player     |\n\t\t\t\t\t|    kalah dan gantung diri\t\t     |"<<endl;
	cout<<"\t\t\t\t\t| 6. Jika player benar menebak kata dengan   |\n\t\t\t\t\t|    nyawa masih tersisa maka player menang  |\n\t\t\t\t\t|    dan dapet hikmahnya .\t\t     |"<<endl;
	cout<<"\t\t\t\t\t|____________________________________________|"<<endl;
	cout<<"\n\n\t\t\t              \t \t\t [Klik Enter] \n\n\n\n\n\n\n\n\n\n";
	}

void lagi(){
	
	char pilih;
	
	cout << "\n\n\n\n\t\t\t\t\t   Mau main lagi ga (y/t)? ";
	cin >> pilih;
	
	if(pilih=='y'||pilih=='Y'){
		system("cls");
		game();
	}
	else if (pilih=='t'||pilih=='T'){
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTerimakasih sudah memainkan game by DDP";
		cout<<"\n\t\t\t\t\t\t       (^_^) byebye!! *"<<endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	else {
		cout<<"\t\t\t\t\t       SALAH INPUT WOY!"<<endl;
		lagi();
	}
}
