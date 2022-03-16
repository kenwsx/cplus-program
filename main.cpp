#include<iostream>
#include<string>
#include<vector>

int main(){
  const std::vector<int> vec_int(10,1);
  for(auto &it:vec_int)
  {
    it = 2;
    std::cout << it <<std::endl;

  }
  //std::cout << vec_int << std::endl;
}
