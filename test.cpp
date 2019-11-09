#include <iostream>
#include <fstream>

using namespace std;

//PROTOTYPE
int getAmount();
void saveToFile(int amount,char letter,char x);
void processInput(char letter);
void display(char l);
char getInput();
void display(char k);
void hello();

int main(){
	//INTAILIZE
	char category;
	string date_spent;

	hello();
			
	return 0;
}

void processInput(char category){
 
	int amount;
	char category_e,n;

	if(category == 'I' || category == 'i'){

		amount = getAmount();
		cout <<"Enter income source P - parent M - self O - others";
		cin >>n;
		saveToFile(amount,category,n);	
	}else if(category == 'E' || category == 'e'){
	
		cout<<"Select category of expenses"<<endl;
		cout<<"S - Shopping  E - Enternment N - Snacks  O - Others"<<endl;
		cin>>category_e;

		if(category_e == 'S' || category_e == 's'){
			amount  = getAmount();	
			saveToFile(amount,'E',category_e);
			
		}else if( category_e == 'E' || category_e == 'e'){
			amount = getAmount();
			saveToFile(amount,'E',category_e);
		}else if(category_e == 'N' || category_e == 'n'){
			amount = getAmount();
			saveToFile(amount,'E',category_e);		
		}else if(category_e == 'O' || category_e == 'o'){
			amount = getAmount();
			saveToFile(amount,'E',category_e);
		}else{
			hello();
		}

	}else if( category == 'D' || category == 'd'){
		char jk;
		jk =getInput();
		
		if(jk == 'E' || jk == 'e' || jk == 'I' || jk == 'i' || jk == 'A' || jk == 'a')
			display(jk);
		else
			hello();		
	}else{
		hello();	
	}	
	
}
	
void hello(){
	char category;
	//INPUT
	cout<<"Welcome,Enter your category"<<endl;
	cout<<"I - Income Amount     E - Expenses D - Display Records"<<endl;
	
	cin>>category;
	
	processInput(category);	

}

char getInput(){
	cout<<"To display Expenses - E Income - I All- A"<<endl;
	char jk;
	cin>>jk;
	return jk;		
}

void display(char jk){
	ifstream dbFile("db.txt");
	int amount[100];
	char letter[100],sub[100],l,r;
	string date[100],d;
	int a,j,i =0;
	double sum =0;

	while(dbFile>>a>>l>>r>>d){
		if(jk == 'A' || jk == 'a'){
			amount[i] = a;
			letter[i] = l;
			sub[i] = r;
			date[i] =d;
			sum+=a;
			i++;		
		}else if(l == jk ){
			amount[i] = a;
			letter[i] = l;
			sub[i] = r;
			date[i] =d;
			sum+=a;
			i++;		
		}		
	}

	dbFile.close();
	cout<<"No.\tAmount\t\t Date"<<endl;
	for(j =0; j<i; j++)
		cout<<(j+1)<<"\t"<<amount[j]<<"\t\t"<<date[j]<<endl;
	
	cout<<"-----------------------------------"<<endl;
	cout<<"\t\t\tTotal: "<<sum<<endl;
	hello();

}


int getAmount(){
	int amount;
	cout<<"Enter Amount(It should be more than 0)"<<endl;
	cin>>amount;
	if(amount >0 && amount<50000){
		return amount;		
	}else{
		cout<<"Invalid input,Enter Amount."<<endl;
		hello();		
		return 0;
	}	
}

void saveToFile(int A, char L,char Z){
	ifstream dbFile("db.txt");
	int amount[100];
	char letter[100],sub[100],l,r;
	string date[100],d;
	int a,j,i =0;

	while(dbFile>>a>>l>>r>>d){
		amount[i] = a;
		letter[i] = l;
		sub[i] = r;
		date[i] =d;		
		i++;
	}
	dbFile.close();

	amount[i] = A;
	letter[i] = L;
	sub[i] = Z;
	
	string myDate;
	cout<<"Enter transaction Date.(dd-mm-yyyy)"<<endl;
	cin>>myDate;
	date[i] = myDate;
		
	cout <<"You have made some changes. Do you want to save ?"<<endl;
	cout << "Y - input to save changes"<<endl;
	cout <<"Input any other character to discard"<<endl; 
	char isTrue;
	cin >>isTrue;
	if(isTrue == 'Y' || isTrue == 'y'){
		ofstream dbFile2("db.txt");
		cout << "Saving ..."<<endl;
	 	for(j =0; j<=i; j++)
			dbFile2<<amount[j]<<' '<<letter[j]<<' '<<sub[j]<<' '<<date[j]<<endl;
		dbFile2.close();
		cout <<"Success!"<<endl;

		hello();
	}else{
		cout <<"Your changes have being discard"<<endl;	
		hello();
	}
}


