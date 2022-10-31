#include <vector>
#include <iostream>
#include <string>

using namespace std;
/*
enum direction{
//x=1,
//y=1,
R[2]=(1,0),
L[2]=(-1,0),
U[2]=(0,-1),
D[2]=(0,1)
};
*/
/*
struct direction{
	vector<int> R{1,0};
	vector<int> L{-1,0};
	vector<int> U{0,-1};
	vector<int> D{0,1};
	vector<char> walk;
};*/

vector<int> PathFinder01(int N, string plan)//common way
{
	vector<char> way(plan.begin(),plan.end());
	vector<int> location;
	vector<char>::iterator itr;
	int x=0;
	int y=0;
	
	for(itr=way.begin();itr!=way.end();++itr)
	{
		switch(*itr)
		{
			case 'R':
				++x;
				break;
			case 'L':
				--x;
				break;
			case 'U':
				--y;
				break;
			case 'D':
				++y;
				break;
			default:
				break;
		}
	}
	location.push_back(x);
	location.push_back(y);
	
	return location;
}

vector<int> PathFinder01A(int N, string plan)//common way
{
	vector<char> way(plan.begin(),plan.end());
	vector<char>::iterator itr;
	vector<int> location;
	int xVec[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int yVec[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int Vec[2]={0,0};

	xVec[17]=1;
	xVec[11]=-1;
	yVec[20]=-1;
	yVec[3]=1;

	for(itr=way.begin();itr!=way.end();++itr)
	{
		Vec[0]+=xVec[static_cast<int>((*itr)-65)];
		Vec[1]+=yVec[static_cast<int>((*itr)-65)];
	}

	location.push_back(Vec[0]);
	location.push_back(Vec[1]);
	return location;
}

vector<int> PathFinder01B(int N, string plan)
{
	vector<char> way(plan.begin(),plan.end());
	vector<char>::iterator itr;
	vector<int> location;
	int xVec[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int yVec[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int Vec[2]={0,0};
	int planLength=0;
	planLength=way.size();
	int over[planLength*2+1]={0};
	int count=0;

	xVec[17]=1;//R
	xVec[11]=-1;//L
	yVec[20]=-1;//U
	yVec[3]=1;//D

	for(itr=way.begin();itr!=way.end();++itr)
	{
		Vec[0]+=xVec[static_cast<int>((*itr)-65)];
		Vec[1]+=yVec[static_cast<int>((*itr)-65)];
	}
	over[planLength+Vec[0]]=1;
	while(count<planLength)
	{
		over[count]=0;
		count++;
	}
	count=planLength+N;
	while(count<planLength*2)
	{
		over[count]=0;
		count++;
	}
	count=0;
	while(count<planLength*2)
	{
		++count;
	}
	over[planLength+Vec[1]]=1;
	location.push_back(Vec[0]);
	location.push_back(Vec[1]);
	return location;
}

vector<int> PathFinder01C(int N, string plan)
{
	vector<char> way(plan.begin(),plan.end());
	vector<char>::iterator itr;
	vector<int> location;
	int xVec[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int yVec[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int Vec[2]={1,1};
	int planLen=0;
	planLen=way.size();
	int count=0;
	int over[N+2]={0};
	int add=0;
	int R=17;
	int L=11;
	int U=20;
	int D=3;
	int X=0;
	int Y=1;

	while(count<N+2)
	{
		over[count]=1;
		++count;
	}
	count=1;
	while(count<N+1)
	{
		over[count]+=add;
		++add;
		++count;
	}
	over[N+1]=N;
	count=0;
	while(count<N+2)
	{
		cout<<"idx : "<<count<<" value : "<<over[count]<<endl;
		++count;
	}

	xVec[R]=1;
	xVec[L]=-1;
	yVec[U]=-1;
	yVec[D]=1;

	for(itr=way.begin();itr!=way.end();++itr)
	{
		Vec[X]+=xVec[static_cast<int>((*itr)-65)];
		Vec[X]=over[Vec[X]];
		Vec[Y]+=yVec[static_cast<int>((*itr)-65)];
		Vec[Y]=over[Vec[Y]];
	}

	location.push_back(Vec[X]);
	location.push_back(Vec[Y]);
	return location;
}

vector<int> PathFinder02(int N, string plan)
{/*
	#define R	vector<int> right
	#define L	vector<int> left
	#define U	vector<int> up
	#define D	vector<int> down
*/
//	vector<int> way(static_cast<int>(plan.begin()),static_cast<int>(plan.end()));
	vector<int> way(plan.begin(),plan.end());
	vector<int>::iterator way_itr;
	int length=0;
	int total=0;
	length=way.size();
	
	for(way_itr=way.begin();way_itr!=way.end();++way_itr)
	{
		total+=(*way_itr);
		cout<<(*way_itr)<<endl;
	}
	cout<<total<<endl;
	cout<<total/length<<endl;
	cout<<total%length<<endl;
	return way;
}

//vector<int> PathFinder03(int N, string plan)
void PathFinder03(int N, string plan)
{
	vector<char> way(plan.begin(),plan.end());
	vector<char>::iterator c_itr;
//	direction cordinate=static_cast<direction>(*way.begin());
/*	vector<direction> cord;rla
	for(c_itr=way.begin();c_itr!=way.end();++c_itr)
	{
		cord.push_back(*c_itr);
	}*/
	
//	cout<<static_cast<direction>(*way.begin())<<endl;
//	cout<<cordinate<<endl;
//	cout<<*cord.begin()<<endl;
}

//vector<int> PathFinder04(int N, string plan)
void PathFinder04(int N, string plan)
{/*
	direction cord;
	vector<char> way(plan.begin(),plan.end());
	cord.walk(plan.begin(),plan.end());
	char c_way;
	c_way=*way.begin();
	cout<<*(cord.R).begin()<<endl;
//	cout<<*(cord.c_way).begin()<<endl;
//	cout<<*(cord.way[0]).begin()<<endl;
	cout<<*((cord.walk).begin())<<endl;*/
}

int main(void)
{
	string plan="RRDDRDULRDRRRR";
	vector<int> location;

//	location=PathFinder01(5, plan);
//	location=PathFinder02(5, plan);
//	PathFinder03(5, plan);
//	PathFinder04(5, plan);
	location=PathFinder01C(5, plan);

	cout<<"we locate at "<<*(location.begin())<<", "<<*(location.begin()+1)<<endl;
	
	return 0;
}
