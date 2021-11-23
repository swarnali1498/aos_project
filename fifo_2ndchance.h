#include<bits/stdc++.h>
using namespace std;

int fifo_secondchance(vector<int>& pages,int frames)
{
	unordered_map<int,int> mp;
	queue<int> q;
	int i,j;
	int hits=0;
	
	for(i=0;i<pages.size();i++)
	{
		if(mp.size()<frames)
		{
			if(mp.find(pages[i])==mp.end())
			{
				mp[pages[i]]=0;
				q.push(pages[i]);
			}
			else
			{
				hits++;
				mp[pages[i]]=1;
			}
		}
		else
		{
			int pos=0;
			if(mp.find(pages[i])==mp.end())
			{
				int f=0,num=q.size(),c=0;
				while(c!=num)
				{
					c++;
					int ele = q.front();
					q.pop();
					if(mp[ele] == 0)
					{
						mp.erase(ele);
						mp[pages[i]]=0;
						q.push(pages[i]);
						f=1;
						break;
					}
					else
					{
						mp[ele]=0;
						q.push(ele);
					}
				}
				if(f==0)
				{
					int ele=q.front();
					q.pop();
					mp.erase(ele);
				}
			}
			else
			{
				mp[pages[i]]=1;
				hits++;
			}
		}
	}
	float hit_ratio=((float)hits)/(pages.size());
	float miss_ratio=1-hit_ratio;
	/*cout<<"Hit-ratio is "<<hit_ratio<<endl;
	cout<<"Miss ratio is "<<miss_ratio<<endl;*/
	int misses = pages.size() - hits;
    return misses;
}
