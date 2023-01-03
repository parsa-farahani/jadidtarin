#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

struct person{
	string name;
	string tel;
	string email;

};

int main(){
	
	struct person p[3];
	
	cout<< "add: "<<'\t'<<"1"<<endl;
	cout<< "search: "<<"2"<<endl;
	cout<< "exit: "<<'\t'<<"3"<<endl;
	
	while(1){
		
	cout << "enter the number: ";
	int d;
	cin >> d;
	
	switch(d){
		case 1:
		{
			ofstream out;
			out.open("file1.txt");


			for(int i=0 ; i<3 ; i++){

				cin >> p[i].name;
				cin >> p[i].tel;
				cin >> p[i].email;
        		out << p[i].name <<"\t"<< p[i].tel <<"\t"<< p[i].email <<endl;
			}

			out.close();


			cout <<"do you wand to add 4th contact? (y/n): ";
			struct person q[3];
			char a;
			cin>> a;
			if (a == 'y'){
				out.open("file1.txt" , ios::app);
				cin >> q[0].name;
				cin >> q[0].tel;
				cin >> q[0].email;

				out << q[0].name <<"\t"<< q[0].tel <<"\t"<< q[0].email <<endl;
			}
			out.close();
			
			break;
		}
		
		case 2:
		{
			ifstream in;
			in.open("file1.txt");
			
			cout << "Enter the name for searching in the list: ";
			string s;
			cin >> s;
			int n=0;
			while(s[n] != '\0'){
				n++;
			}
			bool flag;
			
			string name;
			string tel;
			string email;
			
			while(in >> name >> tel >> email){
				
				for(int i=0 ; i<n  ; i++){
					if(name[i] == s[i]){
						flag = 1 ;
					}
					else{
						flag = 0;
					}
			 	}
				
				if(flag == 1){
					cout << name <<'\t'<< tel <<'\t'<< email <<endl;
					break;
				}

			}
			
			if (flag==0){
				cout <<"Not Found" <<endl;
			}
			
			
			

			/*for(int i=0 ; i<s.size() ; i++){
				if(name[i] != s[i]){
					cout << "N F";
					flag = 0;
					break;
				}
				flag = 1;
			}
			
			if (flag == 1){
				cout << name <<'\t'<< tel<<'\t'<< emai;
			}*/
			
			
			
			


			/*for(int i=0 ; i<3 ; i++){
				if((p[i].name) == s){
					cout << p[i].name <<"\t"<< p[i].tel <<"\t"<< p[i].email <<endl;
					flag = 1;
				}
			}

			if(flag==0){
				cout <<"Not Found!";
			}*/

			in.close();
			break;
		}
		
		case 3:
		{
			exit(1);
		}
		
	}
		
	}
	
	
	return 0;
}