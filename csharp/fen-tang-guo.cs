public class Solution {
    public int DistributeCandies(int[] candyType) {
        ISet<int> set = new HashSet<int>();
        foreach (int candy in candyType) {
            set.Add(candy);
        }
        return Math.Min(set.Count, candyType.Length / 2);
    }
}
