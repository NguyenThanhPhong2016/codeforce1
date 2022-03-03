    #include<bits/stdc++.h>

    using namespace std;

    int n, m, a[1000010], x, s[1000010], q, l, r;
    char c;

    int main(){
    	cin >> n >> m;
    	for(int i = 1; i <= n; i++){
            cout<<" i : "<<i<<endl;
    		for(int j = 1; j <= m; j++){
    			cin >> c;
    			x = c == 'X';
                cout<<a[j]<<" "<<a[j-1]<<endl;
    			if(a[j] && a[j - 1]) s[j] = 1;
    			cout<<" J : "<<j<<" "<<s[j]<<endl;
    			a[j] = x;
    		}
    	}
    	for(int i = 1; i <= m; i++){
    		s[i] += s[i - 1];
    	}
    	cin >> q;
    	for(int i = 1; i <= q; i++){
    		cin >> l >> r;
    		cout<<s[r]<<" "<<s[l]<<endl;
    		if(s[r] - s[l]) cout << "NO" << endl;
    		else cout << "YES" << endl;
    	}
    	return 0;
    }
