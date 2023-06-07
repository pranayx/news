#include <iostream>
#include<string.h>
using namespace std;

class node{
public:
	int tele;
	string name;
	node(){
		tele=0;
	}
	node(int a,string b){
		tele=a;
		name=b;
	}
	friend class hash;
};

class hashT{
public:
	node *hasharray;
	hashT()
	{
		hasharray=new node[10];
	}
	int hashcode(int no){
		int x;
		x=no%10;
		return x;
	}
	void insertwithoutReplacement(int key,string data){

		int hashindex=0;
		hashindex=hashcode(key);
		while(hasharray[hashindex].tele!= 0){
			++hashindex;
			hashindex=hashindex%10;
		}
		hasharray[hashindex]=node(key,data);
	}

	void insertwithreplacement(int key,string data){
		int hashindex;
		hashindex=hashcode(key);
		if(hasharray[hashindex].tele==0){
			hasharray[hashindex]=node(key,data);
			}
		else{
			int x;
			x=hasharray[hashindex].tele;
			int y;
			y=hashcode(x);
			if(y==hashindex){
				while(hasharray[hashindex].tele!= 0){
					++hashindex;
					hashindex=hashindex%10;
				}
				hasharray[hashindex]=node(key,data);
			}
			else{
				node temp=hasharray[hashindex];
				hasharray[hashindex]=node(key,data);
				while(hasharray[hashindex].tele!= 0){
					++hashindex;
					hashindex=hashindex%10;
				}
				hasharray[hashindex]=temp;

			}

		}

	}
	void search(int pN){
		int initialHashIndex = hashcode(pN);
		int finalHashIndex = initialHashIndex;
		int noOfComparisons = 0;
		do{
			noOfComparisons++;
			if(hasharray[finalHashIndex].tele == pN){
				cout<<"No. of comparisons: "<<noOfComparisons<<endl;
				cout<<hasharray[finalHashIndex].name<<" found."<<endl;
				return;
			}
			finalHashIndex++;
			finalHashIndex %= 10;
		}while(finalHashIndex != initialHashIndex);
		cout<<"No. of comparisons: "<<noOfComparisons<<endl;
		cout<<"Not found"<<endl;
	}

	void display(){
		for (int i=0;i<10;i++){
			cout<<hasharray[i].name<<" "<<hasharray[i].tele<<endl;
		}
	}



};


int main(){
	hashT obj;
	obj.insertwithoutReplacement(123,"abc");
	obj.insertwithoutReplacement(456,"def");
	obj.insertwithreplacement(123,"ghi");
	obj.insertwithreplacement(124,"feh");
	obj.display();
	obj.search(123);
	obj.search(111);
	return 0;
}

