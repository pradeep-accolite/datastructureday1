#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std;

struct platform{
	int t;
	int p;
};

bool sort_by_name( const platform & lhs, const platform & rhs )
{
	return lhs.t < rhs.t;
}

int greater(int &a, int &b)
{
	return a > b;
}

int main() {
	int n;
	cin>>n;
	double starttime[n];
	struct platform availableplatform[4];
	availableplatform[0].t=availableplatform[1].t=availableplatform[2].t=availableplatform[3].t=0;
	availableplatform[0].p=1;
	availableplatform[1].p=2;
	availableplatform[2].p=3;
	availableplatform[3].p=4;

	int h,m;
	for(int i=0; i<n; i++){
		cin>>h>>m;
		starttime[i]=h*60+m;
	}

	sort(starttime,starttime+n);

	for(int i=0; i<n; i++){
		double time = starttime[i];

		//sort(availableplatform, availableplatform+4, sort_by_name);

		//	cout<<time<<" "<<availableplatform[0].t<<" "<<availableplatform[1].t<<" "<<availableplatform[2].t<<" "<<availableplatform[3].t<<"\n";

		int route=0;
		int j;
		bool set=false;
		if(!set){
			for(j=0; j<4; j++){
				if(availableplatform[j].t<(time+60)){
					availableplatform[j].t=time+60+15;
					route=1;
					set=true;
					break;
				}
			}
			//				cout<<j<<"\n";
		}


		if(!set){
			for(j=0; j<4; j++){
				if(availableplatform[j].t<(time+75)){
					availableplatform[j].t=time+75+15;
					route=2;
					set=true;
					break;
				}
			}
			//				cout<<j<<"\n";
		}

		//	cout<<j<<"\n";
		if(!set){
			for(j=0; j<4; j++){
				if(availableplatform[j].t<(time+105)){
					availableplatform[j].t=time+105+15;
					route=3;
					set=true;
					break;
				}
			}
			//				cout<<j<<"\n";
		}

		//	cout<<"SET "<<set<<"\n";
		if(!set)
		{
			cout<<"NO";
			return 0;
		}
		//cout<<time<<" "<<availableplatform[0].t<<" "<<availableplatform[1].t<<" "<<availableplatform[2].t<<" "<<availableplatform[3].t<<"\n";
		cout<<"TRAIN NO "<<i+1<<" PLATFORM "<<availableplatform[j].p<<" ROUTE "<<route<<" ";
		cout<<"ARRIVING TIME "<<(availableplatform[j].t-15)/60<<":"<<(availableplatform[j].t-15)%60;
		cout<<" DEPARTING TIME "<<(availableplatform[j].t)/60<<":"<<(availableplatform[j].t)%60<<"\n";
	}

	cout<<"YES";
	return 0;
}
