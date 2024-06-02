#include<iostream> 
#include<conio.h> 
#include<math.h> 
using namespace std; 
char plant[100];
 char cipher[100]; 
char p[]  ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' ,'Q','R','S','T','U','V','W','X','Y','Z'}; 
char ch[]  ={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K' ,'J','I','H','G','F','E','D','C','B','A'}; 
void monoEncryption() 
{ 
cout<<"Enter the plaintext : "; 
cin.ignore(); 
cin.getline(plant ,100);
int s = strlen(plant);
cout<<endl;
for(int j =0 ; j<26;j++) 
{ cout<<p[j];
 } 
 cout<<"=>PlainText\n";
for(int j =0 ; j<26;j++) 
{ cout<<ch[j];
 } 
 cout<<"=>Key\n\n";
cout<<"The ciphertext is :"; 
for(int i =0 ;i<s ;i++) 
{ 
for(int j =0 ; j<26;j++) 
{ 
if(p[j] == plant[i]) 
{ 
cout<<ch[j];
 break; 
} 
} 
} 
cout<<endl<<endl;
for(int i =0 ;i<s ;i++) 
{ 
for(int j =0 ; j<26;j++) 
{ 
if(p[j] == plant[i]) 
{ 
cout<<"\t\t"<<plant[i]<<"=>>"<<ch[j]<<endl;
 break; 
} 
} 
} 
cout<<"\n\n\n\n"; 
} 
void monoDecryption() 
{ 
cin.ignore (); 
cout<<"Enter the ciphertext : "; 
cin.getline(cipher,100); 
int s = strlen(cipher); 
cout<<"The plaintext is : "; 
for(int i =0 ;i<s;i++) 
{ 
for(int j=0 ; j<26 ;j++) 
{ 
if(ch[j] == cipher[i]) 
{ 
cout<<p[j];
break; 
} 
} 
} 
cout<<"\n\n\n\n"; 
} 
int main() { 
int c ; 
do{ cout<<"                         ###### Abubaker Sallam ######\n\n\n\n";
cout<<"1: convert the plantext use monoalphabet\n"; 
cout<<"2:convert the cipher text use monoalphabet in capital letters\n";
cout<<"3: exit\n\n\n"; 
cout<<"enter the number operation "; 
cin>>c; 
switch(c) {
case 1 : 
monoEncryption();
system("pause");
break; 
case 2: 
monoDecryption();
system("pause");
break; 
case 3: 
break; 
} 
}while(c !=3); 
return 0;

}