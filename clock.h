int clock(vector<int>& pages,int frames)
{
	unordered_map<int,int> mp;
	vector<int> v;
	int i,j;
	int hits=0;
	
	for(i=0;i<pages.size();i++)
	{
        //cout<<i<<endl;
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
				int f=0,num=v.size();
				for(j=0;j<num;j++)
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
					int num=v.size();
					for(j=0;j<num;j++)
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
	}
	float hit_ratio=((float)hits)/(pages.size());
	float miss_ratio=1-hit_ratio;
	/*cout<<"Hit-ratio is "<<hit_ratio<<endl;
	cout<<"Miss ratio is "<<miss_ratio<<endl;*/
	int misses = pages.size() - hits;
    return misses;
}
