//first ascend second descend
bool custom_sort(const pair<int,int> &a,const pair<int,int> &b) 
{
   if(a.first == b.first)
   {
      return a.second > b.second;
   }
   return a.first < b.first;
}

//first descend second ascend
bool custom_sort(const pair<int,int> &a,const pair<int,int> &b) 
{
   if(a.first == b.first)
   {
      return a.second < b.second;
   }
   return a.first > b.first;
}

//second ascend first ascend
bool custom_sort(const pair<int,int> &a,const pair<int,int> &b) 
{
   if(a.second == b.second)
   {
      return a.first < b.first;
   }
   return a.second < b.second;
}



//second ascend first descend
bool custom_sort(const pair<int,int> &a,const pair<int,int> &b) 
{
   if(a.second == b.second)
   {
      return a.first > b.first;
   }
   return a.second < b.second;
}

//second descend first ascend
bool custom_sort(const pair<int,int> &a,const pair<int,int> &b) 
{
   if(a.second == b.second)
   {
      return a.first < b.first;
   }
   return a.second > b.second;
}

//second descend first descend
bool custom_sort(const pair<int,int> &a,const pair<int,int> &b) 
{
   if(a.second == b.second)
   {
      return a.first > b.first;
   }
   return a.second > b.second;
}