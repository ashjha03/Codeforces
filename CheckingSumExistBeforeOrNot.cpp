ll x = v[i];
		ll low = 0, high = 1, sum = v[0] + v[1];
		bool f = 0;
		while(low < high and high < i){
			if(x == sum){ f = 1; break;}
			if(x > sum)	high++, sum += v[high];
			else	sum -= v[low], low++;
			if(low == high)	high++, sum += v[high];
		}
		if(f){	res++; continue;}

		low = i+1, high = i+2;
		if(high >= n)	continue;
		sum = v[low] + v[high];
		while(high < n and low < high){
			if(x == sum){ f = 1; break;}
			if(x > sum)	high++, sum += v[high];
			else	sum -= v[low], low++;
			if(low == high)	high++, sum += v[high];
		}
		if(f)	res++;
