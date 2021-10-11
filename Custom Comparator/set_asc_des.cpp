//first ascend second descend
struct custom_pair
{
   bool operator() (const pair<int,int> &a,const pair<int,int> &b) 
   const 
   {
      if(a.first == b.first)
      {
         return a.second > b.second;
      }
      return a.first < b.first;
   }
};

//first descend second ascend
struct custom_pair
{
   bool operator() (const pair<int,int> &a,const pair<int,int> &b) 
   const 
   {
      if(a.first == b.first)
      {
         return a.second < b.second;
      }
      return a.first > b.first;
   }
};

//second ascend first ascend
struct custom_pair
{
   bool operator() (const pair<int,int> &a,const pair<int,int> &b) 
   const 
   {
      if(a.second == b.second)
      {
         return a.first < b.first;
      }
      return a.second < b.second;
   }
};

//second ascend first descend
struct custom_pair
{
   bool operator() (const pair<int,int> &a,const pair<int,int> &b) 
   const 
   {
      if(a.second == b.second)
      {
         return a.first > b.first;
      }
      return a.second < b.second;
   }
};


//second descend first ascend
struct custom_pair
{
   bool operator() (const pair<int,int> &a,const pair<int,int> &b) 
   const 
   {
      if(a.second == b.second)
      {
         return a.first < b.first;
      }
      return a.second > b.second;
   }
};

//second descend first descend
struct custom_pair
{
   bool operator() (const pair<int,int> &a,const pair<int,int> &b) 
   const 
   {
      if(a.second == b.second)
      {
         return a.first > b.first;
      }
      return a.second > b.second;
   }
};