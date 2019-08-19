#include<iostream>
#include<string>
std::string s="HDU";
int main(void){
	int a,t;
	std::cin>>t;
	while(t--){
	std::cin>>a;
		for (int i = 0; i < 3*a; i++)
		{
			for (int i = 0; i < a; i++)
			{
				std::cout<<s;
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
