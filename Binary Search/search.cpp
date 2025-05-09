int s = 0, e = INT_MAX;
while(s <= e){
    int mid = s + (e - s)/2;
    if(check(mid))
        s = mid;
    else
        e = mid - 1;
}
return s;