#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

void testcase() {
	int n,k;
	scanf("%d%d",&n,&k);
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	bool searching=false;
	int prev;
	int ans=0;
	for (int i=0;i<n;i++) {
		if (a[i]==k) {
			searching=true;
			prev=a[i];
		}
		else if (searching) {
			if (prev!=a[i]+1) {
				searching=false;
			}
			if (a[i]==1 && prev==2) {
				ans++;
				searching=false;
			}
			prev=a[i];
		}
	}
	printf("%d",ans);
}

int main() {
	int t;
	cin>>t;
	for (int i=1;i<=t;i++) {
		printf("Case #%d: ",i);
		testcase();
		printf("\n");
	}		
}