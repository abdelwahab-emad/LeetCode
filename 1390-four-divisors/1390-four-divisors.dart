class GetDivisors{
    List<List<int>> getDivisors(){
        final int N = 100000 + 5;
        List<List<int>> divisors = List.generate(N, (_) => []);
        for(int i = 1;i < N;i++){
            for(int j = i;j < N ;j += i){
                divisors[j].add(i);
            }
        }
        return divisors;
    }
}
class Solution {
  int sumFourDivisors(List<int> nums) {
    GetDivisors div = GetDivisors();
    List<List<int>> divisors = div.getDivisors();
    int sum = 0;
    for(int i = 0;i < nums.length;i++){
        if(divisors[nums[i]].length == 4){
            for(int d in divisors[nums[i]]){
                sum += d;
            }
        }
    }
    return sum;
  }
}