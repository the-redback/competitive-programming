func removeElement(nums []int, val int) int {
    n := len(nums)

    for i:=0; i<n ; {
        if nums[i] == val {
            nums[i] = nums[n-1];
            n--;
        } else {
            i++;
        }
    }

    return n;
}