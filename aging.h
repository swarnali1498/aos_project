
int w=5;

struct page{
	int key;
	string b = "00000000";
};


int val(string bits){
	int ans=0;
	for(int i=0;i<w;i++){
        if(bits[i]=='1')
		ans+= pow(2,w-i-1);
	}
	return ans;
}

string right_shift(string s){
    string temp="0";
    for(int i=0;i<w-1;i++){
        temp += s[i];
    }
    return temp;
}

int approx_LRU(int cap, vector<int> token){
	vector<struct page> pg;
	int n = cap;
	int l = token.size();
	int miss=0;
	int flag=0;
	for(int i=0;i<l;i++){
		flag=0;
		int key1 = token[i];
		int l2 = pg.size();
		for(int j=0;j<l2;j++){
			if(pg[j].key == key1){
				flag=1;
				pg[j].b[0]='1';
			}
		}
		if(flag == 0 && l2<cap){
			struct page temp;
			temp.key = key1;
			temp.b[0] ='1';
			pg.push_back(temp);
			miss++;
		}
		else if(flag == 0 && l2==cap){
			int min =99999, index=0;
			for(int j=0;j<l2;j++){
				int temp = val(pg[j].b);
				if(temp<min){
					min = temp;
					index = j;
				}
			}
			pg[index].key = key1;
			pg[index].b = "10000000";
			miss++;
		}
		if((i+1)%n == 0){
			int l2 = pg.size();
			for(int j=0;j<l2;j++){
				pg[j].b = right_shift(pg[j].b);
			}
		}
	}
	return miss;
}