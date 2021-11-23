#include<bits/stdc++.h>
using namespace std;

int main()
{
	string p;
	cout<<"Enter pages: "<<endl;
	getline(cin,p);
	vector<int> pages;
	cout<<"Enter number of frames: "<<endl;
	int frames;
	cin>>frames;
	unordered_map<int,int> mp;
	vector<int> v;
	int i,j;
	string temp="";
	int hits=0;
	for(i=0;i<p.size();i++)
	{
		if(p[i]==' ')
		{
			int val=stoi(temp);
			pages.push_back(val);
			temp="";
		}
		else
		{
			temp+=p[i];
		}
	}
	if(temp!="")
	{
		int val=stoi(temp);
		pages.push_back(val);
	}
	for(i=0;i<pages.size();i++)
	{
		/*cout<<"V"<<endl;
		for(j=0;j<v.size();j++)
		{
			cout<<v[j]<<" ";
		}
		cout<<endl;*/
		if(mp.size()<frames)
		{
			if(mp.find(pages[i])==mp.end())
			{
				mp[pages[i]]=0;
				v.push_back(pages[i]);
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
				int f=0;
				for(j=0;j<v.size();j++)
				{
					if(v[j]!=-1 && mp[v[j]]==0)
					{
						mp.erase(v[j]);
						v[j]=-1;
						mp[pages[i]]=0;
						v.push_back(pages[i]);
						f=1;
						pos=j;
						break;
					}
				}
				if(f==0)
				{
					for(j=0;j<v.size();j++)
					{
						if(v[j]!=-1)
						{
							mp.erase(v[j]);
							v[j]=-1;
							mp[pages[i]]=0;
							v.push_back(pages[i]);
						}
					}
				}
				else
				{
					for(j=0;j<pos;j++)
					{
						if(v[j]!=-1)
						{
							mp[v[j]]=0;
						}
					}
				}
			}
			else
			{
				mp[pages[i]]=1;
				hits++;
			}
		}
		/*for(auto itr:mp)
		{
			cout<<itr.first<<" "<<itr.second<<endl;
		}
		cout<<endl;*/
	}
	float hit_ratio=((float)hits)/(pages.size());
	float miss_ratio=1-hit_ratio;
	//cout<<pages.size()-hits<<endl;
	cout<<"Hit-ratio is "<<hit_ratio<<" and miss ratio is "<<miss_ratio<<endl;
}
